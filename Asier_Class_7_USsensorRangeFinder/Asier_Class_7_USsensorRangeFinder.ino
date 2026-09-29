#define trigPin 4
#define echoPin 3
#define buzPin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration , distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm ");

   if(distance < 50){
    digitalWrite(buzPin, HIGH);
    delay(200);
    digitalWrite(buzPin, LOW);
   }
   else{
    digitalWrite(buzPin, LOW);
   }
   delay(200);
}
