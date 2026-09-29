#define trigPin 2
#define echoPin 3

#define ENA 9
#define ENB 10

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

bool turnLeftNext = true;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 15 || distance == 0 || distance > 100) {
    moveForwardDistance(1000); 
  } else {
    stopBot();
    delay(300);

    if (turnLeftNext) {
      turn90Left();
    } else {
      turn90Right();
    }

    moveForwardDistance(600);
    stopBot();
    delay(200);

    turnLeftNext = !turnLeftNext;
  }
}

void moveForwardDistance(int ms) {
  analogWrite(ENA, 200);
  analogWrite(ENB, 170);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(ms);
  stopBot();
}


void turn90Left() {
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(900);
  stopBot();
}


void turn90Right() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(900);
  stopBot();
}

void stopBot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int dist = duration * 0.0343 / 2;
  return dist;
}
