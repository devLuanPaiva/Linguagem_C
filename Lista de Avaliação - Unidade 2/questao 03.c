#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//criar 4 vetores 100, 1000, 10000 e 100000

/*
NOME:Luan Alves de Paiva
TURMA: 1
MATRICULA:2020022483
*/

void insertionSort(int arr[], int size, int* contTempoinsertionsort){
    int i, j, key;
    for (i = 1; i < size; i++) {
        (*contTempoinsertionsort)++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim, int* contMergeSort){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;
        (*contMergeSort)++;
        mergeSort(vetor, comeco, meio, contMergeSort);
        mergeSort(vetor, meio+1, fim, contMergeSort);
        merge(vetor, comeco, meio, fim);
    }
}

int partition(int vec[], int l, int u) {
  int i, m, temp;
  m = l;   // m: indice do ponto médio
  for(i = l+1; i<=u; i++) {
     if(vec[i] < vec[l]) { // fora de ordem
      m ++;
      temp = vec[i];  // trocar vec[i], vec[m]
      vec[i] = vec[m];
      vec[m] = temp;
     }
  }
  temp = vec[l]; // trocar vec[l], vec[m]
  vec[l] = vec[m];
  vec[m] = temp;
  return m;
}

void quicksort_rec(int vec[], int l, int u,int* contQuickSort) {
  int m;
  if(l >= u)
    return; 
  m = partition(vec, l, u);
 (*contQuickSort)++;
  quicksort_rec(vec, l, m-1,contQuickSort);
 
  quicksort_rec(vec, m+1, u,contQuickSort);
  
}


int main(){
  int contInsertionSort = 0, contMergeSort = 0, contQuickSort = 0;
  int vet1[100], vet2[1000], vet3[10000], vet4[100000];
  int n1 = 100, n2 = 1000, n3 = 10000, n4 = 100000;
  int cont1 = 101, cont2 = 1001, cont3 = 10001, cont4 = 100001;
  int i;
  for(i = 0; i < n1;i++){
    cont1--;
    vet1[i] = cont1;
  }
  
	for(i = 0; i < n2;i++){
    cont2--;
    vet2[i] = cont2;
  }

  for(i = 0; i < n3;i++){
    cont3--;
    vet3[i] = cont3;
  }

   for(i = 0; i < n4;i++){
    cont4--; 
    vet4[i] = cont4;
  }
 
//  insertionSort(vet1, n1, &contInsertionSort);
//  printf("o tempo de execucao do insertion Sort Vetor 1: %d\n",contInsertionSort);
//  contInsertionSort = 0;
//   printArray(vet2,n2);  
 
//  insertionSort(vet2, n2, &contInsertionSort);
//  printf("o tempo de execucao do insertion Sort Vetor 2: %d\n",contInsertionSort);
//  contInsertionSort = 0;
//   printArray(vet2,n2); 

//  insertionSort(vet3, n3, &contInsertionSort);
//  printf("o tempo de execucao do insertion Sort Vetor 3: %d\n",contInsertionSort);
//  contInsertionSort = 0;
//   printArray(vet2,n2); 

//  insertionSort(vet4, n4, &contInsertionSort);
//  printf("o tempo de execucao do insertion Sort Vetor 4: %d\n",contInsertionSort);
//  contInsertionSort = 0;
//  printArray(vet2,n2); 

//---------------------------------------

  // mergeSort(vet1,0,n1,&contMergeSort);
  // printf("o tempo de execucao do contMerge Sort Vetor 1: %d\n",contMergeSort);
  // contMergeSort = 0;

  // mergeSort(vet2,0,n2,&contMergeSort);
  // printf("o tempo de execucao do contMerge Sort Vetor 2: %d\n",contMergeSort);
  // contMergeSort = 0;

  // mergeSort(vet3,0,n3,&contMergeSort);
  // printf("o tempo de execucao do contMerge Sort Vetor 3: %d\n",contMergeSort);
  // contMergeSort = 0;

  // mergeSort(vet4,0,n4,&contMergeSort);
  // printf("o tempo de execucao do contMerge Sort Vetor 4: %d\n",contMergeSort);
  // contMergeSort = 0;

//  quicksort_rec(vet1,0,n1,&contQuickSort);
//   printf("o tempo de execucao doQuick Sort Vetor 1: %d\n",contQuickSort);
//   contQuickSort = 0;

  // quicksort_rec(vet2,0,n2,&contQuickSort);
  // printf("o tempo de execucao doQuick Sort Vetor 2: %d\n",contQuickSort);
  // contQuickSort = 0;

  // quicksort_rec(vet3,0,n3,&contQuickSort);
  // printf("o tempo de execucao doQuick Sort Vetor 3: %d\n",contQuickSort);
  // contQuickSort = 0;

  // quicksort_rec(vet4,0,n4,&contQuickSort);
  // printf("o tempo de execucao doQuick Sort Vetor 4: %d\n",contQuickSort);
  // contQuickSort = 0;
	return 0;
}