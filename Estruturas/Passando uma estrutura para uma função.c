#include <stdio.h>

struct jogo {
	int Fla;
	int Sp;
};
void analista(struct jogo g);

int main(){
	//! showMemory(start=65520)
	struct jogo g;
	printf("Informe a quantidade de gols do Flamengo e Sao Paulo\n");
	scanf("%d %d", &g.Fla, &g.Sp);
	analista(g);
	return 0;
}
void analista(struct jogo g){
	if(g.Fla > g.Sp){
		printf("Vitória do Flamengo\n");
	}
	else if(g.Fla < g.Sp){
		printf("Vitória do Sao Paulo\n");
	}
	else {
		printf("Empate\n");
	}
	
}