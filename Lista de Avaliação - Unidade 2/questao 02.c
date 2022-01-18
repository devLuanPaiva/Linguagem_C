#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
NOME:Luan Alves de Paiva
TURMA: 1
MATRICULA:2020022483
*/

typedef struct aluno Aluno;
struct aluno {
    char nome[81]; 
    float nota;
};

void ordenacaoSelecao(int n, Aluno* a){
    int i, j;
	for(i = 0; i < n; i++){
        int imenor = i;
        for(j = i + 1; j < n; j++){
            if(strcmp(a[j].nome,a[imenor].nome) < 0){
                imenor = j;
            }
            /*Se a condicao do if for verdadeira, a primeira palavra em 
				ordem alfabetica, se aproxima da letra A. Apos isso, o codigo 
				vai usar essa palavra para comparar com a proxima ate o fim do
				vetor. Afim de que possa encontrar a palavra que se aproxime cada
				vez mais da letra A e assim, possa ordenar as demais em ordem
				alfabetica por meio dessas instrucoes aqui em baixo*/
        }
        Aluno aux = a[i];
        a[i] = a[imenor];
        a[imenor] = aux;
    }

}
Aluno* busca (int n, Aluno** v, char* nome){
	int i = 0;
    int f = n - 1;
	//Esse while vai percorrer do inicio ao fim do vetor.
    while(i <= f){
		int meio = (i + f)/2;
		if(strcmp(v[meio]->nome,nome) == 0){
			return v[meio];
			/*Se a condicao acima for verdadeira, quer dizer que as duas
			 palavras sao iguais. Ou seja, a palavra que o usuario digitou para
	        buscar, esta presente no vetor e é a palavra do meio do mesmo. 
			Entao, sera retornado o meio do vetor.*/
		}
		else if(strcmp(v[meio]->nome,nome) < 0){
			i = meio + 1;
            /*Se a condicao anterior for falsa, essa sera averiguada. Caso essa
			seja verdadeira, quer dizer que a palavra buscada esta acima do meio*/
		}
		else if(strcmp(v[meio]->nome,nome) > 0){
            f = meio - 1;
            /*Se as anteriores forem falsas e essa for verdadeira, quer dizer 
			que a palavra buscada esta abaixo do meio*/
		}
	}
	return NULL;
	/*E se todas forem falsas, quer dizer que a palavra buscada nao existe*/
}
void menu(){
	printf("|========== Escolha uma opcao ==========|\n");
	printf("|1 - Procurar                        	|\n");
	printf("|2 - Mostrar ordenacao                  |\n");
	printf("|3 - Sair                               |\n");
	printf("|=======================================|\n");
}


int main(){
	int i, nalunos;
	printf("Informe a quantidade de alunos: ");
	scanf("%d", &nalunos);
	Aluno v[nalunos];
	for(i = 0; i < nalunos; i++){
    printf("nome aluno %d: ",i+1);
		scanf(" %s",v[i].nome);
    printf("nota aluno %d: ",i+1);
    scanf(" %f",&v[i].nota);
	}

	menu();
	int op;
	scanf(" %d", &op);

	while(op != 3){

		if(op == 1){
            //criacao do vetor de ponteiros para ponteiro
            Aluno** a = (Aluno*) malloc(1 * sizeof(Aluno));
      
            //abrindo as posicoes! do ponteiros de ponteiros
            int j = 0;
            for(j = 0; j < nalunos;j++){
                a[i] = malloc(sizeof(Aluno));
            }
      
            /*colocando cada elemento do Aluno v[nalunos] na posicoes 
			do vetor de ponteiro para ponteiros;*/
            int i;
            for(i = 0; i < nalunos;i++){
                a[i] = &v[i];
            }
			char estudante[10];
			printf("Digite o nome do aluno: ");
			scanf("%s", estudante);
			
            //imprimir(nalunos, a);
            ordenacaoSelecao(nalunos,*a);
            Aluno* enderenco =  busca (nalunos, a, estudante);
			if (enderenco != NULL){
			    printf("|Nome: %s| Nota: %2.f|\n",enderenco->nome,enderenco->nota);
			}
			else{
                printf("Nome nao encontrado \n");
            }
			printf("\n");     
		}
		if(op == 2){
			int i;
			//Imprimindo os alunos em ordem alfabetica
		    ordenacaoSelecao(nalunos, v);
		    printf("Imprimindo na ordem alfabetica\n");
		    for(i=0; i<nalunos; i++){
			    printf("| Nome: %s| Nota: %2.f|\n", v[i].nome, v[i].nota);
	        }
	        printf("\n");
		}
		menu();
	    scanf("%d", &op);	
	}
	
	return 0;
}
