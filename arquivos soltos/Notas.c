#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define NUMERO_DE_ALUNOS 4
#define NUMERO_DE_NOTAS 4
#define TAMANHO_MAXIMO_DO_NOME 500

void menu (void);
int fatorial(int);
int main()
{
	setlocale(LC_ALL,"portuguese");
	char nome[NUMERO_DE_ALUNOS][TAMANHO_MAXIMO_DO_NOME];
	int i,op, continua;
	int n1,n2,n3,mp, p1,p2,p3;
	
	for(i=0;i<NUMERO_DE_ALUNOS;i++)
  {
    fflush(stdin);

    printf("\nInforme o nome do aluno %d: ", i+1);
    fgets(nome[i], TAMANHO_MAXIMO_DO_NOME, stdin);
     printf("\nInforme o curso do aluno %d: ", i+1);
    fgets(nome[i], TAMANHO_MAXIMO_DO_NOME, stdin);
    }
	system("cls");
	
	while(1)
	{
		menu();
		printf("\n\n\nEscolha uma Opção :\n");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
			printf("\n");
		printf("Digite o primeiro nota:");
		scanf("%d", &n1);
		printf("Digite o segunda nota:");
		scanf("%d", &n2);
		printf("Digite a terceira nota:");
		scanf("%d", &n3);
		printf("Media: %f", (float)(n1 + n2 + n3) /3);
				
			break;
		case 2:
			printf("\n");
		printf("Digite o primeiro nota:");
		scanf("%d", &n1);
		printf("Digite o segunda nota:");
		scanf("%d", &n2);
		printf("Digite a terceira nota:");
		scanf("%d", &n3);
		printf("\n");
		printf("Digite o primeiro peso:");
		scanf("%d", &p1);
		printf("Digite o segundo peso:");
		scanf("%d", &p2);
		printf("Digite o terceirapeso:");
		scanf("%d", &p3);
	    mp=((n1*p1)+(n2*p2)+(n3*p3))/(p1+p2+p3);
		printf("\nA Média ponderada é de: %i",mp);
		
		
			break;
		
		
		default:
			printf("\n\n\n Operação invalida!!!\n\n\n");
			break;
		}
		printf("\n\n\n\nDeseja continuar usando o programa ? (0)sim (1)não\n\n");
		scanf("%d",&continua);
		if(continua==1)
		{
			break;
		}else
		{
			system("cls");
		}
		
	}
	return 0;
}
void menu (void)
{
	printf("-------------------------------------------------------------------");
	printf("\n\n");
	printf("            Escolha uma opção ");
	printf("\n\n");
	printf("-------------------------------------------------------------------");
	printf("\n");
	printf("(1)Aritmética\n");
	printf("(2)Ponderada\n");
	
	
}
int fatorial(int fat)
{
	int resp=1,i1;
	for(i1=1;i1<=fat;i1++)
	{
		resp*=i1;
	}	
	return(resp);
}