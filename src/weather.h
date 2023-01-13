#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>

const String server = "api.openweathermap.org";
const String lat = "-8.65";
const String lon = "115.2167";
const String appid = "8dacc73cbc2db7d4ccdb4c4c82826bcc";
const String url = "http://" + server + "/data/2.5/weather?lat=" + lat + "&lon=" + lon + "&units=metric&appid=" + appid;// + "&lang=ru";
unsigned long lastConnectionTime = 0;
unsigned long postingInterval = 0;

String httpData;
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

bool httpRequest();
bool parseData();
