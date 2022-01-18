#include <stdio.h>
typedef struct {
	float nota1;
	float nota2;
	float nota3;
}estudantes;

int main(){
	estudantes e;
	printf("Informe as notas do estudante\n");
	scanf("%f %f %f", &e.nota1, &e.nota2, &e.nota3);
	float media = (e.nota1 + e.nota2 + e.nota3)/3;
	printf("%.2f\n", media);
}