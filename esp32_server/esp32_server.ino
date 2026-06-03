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





#include <WiFi.h>

const char* ssid = "SANAL";
const char* password = "1111111111";

IPAddress serverIP(192.168.137.179);

WiFiClient client;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("\nESP32 CLIENT STARTING");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");

  connectServer();
}

void connectServer()
{
  while (!client.connect(serverIP, 5000))
  {
    Serial.println("Connecting to server...");
    delay(1000);
  }

  Serial.println("Connected to server");
}

void loop()
{
  if (!client.connected())
  {
    Serial.println("Disconnected");
    connectServer();
  }

  while (Serial.available())
  {
    char c = Serial.read();
    client.write(c);
  }

  while (client.available())
  {
    char c = client.read();
    Serial.write(c);
  }
}
