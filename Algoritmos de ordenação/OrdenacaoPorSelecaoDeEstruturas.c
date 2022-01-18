#include <stdio.h>
typedef struct{
	int mat;
	char nome[10];
}estudante;
void ler(estudante *pe){
	scanf("%d %s", &pe->mat, pe->nome);
}
int main(){
	int n;
	printf("Informe a quantidade de estudantes\n");
	scanf("%d", &n);
	estudante v[n];
	int i, j;
	for(i = 0; i < n; i++){
		ler(&v[i]);
	}
	
	for(i = 0; i < n; i++){
		int imenor = i;
		for(j = i + 1; j < n; j++){
			if(v[j].mat < v[imenor].mat){
				imenor = j;
			}
		}
		estudante temp = v[i];
		v[i] =v[imenor];
		v[imenor] = temp;
	}
	printf("Lista ordenada:\n");
	for(i = 0; i < n; i++){
		printf("%d: %s\n", v[i].mat, v[i].nome);
	}
	printf("\n");
	return 0;	
}