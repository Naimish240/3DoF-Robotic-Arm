#include <SoftwareSerial.h>
#include <Servo.h>

Servo motor1, motor2, motor3;

int bluetoothTx = 10;
int bluetoothRx = 11;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  motor1.attach(3);
  motor2.attach(4);
  motor3.attach(5);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  if(bluetooth.available() >= 2) 
  {
    unsigned int bit0 = bluetooth.read();
    unsigned int bit1 = bluetooth.read();
    unsigned int value = (bit1 * 256) + bit0;
    Serial.println(value);

    if(value>=10 && value<190) {
      int foo = value;
      //foo = map(foo, 1000, 1180, 0, 180);
      foo -= 10;
      motor1.write(foo);
      Serial.println("SERVO 1 ROTATED");
      delay(10);
    }

    if(value>=200 && value<380) {
      int foo = value;
      //foo = map(foo, 2000, 2180, 0, 180);
      foo -= 200;
      motor2.write(foo);
      Serial.println("SERVO 2 ROTATED");
      delay(10);
    }

    if(value>=400 && value<580) {
      int foo = value;
      //foo = map(foo, 3000, 3180, 0, 180);
      foo -= 400;
      motor3.write(foo);
      Serial.println("SERVO 3 ROTATED");
      delay(10);
    }
  }
}
