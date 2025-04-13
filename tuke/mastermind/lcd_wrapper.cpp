#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <Arduino.h>

#include "lcd_wrapper.h"
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
 
void lcd_init(){
  lcd.begin(16,2);
  
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);

   lcd.print("HADAJ PIN-KOD");
   lcd.setCursor(0,1);
   lcd.print("MAS 15 POKUSOV");
}

void lcd_clear(){
  lcd.clear();
}
void lcd_set_cursor(int y, int x){
  lcd.setCursor(y, x);
}
void lcd_print(char* text){
  lcd.print(text);
    Serial.println(text);
}
void lcd_print_at(int y, int x, char* text){
    lcd_set_cursor(y, x);
    lcd_print(text);
}
