#include <stdio.h>
#include <stdlib.h>
#include "estudante.h"

struct estudante {
	int mat;
	char nome[10];
	float n1;
	float n2;
	float n3;
};
Estudante* cria(int n){
	Estudante *v =(Estudante *) malloc(n * sizeof(Estudante));
	return v;
}
void ler(int n, Estudante *v){
	printf("informe o nome, matricula e as três notas\n");
	int i;
	for(i = 0; i < n; i++){
	    scanf("%s %d %f %f %f", v[i].nome, &v[i].mat, &v[i].n1, &v[i].n2, &v[i].n3);
	}
	
}
void media(int n, Estudante *v){
	printf("Inserindo as medias\n");
	int i;
	for(i = 0; i < n; i++){
	     float media; 
	     media = (v[i].n1 + v[i].n2 + v[i].n3)/3;
	     printf("A media do estudante %s e %.2f\n", v[i].nome, media);
	}
	
}