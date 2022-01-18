#include <stdio.h>
int main(void){
	int x = 10;
	double y = 20.12;
	char z = 'a';
	
	//Acessar o endereço do ponteiro
	//int *pX;
	//pX = &x;
	
	// Acessar o valor endereço de memoria
	int *pX = &x;
	double *pY = &y;
	char *pZ = &z;
	
	printf("Endereco X = %i - Valor X = %i\n", pX, *pX);
	printf("Endereco Y = %i - Valor Y = %f\n", pY, *pY);
	printf("Endereco Z = %i - Valor Z = %c\n", pZ, *pZ);
	
	getchar ();
	return 0;
	
}