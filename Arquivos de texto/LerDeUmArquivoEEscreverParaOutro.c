#include <stdio.h>
#include <ctype.h> /* toupper */

/**
Implemente um código para ler um arquivo e escrever outro com todas letras em maiusculo.
*/

int main(){

  FILE *arq_in, *arq_out;

  arq_in = fopen("./texto.txt", "r");

  arq_out = fopen("./texto_maiusc.txt", "w");
  
  int c;

  if(arq_in==NULL || arq_out==NULL){
    printf("Não foi possivel abrir os arquivos!");
    return 1;
  }

  while((c = fgetc(arq_in)) != EOF){
    fputc(toupper(c), arq_out );
  }

  fclose(arq_in);
  fclose(arq_out);

  return 0;
}