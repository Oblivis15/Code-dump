int snsrpin = 2;
#define LEDpin  3

void setup() {
  // put your setup code here, to run once:
  pinMode(snsrpin, INPU?
  //?
  
  T);
  pinMode(LEDpin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int soundVal = digitalRead(snsrpin);

  if(soundVal == HIGH){
    digitalWrite(LEDpin, HIGH);
    delay(200);
    digitalWrite(LEDpin, LOW);
  }
  else{
    digitalWrite(LEDpin, LOW);
  }

  Serial.println(soundVal);
}
