#include <stdio.h>
#include <string.h>
typedef struct{
	char nome[10];
	int mat;
}estudante;
void ler(estudante *pe){
	scanf("%d %[^\n]s\n", &pe->mat, pe->nome);
}
void bolha(int n, estudante v[]){
	int i, j;
	for(i=0; i<n-1 ;i++){
		int trocou = 0;
	    for(j=0; j<n -i -1; j++){
		    if(v[j.mat > v[j+1].mat){
				estudante temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
				trocou = 1;
			}
	    }
		if(trocou == 0){
			return;
		}
	}
}
int main(){
	int n;
	printf("Informe o valor de n\n");
	scanf("%d", &n);
	int i;
	estudante v[n];
	for(i=0; i<n; i++){
		ler(&v[i]);
	}
	bolha(n, v);
	printf("Imprimindo o vetor ordenado\n");
	for(i=0; i < n; i++){
		printf("%d %s\n", v[i].mat, v[i].nome);
	}
	printf("\n");
	return 0;
}