#include <stdio.h>
#include <string.h>

struct funcionario{
	int matricula, horas;
	char nome[50];
	float valorHora;
};
int main(){
	struct funcionario f;
	char nome[50];
	printf("Informe os dados dos funcionario\n");
	printf("Matricula; Nome; Horas Trabalhadas; Valor por Hora\n");
	scanf("%d %s %d %f", &f. matricula, nome, &f.horas, &f.valorHora);
	stpcpy(f.nome, nome);
	float salario = f.horas * f.valorHora;
	printf("Seu salario vai ser: R$ %2.f", salario);
	
	return 0;
}
