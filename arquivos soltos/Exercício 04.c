#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	float x[5];
	
	// Responsável por inicializar o vetor
	for(i = 0; i < 5; i++){
		scanf("%f", &x[i]);
	}
	
	// Percorrer o vetor e imprimir seus elementos
	printf("\n\tVetor antes da verificacao\n");
	for(i = 0; i < 5; i++){
		printf("x[%i] = %.2f\n", i, x[i]);
		
		// Se o valor for negativo, substitui-lo por zero
		if(x[i] < 0){
			x[i] = 0.00;
		}
	}
	
	// Imprimir o vetor resultante
	printf("\n\tVetor depois da verificacao\n");
	for(i = 0; i < 5; i++){
		printf("x[%i] = %.2f\n", i, x[i]);
	}
	
	system("pause");
	return(0);
}