#include <stdio.h>
#include <stdlib.h>
/*Aluno: Luan Alves de Paiva
  Matricula: 2020022483
  Turma: 1
*/
int Criando_Matriz(int m, int n, int* pmat){

    int *cmz = (int*) malloc(m*n*sizeof(int));
	// Aqui esta alocando na memoria um ponteiro cmz do tamanho m * n
    int i, j, inicio, limitecolunas, limitelinhas, mult, x;
    inicio = 0; 
    limitecolunas = n;
    limitelinhas = m;
    mult = m * n;
    x = 1; 
    i = 0 ;
    while (x<= mult){
        for(j=inicio;j < limitecolunas;j++ ){
            *(pmat + i*n+j) = x++;
			//Esse for vai criar nas linhas de cima os numeros de 0 ate o limite de colunas
        }
        for(i = inicio + 1;i < limitelinhas;i++){
            *(pmat + i*n+j-1)= x++;
			/*Esse for é pertencente a ultima coluna e vai dar continuidade aos numeros
			do for anterior. Mas, dessa vez o seu limite é da primeira linha ate a ultima*/
        }
        for (j = limitecolunas - 1;j > inicio;j--){
            *(pmat + (i-1)*n+j-1)= x++;
			/*Esse for pertence a ultima linha e vai dar continue aos numeros do for anterior.
			No entanto, o mesmo vai inicar na ultima coluna e vai ate a primeira*/
        }
        for (i = limitelinhas - 1; i > inicio + 1; i--){
            *(pmat + (i-1)*n+j)= x++;
			/*Esse pertence a primeira coluna e vai dar continuidade aos numeros do for anterior. 
			No entanto, ele vai inicar na ultima linha e vai ate o inicio. Apos ele, se ainda
			tiver numeros pela frente, o codigo volta para o primeiro for e vai percorrer tudo de novo
			ate que a condicao do while seja cumprida*/
        }
        inicio++;
        limitecolunas --;
        limitelinhas--;
    }
        for (i =0; i <m;i++){
            printf("\n");
        //Esse for vai imprimir as linhas	
            for (j = 0; j < n ; j++){
                printf("%i\t", *(pmat + i*n+j));
				//Esse for vai imprimir as colunas
			}	
        }
	   return *cmz;
    }
    
int main (){
    
    int m;
    int n;
	printf ("digite a quantidade de linhas: \n");
    scanf("%d", &m);
    printf("digite a quantidades de colunas: \n");
    scanf("%d", &n);
    int *pmat = (int*) malloc(m*n*sizeof(int));
	// Aqui esta alocando na memoria um ponteiro pmat do tamanho m * n
    Criando_Matriz(m, n, pmat);
	//Aui esta retornando a funcao criando_matriz
    return 0;
}

