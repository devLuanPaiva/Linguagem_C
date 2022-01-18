#include<stdio.h>
int main(){
    int i, cont,num,maior, posicao;
 cont=0;
 maior=0;

    for(i=0;i<=100;i++){
        scanf("%d",&num);
        if(maior<num){
            maior=num;
            posicao=i;
        }
    }
    printf("\n%d\n%d\n",maior,posicao);
    return 0;
}