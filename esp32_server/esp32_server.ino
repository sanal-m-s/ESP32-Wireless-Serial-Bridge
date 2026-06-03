#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

WiFiServer server(5000);

WiFiClient client;

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
  }

  server.begin();
}

void loop()
{
  if(!client || !client.connected())
  {
    client = server.available();
  }

  if(client && client.connected())
  {
    while(Serial.available())
    {
      client.write(Serial.read());
    }

    while(client.available())
    {
      Serial.write(client.read());
    }
  }
}