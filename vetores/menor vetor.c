#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, x[10], valor, menoresValores;
	
	// Responsável por inicializar o vetor
	for(i = 0; i < 10; i++){
		scanf("%i", &x[i]);
	}
	
	printf("Digite um valor qualquer: ");
	scanf("%i", &valor);
	
	for(i = 0; i < 10; i++){
		printf("x[%i] = %i\n", i, x[i]);
	}
	menoresValores = 0;
	for(i = 0; i < 10; i++){
		if(x[i] < valor){
			printf(" %i e menor que %d \n", x[i], valor);
            menoresValores += 1;
		}
	}  printf("\nTotal de valores inferiores a %i: %d\n\n", valor, menoresValores);
	
	printf("\n\n");
	system("pause");
	return(0);
 }