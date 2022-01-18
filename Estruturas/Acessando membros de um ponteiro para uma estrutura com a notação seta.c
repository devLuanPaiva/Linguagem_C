#include <stdio.h>
struct pesquisa{
	int alcool;
	int gasolina;
	int disel;
};
int main(){
	//! showMemory(start=65520)
	struct pesquisa p = {0, 0, 0};
	struct pesquisa *pp = &p;
	printf("Informe os votos dos clientes\n");
	int voto;
	scanf("%d", &voto);
	while(voto != 4){
		if(voto == 1){
			(*pp).alcool++;
		}
		else if(voto == 2){
			(*pp).gasolina++;
		}
		else if(voto == 3){
			(*pp).disel++;
		
		}
		scanf("%d", &voto);
	}
	printf("Alcool: %d\n", (*pp).alcool);
	printf("Gasolina: %d\n", (*pp).gasolina);
	printf("Disel: %d\n", (*pp).disel);
	return 0;
	
	
}