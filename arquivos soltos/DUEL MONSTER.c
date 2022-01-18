
//LUIS FELIPE PEREIRA DE PAIVA PORDEUS 
//MOISÉS HENRIQUE LIMA HOLANDA

#include <stdio.h>

int main() {
    int player1[3][5];
    int player2[3][5];
    int  x, y;
    
    printf("Preencha o Tabuleiro do player1:\n ");
    for(x=0;x<3;x++){
        for(y=0;y<5;y++){
			scanf("%d", &player1[x][y]);
			
        }
    }
	for(x=0;x<3;x++){
        for(y=0;y<5;y++){
          printf("| %d |" ,player1[x][y]);
        } 
    } 

    printf("\nPreencha o Tabuleiro do player2:\n ");
    for(x=0;x<3;x++){
        for(y=0;y<5;y++){
        	 scanf("%d", &player2[x][y]);
        }
    }
	for(x=0;x<3;x++){
        for(y=0;y<5;y++){
          printf("| %d |" ,player2[x][y]);
        } 
    }
	putchar('\n'); 
    
	for(x=0;x<3;x++){
        for(y=0;y<5;y++){
		    if( x == 0){
	        	if( y == 0){
		         	if(player1[x][y] > player2[x][y]){
						printf(" O atkF do monstro1 do player1 e maior!\n");
					} else if(player2[x][y] > player1[x][y]){
						printf(" O atkF do monstro1 do player2 e maior!\n");
					} else{
						printf("\n atkF igual\n");
					}  
				} else if ( y == 1){
					if(player1[x][y] > player2[x][y]){
					  	printf(" A defF do monstro1 do player1 e maior!\n");  
					} else if(player2[x][y] > player1[x][y]){
					  	printf(" A defF do monstro1 do player2 e maior!\n");
					} else{
						printf("\n defF igual\n");
					}
				} else if ( y == 2){
					if (player1[x][y] > player2[x][y]){
					 	printf(" A Mag do monstro1 do player1 e maior!\n");
					} else if(player2[x][y] > player1[x][y]){
					  	printf(" A Mag do monstro1 do player2 e maior!\n");	 
					} else{
						printf("\n mag igual\n");
					}
				} else if ( y == 3){
					if(player1[x][y] > player2[x][y]){
						printf(" A DefM do monstro1 do player1 e maior!\n");
					} else if(player2[x][y] > player1[x][y]){
						printf(" A DefM do monstro1 do player2 e maior!\n");
					} else{
						printf("\n DefM igual\n");
					} 
				} else if ( y == 4){
					if(player1[x][y] > player2[x][y]){
						printf(" A vel do monstro1 do player1 e maior!\n");
					} else if(player2[x][y] > player1[x][y]){
					  	printf(" A vel do monstro1 do player2 e maior!\n");
					} else{
						printf("\n vel igual\n");
					} 
				}		 
			} else if ( x == 1){	 
				if( y == 0){
		         	if(player1[x][y] > player2[x][y]){
					  	printf(" O atkF do monstro2 do player1 e maior!\n");
					} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" O atkF do monstro2 do player2 e maior!\n"); 
					} else{
						printf("\n atkF igual\n");
					}  
				} else if ( y == 1){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A defF do monstro2 do player1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A defF do monstro2 do player2 e maior!\n");	 
				 	} else{
						printf("\n defF igual\n");
					}
				} else if ( y == 2){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A Mag do monstro2 do player1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A Mag do monstro2 do player2 e maior!\n");
				 	} else{
						printf("\n Mag igual\n");
					}
				}else if ( y == 3){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A DefM do monstro2 do player1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A DefM do monstro2 do player2 e maior!\n");
				 	} else{
						printf("\n DefM igual\n");
					}
				} else if ( y == 4){
				  	if(player1[x][y] > player2[x][y]){
				  		printf(" A vel do monstro2 do player1 e maior!\n"); 
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A vel do monstro2 do player2 e maior!\n"); 
				 	} else{
						printf("\n Vel igual\n");
					}
			  	} 
			} else if ( x == 2){ 
			 	if( y == 0){
		         	if(player1[x][y] > player2[x][y]){
					  	printf(" O atkF do monstro3 do player1 e maior!\n");
					   
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" O atkF do monstro3 do player2 e maior!\n");
						 
				 	} else{
						printf("\n atkF igual\n");
					}  
			  	} else if ( y == 1){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A defF do monstro3 do player1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A defF do monstro3 do player2 e maior!\n");
				 	} else{
						printf("\n DefF igual\n");
					}	  
			  	} else if ( y == 2){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A Mag do monstro3 do 1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A Mag do monstro3 do jogador2 e maior!\n");
				 	} else{
						printf("\n Mag igual\n");
					}
			  	}else if ( y == 3){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A DefM do monstro3 do player1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A DefM do monstro3 do player2 e maior!\n"); 
				 	} else{
						printf("\n DefM igual\n");
					}
			  	} else if ( y == 4){
				  	if(player1[x][y] > player2[x][y]){
					  	printf(" A vel do monstro3 do player1 e maior!\n");
				 	} else if(player2[x][y] > player1[x][y]){
			    	  	printf(" A vel do monstro3 do player2 e maior!\n");
				 	}else{
						printf("\n Vel igual\n");
					}
			  	}
	  		}
        }
    }
    
 
    return 0;
    
}