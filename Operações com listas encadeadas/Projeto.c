#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Campeonato Brasileiro
// Luan Alves de Paiva
typedef struct {
	char nome[10];
	int vitorias;
	int empates;
	int pontos;
	int saldoGol;	
} Times;
struct No{
	Times dado;
	struct No *prox;
};
typedef struct {
	struct No * inicio;
} Lista;
void lerTime(Times *ptimes){
	printf("Digite o nome do time \n");
	scanf("%s", ptimes->nome);
	printf("Digite o numero de vitorias e empates\n");
	scanf("%d %d", &ptimes->vitorias, &ptimes->empates);
	printf("Digite o saldo de gols\n");
	scanf("%d", &ptimes->saldoGol);
	ptimes->pontos = (ptimes->vitorias * 3) + ptimes->empates;
}

void incerir_time(Lista *plista, Times  dado){
	struct No * novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}
struct No* pesquisar(Lista lista, char s1[]){
	struct No* pi;
	for(pi = lista.inicio; pi != NULL && strcmp(s1, pi->dado.nome) != 0; pi = pi->prox);
	return pi;
}
void ordena_pontos(Lista *ptimes){
	struct No* pi;
	struct No* pj;
	struct No* pfim = NULL;
	if(ptimes->inicio == NULL){
		return;
	}
	for(pi = ptimes->inicio; pi->prox != NULL ; pi = pi->prox){
		for(pj = ptimes->inicio; pj->prox != pfim; pj = pj->prox ){
			if(pj->dado.pontos < pj->prox->dado.pontos){
				Times temp = pj->dado;
				pj->dado = pj->prox->dado;
				pj->prox->dado = temp;
			}
		}
		pfim = pj;
	}
	for(pi = ptimes->inicio; pi != NULL ; pi = pi->prox){
	    printf("|Pontos %d |Nome: %s|\n", pi->dado.pontos, pi->dado.nome);
	}
	
}
void inserir_fim(Lista *ptimes, Times dado){
	struct No *novo= (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = NULL; 
	if(ptimes->inicio == NULL){
		ptimes->inicio = novo;
	}
	else{
	    struct No *pi;
	    for(pi = ptimes->inicio; pi->prox != NULL; pi = pi->prox);
	    pi->prox = novo;
	}
}
struct No* inserir_apos(Lista *ptimes, Times dado, char s1[]){
    struct No* pi;
    for(pi = ptimes->inicio; pi != NULL && strcmp(s1, pi->dado.nome) != 0; pi = pi->prox);
    if(pi == NULL){
	    return pi;
    }
    else {
	    struct No *novo = (struct No*) malloc(sizeof (struct No));
	    novo->dado = dado;
	    novo->prox = pi->prox;
	    pi->prox = novo;
	    return pi;
    }
}
struct No* inserir_antes(Lista *ptimes, Times dado, char s1[]){
	if(ptimes->inicio == NULL){
		return NULL;
	}
	
	else if(strcmp(ptimes->inicio->dado.nome, s1) == 0){
		struct No* novo = (struct No*) malloc(sizeof (struct No));
		novo->dado = dado;
		novo->prox = ptimes->inicio;
		ptimes->inicio = novo;
	} 
	else{
		struct No* pi;
        for(pi = ptimes->inicio; pi->prox != NULL && strcmp(s1, pi->dado.nome) != 0; pi = pi->prox);
        if(pi->prox == NULL){
			return NULL;	
		}
		else {
			struct No *novo = (struct No*) malloc(sizeof (struct No));
			novo->dado = dado;
			novo->prox = pi->prox;
			pi->prox = novo;
			return pi;
		}
	}
}
void deletar_inicio(Lista *ptimes){
	if(ptimes->inicio == NULL){
		printf("A lista esta vazia\n");
	}
	else{
		struct No* pi = ptimes->inicio;
		ptimes->inicio = pi->prox;
		free(pi);
		printf("Time excluido\n");
	}
}
void deletar_fim(Lista *ptimes){
	if(ptimes->inicio == NULL){
		printf("O time nao pode ser deletado\n");
	}
	else if(ptimes->inicio->prox == NULL){
		struct No* pi = ptimes->inicio;
		ptimes->inicio = NULL;
		free(pi);
		printf("Agora a lista esta vazia\n");
	}
	else{
		struct No* pi;
		struct No* pa;
		for(pi = ptimes->inicio; pi->prox != NULL; pi = pi->prox){
			pa = pi;
		}
		pa->prox = NULL;
		free(pi);
		printf("Time excluido\n");
		
	}
}
void deletar_valor(Lista *ptimes, char s1[]){
   //Inicio == null;
	if(ptimes->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No se localiza no inicio;
	else if(strcmp(ptimes->inicio->dado.nome, s1) ==0 ){
		struct No* pi = ptimes->inicio;
		ptimes->inicio = pi->prox;
		free(pi);
		printf("Time excluido\n");
	}
	//Lista tem um unico No. Nome nao existe
	else if(ptimes->inicio->prox == NULL){
		if((strcmp(ptimes->inicio->dado.nome, s1) != 0)){
			printf("O time nao pode ser removido\n");
		}
	}
	//Lista com multiplos Nos. Valor nao existe
	//Lista com multiplos Nos. Valor existe
	else{
		struct No* pa;
		struct No* pi;
		for(pi = ptimes->inicio; pi != NULL && (strcmp(pi->dado.nome ,s1) != 0); pi = pi->prox){
			pa = pi;
		}
		if(pi == NULL){
			printf("O time nao pode ser removido\n");
		}
		else{
			pa->prox = pi->prox;
			free(pi);
			printf("Time escluido\n");
		}
	}
}
void deletat_apos(Lista *ptimes, char s1[]){
	struct No* pa;
	struct No* pi;
	for(pa = ptimes->inicio; pa != NULL && (strcmp(pa->dado.nome ,s1) != 0); pa = pa->prox);
	if(pa == NULL){
		printf("O time nao pode ser removido\n");
	}
	else if(pa->prox == NULL){
		printf("Time nao pode ser removido\n");
	}
	else{
		pi = pa->prox;
		pa->prox = pi->prox;
		free(pi);
		printf("Time excluido\n");
	}
}
void deletar_antes(Lista *ptimes, char s1[]){
	
	//Lista vazia
	if(ptimes->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No inicial igual ao no pesquisado
	else{
		
	    struct No* paa = NULL;
	    struct No* pa = NULL;
        struct No* pi = NULL;
        for(pi = ptimes->inicio; pi != NULL && (strcmp(pi->dado.nome ,s1) != 0); pi = pi->prox){
			paa = pa;
			pa = pi;
		}
		//O segundo no e igual ao valor pesquisado
		if (pa == NULL){
			printf("Time nao pode ser removido\n");
		}
	    //Multiplos itens: No existe
	    if(paa == NULL){
			ptimes->inicio = pi;
			free(pa);
			printf("Time excluido\n");
		}
	    //Multiplos itens: No nao existe
	    else if(pi == NULL){
			printf("Time nao pode ser removido\n");
		}
		else{
			paa->prox = pi;
			free(pa);
			printf("Time excluido\n");
		}
	}
	
}
void deletar_lista(Lista *ptimes){
	struct No* pi;
	while(ptimes->inicio != NULL){
		pi = ptimes->inicio;
		ptimes->inicio = pi->prox;
		free(pi);
	}
}
void mostrar(Lista ptimes){
	struct No * pi;
	for(pi = ptimes.inicio; pi != NULL ; pi = pi->prox){
	    printf("|Nome: %s| Pontos %d| Vitorias %d| Empates %d| Saldo de Gols %d|\n", 
		pi->dado.nome, pi->dado.pontos, pi->dado.vitorias, pi->dado.empates, pi->dado.saldoGol);
	}
	
}
void alterar(Lista *ptimes, char s1[], int goool){	
	struct No* pi = pesquisar(*ptimes, s1);
	if(pi == NULL){
	printf("Time nao encontrada\n");	
	}
	else{
		pi->dado.saldoGol = goool;
		printf("Modificacao concluida\n");
	}
}
int tamanho(Lista lista){
	struct No* pi;
	int cont = 0;
	for(pi = lista.inicio; pi != NULL ;pi = pi->prox){
		cont++;
	}
	return cont;
}
Lista cria_lista(int n){
	Lista lista;
	lista.inicio = NULL;
	int i;
	for(i = 0; i < n ; i++){
		Times ptimes;
		lerTime(&ptimes);
		inserir_fim(&lista, ptimes);
	}
	return lista;
} 
Lista ler_arquivo(){
	Lista lista;
	lista.inicio = NULL;
	
	FILE *file = fopen ("./Times_salvos.b", "rb");
	Times ptimes;;
	while(fread(&ptimes, sizeof(Times), 1, file)){
		inserir_fim(&lista, ptimes);
	}
	fclose(file);
	return lista;
}
void salvar_arquivo(Lista lista){
	FILE *file = fopen ("./Times_salvos.b", "wb");
	struct No* pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
		fwrite(&pi->dado, sizeof(Times), 1, file);
	}
	fclose(file);
}
void menu(){
	printf(" ________________________________________ \n");
    printf("|           MENU DO CAMPEONATO           |\n");
	printf("|1  - Adiciona time                      |\n");
	printf("|2  - Procurar time                      |\n");
	printf("|3  - Mostrar Tabela ordenada            |\n");
	printf("|4  - Inserir mais um time no final      |\n");
	printf("|5  - Inserir um time apos outro         |\n");
	printf("|6  - Inserir um time antes de outro     |\n");
	printf("|7  - Mostrar os times                   |\n");
	printf("|8  - Deletar o primeiro time            |\n");
	printf("|9  - Deletar o ultimo time              |\n");
	printf("|10 - Deletar um time especifico         |\n");
	printf("|11 - Deletetar um time apos outro       |\n");
	printf("|12 - Deletar um time antes de outro     |\n");
	printf("|13 - Deletar lita de times completa     |\n");
	printf("|14 - Alterar dados de um time           |\n");
	printf("|15 - Saber o tamanho da lista           |\n");
	printf("|16 - Criar uma nova lista               |\n");
	printf("|17 - Salvar lista em um arquivo         |\n");
	printf("|18 - Ler lista de um arquivo            |\n");
	printf("|19 - Sair                               |\n");
	printf("|________________________________________|\n");
}

int main(){
	Lista lista;
	lista.inicio = NULL;
	menu();
    int op;
    printf("Escolha uma opcao\n");
    scanf("%d", &op);
	while(op != 19){
		if(op == 1){
			Times ptimes;
            lerTime(&ptimes);
            incerir_time(&lista, ptimes);
            printf("\n");
		}
		else if(op == 2){
			char s1[100];
		    printf("Digite o nome do time \n");
	  		scanf("%s", s1);
		    struct No * pi = pesquisar(lista, s1);			    
			if(pi !=  NULL){
		        printf("Nome: %s\n", pi->dado.nome);
                printf("Vitorias: %d\n",pi->dado.vitorias);
			    printf("Empates: %d\n", pi->dado.empates);
                printf("Pontos: %d\n", pi->dado.pontos);
			    printf("Saldo de Gols: %d\n", pi->dado.saldoGol);
            }
            else{
                printf("Time nao encontrado\n");
            }
            printf("\n");
		}
		else if(op == 3){
		    ordena_pontos(&lista);
			printf("\n");
		}
		else if(op == 4){
			Times ptimes;
			lerTime(&ptimes);
			inserir_fim(&lista, ptimes);
			printf("\n");
		}
		else if(op == 5){
			Times ptimes;
			lerTime(&ptimes);
			char s1[100];
			printf("Informe o time para inserir apos\n");
			scanf("%s", s1);
			struct No * pi = inserir_apos(&lista, ptimes, s1);
			if(pi == NULL){
				printf("Nao foi possivel inserir o time\n");
			}
			printf("\n");
		}
		else if(op == 6){
			Times ptimes;
			lerTime(&ptimes);
			char s1[100];
			printf("Informe o time para inserir antes\n");
			scanf("%s", s1);
			struct No * pi = inserir_antes(&lista, ptimes, s1);
			if(pi == NULL){
				printf("Nao foi possivel inserir o time\n");
			}
			printf("\n");	
		}
		else if(op == 7){
			mostrar(lista);
			printf("\n");
		}
		else if(op == 8){
			deletar_inicio(&lista);
			printf("\n");
		}
		else if(op == 9){
			deletar_fim(&lista);
			printf("\n");
		}
		else if(op == 10){
		    char s1[100];
			printf("Informe o time para ser deletado\n");
			scanf("%s", s1);
			deletar_valor(&lista, s1);
			printf("\n");
		}
        else if(op == 11){
			char s1[100];
			printf("Informe o time para ser deletado apos \n");
			scanf("%s", s1);
			deletat_apos(&lista, s1);
			printf("\n");
		}
		else if(op == 12){
			char s1[100];
			printf("Informe o time para ser deletado antes\n");
			scanf("%s", s1);
			deletar_antes(&lista, s1);
			printf("\n");
		}
		else if(op == 13){
			deletar_lista(&lista);
			printf("Lista deletada\n");
			printf("\n");
		}
		else if(op == 14){
		    char s1[100];
			printf("Informe o time para ser deletado antes\n");
			scanf("%s", s1);
			int goool;
			printf("Informe o novo saldo de gols\n");
			scanf("%d", &goool);
			alterar(&lista, s1, goool);
			printf("\n");
		}
		else if(op == 15){
			int tam = tamanho(lista);
			printf("O tamanho da lista e: %d\n", tam);
			printf("\n");
		}
		else if(op == 16){
			int n;
			printf("Informe a quantidade de times\n");
			scanf("%d", &n);
			lista = cria_lista(n);
			printf("\n");
		}
		else if(op == 17){
		    salvar_arquivo(lista);
			printf("Arquivo salvo\n");
			printf("\n");	
		}
		else if(op == 18){
			lista = ler_arquivo();
		}						
		menu();
		scanf("%d", &op);
	}
	return 0;
}
