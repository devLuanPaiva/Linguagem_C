#include <stdio.h>
#include <stdlib.h>

int main(){
	//! showMemory(start=342)
	int *pdiatancia = (int *) malloc(sizeof(int));
	float *plitros = (float *) malloc(sizeof(float));
	float *pconsumo = (float *) malloc(sizeof(float));
	/* Enquanto a funcao malloc serve para reservar um espaço sugerido pelo usuário na memoria,
	a funçao sizeof serve para sugerir um espaço necessário para o usuario. */
	printf("Informe a distancia percorrida\n");
	scanf("%d", pdiatancia);
	printf("\n Informe o total de litros gastos\n");
	scanf("%f", plitros); 
	
	*pconsumo = *pdiatancia / *plitros;
	printf("\n Seu consumo foi de %.1f Km/L \n");
}