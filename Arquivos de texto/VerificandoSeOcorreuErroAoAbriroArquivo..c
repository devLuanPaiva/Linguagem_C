#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
} estudante;
int main(){
	FILE *file = fopen("./estudante.txt", "a");
	if (file == NULL){
		printf("Ocorreu erro ao abrir o arquivo \n");
	}
	estudante e;
	scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);

	fprintf(file, "%s %f %f %f", e.nome, e.nota1, e.nota2, e.nota3);
	
	if (e.nota1 >= e.nota2 && e.nota1 >= e.nota3){
		printf("%s: %f \n", e.nome, e.nota1);
	}
	else if (e.nota2 >= e.nota1 && e.nota2 >= e.nota3){
		printf("%s: %f \n", e.nome, e.nota2);
	}
	else
		printf("%s: %f \n", e.nome, e.nota3);

	fclose(file);
	return 0;
}