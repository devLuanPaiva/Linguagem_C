#include <stdio.h>
#include <string.h>
//Campeonato Brasileiro

int totalDeTimes;
int totalJogador = 5;

typedef struct {
	int golPros;
	int golContra;
	int saldo;
}saldoGol;
typedef struct {
	char nomej[100];
	int gol;
}artilheiro;
typedef struct {
	char nome[100];
	int vitorias;
	int empates;
	int pontos;
	 artilheiro art;
	 saldoGol sal;
} Times;

void vencedor( Times *ptimes);

int main(){
	FILE *file = fopen("./projetinho.txt", "a");
	int i;
   printf("Defina a quantidade de times\n");
   scanf("%d", &totalDeTimes);
	if(totalDeTimes < 5){
		printf("Quantidade insuficiente!");
	}
	else{
    Times times[totalDeTimes];
	Times *ptimes;
	ptimes = times;
    for(i = 0; i < totalDeTimes; i++){
		printf("Informe o nome do time: %d\n ", i+1);
		scanf(" %[^\n]s", (ptimes+i)->nome);
		fprintf(file, "\n %s", (ptimes+i)->nome);

		printf("Informe a quantidade de vitorias e empates: \n");
		scanf("%d %d", &(ptimes+i)->vitorias, &(ptimes+i)->empates);
		(ptimes+i)->pontos = ((ptimes+i)->vitorias * 3) + (ptimes+i)->empates;
		fprintf(file, "\nVitorias: %d \n Empates %d \n", (ptimes+i)->vitorias, (ptimes+i)->empates);

		printf("Informe a quantidade de gols pros e contra: \n");
		scanf("%d %d", &(ptimes+i)->sal.golPros, &(ptimes+i)->sal.golContra);
		(ptimes+i)->sal.saldo = (ptimes+i)->sal.golPros - (ptimes+i)->sal.golContra;
		fprintf(file, "\nGols pros: %d\n Gols Contra: %d \n", (ptimes+i)->sal.golPros, (ptimes+i)->sal.golContra);
	}

	printf("Defina o nome dos 5 artilheiros e a quantidade de gols de cada um!\n");
	for(i = 0; i < 5; i++){
		scanf("%s %d", (ptimes+i)->art.nomej, &(ptimes+i)->art.gol);
	}
	vencedor(ptimes);
	fclose(file);
	}
    return 0;
}
void vencedor( Times *ptimes){
	int i, maiorPontuacao = 0, maiorArtilheiro = 0;
	int maiorSaldo = 0;
	char timeComMaisPontos[100];
	char jogadorComMaisGols[100];
	char timeComMaiorSaldo[100];
	for(i=0; i<totalDeTimes; i++){
     	if((ptimes+i)->pontos > maiorPontuacao){
	    	maiorPontuacao = (ptimes+i)->pontos;
	    	strcpy(timeComMaisPontos, (ptimes+i)->nome);
	    }
    }
    for(i = 0; i < 5; i++){
    	if((ptimes+i)->art.gol > maiorArtilheiro){
			maiorArtilheiro = (ptimes+i)->art.gol;
			strcpy(jogadorComMaisGols, (ptimes+i)->art.nomej);
		}

	}
	for(i=0; i<totalDeTimes; i++){
		if((ptimes+i)->sal.saldo > maiorSaldo){
			maiorSaldo = (ptimes+i)->sal.saldo;
			strcpy(timeComMaiorSaldo, (ptimes+i)->nome);
		}
	}

	printf("O time vencedor eh o %s com %d pontos\n", timeComMaisPontos, maiorPontuacao);
	printf("O artilheiro do campeonato eh %s com %d gols!\n", jogadorComMaisGols, maiorArtilheiro);
	printf("O time com maior saldo de gols eh %s com %d gols!\n", timeComMaiorSaldo, maiorSaldo);
}

