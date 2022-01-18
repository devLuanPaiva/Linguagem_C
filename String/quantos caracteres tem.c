#include <stdio.h>
#include <string.h>
int main(void) {
    int tamanhoString(char string[]);
    char stringUsuario[20];
        printf("Digite uma palavra(string) : \n");
        scanf("%s", stringUsuario );
        
	int num = tamanhoString(stringUsuario);
		printf("A string %s possui %i caracteres!\n", stringUsuario, num);
		
    system("pause");
	return 0;
  
}  
int tamanhoString(char string[]){
	int numCaractere = 0;
	    while(string[numCaractere] != '\0'){
			numCaractere++;
		}
		numCaractere++;
	return numCaractere;	
}