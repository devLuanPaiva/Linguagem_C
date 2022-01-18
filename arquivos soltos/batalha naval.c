#include <stdio.h>

int main() {
int jogador1[5][5];
int jogador2[5][5];
int p1 = 0, p2 = 0;
int count = 0, i, j, linha, coluna;

    printf("Jogador 1: \n ");
    printf("Insira 0 para MAR e 1 para NAVIO!\n ");
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
				if(count == 4) {
                    jogador1[i][j] = 0;
                }
                else{
					
					scanf(" %d", &jogador1[i][j]);
                        if(jogador1[i][j]==1) count++;
                }
            }
        }

    count = 0;
    printf("Jogador 2: \n ");
    printf("Insira 0 para MAR e 1 para NAVIO!\n ");
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
				if(count == 4)  {
                    jogador1[i][j] = 0;
                }
                else{
                    
					scanf("  %d", &jogador2[i][j]);
                        if(jogador1[i][j]==1) count++;
                }
            }
        }
  i = 1;
 do{
    printf("Vez do Jogador %d \n ", i );
    printf("\n Qual posicao? \n");
    scanf("%d %d", &linha, &coluna);
    if(i == 1){
        if(jogador2[linha][coluna] == 1){
        p1++;
        printf("Acerto, ah mizeravi! \n");
        }
        else printf("a caba burro viu vei \n");
    }
    else{
        if(jogador1[linha][coluna] == 1){
        p2++;
        printf("Acerto, ah mizeravi!\n ");
        }
        else printf("a caba burro viu vei\n ");
    }

    if(p1 == 4 || p2 == 4) break;
    if(i == 1 ) {
		if(jogador2[linha][coluna] == 1) i=1;
		else i = 2;
	}
    else {
		if(jogador1[linha][coluna] == 1) i=2;
		else i = 1;
	};
}while(1);
    if(p1 || p2 == 4)printf("\n Aprendeu cum quem?");
}
   