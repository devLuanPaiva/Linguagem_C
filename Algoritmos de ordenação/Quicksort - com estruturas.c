#include <stdio.h>
typedef struct{
	int mat;
	char nome[10];
} estudante;

int particao(int e, int d, estudante v[]){
	
	int j = - 1;
	int i;
	estudante pivo = v[d];
	for(i = e; i<d; i++){
		if(v[i].mat <= pivo.mat){
			j++;
			estudante temp = v[j];
			v[j] = v[i];
			v[i] = temp;
		}
	}
	estudante temp = v[j + 1];
	v[j + 1] = v[d];
	v[d] = temp;
	return j + 1;
}
int quicksort(int i, int f, estudante v[]){
	if(i < f){
		int p = particao(i, f, v);
		quicksort(i, p -1, v);
		quicksort(p+1, f, v);
	}
}
void ler(estudante *pe){
	scanf("%[^\n]s %d", pe->nome, &pe->mat);
}
int main(){
	int n, i;
	printf("Informe o valor de alunos\n");
	scanf("%d", &n);
	estudante v[n];
	for(i=0; i<n; i++){
		ler(&v[i]);
	}
	quicksort(0, n-1, v);
	printf("Imprimindo o vetor\n");
	for(i=0; i<n; i++){
		printf("%s %d", v[i].nome, v[i].mat);
	}
	printf("\n");
	return 0;
}