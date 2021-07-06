#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "Talha"; //SSID
char pass[] = "ttfornow"; // Password
//-------------------------------------------//

WiFiClient  client;

unsigned long myChannelNumber = 931724; // Channel ID here
const int FieldNumber = 1;
const char * myWriteAPIKey = "RLE2V0FQE7QLCVXB"; // Your Write API Key here
void setup()
{
   Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);
}
void wificonnection()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
 }
void loop()
{
  int reading = 0;
  reading = digitalRead(D0);
  if(reading == LOW)
  {
    digitalWrite(D1, HIGH);
    ThingSpeak.writeField(myChannelNumber, FieldNumber, 1, myWriteAPIKey);
    delay(50);
  }
  else
  {
    digitalWrite(D1, LOW);
    ThingSpeak.writeField(myChannelNumber, FieldNumber, 0, myWriteAPIKey);
    delay(50);
}
}
