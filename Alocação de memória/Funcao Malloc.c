#include <stdio.h>
#include <stdlib.h>

int main(){
	//! showMemory(start=342)
	int *phoras = (int *) malloc(4);
	double *pvhoras = (double *) malloc(8);
	double *psalario = (double *) malloc(8);
	// A funcao malloc serve para reservar um espaço sugerido pelo usuário na memoria
	printf("Informe quantas horas trabalhadas\n");
	scanf("%d", phoras);
	printf("\n Informe o valor por hora\n");
	scanf("%f", pvhoras);
	
	*psalario = *phoras * *pvhoras;
	printf("O seu salario vai ser %.1lf\n", *psalario);
}