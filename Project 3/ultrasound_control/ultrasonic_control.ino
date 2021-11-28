#define trigPin 12
#define echoPin 13
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  bluetooth.begin(9600);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;

  /*if(bluetooth.available() >= 2){
    //bluetooth.write(distance);
    Serial.print("Distance Sent : ");
    Serial.println(distance);
    delay(100);
  }*/

  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(50);
  }
  delay(200);

}
