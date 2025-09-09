/***********************************************************************************
**********
- DHT11 -
@descrição: Exemplo simples de uso do sensor DHT11 para leitura de temperatura.
************************************************************************************
**********/

#include "DHT.h"          // Biblioteca do sensor DHT

// Porta usada e o tipo de sensor
#define PINO_DHT 3
#define TIPO_DHT DHT11

DHT dht(PINO_DHT, TIPO_DHT);

// Variável para armazenar a temperatura
float temperatura;

void setup() {
  Serial.begin(9600);   // Inicializando o monitor serial
  dht.begin();          // Inicializando o sensor
}

void loop() {
  delay(2000); // Aguarda dois segundos entre as leituras

  // Lê o valor da temperatura em °C
  temperatura = dht.readTemperature();

  // Verificando se existe erro na leitura
  if (isnan(temperatura)) {
    Serial.println("ERRO NO SENSOR!");
  }
  else {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");
  }
}
/* fim do código :) */
