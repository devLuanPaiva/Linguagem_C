#include <stdio.h>
struct cliente{
	int codigo;
	char nome[50]
};
struct comanda{
	float total;
	struct cliente cli;
	
};
int main(){
	//! showMemory(start=65520)
	struct comanda c;
	printf("Indforme os dados da comanda\n");
	scanf("%f %d %s", &c.total, &c.cli.codigo, c.cli.nome);
	float total = c.total - c.total *(5/100.0);
	printf("Total: R$ %2.f\n", total);
	return 0;
}