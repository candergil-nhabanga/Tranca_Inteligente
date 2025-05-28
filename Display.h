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
  lcd.setCursor(0, 1);
  lcd.print("Senha: ");
}

void imprimirLCD(char digit) {
  if (size < 8) {
    pass[size++] = digit;

    int posicao = 7 + size - 1;

    lcd.setCursor(posicao, 1);
    lcd.print(digit);
    delay(300);

    lcd.setCursor(posicao, 1);
    lcd.print('*');
  }
}

void imprimirCorrecao() {
  if (size > 0) {
    size--;
    pass[size] = '\0';

    int posicao = 7 + size;

    lcd.setCursor(posicao, 1);
    lcd.print(' ');
  }
}

#endif
