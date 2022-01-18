#include <stdio.h>
struct funcionario{
	int matricula;
	float salario;
};
void aumento(struct funcionario *pf);
int main(){
	//showMemory(start=65520)
	struct funcionario f;
	struct funcionario *pf = &f;
	printf("Informe os dados do funcionario\n");
	scanf("%d %f", &(*pf).matricula, &(*pf).salario);
	aumento(pf);
	printf("Novo salario: %.2f\n", (*pf).salario);
}
void aumento(struct funcionario *pf) {
	(*pf).salario = (*pf).salario + (*pf).salario * (15/100.0);
}