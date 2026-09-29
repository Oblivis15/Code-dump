const int sensorPin = 2;
int LED = 3;
int lastState = LOW;
int LEDstate = LOW;
int currentState;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentState = digitalRead(sensorPin);
  if(lastState == LOW && currentState == HIGH){
    if(LEDstate == LOW)
    LEDstate = HIGH;
    else if (LEDstate == HIGH)
    LEDstate = LOW;
    digitalWrite(LED, LEDstate);
  }
  lastState = currentState;
}
