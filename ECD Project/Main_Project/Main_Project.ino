#include "ThingSpeak.h"
#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
const int LM35 = A0;
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "Talha"; //SSID
char pass[] = "ttfornow"; // Password
//-------------------------------------------//

WiFiClient  client;

unsigned long myChannelNumber = 931815; // Channel ID here
const char * myWriteAPIKey = "BJ9TMH5C9V5U8KUO"; // Your Write API Key here
LiquidCrystal lcd(D2, D3, D4, D5, D6, D7);

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);
  lcd.begin(16, 2);
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

void temperature()
{
  int ADC;
  float temp;
  ADC = analogRead(LM35);  /* Read Temperature */
  temp = (ADC*3); /* Convert adc value to equivalent voltage */
  temp = (temp / 10); /* LM35 gives output of 10mv/°C */
  delay(1000);
  delay(1000);
  lcd.clear();
  lcd.print("Temp: ");
  delay(200);
  lcd.setCursor(7, 0);
  lcd.print(temp);
  delay(200);

}

void panic_ind()
{
  int reading = 0;
  
  reading = digitalRead(D0); /*Read Panic*/
  if(reading == LOW)
  {
    digitalWrite(D1, HIGH);
    delay(1000);
    ThingSpeak.writeField(myChannelNumber, 2, 1, myWriteAPIKey);
    delay(1000);
  }
  else
  {
    digitalWrite(D1, LOW);
    delay(1000);
    ThingSpeak.writeField(myChannelNumber, 2, 0, myWriteAPIKey);
    delay(1000);
}
}

void loop()
{
  panic_ind();
  temperature();
}
