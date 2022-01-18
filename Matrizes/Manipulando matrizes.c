#include <stdio.h>
int main(){
    //! showMemory(start=65520, cursors=[m[0], m1[1], p])
    //! m = showArray2D(m, rowCursors=[i], colCursors=[j])
    int n; 
    int *pn; 
    pn = &n;
    printf("Informe o valor de n \n");
    scanf("%d", pn);
    int m[n][n];
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    int p;
    scanf("%d", &p);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(m[i][j] == p){
                    printf("Linha %d \n Coluna %d\n", i, j);
                }
            }
        }
    return 0;    
}