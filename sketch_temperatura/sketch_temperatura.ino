/*
 * ARDUINO - CONTROLE VIA SITE WEB
 * Aguarda comandos do Python para abrir/fechar porta
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LED_VERDE = 9;    // Porta FECHADA
const int LED_VERMELHO = 10; // Porta ABERTA

bool portaAberta = false;

void setup() {
  // Configuração dos pinos
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  
  // LCD
  lcd.begin(16, 2);
  lcd.print("AGUARDANDO");
  lcd.setCursor(0, 1);
  lcd.print("COMANDO WEB...");
  delay(2000);
  
  // Serial para comunicação com Python
  Serial.begin(9600);
  
  // Estado inicial
  atualizarDisplay();
}

void loop() {
  // Aguarda comandos do Python via Serial
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    
    if (comando == "ABRIR") {
      portaAberta = true;
      atualizarDisplay();
      Serial.println("PORTAAberta");
    }
    else if (comando == "FECHAR") {
      portaAberta = false;
      atualizarDisplay();
      Serial.println("PORTAFechada");
    }
    else if (comando == "STATUS") {
      // Responde com o status atual
      if (portaAberta) {
        Serial.println("PORTAAberta");
      } else {
        Serial.println("PORTAFechada");
      }
    }
  }
  
  delay(100);
}

void atualizarDisplay() {
  lcd.clear();
  
  if (portaAberta) {
    // PORTA ABERTA
    lcd.setCursor(0, 0);
    lcd.print("   PORTA ABERTA  ");
    lcd.setCursor(0, 1);
    lcd.print("  [ALERTA!]     ");
    
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    
  } else {
    // PORTA FECHADA
    lcd.setCursor(0, 0);
    lcd.print("   PORTA FECHADA");
    lcd.setCursor(0, 1);
    lcd.print("  [TUDO OK!]    ");
    
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
  }
}