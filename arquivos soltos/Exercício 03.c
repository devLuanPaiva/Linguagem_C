#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, x[10], valor, menoresValores = 0;
	
	// Responsável por inicializar o vetor
	for(i = 0; i < 10; i++){
		scanf("%i", &x[i]);
	}
	
	printf("Digite um valor qualquer: ");
	scanf("%i", &valor);
	
	// Imprime o vetor e contabiliza quantos valores são
	// inferiores ao valor digitado pelo usuário
	for(i = 0; i < 10; i++){
		printf("x[%i] = %i\n", i, x[i]);
		
		if(x[i] < valor){
			menoresValores += 1;
		}
	}
	
	printf("\nTotal de valores inferiores a %i: %i\n\n", valor, menoresValores);
	
	system("pause");
	return(0);
}