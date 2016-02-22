#include "GpsForPlane.h";
GpsForPlane gpsForPlane(16,17);
void setup() {
  //error reporting from the computer.
   Serial.begin(9600);
   //Gps communication.
   Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
