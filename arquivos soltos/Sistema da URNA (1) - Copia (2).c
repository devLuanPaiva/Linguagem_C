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
	int voto_numero_presidente, voto_numero, svr1, svr2, svr3, svr4, svr5, svp1, svp2, votor1 = 0, votor2 = 0, votor3 = 0, votor4 = 0, votor5 = 0, votop1 = 0, votop2 = 0, votosnpres= 0, votosnrepres = 0, votosbpres = 0, votorbrepres = 0, menu, votantes, i, password, validpassword = 13811673458, votonulore, votonulopre, votobrancore, votobrancopre;
	char nomer1[40], nomer2[40], nomer3[40], nomer4[40], nomer5[40], nomep1[40], nomep2[40], votorepresentante1[6], votorepresentante2[6], votorepresentante3[6], votorepresentante4[6], votorepresentante5[6], votopresidente1[3], votopresidente2[2];
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
						printf("Digite seunumero para REPRESENTANTE!\n");
        				scanf("%i", &voto_numero);
        				if (strcmp(voto_numero, votorepresentante1)==0)
       					 {
          					 urna_representante();

          					 votor1 = votor1 + 1;
       					 }
        					else if (strcmp(voto_numero, votorepresentante2)==0)
       							 {
           							 urna_representante();

            						votor2 = votor2 + 1;
       							 }
       							 else if (strcmp(voto_numero, votorepresentante3)==0)
       							 	{
          			 					urna_representante();

           								votor3 = votor3 + 1;
        							}
        								else if (strcmp(voto_numero, votorepresentante4)==0)
        									{
           										urna_representante();

           										votor4 = votor4 + 1;
        									}
        											else if (strcmp(voto_numero, votorepresentante5)==0)
        											{
            											urna_representante();

            											votor5 = votor5 + 1;
        											}
        													else
        													{
            													urna_representante();

           														printf("Voto Nulo!");
            													votonulore = votonulore + 1;
        													}
        
        														printf("Digite o numero do PRESIDENTE!");
        														scanf("%i", &voto_numero_presidente);
        														if (strcmp(voto_numero_presidente, votopresidente1)==0)
        														{
            														urna_presidente();

           					 										votop1 = votop1 + 1;
        														}
       						 										else if (strcmp(voto_numero_presidente, votopresidente2)==0)
        															{
           						 										urna_presidente();

            															votop2 = votop2 + 1;
       							 									}
        	
					} 
				}
			break;
			}
			case 2: {
				system("cls");
				printf("\nQuantos eleitores estão aptos a votar?\n");
				scanf("%d", &votantes);
				if(votantes < 30){
					printf("Tem poucos votantes, o minimo permitido é 30!\n");
					printf("A eleição só sera iniciada quando a quantidade vontates for igual ou superior a 30!\n");
				}
				else printf("\n");
				break;
			}
			case 3: {
				system("cls");
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
				printf("|    VOTOS BRANCOS: %i                                        \n", votorbrepres = votobrancore + 1);
    			printf("|    VOTOS NULOS: %i                                          \n", votosnrepres = votonulore + 1);
   				printf("|                                                             \n");
   				printf("|  TOTAL DE VOTOS PARA CADA PRESIDENTE DO GRÊMIO              \n");
				printf("|    CANDIDATO %c : %i                                        \n", nomep1, svp1 = votop1 + 1);
   				printf("|    CANDIDATO %c : %i                                        \n", nomep2, svp2 = votop2 + 1);
				printf("|    VOTOS BRANCOS: %i                                        \n", votosbpres = votobrancopre + 1);
    			printf("|    VOTOS NULOS: %i                                          \n", votosnpres = votonulopre + 1);   
   				printf("|                                                             \n");
    			printf("|============================================================|\n");
				break;
            }
                				

			case 4: {
				system("cls");
				printf("CADASTRO DE CANDIDATOS PARA REPRESENTANTES:\n");
				printf("Candidato 1\n");
				scanf(" %[^\n]s", nomer1);
                printf("Numero do candidato!\n");
                scanf(" %[^\n]s", votorepresentante1);
				printf("Candidato 2\n");
				scanf(" %[^\n]s %i", nomer2);
                printf("Numero do candidato!\n");
                scanf(" %[^\n]s", votorepresentante2);
				printf("Candidato 3\n");
				scanf(" %[^\n]s", &nomer3);
                printf("Numero do candidato!\n");
                scanf(" %[^\n]s", votorepresentante3);
				printf("Candidato 4\n");
				scanf(" %[^\n]s", nomer4);
                printf("Numero do candidato!\n");
                scanf(" %[^\n]s", votorepresentante4);
				printf("Candidato 5\n");
				scanf(" %[^\n]s", nomer5);
                printf("Numero do candidato!\n");
                scanf(" %[^\n]s", votorepresentante5);
				printf("CADASTRO DE CANDIDATOS PARA PRESIDENTE:\n");
				printf("Candidato 1\n");
				scanf(" %[^\n]s", nomep1);
                printf("Numero do candidato!\n");
                scanf(" %[^\n]s", votopresidente1);
				printf("Candidato 2");
				scanf(" %[^\n]s", nomep2);
                scanf(" %[^\n]s", votopresidente2);
			    break;
			}
			case 5: {
				system("cls");
				printf("Obrigado por usar nosso sistema de votação\nSaindo...\n");
				break;
			}
			system("cls");
             default: printf("Opção Invalida!\a\n\n");
			 break;
			
		}
        }
system("pause");
return 0;
}
  