int ledVermelho = 11;
int ledAmarelo  = 12;
int ledVerde    = 13;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  digitalWrite(ledVerde, HIGH);
  delay(2000);
  digitalWrite(ledVerde, LOW);

  digitalWrite(ledAmarelo, HIGH);
  delay(2000);
  digitalWrite(ledAmarelo, LOW);

  digitalWrite(ledVermelho, HIGH);
  delay(2000); 
  digitalWrite(ledVermelho, LOW);
}

