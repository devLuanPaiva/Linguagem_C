#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Campeonato Brasileiro
// Luan Alves de Paiva

int totalJogador = 4;

typedef struct {
	int golPros;
	int golContra;
	int saldo;
}saldoGol;

typedef struct {
	char nomej[20];
	int gol;
	int numero;
	int pontuacao;
}artilheiro;

typedef struct {
	char nome[100];
	int vitorias;
	int empates;
	int pontos;
 	saldoGol sal;
} Times;
struct No{
	Times dado;
	struct No *prox;
};
typedef struct {
	struct No * inicio;
} Lista;


void vencedor(Lista *plista){
	int i, maiorPontuacao = 0;
	int maiorSaldo = 0;
	char timeComMaisPontos[100];
	char timeComMaiorSaldo[100];
	
    struct No* pi;
	if(plista->inicio == NULL){
		return;
	}
	for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
	        if((pi->prox)->dado.pontos > maiorPontuacao){
	        	maiorPontuacao = (pi->prox)->dado.pontos;
	        	strcpy(timeComMaisPontos, (pi->prox)->dado.nome);
	          }
        }
    
	    for(i=0; i<totalDeTimes; i++){
	    	if((pi->prox)->dado.sal.saldo > maiorSaldo){
	    		maiorSaldo = (pi->prox)->dado.sal.saldo;
	    		strcpy(timeComMaiorSaldo, (pi->prox)->dado.nome);
	    	}
	   }
	
	
	printf("O time vencedor eh o %s com %d pontos\n", timeComMaisPontos, maiorPontuacao);
	
	printf("O time com maior saldo de gols eh o %s com %d gols!\n", timeComMaiorSaldo, maiorSaldo);
}

void melhorJogador(artilheiro *part){
	char jogadorComMaisPontos[100]; 
	int maiorArtilheiro = 0;
	int i;
	for(i = 0; i < totalJogador; i++){
		(part+i)->pontuacao = (((part+i)->gol) - ((part+i)->carAmarelo) - ((part+i)->carVemelho * 2));
    	if((part+i)->pontuacao > maiorArtilheiro){
			maiorArtilheiro = (part+i)->pontuacao;
			strcpy(jogadorComMaisPontos, (part+i)->nomej);
		}

	}
	printf("O artilheiro do campeonato eh %s com %d pontos!\n", jogadorComMaisPontos, maiorArtilheiro);
}
struct No* pesquisar(Lista lista, char s1[]){
	struct No* pi;
	for(pi = lista.inicio; pi != NULL && strcmp(s1, pi->dado.nome) != 0; pi = pi->prox);
	return pi;
}

int procurarJogador(int numero, int totalDeTimes, artilheiro v[]){
	
	int i = 0;
	int f = totalJogador - 1;
	while(i <= f){
		int meio = (i + f)/2;
		if(v[meio].numero == numero){
			return meio;
		}
		else if(v[meio].numero < numero){
			i = meio + 1;
		}
		else {
			f = meio - 1;
		}
	}
	return -1;
}

void intercala(int e, int m, int d, artilheiro v[]){
	int n1 = (m - e) + 1;
	int n2 = d - m;
	int k = e;
	artilheiro E[n1];
	artilheiro D[n2];
	int i, j;
	for(i=0; i<n1; i++){
		E[i] = v[e + i];
	}
	for(j=0; j<n2; j++){
		D[j] = v[m + 1 + j];
	}
	i = 0;
	j = 0;
	while(i<n1 && j<n2){
		if(E[i].pontuacao > D[j].pontuacao){
			v[k] = E[i];
			i++;
		}
		else {
			v[k] = D[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		v[k] = E[i];
		i++;
		k++;
	}
	while(j < n2){
		v[k] = D[j];
		j++;
		k++;
	}
}

void mergeSort(int i, int f, artilheiro v[]){
	if(i < f){
		int m = (i + f)/2;
		mergeSort(i, m, v);
		mergeSort(m + 1, f, v);
		intercala(i, m, f, v);
	}
}

void lerTimes(Times *ptimes){
	FILE *file = fopen("./SalvarTimes.b", "wb");
	printf("Informe o nome do time: \n ");
	scanf(" %[^\n]s", ptimes->nome);
			
	printf("Informe a quantidade de vitorias e empates: \n");
	scanf(" %d %d", &ptimes->vitorias, &ptimes->empates);
	(ptimes)->pontos = (ptimes->vitorias * 3) + (ptimes)->empates;
		
	printf("Informe a quantidade de gols pros e contra: \n");
	scanf(" %d %d", &(ptimes)->sal.golPros, &(ptimes)->sal.golContra);
	(ptimes)->sal.saldo = (ptimes)->sal.golPros - (ptimes)->sal.golContra;
	fwrite(ptimes, sizeof(Times), totalDeTimes, file);
    fclose(file);
}
void lerArtilheiro(artilheiro *part){
	int i; 
	printf("Defina os artilheiros!\n");
	    for(i = 0; i < totalJogador; i++){
            printf("Defina o nome do jogador %d\n", i+1);
            scanf(" %[^\n]s", (part+i)->nomej);
            printf("Defina o numero da camisa do jogador %d\n", i+1); 
            scanf(" %d", &(part+i)->numero);
	        printf("Quantidade de Gols do jogador %d\n", i+1);
	        scanf(" %d", &(part+i)->gol);
	        printf("Defina a quantidade de cartoes amarelos do jogador %d\n", i+1);
	        scanf(" %d", &(part+i)->carAmarelo);
            printf("Defina a quantidade de cartoes Vermelhos do jogador %d\n", i+1);
	        scanf(" %d", &(part+i)->carVemelho);
	    }
}

void ordenacaoinsercao(int n, artilheiro* a){
    int i, j;
    for(i = 1; i < n; i++){
        artilheiro x = a[i];
            for(j = i - 1; j >= 0 && x.numero < a[j].numero; j--){
                a[j + 1] = a[j];
            }
            a[j + 1] = x;
    }
}
void incerir_inicio(Lista *lista, Times  dado){
  printf("Vitorias ao inserir %d\n", dado.vitorias);
	struct No * novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = lista->inicio;
	lista->inicio = novo;
}
void ordenar(Lista *plista){
	struct No* pi;
	struct No* pj;
	struct No* pfim = NULL;
	if(plista->inicio == NULL){
		return;
	}
	for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
		for(pj = plista->inicio; pj->prox != pfim; pj = pj->prox){
			if(pj->dado.pontos > pj->prox->dado.pontos){
				Times temp = pj->dado;
				pj->dado = pj->prox->dado;
				pj->prox->dado = temp;
			}
		}
		pfim = pj;
	}
	printf("Imprimindo tabela do campeonato\n");
	for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
	   printf("|Pontos %d| Time: %s| Vitorias: %d| Saldo: %d|\n", 
	   (pi->prox)->dado.pontos,(pi->prox)->dado.nome,(pi->prox)->dado.vitorias,(pi->prox)->dado.sal.saldo);
	}   
}
void menu(){
	printf("\n");
    printf("__ MENU DO CAMPEONATO__\n");
	printf("|1 - Adiciona time                      |\n");
	printf("|2 - Adicionar Artilheiro               |\n");
	printf("|3 - Procurar time                   	|\n");
	printf("|4 - Procurar Jogador                   |\n");
	printf("|5 - Mostrar Tabela                     |\n");
	printf("|6 - Mostrar Estatisticas               |\n");
	printf("|7 - Sair                               |\n");
	printf("|_____|\n");
}


int main(){
    
	Lista lista;
	lista.inicio = NULL;
    
	Times *ptimes = (Times*) malloc(sizeof(Times));
  //Times times[totalDeTimes];
	//ptimes = times;
		
	artilheiro *part;
	artilheiro v[totalJogador];
	part = v;
	    menu();
	    int op;
	    printf("Escolha uma opcao\n");
	    scanf("%d", &op);
	
	    while(op != 7){
			if(op == 1){
            lerTimes(ptimes);
		        incerir_inicio(&lista, *ptimes);
		        totalDeTimes++;
			}
			else if(op == 2){
				lerArtilheiro(part);
			}
		    else if(op == 3){
		    	char s1[100];
			    printf("Digite o nome do time \n");
	    		scanf("%s", s1);
		    	struct No * pi = pesquisar(lista, s1);
			    
			    if(pi !=  NULL){
			       printf("Nome: %s\n", pi->dado.nome);
                   printf("Vitorias: %d\n",pi->dado.vitorias);
			       printf("Empates: %d\n", pi->dado.empates);
			       printf("Pontos: %d\n", pi->dado.pontos);
			       printf("Saldo de Gols: %d\n", pi->dado.sal.saldo);
	            }
				else{
				   printf("Time nao encontrado\n");
		       }
			}  
		    else if(op == 4){
                int numero;
				printf("Digite o numero da camisa do Jogador\n");
				scanf("%d", &numero);
                ordenacaoinsercao(totalJogador,v);
				int idx = procurarJogador(numero, totalJogador, v);       
				if(idx != -1){
					printf("Nome: %s\n", part[idx].nomej);
					printf("Gols: %d\n", part[idx].gol);
					printf("Cartoes Amarelos: %d\n", part[idx].carAmarelo);
					printf("Cartoes Vermelhos: %d\n", part[idx].carVemelho);
					printf("Pontos: %d\n", part[idx].pontuacao);
				}
			}
			else if(op == 5){
        		ordenar(&lista);
	    		printf("\n");
	    		vencedor(&lista);
	    		printf("\n");
			}
			else if(op == 6){
				int i;
				//mergeSort(0, totalJogador-1, v);
				printf("Estatisticas de Jogadores\n");
				for(i=0; i<totalJogador ; i++){
					printf("|Nome %s| Camisa %d| Gols %d| Pontuacao %d|\n", v[i].nomej, v[i].numero, v[i].gol, v[i].pontuacao);
				}
				
				printf("\n");
				melhorJogador(part);
				printf("\n");
			}
		    menu();
		    scanf("%d", &op);
	    }
	
    return 0;
}