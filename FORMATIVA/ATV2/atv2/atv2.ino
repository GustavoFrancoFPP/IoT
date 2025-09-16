#include <Servo.h>

Servo motor;
int pot = A0;

void setup() {
  motor.attach(9); // Servo no pino 9
}

void loop() {
  int valor = analogRead(pot);
  int angulo = map(valor, 0, 1023, 0, 180);
  motor.write(angulo);
  delay(15);
}
