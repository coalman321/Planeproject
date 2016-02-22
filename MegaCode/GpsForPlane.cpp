#include <TinyGPS.h>


/*
   GpsForPlane.cpp - handles GPS functions
   By Joy Smith and Cole Tucker
   All rights reserved, but none enforced.
 */
#include "Arduino.h"
#include "GpsForPlane.h"

GpsForPlane::GpsForPlane(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  start();
}
  String GpsForPlane::initialize(){
   return ("GPS is initialized.");
}
String GpsForPlane::getStatus(){
  float flat, flon;
  unsigned long age;
  String s;
  f_get_position(&flat, &flon, &age);
  s += "LAT=";
  s += (flat == TinyGPS::GPS_INVALID_F_ANGLE) ? 0.0 : flat, 6;
  s += "\nLON=";
  s += (flon == TinyGPS::GPS_INVALID_SATELLITES) ? 0 : satellites();
  s += "\nPREC=";
  s += (gps.hdop() == TinyGPS::GPS_INVALID_HDOP) ? 0 : hdop();
}
