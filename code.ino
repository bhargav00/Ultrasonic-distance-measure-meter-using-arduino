#include <NewPing.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define trigPin 10 
#define echoPin 9 
#define MAX_DISTANCE 200 

NewPing sonar(trigPin,echoPin, MAX_DISTANCE);

void setup() {
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(echoPin, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Target Distance:");
}

void loop() {
  long distance;
  digitalWrite(echoPin, LOW);
  unsigned int duration = sonar.ping();
  distance = (duration/2) / 29.1;
  
  lcd.setCursor(0,1);   
  lcd.print(distance); 
  lcd.print(" cm");  
  delay(100); 
}

