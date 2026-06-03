#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

IPAddress serverIP(192,168,1,100);

WiFiClient client;

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
  }

  while(!client.connect(serverIP,5000))
  {
    delay(1000);
  }
}

void loop()
{
  if(!client.connected())
  {
    client.connect(serverIP,5000);
  }

  while(Serial.available())
  {
    client.write(Serial.read());
  }

  while(client.available())
  {
    Serial.write(client.read());
  }
}