#include <stdio.h>
#include <string.h>

/* Vari�vel global que define o total de times.
   Defini-la globalmente � mais pr�tico, porque se voc� precisar
   alterar esse valor, basta apenas modificar o valor dessa vari�vel.
*/
int totalDeTimes;

// Define a estrutura de times
typedef struct {
	char nome[100];
	int vitorias;
	int empates;
	int pontos;
} Times;

// Fun��o que determina o total de vencedores
void vencedor(Times times[]);


int main(){	
	int i;
    printf("Defina a quantidade de times\n");
	scanf("%d", &totalDeTimes); 
    // Vetor de times
    Times times[totalDeTimes];
    
    /* La�o que percorre o vetor de times e preenche cada elemento com
       as informa��es referentes a cada time. */
    for(i = 0; i < totalDeTimes; i++){
		printf("Informe o nome do time %d: ", i+1);
		scanf(" %[^\n]s", times[i].nome);	
		
		printf("Informe a quantidade de vitorias e empates \n");
		scanf("%d %d", &times[i].vitorias, &times[i].empates);
		
		// Calcula o total de pontos que o time possui
		times[i].pontos = (times[i].vitorias * 3) + times[i].empates;
	}
	
	// Ap�s preencher o vetor de times, chama a fun��o vencedor() para determinar o time vencedor
	vencedor(times);
	
    return 0;
}

// Fun��o que determina o time com mais pontos
void vencedor(Times times[]){
	int i, maiorPontuacao = 0;
	char timeComMaisPontos[100]; // Vari�vel para armazenar o nome do time vencedor
	
	// Identifica o time com mais pontos e armazena sua pontua��o e o seu nome
	for(i=0; i<totalDeTimes; i++){
     	if(times[i].pontos > maiorPontuacao){
	    	maiorPontuacao = times[i].pontos;
	    	strcpy(timeComMaisPontos, times[i].nome);
	    }
    }
    
	printf("O time vencedor eh o %s com %d pontos", timeComMaisPontos, maiorPontuacao);
}

