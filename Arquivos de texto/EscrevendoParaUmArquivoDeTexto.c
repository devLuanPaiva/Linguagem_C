#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char nome[50];
	int cont;
}estudante;

int main(){
	int n;
	printf("Informe a quantidade de estudantes\n");
	scanf("%d", &n);
	estudante e[n];
	int i;
	FILE *file = fopen("./alunos.txt", "w");
	for(i = 0; i<n; i++){
		scanf("%s %d", e[i].nome, &e[i].cont);
	}
	estudante maior = e[0];
	for(i = 1; i<n; i++){
		if(e[i].cont > maior.cont){
			maior = e[i];
		}
	}
	fprintf(file, "\n%s com %d atividades feitas\n", maior.nome, maior.cont);
	fclose(file);
	return 0;

}