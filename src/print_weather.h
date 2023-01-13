#pragma once
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

#include <UnixTime.h>
UnixTime stamp(8);  // указать GMT (3 для Москвы)


struct weather_structure {
  const char* main;
  float temp;
  float feel;
  int pressure;
  byte  humidity;
  float speed;
  int time;
};
extern weather_structure weather;

void clearHalfScreen(Adafruit_ST7735);
