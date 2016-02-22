#ifndef GpsForPlane_h
#define GpsForPlane_h
#include <TinyGPS.h>
#include "Arduino.h"

/*
    GpsForPlane.h - Library for processing GPS
    Created by Joy Smith and Cole Tucker Feb. 2016
    Welcome to the Danger Zone, proceed with caution
 */



TinyGPS gps;

class GpsForPlane : public TinyGPS
{
  public:
     GpsForPlane(int pinTX, int pinRX);
     String getStatus();
     String initialize();
  private:
     int _pin;
     
};

#endif
