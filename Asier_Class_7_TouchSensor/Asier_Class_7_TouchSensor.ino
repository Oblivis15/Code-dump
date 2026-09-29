const int sensorPin = 2;
int LED = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(sensorPin);
  digitalWrite(LED, state);
}
