#include "weather.h"

HTTPClient client;
WiFiClient wifiClient;

bool getWaether()
{
    if (httpRequest() and parseData())
        return true;
    else
        return false;
}

bool httpRequest()
{

    bool find = false;
    client.setTimeout(1000);
    Serial.print("Connecting to weather ");
    client.begin(wifiClient, url);
    int httpCode = client.GET();

    if (httpCode > 0)
    {
        Serial.print("successfully, code:");
        Serial.print(httpCode);

        delay(1000);
        if (httpCode == HTTP_CODE_OK)
        {
            httpData = client.getString();
            if (httpData.indexOf(F("\"main\":{\"temp\":")) > -1)
            {
                lastConnectionTime = millis();
                find = true;
            }
            else
            {
                Serial.println("Failed, json string is not found");
            }
        }
    }
    else
    {
        Serial.print("failed, error: ");
        Serial.println(httpCode);
    }

    postingInterval = find ? 600L * 1000L : 60L * 1000L;
    client.end();

    return find;
}

bool parseData()
{

    DynamicJsonDocument doc(1024);
    deserializeJson(doc, httpData);

    JsonObject main = doc["main"];
    JsonObject wind = doc["wind"];

    weather.main = doc["name"];
    weather.temp = main["temp"];
    weather.feel = main["feels_like"];
    weather.humidity = main["humidity"];
    weather.pressure = main["pressure"];
    weather.speed = wind["speed"];
    weather.time = doc["dt"];

    httpData = "";
    Serial.println(" parse data ok");

    return true;
}