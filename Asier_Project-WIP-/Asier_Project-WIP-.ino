#define echo 2
#define trig 3
#define led 4

void setup() {
  // put your setup code here, to run once:
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinmode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long distance, duration;

  digitalWrite(trig, LOW);
  delay(20);
  digitalWrite(trig, HIGH);
  delay(20);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034/2;

  Serial.println(distance);
  delay(10)

  if(distance < 10) {
    digitalWrite(led, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led, LOW);
  }
}
