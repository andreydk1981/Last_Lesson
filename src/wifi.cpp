#include "wifi_conf.h"

void WIFIscan(Adafruit_ST7735 _tft)
{
    _tft.setCursor(0, 0);
    _tft.setTextColor(ST77XX_WHITE);
    _tft.setTextWrap(true);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    _tft.println("WIFI scan start");
    Serial.println("WIFI scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    _tft.println("WIFI scan done");
    Serial.println("WIFI scan done");
    if (n == 0)
    {
        _tft.println("no networks found");
    }
    else
    {
        _tft.print(n);
        _tft.println(" networks found");
        _tft.setTextColor(ST77XX_GREEN);
        for (int i = 0; i < n; ++i)
        {
            // Print SSID and RSSI for each network found
            _tft.print(i + 1);
            _tft.print(": ");
            _tft.print(WiFi.SSID(i));
            _tft.print(" (");
            _tft.print(WiFi.RSSI(i));
            _tft.print(")");
            _tft.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
            delay(10);
        }
    }
    _tft.setTextColor(ST77XX_WHITE);

    _tft.println("");
    delay(CONNECT_DELAY);
    _tft.fillScreen(ST77XX_BLACK);
}

void WIFIconnect(Adafruit_ST7735 _tft, int connect_attempts)
{
    clearHalfscreen(_tft);

    _tft.setCursor(0, 0);
    _tft.setTextColor(ST77XX_WHITE);
    _tft.setTextSize(1);
    WiFi.begin(ssid, password);
    _tft.println("Connecting to ");
    _tft.setTextColor(ST77XX_GREEN);
    _tft.println(ssid);
    _tft.setTextColor(ST77XX_WHITE);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED && connect_attempts > 0)
    {
        delay(1000);
        _tft.print(".");
        connect_attempts--;
    }

    if (connect_attempts > 0)
    {
        _tft.setCursor(0, 0);
        clearHalfscreen(_tft);
        _tft.setTextColor(ST7735_CYAN);
        _tft.println("WiFi connected");
        Serial.println("WiFi connected");
        _tft.println("IP address: ");
        _tft.println(WiFi.localIP());
        delay(2000);
    }
    else
    {
        _tft.setCursor(0, 0);
        clearHalfscreen(_tft);
        _tft.setTextColor(ST7735_RED);
        _tft.println("WiFi");
        _tft.println("NOT");
        _tft.println("connected!!!!");
        Serial.println("WiFi NOT connected!!!!");
        delay(2000);
    }
}

void testWifiConnection(Adafruit_ST7735 _tft, int connect_attempts)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        WIFIconnect(_tft, connect_attempts);
    }
    else
    {
        Serial.println("Wifi connection OK");
    }
}

void clearHalfscreen(Adafruit_ST7735 _tft)
{
    for (int i = 0; i < 70; i++)
    {
        _tft.drawFastHLine(0, i, 128, ST77XX_BLACK);
    }
}