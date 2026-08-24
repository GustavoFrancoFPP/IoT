#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int BOTAO = 6;   
const int LED_VERDE = 9;
const int LED_VERMELHO = 10;

bool portaAberta = false;
bool botaoPressionado = false;

void setup() {
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  
  // LCD
  lcd.begin(16, 2);
  lcd.print("SISTEMA PRONTO");
  lcd.setCursor(0, 1);
  lcd.print("BOTAO: PINO 6");
  delay(2000);

  Serial.begin(9600);
  Serial.println("SISTEMA:INICIADO");
  Serial.println("PORTA:FECHADA");
  
  atualizarDisplay();
}

void loop() {
  bool estadoAtual = digitalRead(BOTAO);
  if (estadoAtual == LOW && !botaoPressionado) {
    botaoPressionado = true;
    portaAberta = !portaAberta;
    atualizarDisplay();
    delay(300); 
  }

  if (estadoAtual == HIGH && botaoPressionado) {
    botaoPressionado = false;
  }
  
  delay(50);
}

void atualizarDisplay() {
  lcd.clear();
  
  if (portaAberta) {
    lcd.setCursor(0, 0);
    lcd.print("   PORTA ABERTA  ");
    lcd.setCursor(0, 1);
    lcd.print("  [ALERTA!]     ");
    
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    

    Serial.println("PORTA:ABERTA");
    
  } else {

    lcd.setCursor(0, 0);
    lcd.print("   PORTA FECHADA");
    lcd.setCursor(0, 1);
    lcd.print("  [TUDO OK!]    ");
    
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, LOW);

    Serial.println("PORTA:FECHADA");
  }
}