#include <stdio.h>
typedef struct{
	char nome[10];
	float nota1;
	float nota2;
	float nota3;
}estudante;

void menu(){
	printf("|========== Escolha uma opcao ==========|\n");
	printf("|1 - Cadastrar novo estudante           |\n");
	printf("|2 - Sair                               |\n");
	printf("|=======================================|\n");
}
int main(){
	FILE *file = fopen("./alunosNotas.b", "wb");
	menu();
	int op;
	scanf("%d", &op);
	while(op != 2){
		if(op == 1){
			printf("Informe os dados do estudante\n");
			estudante e;
			scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
			fwrite(&e, sizeof(estudante), 1, file);
		}
		menu();
		scanf("%d", &op);
	}
	printf("Programa finalizado!\n");
	 fclose(file);
	return 0;
}