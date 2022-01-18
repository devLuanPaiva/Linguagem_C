#include <stdio.h>

struct produto{
	int codigo;
	float preco;	
};
int main(){
	//! showMemory(start=65520)
	struct produto p1 = {1, 2.50};
	struct produto p2 = {2, 4.00};
	struct produto p3 = {3, 5.00};
	int quantidade;
	int codigo;
	printf("Informe a quantidade e o codigo do produto\n");
	scanf("%d %d", &quantidade, &codigo);
	if(codigo == p1.codigo){
		float valor = quantidade * p1.preco;
		printf("Valor: R$ %.2f\n", valor);
	}
	else if(codigo == p2.codigo){
		float valor = quantidade * p2.preco;
		printf("Valor: R$ %.2f\n", valor);
	}
	else if(codigo == p3.codigo){
		float valor = quantidade * p3.preco;
		printf("Valor: R$ %.2f\n", valor);
	}
	else{
		printf("Codigo invalido\n");
	}
	return 0;
}