int ledVerde = 2;
int ledAmarelo = 3;
int ledVermelho = 4;
int ledPedestre = 5;
int botao = 6;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledPedestre, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  if (digitalRead(botao) == HIGH) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledPedestre, HIGH);
    delay(5000);
  } else {
    digitalWrite(ledVerde, HIGH);
    delay(1000);
    digitalWrite(ledVerde, LOW);

    digitalWrite(ledAmarelo, HIGH);
    delay(1000);
    digitalWrite(ledAmarelo, LOW);

    digitalWrite(ledVermelho, HIGH);
    delay(1000);
    digitalWrite(ledVermelho, LOW);
  }
}
