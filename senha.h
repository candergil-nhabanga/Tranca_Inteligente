#ifndef SENHA_H
#define SENHA_H
#include <string.h>

#define tamanhoMax 8 // numero maximo de caractres armazenaveis na senha
#define tamanhoMin 4 // numero minimo de caractres armazenaveis na senha

char * senha;

int setSenha(char * senhaArg){

  int tamanho = strlen(senhaArg);

  if(tamanho > 3 && tamanho < 9){
    
    senha = senhaArg;
    return 1;
  }

  return 0;  
}

int senhaAceite(const char * senhaArg, int tamanho){

  if(!strncmp(senha,senhaArg,tamanho) && tamanho > 0)return 1;

  return 0;
}

int tamanhoSenha(const char * senhaArg){

  return strlen(senhaArg);
}


#endif
