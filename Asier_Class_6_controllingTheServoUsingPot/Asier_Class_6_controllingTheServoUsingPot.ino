#include <Servo.h>

Servo myservo;
const int potPin = A0;
int value;


void setup() {
  myservo.attach(9);
}

void loop() {
  value = analogRead(potPin);

  value = map(value, 0, 1023, 0, 180);

  myservo.write(value);
  delay(15);
}
