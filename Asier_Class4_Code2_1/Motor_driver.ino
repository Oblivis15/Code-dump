void setup()
{
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  analogWrite(6, 127);
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