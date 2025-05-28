#ifndef TECLADO_H
#define TECLADO_H
#include <Keypad.h>

const byte LINHAS = 4; //quatro linhas
const byte COLUNAS = 4; //tres colunas

//mapa para chaves
char chaves[LINHAS][COLUNAS] = {
  
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  
};

// connect the pins from right to left to pin 2, 3, 4, 5,6,7,8,9
byte pinosDeLinha[LINHAS] = {5,4,3,2};// pinos para conexao das linhas
byte pinosDeColunas[COLUNAS] = {9,8,7,6}; // pinos para conexao das colunas

// teclado
Keypad keypad = Keypad( makeKeymap(chaves), pinosDeLinha, pinosDeColunas, LINHAS, COLUNAS);


#endif
