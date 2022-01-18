#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#include <time.h>


int tamanhoString(char string[]){
	int numCaractere = 0;
	    while(string[numCaractere] != '\0'){
			numCaractere++;
		}
		
		numCaractere++;
		
	return numCaractere;	
}
void transferir_para_arquivo(char string[]){
	while((c = fgetc(arq_in)) != EOF){
		    srand (time(NULL)); 
            int r = rand() % 10;
            printf("Numero aleatorio entre 0 e 10 : %d\n", r);
            fputc(toupper(c), arq_out );
        }
}
int main(void) {
	FILE *arq_in, *arq_out;
	arq_in = fopen("./Q3_entrada.txt", "r");
	arq_out = fopen("./Q3_saida.txt", "w");
  
    int tamanhoString(char string[]);
    char stringUsuario[20];
        printf("Digite uma palavra(string) : \n");
        scanf("%s", stringUsuario );
        
	int num = tamanhoString(stringUsuario);
		printf("A string %s possui %i caracteres!\n", stringUsuario, num);
		
    system("pause");
	

    fclose(arq_in);
    fclose(arq_out);
	return 0;
  
}  
