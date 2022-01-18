#include <stdio.h>
#include <string.h>
    //alunos de uma escola

int alunos;
typedef struct {
	float nota1;
	float ultimaChance;
}recuperacao;
typedef struct {
    char nome[100];
    int matricula;
    int serie;
}identificacao;
typedef struct {
    float bimestre1;
    float bimestre2;
    float bimestre3;
    float bimestre4;
    float media;
	identificacao ide;
    recuperacao re;
}notas;
void  decisao(notas *pno){
    FILE *file = fopen("./estudantes.txt", "r");
	int i;
	char AlunoAprovado[100];
	char AlunoRecuperacao[100];
	for(i=0; i< alunos; i++){
        fscanf(file, "%f %f %f %f", &(pno+i)->bimestre1, &(pno+i)->bimestre2, &(pno+i)->bimestre3, &(pno+i)->bimestre4);   	
	    (pno+i)->media= ((pno+i)->bimestre1 + (pno+i)->bimestre2 + (pno+i)->bimestre3 + (pno+i)->bimestre4)/4;
		printf("A media do aluno %s eh %.2f",(pno+i)->ide.nome, (pno+i)->media);
	}
	fclose(file);
	for(i=0; i< alunos; i++){
		if((pno+i)->media >= 7){
			strcpy(AlunoAprovado, (pno+i)->ide.nome);
			printf("O Aluno %s passou!\n", AlunoAprovado);
		}
		else{
			strcpy(AlunoRecuperacao, (pno+i)->ide.nome);
			printf("O aluno %s foi para a recuperacao!\n", AlunoRecuperacao);
			printf("Digite a nota da recuperacao \n");
			scanf("%f", &(pno+i)->re.nota1);
			if((pno+i)->re.nota1 > 6){
				printf("Aprovado!\n");
			}
			else printf("Reprovado!\n");
		}
	}
}	
void menu(){
	printf("|========== Escolha uma opcao ==========|\n");
	printf("|1 - Procurar                        	|\n");
	printf("|2 - Emitir Medias                      |\n");
	printf("|3 - Sair                               |\n");
	printf("|=======================================|\n");
}

int pesquisar(int matricula, int alunos,  notas no[]){
	int i = 0;
    int f = alunos - 1;
    while(i <= f){
		int meio = (i + f)/2;
		if(no[meio].ide.matricula == matricula){
			return meio;
		}
		else if(no[meio].ide.matricula < matricula){
			i = meio + 1;
		}
		else {
			f = meio - 1;
		}
	}
	return -1;
}



int main(){
    FILE *file = fopen("./estudantes.txt", "a");
    printf("informe a quantidade de alunos\n");
    scanf("%d", &alunos);
	notas no[alunos];
	notas *pno;
	pno = no;
    printf("nome, matricula e serie\n");
    int i;
    for(i = 0; i < alunos ; i ++){
        scanf("%s %d %d", (pno+i)->ide.nome, &(pno+i)->ide.matricula, &(pno+i)->ide.serie);
        fprintf(file, "%s %d %d \n", (pno+i)->ide.nome, (pno+i)->ide.matricula, (pno+i)->ide.serie);
    }
	printf("digite as notas de cada bimestre dos alunos\n");
	for(i = 0; i < alunos ; i ++){
        scanf("%f %f %f %f", &(pno+i)->bimestre1, &(pno+i)->bimestre2, &(pno+i)->bimestre3, &(pno+i)->bimestre4);
        fprintf(file, "%f %f %f %f", (pno+i)->bimestre1, (pno+i)->bimestre2, (pno+i)->bimestre3, (pno+i)->bimestre4);   
	    printf("%.2f %.2f %.2f %.2f\n ", (pno+i)->bimestre1, (pno+i)->bimestre2, (pno+i)->bimestre3, (pno+i)->bimestre4 );
	     
    }
    fclose(file);
	
    int op;
    menu();
	scanf("%d", &op);
	while(op != 3){
		if (op == 1){
			printf("informe a matricula\n");
			scanf("%d", &(pno)->ide.matricula);
			int idx = pesquisar((pno)->ide.matricula, alunos, no);
			if(idx != -1){
				printf("Nome: %s\n", no[idx].ide.nome);
				printf("Serie: %d\n", no[idx].ide.serie);
				printf("Nota 1: %.2f\n", no[idx].bimestre1);
				printf("Nota 2: %.2f\n", no[idx].bimestre2);
				printf("Nota 3: %.2f\n", no[idx].bimestre3);
				printf("Nota 4: %.2f\n", no[idx].bimestre4);
				printf("Media: %.2f\n", no[idx].media);
			}
		}
		else if(op == 2){
			int i, j;
			for (i=0; i<alunos; i++){
				int imaior = i;
				for(j = i + 1; j < alunos; j++){
					if(no[j].media > no[imaior].media){
						imaior = j;
					}
			    }
			    notas temp = no[i];
				no[i] = no[imaior];
				no[imaior] = temp;
				
			}
			printf("Tabela de Medias\n");
			for(i=0; i< alunos; i++){
				printf("Aluno %s: Media %.2f\n", no[i].ide.nome, no[i].media);
			}
			printf("\n");
		}
		menu();
		scanf("%d", &op);	
	}
	printf("programa finalizado");
	decisao(pno);
    return 0;
}

#include <stdio.h>
#include <string.h>
    //alunos de uma escola

int alunos;
typedef struct {
	float nota1;
	float ultimaChance;
}recuperacao;
typedef struct {
    char nome[100];
    int matricula;
    int serie;
}identificacao;
typedef struct {
      float bimestre1;
      float bimestre2;
      float bimestre3;
      float bimestre4;
      float media;
       identificacao ide;
       recuperacao re;
}notas;
void  decisao(notas *pno){
    FILE *file = fopen("./estudantes.txt", "r");
	int i;
	char AlunoAprovado[100];
	char AlunoRecuperacao[100];
	for(i=0; i< alunos; i++){
        fscanf(file, "%f %f %f %f", &(pno+i)->bimestre1, &(pno+i)->bimestre2, &(pno+i)->bimestre3, &(pno+i)->bimestre4);   	
	    (pno+i)->media= ((pno+i)->bimestre1 + (pno+i)->bimestre2 + (pno+i)->bimestre3 + (pno+i)->bimestre4)/4;
		printf("A media do aluno %s eh %.2f",(pno+i)->ide.nome, (pno+i)->media);
	}
	fclose(file);
	for(i=0; i< alunos; i++){
		if((pno+i)->media >= 7){
			strcpy(AlunoAprovado, (pno+i)->ide.nome);
			printf("O Aluno %s passou!\n", AlunoAprovado);
		}
		else{
			strcpy(AlunoRecuperacao, (pno+i)->ide.nome);
			printf("O aluno %s foi para a recuperacao!\n", AlunoRecuperacao);
			printf("Digite a nota da recuperacao \n");
			scanf("%f", &(pno+i)->re.nota1);
			if((pno+i)->re.nota1 > 6){
				printf("Aprovado!\n");
			}
			else printf("Reprovado!\n");
		}
	}
}	
void menu(){
	printf("|========== Escolha uma opcao ==========|\n");
	printf("|1 - Procurar                        	|\n");
	printf("|2 - Sair                               |\n");
	printf("|=======================================|\n");
}

int pesquisar(int matricula, int alunos,  notas no[]){
	int i = 0;
    int f = alunos - 1;
    while(i <= f){
		int meio = (i + f)/2;
		if(no[meio].ide.matricula == matricula){
			return meio;
		}
		else if(no[meio].ide.matricula < matricula){
			i = meio + 1;
		}
		else {
			f = meio - 1;
		}
	}
	return -1;
}



int main(){
    FILE *file = fopen("./estudantes.txt", "a");
    printf("informe a quantidade de alunos\n");
    scanf("%d", &alunos);
	notas no[alunos];
	notas *pno;
	pno = no;
    printf("nome, matricula e serie\n");
    int i;
    for(i = 0; i < alunos ; i ++){
        scanf("%s %d %d", (pno+i)->ide.nome, &(pno+i)->ide.matricula, &(pno+i)->ide.serie);
        fprintf(file, "%s %d %d \n", (pno+i)->ide.nome, (pno+i)->ide.matricula, (pno+i)->ide.serie);
    }
	printf("digite as notas de cada bimestre dos alunos\n");
	for(i = 0; i < alunos ; i ++){
         scanf("%f %f %f %f", &(pno+i)->bimestre1, &(pno+i)->bimestre2, &(pno+i)->bimestre3, &(pno+i)->bimestre4);
         fprintf(file, "%f %f %f %f", (pno+i)->bimestre1, (pno+i)->bimestre2, (pno+i)->bimestre3, (pno+i)->bimestre4);   
	     printf("%.2f %.2f %.2f %.2f\n ", (pno+i)->bimestre1, (pno+i)->bimestre2, (pno+i)->bimestre3, (pno+i)->bimestre4 );
	     
    }
    fclose(file);
	
    int op;
    menu();
	scanf("%d", &op);
	while(op !=2){
		if (op == 1){
			printf("informe a matricula\n");
			scanf("%d", &(pno)->ide.matricula);
			int idx = pesquisar((pno)->ide.matricula, alunos, no);
			if(idx != -1){
				printf("Nome: %s\n", no[idx].ide.nome);
				printf("Serie: %d\n", no[idx].ide.serie);
				printf("Nota 1: %.2f\n", no[idx].bimestre1);
				printf("Nota 2: %.2f\n", no[idx].bimestre2);
				printf("Nota 3: %.2f\n", no[idx].bimestre3);
				printf("Nota 4: %.2f\n", no[idx].bimestre4);
				printf("Media: %.2f\n", no[idx].media);
			}
		}
		menu();
		scanf("%d", &op);	
	}
	printf("programa finalizado");
	decisao(pno);
    return 0;
}
