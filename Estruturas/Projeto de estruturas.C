#include <stdio.h>
#include <string.h>
//Campeonato Brasileiro

int totalDeTimes;
int totalJogador = 6;

struct saldoGol{
	int golPros;
	int golContra;
	int saldo;
};
struct artilheiro{
	char nomej[100];
	int gol;
};
typedef struct {
	char nome[100];
	int vitorias;
	int empates;
	int pontos;
	struct artilheiro art;
	struct saldoGol sal;
} Times;

void vencedor(Times times[]);

int main(){	
	int i;
    printf("Defina a quantidade de times\n");
	scanf("%d", &totalDeTimes); 
    Times times[totalDeTimes];
    for(i = 0; i < totalDeTimes; i++){
		printf("Informe o nome do time: %d\n ", i+1);
		scanf(" %[^\n]s", times[i].nome);
		
		printf("Informe a quantidade de vitorias e empates: \n");
		scanf("%d %d", &times[i].vitorias, &times[i].empates);
		times[i].pontos = (times[i].vitorias * 3) + times[i].empates;
		
		printf("Informe a quantidade de gols pros e contra: \n");
		scanf("%d %d", &times[i].sal.golPros, &times[i].sal.golContra);
		times[i].sal.saldo = times[i].sal.golPros - times[i].sal.golContra;
	}
	
	printf("Defina o nome dos 5 artilheiros e a quantidade de gols de cada um!\n");
	for(i = 0; i < totalJogador; i++){
		scanf("%s %d", times[i].art.nomej, &times[i].art.gol);
	}
	vencedor(times);
	 
    return 0;
}
void vencedor(Times times[]){
	int i, maiorPontuacao = 0, maiorArtilheiro = 0;
	int maiorSaldo = 0;
	char timeComMaisPontos[100];
	char jogadorComMaisGols[100];
	char timeComMaiorSaldo[100];
	for(i=0; i<totalDeTimes; i++){
     	if(times[i].pontos > maiorPontuacao){
	    	maiorPontuacao = times[i].pontos;
	    	strcpy(timeComMaisPontos, times[i].nome);
	    }
    }
    for(i = 0; i < totalJogador; i++){
    	if(times[i].art.gol > maiorArtilheiro){
			maiorArtilheiro = times[i].art.gol;
			strcpy(jogadorComMaisGols, times[i].art.nomej);
		}
		
	}
	for(i=0; i<totalDeTimes; i++){
		if(times[i].sal.saldo > maiorSaldo){
			maiorSaldo = times[i].sal.saldo;
			strcpy(timeComMaiorSaldo, times[i].nome);
		}
	}
    
	printf("O time vencedor eh o %s com %d pontos\n", timeComMaisPontos, maiorPontuacao);
	printf("O artilheiro do campeonato eh %s com %d gols!\n", jogadorComMaisGols, maiorArtilheiro);
	printf("O time com maior saldo de gols eh %s com %d gols!\n", timeComMaiorSaldo, maiorSaldo);
}
