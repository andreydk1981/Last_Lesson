#include "print_weather.h"

void printWeather(Adafruit_ST7735 _tft)
{
    clearHalfScreen(_tft);
    _tft.setTextSize(2);
    _tft.setCursor(20, 0);
    _tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    _tft.print("OUTSIDE:");
    _tft.setTextSize(1);
    _tft.setCursor(1, 20);
    _tft.print("CITY: ");
    _tft.print(weather.main);
    _tft.setCursor(1, 30);
    _tft.print("TEMP: ");
    _tft.printf("%.1f (%.1f)", weather.temp, weather.feel);
    _tft.setCursor(1, 40);
    _tft.print("HUM.: ");
    _tft.print(weather.humidity);
    _tft.print("%");

    _tft.setTextColor(ST77XX_MADCTL, ST77XX_BLACK);
    _tft.setCursor(25, 50);
    _tft.print("updated ");
    stamp.getDateTime(weather.time);
    _tft.printf("%02d:%02d", stamp.hour, stamp.minute);
}

void clearHalfScreen(Adafruit_ST7735 _tft)
{
    for (int i = 0; i < 70; i++)
    {
        _tft.drawFastHLine(0, i, 128, ST77XX_BLACK);
    }
}