#include "GpsForPlane.h";
GpsForPlane gpsForPlane(16,17);
#include <Servo.h>

//motors - handle with servo.write(speed)
Servo servo1;
Servo servo2;
Servo servo3;

//electronic speed controller (throttle)
//handle with servo.writeMicroSec(speed) -(time high time low) (700 - 2000)
Servo esc1;

const int servo1pin = 1;
const int servo2pin = 2;
const int servo3pin = 3;
const int esc1pin = 4;

void readESP(){
  
}

void updateServos(){
   
}

void setup() {
  //error reporting from the computer.
   Serial.begin(9600);
   //Gps communication.
   Serial1.begin(9600);
   //ESP communication
   Serial2.begin(115200);
  pinMode(servo1pin, OUTPUT);
  pinMode(servo2pin, OUTPUT);
  pinMode(servo3pin, OUTPUT);
  pinMode(esc1pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateservos();
}

