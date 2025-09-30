#include <LiquidCrystal.h>

// Definição dos pinos do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LED vermelho
int ledVermelho = 8;

void setup() {
  // Inicializa o LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Teste LED");

  // Configura LED como saída
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  // Liga LED vermelho
  digitalWrite(ledVermelho, HIGH);
  lcd.clear();
  lcd.print("Cor: VERMELHO");
  delay(1000); // espera 1 segundo

  // Desliga LED vermelho
  digitalWrite(ledVermelho, LOW);
  lcd.clear();
  lcd.print("LED DESLIGADO");
  delay(1000); // espera 1 segundo
}
