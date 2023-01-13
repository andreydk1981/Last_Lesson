
#include "dht.h"

void DHTinit()
{
    dht.setup(2, DHTesp::DHT11);
    Serial.println("DHT init OK");
}

void DHTprint(Adafruit_ST7735 _tft)
{
    _tft.setTextSize(3);
    if (dht.getStatusString() == "OK")
    {
        Serial.println("Sensor OK");
        _tft.setCursor(10, 75);
        _tft.setTextColor(ST77XX_MAGENTA, ST77XX_BLACK);
        _tft.print(dht.getTemperature(), 1);
        _tft.setTextSize(1);
        _tft.print(" o ");
        _tft.setTextSize(3);
        _tft.print("C");
        _tft.setCursor(40, 100);
        _tft.setTextColor(ST77XX_CYAN, ST77XX_BLACK);
        _tft.print((int)dht.getHumidity());
        _tft.print("%");
    }
    else if (dht.getStatusString() == "CHECKSUM")
    {
        Serial.println("Checksum error");
        _tft.setCursor(10, 40);
        _tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
        _tft.print("      ");
        _tft.setCursor(40, 100);
        _tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
        _tft.print("   ");
    }
    else if (dht.getStatusString() == "TIMEOUT")
    {
        Serial.println("Time out error");
        _tft.setCursor(10, 40);
        _tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
        _tft.print("      ");
        _tft.setCursor(40, 100);
        _tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
        _tft.print("   ");
    }
    else
    {
        Serial.println("Unknown DHT11 EROOR");
    }
}