int Led = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
}

void loop() {
  // put yourmain code here, to run repeatedly:
  for(int i=0; i<255; i++){
    analogWrite(Led, i);
    delay(15);
  }
  for(int i=255; i>0; i--){
    analogWrite(Led, i);
    delay(15);
  }
  delay(10);
}
