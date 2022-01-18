#include <stdio.h>
#include <string.h>

/* Variável global que define o total de times.
   Defini-la globalmente é mais prático, porque se você precisar
   alterar esse valor, basta apenas modificar o valor dessa variável.
*/
int totalDeTimes;

// Define a estrutura de times
typedef struct {
	char nome[100];
	int vitorias;
	int empates;
	int pontos;
} Times;

// Função que determina o total de vencedores
void vencedor(Times times[]);


int main(){	
	int i;
    printf("Defina a quantidade de times\n");
	scanf("%d", &totalDeTimes); 
    // Vetor de times
    Times times[totalDeTimes];
    
    /* Laço que percorre o vetor de times e preenche cada elemento com
       as informações referentes a cada time. */
    for(i = 0; i < totalDeTimes; i++){
		printf("Informe o nome do time %d: ", i+1);
		scanf(" %[^\n]s", times[i].nome);	
		
		printf("Informe a quantidade de vitorias e empates \n");
		scanf("%d %d", &times[i].vitorias, &times[i].empates);
		
		// Calcula o total de pontos que o time possui
		times[i].pontos = (times[i].vitorias * 3) + times[i].empates;
	}
	
	// Após preencher o vetor de times, chama a função vencedor() para determinar o time vencedor
	vencedor(times);
	
    return 0;
}

// Função que determina o time com mais pontos
void vencedor(Times times[]){
	int i, maiorPontuacao = 0;
	char timeComMaisPontos[100]; // Variável para armazenar o nome do time vencedor
	
	// Identifica o time com mais pontos e armazena sua pontuação e o seu nome
	for(i=0; i<totalDeTimes; i++){
     	if(times[i].pontos > maiorPontuacao){
	    	maiorPontuacao = times[i].pontos;
	    	strcpy(timeComMaisPontos, times[i].nome);
	    }
    }
    
	printf("O time vencedor eh o %s com %d pontos", timeComMaisPontos, maiorPontuacao);
}

