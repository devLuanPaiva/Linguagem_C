#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
 struct aluno{
	char nome[10];
	float nota;
};
Aluno* aluno_cria(int n){
   	Aluno *v =(Aluno *) malloc(n * sizeof(Aluno));
	return v;
	/*Essa funcao é responsavel por alocar espaco na memoria
	para a estrutura aluno.*/
}
void ler(int n, Aluno *v){
	printf("Informe o nome e a nota dos alunos\n");
	int i;
	for(i = 0; i < n; i++){
	    scanf("%s %f", v[i].nome, &v[i].nota);
	}
	/*Essa funcao tem como objetivo percorrer o vetor de alunos afim de que
	possa ler os dados dos mesmos*/
	printf("\n");
	
}

void aluno_imprime(int n, Aluno* a){
	printf("Imprimindo os alunos\n");
	int i;
	for(i = 0; i < n ; i++){
	    printf("%s %2.f\n", a[i].nome, a[i].nota);
	}
	/*Ja essa funcao, é responsao por imprimir os alunos pela mesma ordem que
	foram inscritos na funcao anterior.*/
	printf("\n");
}
void aluno_ordena(int n, Aluno* a){
	printf("Imprimindo por ordem alfabetica\n");
	int i, j;
	for(i = 0; i < n; i++){
        int imenor = i;
        for(j = i + 1; j < n; j++){
            if(strcmp(a[j].nome, a[imenor].nome) < 0){
                imenor = j;
                /*Se a condicao desse if for verdadeira, a primeira
				palavra, chega a ser mais proxima da letra A do que a outra
				(que seria a menor ate entao). Com isso, o codigo vai definir
   	            a primeira palavra como a menor dentre as que ja foram
                averiguadas. Apos isso, ele passa para a proxima palavra
			    ate o fim do vetor. */
            }
        }
        Aluno aux = a[i];
        a[i] = a[imenor];
        a[imenor] = aux;
    }
    /*Com a menor palavra definida, basta ordenar as outras em sequencia da menor
	para a maior, e imprimilas em ordem alfabetica. E esse for abaixo é quem vai
	fazer essa tarefa*/
    for(i=0; i<n; i++){
        printf("| Nome: %s| Nota: %2.f|\n", a[i].nome, a[i].nota);
   }
   printf("\n");
}

void aluno_salva(int n, Aluno *v){
    FILE *file = fopen("./Alunos.txt", "w");
    printf("Salvando Alunos...\n");
    int i;
    for (i = 0; i < n; i++){
       fprintf(file, "|Nome: %s |Nota :%2.f|\n", v[i].nome, v[i].nota);
    }
    fclose(file);
    printf("Alunos salvos no arquivo!");
    /*Essa funcao, é responsavel por imprimir todos os alunos em ordem 
	alfabetica no arquivo de texto */
    printf("\n");
}
void aluno_libera(Aluno* a){
    free(a);
    printf("Espaco liberado na memoria!");
    /*Por fim, essa é responsavel por liberar espaco na memoria suficiente
	para a estrutura aluno*/
    printf("\n");
}
