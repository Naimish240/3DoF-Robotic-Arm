#include <SoftwareSerial.h>
#include <Servo.h>

#define trigPin 12
#define echoPin 13

Servo motor1, motor2, motor3;

SoftwareSerial bluetooth(0, 1);

void setup()
{
  motor1.attach(3);
  motor2.attach(4);
  motor3.attach(5);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  bluetooth.begin(9600);
}

void servoControl()
{
  if(bluetooth.available() >= 2) 
  {
    unsigned int bit0 = bluetooth.read();
    unsigned int bit1 = bluetooth.read();
    unsigned int value = (bit1 * 256) + bit0;
    //Serial.println(value);

    if(value>=10 && value<190) {
      int foo = value;
      foo -= 10;
      motor1.write(foo);
      delay(10);
    }

    if(value>=200 && value<380) {
      int foo = value;
      foo -= 200;
      motor2.write(foo);
      delay(10);
    }

    if(value>=400 && value<580) {
      int foo = value;
      foo -= 400;
      motor3.write(foo);
      delay(10);
    }
  }
}

void distanceCalc()
{
  float duration;
  int distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;

  if (distance >= 400 || distance <= 2){
    //Serial.print("Distance = ");
    Serial.println("NaN");
  }
  else {
    //Serial.print("Distance = ");
    Serial.println(distance);
    //Serial.println(" cm");
    delay(50);
  }
}

void loop()
{
  long int t0;
  t0 = millis();

  // Check Servo Stuff
  servoControl();

  // Check Ultrasound Stuff
  if (millis() - t0 > 3000){
    distanceCalc();
    t0 = millis();
  }
}
