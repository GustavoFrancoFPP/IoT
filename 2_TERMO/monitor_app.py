from flask import Flask, render_template, jsonify, request
import serial
import time
import threading

app = Flask(__name__)

try:
    arduino = serial.Serial('COM3', 9600, timeout=0.1)
    time.sleep(2)
    print("✅ Arduino conectado - Controle via Web")
except Exception as e:
    print(f"❌ Arduino não conectado: {e}")
    arduino = None

status = {'porta': 'FECHADA'}

def ler_status_serial():
    """Thread para ler o status do Arduino"""
    while True:
        if arduino:
            try:
                while arduino.in_waiting > 0:
                    linha = arduino.readline().decode().strip()
                    print(f"Arduino: {linha}")
                    
                    if "PORTAAberta" in linha:
                        status['porta'] = 'ABERTA'
                    elif "PORTAFechada" in linha:
                        status['porta'] = 'FECHADA'
            except Exception as e:
                print(f"Erro serial: {e}")
        
        time.sleep(0.1)

if arduino:
    thread = threading.Thread(target=ler_status_serial, daemon=True)
    thread.start()

def enviar_comando(comando):
    """Envia comando para o Arduino"""
    if arduino:
        try:
            arduino.write(f"{comando}\n".encode())
            print(f"✅ Comando enviado: {comando}")
            return True
        except Exception as e:
            print(f"❌ Erro ao enviar comando: {e}")
            return False
    return False

@app.route('/')
def index():
    return render_template('monitor.html')

@app.route('/status')
def get_status():
    """Retorna o status atual"""
    return jsonify(status)

@app.route('/controlar/<acao>')
def controlar_porta(acao):
    """Controla a porta via web"""
    if acao == 'abrir':
        sucesso = enviar_comando("ABRIR")
        return jsonify({'status': 'ABERTA' if sucesso else 'ERRO'})
    elif acao == 'fechar':
        sucesso = enviar_comando("FECHAR")
        return jsonify({'status': 'FECHADA' if sucesso else 'ERRO'})
    else:
        return jsonify({'status': 'COMANDO_INVALIDO'})

if __name__ == '__main__':
    print("🚀 Sistema Web Iniciado!")
    print("📡 Acesse: http://localhost:5002")
    print("💡 Use os botões no site para controlar a porta!")
    app.run(debug=True, host='0.0.0.0', port=5002, use_reloader=False)