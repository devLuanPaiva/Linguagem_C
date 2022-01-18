#include <stdio.h>
int main() {
    int linhas;
    int alunos[linhas][3];
    int i, j;
    printf("Quantidade de alunos: \n");
    scanf("%d", &linhas);

    printf("insira as tres notas de cada um: \n");
    for(i=0; i<linhas; i++){
        for(j=0; i<3; j++){
            scanf("%d", &alunos[linhas][3]);
        }
    }
    putchar("\n ");
    for(i=0; i<linhas; i++){
        for(j=0; i<3; j++){
            scanf("%d", &alunos[linhas][3]);
        }
        putchar("\n ");
    }

}
