#include "teclado.h"
#include "senha.h"
#include "Display.h"

char cadeia[tamanhoMax];
int index = 0;

void setup(){
  inicializarLCD();
  char senha1[4]={'0','0','0','0'};
  setSenha(senha1);
  Serial.begin(9600);
}

void loop(){

 char key = keypad.getKey();
 
 receberCaracteres(key);
 imprimir(key);
 indexVef();
 
 switch(key){

  case '*':
    apagar();
    break;
  
  case '#':
    validar();
    break;

 }
 
}

void receberCaracteres(char key){

  if(caracterValido((int)key)){

    cadeia[index] = key;
    index ++;
    Serial.print("Key ");

    Serial.print(key);

    Serial.println(" is pressed");
  }
}


int caracterValido(int caracter){

  if(caracter > 47 && caracter < 58)return 1;
  
  return 0;
}  


void apagar(){
   imprimirCorrecao();
}

void validar(){
  
    Serial.println("validar");
  
    if(senhaAceite(cadeia, index)){
  
      //abrir fechadura
      Serial.println("Fechadura aberta");
    }
  
    index = 0;
}


void indexVef(){

    if(index > 7 || index < 0){
      
      index = 0;
    }
}

void imprimir(char key){

  if(caracterValido(key)){

    imprimirLCD(key);
  }

}



    
