#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char pass[8]; 
int size = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void inicializarLCD() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("    FECHADURA");
}


void imprimirLCD(char digit) {
 
  lcd.setCursor(0, 1);
  pass[size++] = digit;

  for(int i = 0; i<size; i++){
    lcd.print(pass[i]);
  }

  delay(500);
  pass[size-1] = "*";

  for(int i = 0; i<size; i++){
    lcd.print(pass[i]);
  }
}

#endif