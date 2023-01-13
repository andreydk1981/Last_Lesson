#include "bitmap1.h"

void printLogo(Adafruit_ST7735 _tft)
{
    int index = 0;
    for (int y = 0; y < LOGO_HEIGHT; y++)
    {

        for (int x = 0; x < LOGO_WIDTH; x++)
        {
            _tft.drawPixel(x, y, logo[index++]);
        }
    }

    delay(1000);

    _tft.setTextSize(2);
    _tft.setCursor(30, 20);
    _tft.setTextColor(ST77XX_BLACK);
    _tft.print("METEO");
    delay(1000);

    _tft.setCursor(20, 40);
    _tft.print("STATION");
    delay(1000);

    _tft.setCursor(30, 60);
    _tft.print("V 1.0");
    delay(3000);
    for (int i = 0; i < 1000; i++)
    {
        _tft.fillCircle(random(0, 128), random(0, 128), 5, ST77XX_BLACK);
    }
    _tft.fillScreen(ST77XX_BLACK);
}
