#include <LiquidCrystal.h>

LiquidCrystal lcd(D0, D1, D3, D4, D5, D8);

void setup() 
{
   lcd.begin(16, 2);
}

void lcd_display()
{
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Temperature: ");
   delay(1000);
   lcd.setCursor(1, 0);
   lcd.print("BPM: ");
   delay(1000);
}
void loop() 
{
  lcd_display();
}
