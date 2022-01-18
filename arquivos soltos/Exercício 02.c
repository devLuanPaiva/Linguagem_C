#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, x[10], valor;
	
	// Responsável por inicializar o vetor
	for(i = 0; i < 10; i++){
		scanf("%i", &x[i]);
	}
	
	printf("Digite um valor qualquer: ");
	scanf("%i", &valor);
	
	for(i = 0; i < 10; i++){
		printf("x[%i] = %i\n", i, x[i]);
	}
	
	for(i = 0; i < 10; i++){
		if(x[i] == valor){
			printf("Valor presente em x[%i]!\n", i);
		}
	}
	
	printf("\n\n");
	system("pause");
	return(0);
}