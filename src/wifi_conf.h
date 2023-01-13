#pragma once

#include "WiFi.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

const char* ssid = "Arenahouse2";
const char* password =  "Lovearenahouse";
const int CONNECT_DELAY = 10000;

void WIFIconnect(Adafruit_ST7735, int);
void clearHalfscreen(Adafruit_ST7735);
