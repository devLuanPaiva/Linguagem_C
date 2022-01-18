#include <stdio.h>
#include <stdlib.h>
#include "universitario.h"

struct estudante{
	int mat;
	char nome[10];
};
Estudante* cria(int n){
	Estudante* v =(Estudante *) malloc(n * sizeof(Estudante));
	return v;
}	
void ler(int n, Estudante *v){
	printf("Informe os dados dos estudantes\n");
	int i;
	for(i=0; i<n; i++){
		scanf("%s %d", v[i].nome, &v[i].mat);
	}	
}

void imprimir(int n, Estudante *v){
	printf("Imprimindo os estudantes\n");
	int i;
	for(i=0; i<n; i++){
		printf("%s %d\n", v[i].nome, v[i].mat);
	}
}