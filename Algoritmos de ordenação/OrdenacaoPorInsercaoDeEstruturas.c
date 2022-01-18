#include <stdio.h>
#include <string.h>
typedef struct{
	char nome[10];
	int mat;
}estudante;
void ler(estudante *pe){
	scanf("%d %[^\n]s\n", &pe->mat, pe->nome);
}
int main(){
	int n;
	printf("Informe o valor de n\n");
	scanf("%d", &n);
	int i, j;
	estudante v[n];
	for(i=0; i<n; i++){
		ler(&v[i]);
	}
	for(i=1; i<n; i++){
        estudante x =	v[i];
	    for(j=i-1; j >= 0 && x.mat <v[j].mat; j--){
		    v[j + 1] = v[j];
	    }
 	    v[j + 1] = x;
	}
	printf("Imprimindo o vetor ordenado\n");
	for(i=0; i < n; i++){
		printf("%d %s\n", v[i].mat, v[i].nome);
	}
	printf("\n");
	return 0;
}