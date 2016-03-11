#include <GpsForbot.h>;
GpsForbot gpsForbot(16,17);
#include <Servo.h>

//motors - handle with servo.write(speed)
Servo Servo1;
Servo Servo2;
//Servo Servo3;

//electronic speed controller (throttle)
//handle with servo.writeMicroSec(speed) -(time high time low) (700 - 2000)
Servo ESC1;

const int servo1pin = 1;
const int servo2pin = 2;
//const int servo3pin = 3;
const int escpin = 4;

//stores the last value passed to each servo
int servo1value = 90;
int servo2value = 90;
//int servo3value = 0;
int escValue = 700;
//inputs 
char* inputcoords;
long gpsx;
long gpsy;
long imurotx;
long bankleftval = 0.0; //set this before flight 
long bankrightval = 0.0; //set this before flight
long bankcenter = 0.0; //set this before flight
long degtarget; // degrees til heading hits target value 
long currentdeg;


void readESP(){
  Serial2.read(inputcoords);
}

void bankLeft(){
Servo1.write(180);
if(imurotx <= bankleftval){
  Servo1.write(90); 
  Servo2.write(180);
  if(currentdeg >= degtarget){
  Servo2.write(90);
  Servo1.write(0)
    if(imurotx = bankcenter){
    Servo1.write(90); 
   }
  }
}
}
void bankRight(){
Servo1.write(180);
if(imurotx >= bankrightval){
  Servo1.write(90); 
  Servo2.write(180);
  if(currentdeg >= degtarget)
  Servo2.write(90);
    Servo1.write(180)
    if(imurotx = bankcenter){
    Servo1.write(90);
    }
  }
}
}

void setup() {
  //error reporting to the computer.
   Serial.begin(9600);
   //Gps communication.
   Serial1.begin(9600);
   //ESP communication
   Serial2.begin(115200);
  Servo1.attach(servo1pin); 
  Servo2.attach(servo2pin);
 // Servo3.attach(servo3pin);
  ESC1.attach(escpin);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read ESP
  //if botGone, fly.
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


