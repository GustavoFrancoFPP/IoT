int ldr = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(ldr);
  Serial.print("Luminosidade: ");
  Serial.println(valor);
  delay(500);
}
