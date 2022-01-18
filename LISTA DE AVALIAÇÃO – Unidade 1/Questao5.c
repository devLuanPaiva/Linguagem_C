#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Aluno: Luan Alves de Paiva
  Matricula: 2020022483
  Turma: 1
*/
#define MAX_VAGAS 9
#define MAX_TURMAS 3

typedef struct aluno Aluno;
struct aluno{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};

typedef struct turma Turma;
struct turma{
    char id; 
    int vagas;
    Aluno* alunos[MAX_VAGAS];
};


void menu(){
    printf("\n");
    printf("|========== MENU ESCOLAR ===============|\n");
	printf("|1 - Criar turma                        |\n");
	printf("|2 - Salvar turmas                      |\n");
	printf("|3 - Carregar turmas                    |\n");
	printf("|4 - Listar turmas                      |\n");
	printf("|5 - Matricular aluno                   |\n");
	printf("|6 - Lancar notas                       |\n");
	printf("|7 - Listar alunos                      |\n");
	printf("|8 - Sair                               |\n");
	printf("|=======================================|\n");
}	

Turma* cria_turma(char id){
 Turma* t = (Turma*) malloc(sizeof(Turma));
 t->id = id;

 int i;
 for(i = 0; i < MAX_VAGAS; i++)
    t->alunos[i] = NULL;

 return t;
}
/*A funcao acima e responsavel por percorrer o maximo de vagas e verificar
 se o id escolhido pelo usuario ja esta criado naquela vaga especifica. Caso nao esteja,
 o mesmo sera alocado na memoria*/
 
void CriarEnderencoPosicoes(Turma** t){
  int i;
  for(i = 0; i < MAX_TURMAS; i++){
    t[i] = (Turma*) malloc(sizeof(Turma*));
  }
}
/**/
void matricula_aluno(Turma* turma, int mat, char* nome){
 int i;
 for(i = 0; i < MAX_VAGAS; i++){
   if(turma->alunos[i] == NULL){
     turma->alunos[i] =(Aluno*) malloc(sizeof(Aluno));
     strcpy(turma->alunos[i]->nome, nome);
     turma->alunos[i]->mat = mat;
     turma->alunos[i]->notas[0] = 0.0;
     turma->alunos[i]->notas[1] = 0.0;
     turma->alunos[i]->notas[2] = 0.0;
     break;
   }
 }
}
/*A funcao acima vai rodar o maximo de vagas e verificar se na vaga especifica
 ja existe um aluno matriculado. Caso nao tenha nenhum, a vaga sera ocupada por
 uma matricula, onde a mesma possuira 3 notas zeradas.*/
 
float mediaAluno(float n1, float n2, float n3){
  return ((n1 + n2 + n3) / 3);
}
/*Essa funcao vai retornar a media do aluno*/
void lanca_notas(Turma* turma){
  int i;
  for(i = 0; i < MAX_VAGAS; i++){
   if(turma->alunos[i] != NULL){
     printf("Matricula: %d  Aluno: %s\n",turma->alunos[i]->mat,turma->alunos[i]->nome);
     printf("Digite a nota 1: ");
     scanf(" %f",&turma->alunos[i]->notas[0]);
     printf("Digite a nota 2: ");
     scanf(" %f",&turma->alunos[i]->notas[1]);
     printf("Digite a nota 3: ");
     scanf(" %f",&turma->alunos[i]->notas[2]);
     turma->alunos[i]->media = mediaAluno(turma->alunos[i]->notas[0],turma->alunos[i]->notas[1],turma->alunos[i]->notas[2]);
    }
  }
  /*Essa funcao vai ler as notas do aluno[i] e vai calcular a media*/
}

void imprime_alunos(Turma* turma){
    int i;
    for(i = 0; i < MAX_VAGAS; i++){
    if(turma->alunos[i] != NULL){
     printf("Matricula: %d\n",turma->alunos[i]->mat);
     printf("Nome: %s\n",turma->alunos[i]->nome);
     printf("Media: %.1f\n",turma->alunos[i]->media);
     printf("\n");
    }
  }
/*Essa funcao vai ler o id la no menu e em seguida vai imprimir todos os dados dos alunos matriculados nesse id*/
}
void qtdDisponivelTurma(Turma* turma){
  int cont = 0, i;
  for(i = 0; i < MAX_VAGAS;i++){
     if(turma->alunos[i] == NULL){
       cont++;
     }
  }
  turma->vagas = cont;
  cont = 0;
  printf("Turma %c – %d vagas disponíveis\n",turma->id,turma->vagas);
  /*Essa funcao vai rodar o maximo turmar e o maximo vagas afim de verificar
  se tem vagas disponiveis ou nao. Isso por meio da funcao NULL. Onde,
  se a turma->alunos[i] for igual NULL, quer dizer que ela esta vazia, com essa informacao,
  a variavel cont vai somar mais uma vaga.*/
}
void salvar_turma(Turma* turma){
	FILE *file = fopen("./turmas_salvas.txt", "a");
	int i;
    for(i = 0; i < MAX_VAGAS; i++){
       if(turma->alunos[i] != NULL){
	       fprintf(file,"Turma: %c\n", turma->id);
           fprintf(file,"Matricula: %d\n",turma->alunos[i]->mat);
           fprintf(file,"Nome: %s\n",turma->alunos[i]->nome);
           fprintf(file,"Media: %.1f\n",turma->alunos[i]->media);
           fflush(file);
    }
  }
  printf("Turma salva com sucesso!\n");
  fclose(file);
  /*Essa funcao vai salvar a turma especifica no arquivo de texto*/
}
void carregar_turma(Turma* turma){
	FILE *file = fopen("./turmas_salvas.txt", "a");
	int i;
    for(i = 0; i < MAX_VAGAS; i++){
       if(turma->alunos[i] != NULL){
       	   fscanf(file,"Turma: %c\n", &turma->id);
           fscanf(file,"Matricula: %d\n", &turma->alunos[i]->mat);
           fscanf(file,"Nome: %s\n", turma->alunos[i]->nome);
           fscanf(file,"Media: %f\n", &turma->alunos[i]->media);
       }
	}
	
	for(i = 0; i < MAX_VAGAS; i++){
       if(turma->alunos[i] != NULL){
       	   printf("Turma: %c\n", turma->id);
           printf("Matricula: %d\n",turma->alunos[i]->mat);
           printf("Nome: %s\n",turma->alunos[i]->nome);
           printf("Media: %.1f\n",turma->alunos[i]->media);
        }
	}
	fclose(file);
	/*Essa funcao vai ler as turmas salvas no arquvo e imprimilas no codigo*/
}

int main(void){
    Turma ** t = (Turma**) malloc(sizeof(Turma*)*5);
    CriarEnderencoPosicoes(t);
    int indiceTurmas = 0, opcao;
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidadesde\nmatricula, lancamento de notas e listagem de alunos\nAutor: Luan Alves de Paiva  Versao: 1.0\n");
    menu();
    scanf("%d",&opcao);
while(opcao != 8){
    if(opcao == 1){
        if(indiceTurmas < MAX_TURMAS){
            char idTurma;
            printf("Criando nova turma...\n");
            printf("Digite o id:\n");
            scanf(" %c",&idTurma);
            t[indiceTurmas] = cria_turma(idTurma);
            printf("Turma %c criada com sucesso!\n",idTurma);
            indiceTurmas++;
        }
		/*O primeiro if é sobre a opcao 1 do menu de cadastrar turmas,
		ja no segundo vai verificar se o indiceTurmas é menor que o maximo turmas, 
		enquanto for, ele vai ler um id do usuario e o mesmo vai ser retornado la pra funcao
		cria_turma e vai ser verificado para saber se ja esta cadastrado ou nao. Caso nao esteja,
		sera cadastrado e vai contar mais um cadastro para o indice turmas */
    }
    else if(opcao == 2){
		char idTurma;
        printf("Salvando Turma...\n");
        printf("Digite o id da turma: ");
        scanf(" %c",&idTurma);
        if(t[0]->id != idTurma && t[1]->id != idTurma && t[2]->id != idTurma){
             printf("Turma inexistente!\n");
        }
		else{
            int i;
            for(i = 0; i < MAX_TURMAS; i++){
                if(t[i]->id == idTurma){
                   salvar_turma(t[i]);
                }
            }
        }
		/*Nessa opcao, o if vai verificar se o id digitado pelo usuario existe ou nao.
		Caso nao exista, ele vai falar que a turma é inexistente. Mas caso exista, 
		ele vai retornar para a funcao salvar_turma e la vai salvar a turma no arquivo de texto*/
	}
	else if(opcao == 3){
        printf("Carregando Turmas...\n");
        int i;
        for(i = 0; i < MAX_TURMAS; i++){
           carregar_turma(t[i]);
        }
		/*Ja nessa opcao, ele vai retornar a funcao carregar_turma e vai imprimir todas as turmas salvas no arquivo*/
	}
  
    else if(opcao == 4){
        printf("Listando turmas...\n");
        int i;
        for(i = 0; i < MAX_TURMAS; i++){
            if(t[i] != NULL){
                qtdDisponivelTurma(t[i]);
            }
        }
		/*Essa opcao vai retornar para a funcao qtdDisponivelTurma e vai dizer quantas vagas tem em cada turma*/
    }
	
    else if(opcao == 5){
        int mat;
        char idTurma;
        char nomeAluno[20];
        printf("Matriculando aluno...\n");
        printf("Digite o id da turma: ");
        scanf(" %c",&idTurma);
        
        if(t[0]->id != idTurma && t[1]->id != idTurma && t[2]->id != idTurma){
            printf("Turma Ineexistente!\n");
        }
		else{
             printf("Digite a matricula: ");
             scanf(" %d",&mat);
             printf("Digite o nome: ");
             scanf(" %[^\n]s",nomeAluno);
            int i;
            for(i = 0; i < MAX_TURMAS; i++){
                if(t[i]->id == idTurma){
                    matricula_aluno(t[i],mat,nomeAluno);
                }
            } 
            printf("Aluno matriculado com sucesso!\n");     
        }
		/*Essa opcao vai ler o id, matricula e nome do aluno. Em seguida vai verificar se o id
		esta cadastrado ou nao, se nao tiver, vai retornar um printf informando que a inexistencia dele.
		Mas se tiver, ele vai retornar para a funcao matricula_aluno e vai matricular os dados 
		desse aluno naquele id*/
    }
    else if(opcao == 6){
        char idTurma;
        printf("Lancando notas...\n");
        printf("Digite o id da turma: ");
        scanf(" %c",&idTurma);
        if(t[0]->id != idTurma && t[1]->id != idTurma && t[2]->id != idTurma){
            printf("Turma inexistente!\n");
        }
		else{
            int i;
            for(i = 0; i < MAX_TURMAS; i++){
                if(t[i]->id == idTurma){
                    lanca_notas(t[i]);
                }
            }
        }
		/*Essa opcao vai ler o id do usuario e verificar se ele existe ou nao e caso exista,
		vai retornara funcao lanca_notas e la, a mesma vai pedir as notas dos alunos naquele id
		para  calcular a media*/
    }
    else if(opcao == 7){
        char idTurma;
        printf("Listando alunos...\n");
        printf("Digite o id da turma: ");
        scanf(" %c",&idTurma);
        if(t[0]->id != idTurma && t[1]->id != idTurma && t[2]->id != idTurma){
            printf("Turma inexistente!\n");
        }
		else{
            int i;
            for(i = 0; i < MAX_TURMAS; i++){
                if(t[i]->id == idTurma){
                    imprime_alunos(t[i]);
                }
            }
        }
		/*Essa opcao vai ler o id do usuario e verificar se ele existe ou nao e caso exista,
		vai retornara funcao imprime_alunos e la vai imprimir os dados dos alunos do id*/
    }
    else if(opcao < 0 || opcao > 8){
            printf("opcao invalida!!\n");
        }
    menu();
    scanf("%d",&opcao);
}
  
  printf("Obrigado por usar este programa!\n");
  return 0;
}