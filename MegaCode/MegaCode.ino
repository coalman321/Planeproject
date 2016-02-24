#include <GpsForPlane.h>;
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
const int escpin = 4;

//stores the last value passed to each servo
double servo1value = 0.0;
double servo2value = 0.0;
double servo3value = 0.0;
double escValue = 0.0;

void readESP(){
  
}

void bankLeft(){
   digitalWrite(servo1pin, servo1value-20);
   servo1value -= 20;
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
  pinMode(escpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read ESP
  //if planeGone, fly.
}

void fly() {
   if(getTargetDifference() < -20){
    
      digitalWrite(servo1pin, servo1value-20);
      servo1value -= 20;
   }
      
    
}

double getTarget(){
   return 0.0;
}

double getTargetDifference(){
   return 0.0 - getTarget();
}


