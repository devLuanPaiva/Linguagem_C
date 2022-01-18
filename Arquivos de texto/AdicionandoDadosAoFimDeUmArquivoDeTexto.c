#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
}estudante;
void menu(estudante e){
	printf("|========== Digite a opcao ==========|\n");
	printf("| 1 - Cadastrar novo aluno           |\n");
	printf("| 2 - Sair                           |\n");
	printf("|====================================|\n");
}
int main(){
	FILE *file = fopen("./notas.txt", "a");
	printf("Informe os dados dos estudantes\n");
	estudante e;
	int op;
	menu(e);
	scanf("%d", &op);
	while(op != 2){
		if(op == 1){
			
			scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
			fprintf(file, "%s %f %f %f\n", e.nome, e.nota1, e.nota2, e.nota3);
			fflush(file);
		}
		menu(e);
		scanf("%d", &op);
	}
	printf("Programa finalizado \n");
	fclose(file);
	return 0;
}