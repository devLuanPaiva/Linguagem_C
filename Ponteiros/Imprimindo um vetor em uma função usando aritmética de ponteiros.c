#include <stdio.h>

void imprime(int n, int v[]){
    int i;
    for(i=0; i<n; i++){
        printf("%d", *(v + i));
    }
    printf("\n");
    
}
int main(){
    //!showMemory(start=65520)
    int n;
    int *pn = &n;
    printf("Informe a quantidade de valores!\n");
    scanf("%d", pn);
    int v[n];
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(i=0; i<n; i++){
        v[i]= 2 * v[i];
    }
    imprime(n, v);
    return 0;
}