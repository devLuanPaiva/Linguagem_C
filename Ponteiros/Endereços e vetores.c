#include  <stdio.h>

int main(){
    //! showMemory(start=65520)
    int n;
    int *pn;
    pn = &n;
    printf("Informe a quantidade de valores: \n");
    scanf("%d", pn);
    int v[n];
    int i;
        for(i=0; i<n; i++){
            scanf("%d", &v[i]);
        }
        for(i=0; i<n; i++){
            if(v[i] %2 == 0){
                printf("PAR\n");
            }
            else printf("IMPAR");
        }
    return 0;
}