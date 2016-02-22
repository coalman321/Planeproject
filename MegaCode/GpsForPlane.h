#include <TinyGPS.h>

/*
    GpsForPlane.h - Library for processing GPS
    Created by Joy Smith and Cole Tucker Feb. 2016
    Welcome to the Danger Zone, proceed with caution
 */
#ifndef GpsForPlane_h
#define GpsForPlane_h

#include "Arduino.h"
#include <SoftwareSerial.h>
TinyGPS gps;

class GpsForPlane : public TinyGPS
{
  public:
     GpsForPlane(int pin);
     String start();
     String getStatus();
     String initialize();
  private:
     int _pin;
     
};

#endif
