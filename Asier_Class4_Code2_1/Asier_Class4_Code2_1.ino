int red = 9;
int blue = 10;
int green = 11;


void setup()
{
  Serial.begin(9600);
  
  	pinMode(red, OUTPUT);
	pinMode(blue, OUTPUT);
	pinMode(green, OUTPUT);
  Serial.println("Write the RBG values like 255, 0, 0");
}

void loop()
{
  if (Serial.available()>0)
  {
    int r = Serial.parseInt();
int b = Serial.parseInt();
int g = Serial.parseInt();
    
    analogWrite(red, r);
    analogWrite(blue, b);
	analogWrite(green, g);
    
    Serial.print("Red = ");
    Serial.print(r);
Serial.print("Blue = ");
    Serial.print(b);
Serial.print("Green = ");
    Serial.println(g);
  }
}