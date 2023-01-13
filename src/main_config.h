#pragma once

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>


#define uS_TO_S_FACTOR 1000000 /* коэффициент пересчета микросекунд в секунды */
#define TIME_TO_SLEEP 30       /* время, в течение которого будет спать ESP32 (в секундах) */

int CONNECTION_ATTEMPTS  = 50;

//TFT pins
#define TFT_CS 5
#define TFT_RST 13
#define TFT_DC 12

// WEATHER
struct weather_structure
{
  const char *main;
  float temp;
  float feel;
  int pressure;
  byte humidity;
  float speed;
  int time;
};
weather_structure weather;

// FOO INIT
void WIFIscan(Adafruit_ST7735);
void WIFIconnect(Adafruit_ST7735, int);
void testWifiConnection(Adafruit_ST7735, int);
void DHTprint(Adafruit_ST7735);
void DHTinit();
bool getWaether();
void printWeather(Adafruit_ST7735);
void printLogo(Adafruit_ST7735);






