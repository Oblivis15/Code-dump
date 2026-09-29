int Led = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
}

void loop() {
  // put yourmain code here, to run repeatedly:
  analogWrite(Led, 0);
  delay(100);
    analogWrite(Led, 30);
  delay(100);
    analogWrite(Led, 60);
  delay(100);
    analogWrite(Led, 90);
  delay(100);
    analogWrite(Led, 120);
  delay(100);
    analogWrite(Led, 150);
  delay(100);
    analogWrite(Led, 180);
  delay(100);
    analogWrite(Led, 210);
  delay(100);
    analogWrite(Led, 210);
  delay(100);
    analogWrite(Led, 180);
  delay(100);
    analogWrite(Led, 150);
  delay(100);
    analogWrite(Led, 120);
  delay(100);
    analogWrite(Led, 90);
  delay(100);
    analogWrite(Led, 60);
  delay(100);
    analogWrite(Led, 30);
  delay(100);
    analogWrite(Led, 0);
  delay(100);
}
