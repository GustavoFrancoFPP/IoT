#include <DHT.h>
#include <LiquidCrystal.h>

// Configuração do DHT11
#define DHTPIN  7      // pino de dados do DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Configuração do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // inicializa LCD 16x2
  dht.begin();       // inicializa DHT11
  Serial.begin(9600); // opcional, para monitor serial
}

void loop() {
  delay(2000); // DHT11 precisa de intervalo entre leituras

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Checa se a leitura falhou
  if (isnan(temperatura) || isnan(umidade)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor!");
    return;
  }

  // Mostra temperatura e umidade no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umidade);
  lcd.print(" %");

  // Mostra no Serial Monitor (opcional)
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.println(" C");
  Serial.print("Umid: ");
  Serial.print(umidade);
  Serial.println(" %");
}
