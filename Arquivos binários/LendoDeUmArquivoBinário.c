#include <stdio.h>
typedef struct{
	char nome[10];
	float nota1;
	float nota2;
	float nota3;
}estudante;
int main(){
	FILE *file = fopen("./alunosNotas.b", "rb");
	estudante e;
	while(fread(&e, sizeof(estudante), 1, file)){
		float media = (e.nota1 + e.nota2 + e.nota3)/3;
	    if(media >= 7.0){
			printf("%s: Aprovado com a nota %f\n", e.nome, media);
		}
		else if(media < 5.0){
			printf("%s: Reprovado com a nota %f\n", e.nome, media);
		}
		else{
			float recuperacao = 10.0 - media;
			printf("%s precisa de %f pra passar\n", e.nome, recuperacao);
		}
	}
	printf("Programa finalizado!\n");
	 fclose(file);
	return 0;
}