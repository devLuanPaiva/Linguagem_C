#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void urna_representante(){
printf("|-------------------------------------------------------------------------------------|\n");
printf("|#===================================================================================#|\n");
printf("||            Seu voto para             ||              JUSTICA ESTUDANTIL           ||\n");
printf("||            REPRESENTANTE             ||                                           ||\n");
printf("||                                      ||                    1 2 3                  ||\n");
printf("||           __ __ __ __ __             ||                    4 5 6                  ||\n");
printf("||                                      ||                    7 8 9                  ||\n");
printf("||                                      ||                      0                    ||\n");
printf("||                                      ||  |BRANCO|        |CORRIGE|     |CONFIRMA| ||\n");
printf("|#===================================================================================#|\n");
printf("|-------------------------------------------------------------------------------------|\n");
}
void urna_presidente(){
printf("|-------------------------------------------------------------------------------------|\n");
printf("|#===================================================================================#|\n");
printf("||            Seu voto para             ||              JUSTICA ESTUDANTIL           ||\n");
printf("||            PRESIDENTE                ||                                           ||\n");
printf("||                                      ||                    1 2 3                  ||\n");
printf("||           __  __                     ||                    4 5 6                  ||\n");
printf("||                                      ||                    7 8 9                  ||\n");
printf("||                                      ||                      0                    ||\n");
printf("||                                      ||  |BRANCO|        |CORRIGE|     |CONFIRMA| ||\n");
printf("|#===================================================================================#|\n");
printf("|-------------------------------------------------------------------------------------|\n");
}
int main(){
	int svr1, svr2, svr3, svr4, svr5, svp1, svp2, votor1, votor2, votor3,votor4, votor5, votop1, votop2, votosnpres= 0, votosnrepres = 0, votosbpres = 0, votorbrepres = 0, menu, votantes, i, REPRESENTANTE, PRESIDENTE, password, validpassword = 13811673458;
	char nomer1, nomer2, nomer3, nomer4, nomer5, nomep1, nomep2;
		system("color 0a");
        setlocale(LC_ALL, "portuguese");
	   while(menu != 5){
		   /*senha = 13811673458*/
    	printf("Digite a senha de acesso: ");
    	scanf("%i", &password);


 		while (password != validpassword){
         printf("SENHA INVALIDA!!(INVALID_PASSWORD!!)\a\nDigite a senha de acesso: \n");
         scanf("%i", &password);
 		}
		system("cls");
		printf("|=====================================|\n");
		printf("|                Bem-Vindo            |\n");
    	printf("|=====================================|\n");
    	printf("|          Eleições Estudantis        |\n");
    	printf("|1- Iniciar Votação                   |\n");
    	printf("|2- Definir quantidade de eleitores   |\n");
    	printf("|3- Relatório de votos                |\n");
    	printf("|4- Cadastro de Candidatos            |\n");
    	printf("|5- Sair                              |\n");
   	 	printf("|=====================================|\n");
    	printf("Opção: ");
        scanf("%d", &menu);
		system("cls");
        switch(menu) {
            case 1: {
                if (votantes < 30){
					printf("\nA votacao nao pode ser iniciada!");
					printf("Volte para o menu e defina os votantes e os candidatos!");	
				}
				else{
					printf("\nIniciando a votação!");
					for(i=0; i < votantes; i++){
						urna_representante();
						urna_presidente();
					} 
				}
			if(urna_representante == votor1){
				
			}
			else if(urna_representante == votor2){
				
			}
			else if(urna_representante == votor3){
				
			}
			else if(urna_representante == votor4){
				
			}
			else if(urna_representante == votor5){
				
			}
			else if(urna_representante == BRANCO){
				
			}
			else if(urna_representante == CORRIGE){
				
			}
			else{}
				system("cls");
			break;
			}
			case 2: {
				printf("\nQuantos eleitores estão aptos a votar?");
				scanf("%d", &votantes);
				if(votantes < 30){
					printf("Tem poucos votantes, o minimo permitido é 30!");
					printf("A eleição só sera iniciada quando a quantidade vontates for igual ou superior a 30!");
				}
				else printf("\n");
				break;
			}
			case 3: {
				printf("|============================================================|\n");
				printf("|************************ RELATORIO *************************|\n");
				printf("|============================================================|\n");
                printf("|  TOTAL DE ELEITORES: %i                                     \n", votantes);
               	printf("|  TOTAL DE VOTOS PARA CADA REPRESENTANTE ESTUDANTIL:         \n");
                printf("|    CANDIDATO %c : %i                                        \n", nomer1, svr1 = votor1 + 1);
    			printf("|    CANDIDATO %c : %i                                        \n", nomer2, svr2 = votor2 + 1);
   				printf("|    CANDIDATO %c : %i                                        \n", nomer3, svr3 = votor3 + 1);
   				printf("|    CANDIDATO %c : %i                                        \n", nomer4, svr4 = votor4 + 1);
   				printf("|    CANDIDATO %c : %i                                        \n", nomer5, svr5 = votor5 + 1);
				printf("|    VOTOS BRANCOS: %i                                        \n", votorbrepres += 1);
    			printf("|    VOTOS NULOS: %i                                          \n", votosnrepres += 1);
   				printf("|                                                             \n");
   				printf("|  TOTAL DE VOTOS PARA CADA PRESIDENTE DO GRÊMIO              \n");
				printf("|    CANDIDATO %c : %i                                        \n", nomep1, svp1 = 1);
   				printf("|    CANDIDATO %c : %i                                        \n", nomep2, svp2 = 1);
				printf("|    VOTOS BRANCOS: %i                                        \n", votosbpres += 1);
    			printf("|    VOTOS NULOS: %i                                          \n", votosnpres += 1);   
   				printf("|                                                             \n");
    			printf("|============================================================|\n");
				break;
            }
                				

			case 4: {
				printf("CADASTRO DE CANDIDATOS PARA REPRESENTANTES:\n");
				
				printf("Candidato 1\n");
				scanf("%s \n %d", &nomer1, &votor1);
				printf("Candidato 2\n");
				scanf("%s \n %d", &nomer2, &votor2);
				printf("Candidato 3\n");
				scanf("%s \n %d", &nomer3, &votor3);
				printf("Candidato 4\n");
				scanf("%s \n %d", &nomer4, &votor4);
				printf("Candidato 5\n");
				scanf("%s \n %d", &nomer5, &votor5);
				printf("\n CADASTRO DE CANDIDATOS PARA PRESIDENTE:\n");
				printf("Candidato 1\n");
				scanf("%s \n %d", &nomep1, &votop1);
				printf("Candidato 2\n");
				scanf("%s \n %d", &nomep2, &votop2);
			break;	
			}
			case 5: {
				printf("Obrigado por usar nosso sistema de votação\nSaindo...\n");
			}
			
             default: printf("Opção Invalida!\a\n\n");
			 break;
		}
        }
system("pause");
return 0;
				break;
}
 