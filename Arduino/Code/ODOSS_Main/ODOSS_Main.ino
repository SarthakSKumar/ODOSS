/*
  # By: Sarthak.S.Kumar, Obstacle Distance and Obstacle Sensing System.
*/
#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(11, 10, 9, 2, 3, 4, 5); //Create Liquid Crystal Object called LCD

int trigPin =3;
int echoPin =4;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  LCD.begin(16, 2);
  LCD.setCursor(0, 0);
  LCD.print("Target Distance:");
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  LCD.setCursor(0, 1);
  LCD.print("                ");
  LCD.setCursor(0, 1);
  LCD.print(distance);
  Serial.println(distance);
  LCD.print(" cm");
  delay(250);
}
