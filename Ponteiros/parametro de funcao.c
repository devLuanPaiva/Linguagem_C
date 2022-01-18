#include <stdio.h>
void f(int *pa){
    *pa = 2 * *pa;
    printf("Valor de a na funcao: %d\n", *pa);
}
int main(){
    //! showMemory(start=65520)
    int a;
    int *pa;
    pa = &a;
        printf("Informe um valor para a: \n");
        scanf("%d", pa);
        f(pa);
        printf("Valor de a no main: %d", a);
    return 0;
}