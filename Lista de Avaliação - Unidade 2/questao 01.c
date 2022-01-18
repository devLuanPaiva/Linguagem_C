#include <stdio.h>
#include <string.h>

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
	for(i=0; i<n-1 ;i++){
	    for(j=0; j<n -i -1; j++){
		    if(strcmp(a[j].nome,a[j+1].nome) > 0){
		    	/*Se a condicao do if for verdadeira, a primeira palavra em 
				ordem alfabetica, se aproxima da letra A. Apos isso, o codigo 
				vai usar essa palavra para comparar com a proxima ate o fim do
				vetor. Afim de que possa encontrar a palavra que se aproxime cada
				vez mais da letra A e assim, possa ordenar as demais em ordem
				alfabetica por meio dessas instrucoes aqui em baixo*/
				Aluno temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	    }
	}

}


int main(){
	int i, n;
	printf("Informe a quantidade de alunos: ");
	scanf("%d", &n);
	Aluno v[n];
	for(i = 0; i < n; i++){
        printf("nome aluno %d: ",i+1);
		scanf(" %s",v[i].nome);
        printf("nota aluno %d: ",i+1);
        scanf(" %f",&v[i].nota);
        /*Aqui, o codigo esta lendo o nome e a nota do estudante*/
	}
	printf("\n");
	ordenacaoSelecao(n, v);
	printf("Imprimindo na ordem alfabetica\n");
	for(i=0; i<n; i++){
		printf("| Nome: %s| Nota: %2.f|\n", v[i].nome, v[i].nota);
		/*E aqui, esta imprimindo em ordem alfabetica*/
	}
	return 0;
}
