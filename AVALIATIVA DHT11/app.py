from flask import Flask, jsonify
import serial
import time
import threading

app = Flask(__name__)

# Variáveis para os dados
dados = {
    'temperatura': 0,
    'umidade': 0
}

arduino = None

# Thread para ler dados do Arduino
def ler_arduino():
    global dados
    while True:
        if arduino and arduino.in_waiting > 0:
            try:
                linha = arduino.readline().decode().strip()
                print("Arduino:", linha)
                
                # Procura por "Temp:" e "Umid:" na linha
                if "Temp:" in linha and "Umid:" in linha:
                    # Exemplo: "Temp: 24.50  Umid: 60.00"
                    temp_str = linha.split("Temp:")[1].split("Umid:")[0].strip()
                    umid_str = linha.split("Umid:")[1].strip()
                    
                    dados['temperatura'] = float(temp_str)
                    dados['umidade'] = float(umid_str)
                    
            except Exception as e:
                print("Erro na leitura:", e)
        
        time.sleep(1)

# Tenta conectar com Arduino
try:
    arduino = serial.Serial('COM4', 9600, timeout=1)
    time.sleep(2)
    print("Arduino conectado - Lendo dados...")
    threading.Thread(target=ler_arduino, daemon=True).start()
except:
    arduino = None
    print("Arduino não conectado")

@app.route('/')
def index():
    return '''
    <!DOCTYPE html>
    <html>
    <head>
        <title>Monitor Temperatura</title>
        <meta charset="UTF-8">
        <style>
            body {
                font-family: Arial, sans-serif;
                max-width: 400px;
                margin: 0 auto;
                padding: 20px;
                background: #f0f8ff;
            }
            .container {
                background: white;
                padding: 20px;
                border-radius: 10px;
                box-shadow: 0 0 10px rgba(0,0,0,0.1);
            }
            h2 {
                text-align: center;
                color: #333;
            }
            .dados {
                text-align: center;
                margin: 20px 0;
            }
            .temp {
                font-size: 32px;
                font-weight: bold;
                color: #e74c3c;
            }
            .umid {
                font-size: 24px;
                color: #3498db;
            }
            .atualizacao {
                text-align: center;
                color: #666;
                font-size: 12px;
                margin-top: 20px;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <h2>🌡️ Monitor de Temperatura</h2>
            
            <div class="dados">
                <div class="temp">
                    <span id="temperatura">0</span>°C
                </div>
                <div class="umid">
                    Umidade: <span id="umidade">0</span>%
                </div>
            </div>

            <div class="atualizacao">
                Atualizado: <span id="hora">--:--:--</span>
            </div>
        </div>

        <script>
            function atualizarDados() {
                fetch('/dados')
                    .then(response => response.json())
                    .then(dados => {
                        document.getElementById('temperatura').textContent = dados.temperatura.toFixed(1);
                        document.getElementById('umidade').textContent = dados.umidade.toFixed(1);
                        
                        // Atualiza hora
                        const agora = new Date();
                        document.getElementById('hora').textContent = 
                            agora.toLocaleTimeString();
                    })
                    .catch(error => {
                        console.log('Erro ao atualizar:', error);
                    });
            }

            // Atualiza a cada 2 segundos (mesmo intervalo do Arduino)
            setInterval(atualizarDados, 2000);
            
            // Primeira atualização
            atualizarDados();
        </script>
    </body>
    </html>
    '''

@app.route('/dados')
def get_dados():
    return jsonify(dados)

if __name__ == '__main__':
    print("Monitor iniciado: http://localhost:5000")
    app.run(host='0.0.0.0', port=5000, debug=False)