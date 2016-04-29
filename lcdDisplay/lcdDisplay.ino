#include <LiquidCrystal.h>
//#include <LCD4Bit_mod.h>

//#include <LiquidCrystal.h>
// dig pin 11 - adv
// dig pin 12 - connected
// dig pin 13 - disconnected
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  lcd.print("initializing...");
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.print("printing text");

  delay(250);
  lcd.clear();
  delay(250);
  if(digitalRead(11) == HIGH)
  {
    lcd.print("Advertising...");
  }
  else
  {
    if(digitalRead(12) == HIGH)
    {
      lcd.print("Connected :)");
    }
    else
    {
      if(digitalRead(13) == HIGH)
      {
        lcd.print("Disconnected :(");
      }
    }
  }
}
