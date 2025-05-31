#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <stdbool.h>
#include "senha.h"
#include <LiquidCrystal_I2C.h>

char pass[9];
int size = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void limparSenha() {
  for (int i = 0; i < 9; i++) {
    pass[i] = '\0';
  }
  size = 0;
}

void resetarSenha() {
  limparSenha();
  lcd.setCursor(7, 1);
  lcd.print("                ");
  for (int i = 0; i < 8; i++) {
    lcd.print(' ');
  }
}

void inicializarLCD() {

  lcd.begin();
  lcd.backlight();
  resetarSenha();
  lcd.setCursor(3, 0);
  lcd.print("FECHADURA");
  lcd.setCursor(0, 1);
  lcd.print("Senha: ");
}

void imprimirLCD(char digit) {
  if (size < 8) {
    pass[size++] = digit;
    pass[size] = '\0';

    int posicao = 7 + size - 1;

    lcd.setCursor(posicao, 1);
    lcd.print(digit);
    delay(300);

    lcd.setCursor(posicao, 1);
    lcd.print('*');
  }
}

void apagar() {

  if (size > 0) {
    size--;
    pass[size] = '\0';

    int posicao = 7 + size;

    lcd.setCursor(posicao, 1);
    lcd.print(' ');
  }
}


bool validacao() {

  lcd.setCursor(0, 1);
  lcd.print("                ");

  if (!senhaAceite(pass, size)) {
    return false;
  }
  
  return true;
}

#endif
