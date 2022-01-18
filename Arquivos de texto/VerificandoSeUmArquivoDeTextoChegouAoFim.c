#include <stdio.h>
typedef struct{
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
}estudante;
int main(){

	FILE *file = fopen("./estudante.txt", "r");
	estudante e;
	while(fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3) != EOF){
		float media = (e.nota1 + e.nota2 + e.nota3)/3;
		printf("%s: %f", e.nome, media); 
	}
	fclose(file);
	return 0;
}