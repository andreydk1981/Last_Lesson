#include "main_config.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void)
{
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
  tft.initR(INITR_GREENTAB);
  tft.setRotation(2);
  Serial.println(F("Initialized"));
  tft.fillScreen(ST77XX_BLACK);
  printLogo(tft);
  DHTinit();
  WIFIscan(tft);
  WIFIconnect(tft, CONNECTION_ATTEMPTS);
}

void loop()
{
  DHTprint(tft);
  testWifiConnection(tft, 20);
  if (getWaether())
    printWeather(tft);

  ///------------------------- реализация ухода в легкий сон -------------------------///
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
  Serial.println("Going to sleep now\n");
  Serial.flush();
  esp_light_sleep_start();
}
