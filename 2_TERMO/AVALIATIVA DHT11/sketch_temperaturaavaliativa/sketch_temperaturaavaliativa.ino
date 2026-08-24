#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 13, A0, A1, A2, A3);

int ledVerde = 8;
int ledAmarelo = 9;
int ledVermelho = 10;
int ledVentilador = 7;

int buzzer = 11;

DHT dht(DHTPIN, DHTTYPE);

float minIdeal = 20.0;
float maxIdeal = 26.0;
float alertaAlta = 30.0;
float alertaBaixa = 15.0;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVentilador, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();

  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.print("Erro DHT11");
    digitalWrite(ledAmarelo, HIGH);
    delay(2000);
    digitalWrite(ledAmarelo, LOW);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("  Umid: ");
  Serial.println(h);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Umid:");
  lcd.print(h);
  lcd.print("%");

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVentilador, LOW);
  digitalWrite(buzzer, LOW);

  if (t >= minIdeal && t <= maxIdeal) {
    digitalWrite(ledVerde, HIGH);
    lcd.setCursor(11, 0);
    lcd.print("OK ");
  }
  else if ((t > maxIdeal && t < alertaAlta) || (t < minIdeal && t > alertaBaixa)) {
    digitalWrite(ledAmarelo, HIGH);
    lcd.setCursor(11, 0);
    lcd.print("Aten");
  }
  else if (t >= alertaAlta) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVentilador, HIGH);
    tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);
    lcd.setCursor(11, 0);
    lcd.print("Calor");
  }
  else if (t <= alertaBaixa) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVentilador, HIGH);
    tone(buzzer, 800);
    delay(300);
    noTone(buzzer);
    lcd.setCursor(11, 0);
    lcd.print("Frio");
  }

  delay(2000);
}
