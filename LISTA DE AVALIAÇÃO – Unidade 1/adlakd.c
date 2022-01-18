#include <stdio.h>
#include <stdlib.h>


int* transposta(int m, int n, int* pmat){
    int i, j;

    int* trp;

    trp = (int*) malloc(m*n*sizeof(int));

    if(trp == NULL){
        printf("Memória Insuficiente");
        exit(1);
    }

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            *(trp + j*m+i) = *(pmat + i*n+j);
        }
    }

    return trp;

}

int main(){
    int m = 3; // Linha
    int n = 4; // Coluna
    int *pmat = (int*) malloc(m*n*sizeof(int));
    int i,j;

    int matriz[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    printf("# Salvando a matrizn no ponteiro :\n");
    
    for(i=0; i<m; i++){
            for(j=0; j<n;j++){
            printf("Linha %d, Coluna %d, Posição %d, Valor %d\n", i, j, i * n + j, matriz[i][j]);
            *(pmat + i*n + j) = matriz[i][j]; // IMPORTANTE!! 
            // i percorre as linhas
            // n é o numero de colunas da matriz
            // j percorre as colunas
        }
    }
    printf(" \n# Matriz %d x %d \n", m, n);

    for(i=0; i<m; i++){
        for(j=0; j<n;j++){
            printf("%d ", *(pmat + i*n + j));
        }
        printf("\n");
    }

    pmat = transposta(m, n, pmat);
    
    printf(" \n# Matriz transposta %d x %d \n", n, m);
    
    for(i=0; i<n; i++){
            for(j=0; j<m;j++){
            //printf("Linha %d, Coluna %d, Posição %d, Valor %d \n", i, j, i * m + j, pmat[i * m + j] );
            printf("%d ", *(pmat + i*m + j));
        }
        printf("\n");
    }

    return 0;
}