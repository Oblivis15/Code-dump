void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(6, 191);
  digitalWrite(4, HIGH);
  delay(3000);
  digitalWrite(4, LOW);
  delay(3000);
  digitalWrite(2, HIGH);
  delay(3000);
  digitalWrite(2, LOW);
  delay(3000);

  analogWrite(6, 255);
  digitalWrite(4, HIGH);
  delay(3000);
  digitalWrite(4, LOW);
  delay(3000);
  digitalWrite(2, HIGH);
  delay(3000);
  digitalWrite(2, LOW);
  delay(3000);
}
