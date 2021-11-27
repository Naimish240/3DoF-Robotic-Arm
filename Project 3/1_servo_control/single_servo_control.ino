#include <SoftwareSerial.h>
#include <Servo.h>

Servo motor;

int bluetoothTx = 10;
int bluetoothRx = 11;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  motor.attach(9);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  if(bluetooth.available()> 0 ) 
  {
    int servopos = bluetooth.read();
    Serial.println(servopos);
    motor.write(servopos);
  }
}
