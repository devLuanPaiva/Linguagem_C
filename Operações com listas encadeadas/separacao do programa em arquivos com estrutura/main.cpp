#include <stdio.h>
#include "estudante.h"

int main(){
	int n;
	printf("Digite o valor de n\n");
	scanf("%d", &n);
	Estudante * v = cria(n);
	ler(n, v);
	imprimir(n, v);
	return 0;
}