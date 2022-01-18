#include <stdio.h>
typedef struct{
	int mat;
	char nome[10];
	float n1;
	float n2;
	float n3;
}estudante;

void ler(estudante *pe){
	scanf("%d %s %f %f %f", &pe->mat, pe->nome, &pe->n1, &pe->n2, &pe->n3);
	
}
void menu(){
	printf("|========== Escolha uma opcao ==========|\n");
	printf("|1 - Procurar                        	|\n");
	printf("|2 - Sair                               |\n");
	printf("|=======================================|\n");	
}

int pesquisaBrinaria(int mat, int n, estudante v[]){
    int i = 0;
    int f = n - 1;
    while(i <= f){
		int meio = (i + f)/2;
		if(v[meio].mat == mat){
			return meio;
		}
		else if(v[meio].mat < mat){
			i = meio + 1;
		}
		else {
			f = meio - 1;
		}
	}
	return -1;	
}
int main(){
	int n, i;
	printf("Informe a quantodade de estudantes\n");
	scanf("%d", &n);
	estudante v[n];
	for(i=0; i<n; i++){
		ler(&v[i]);
	}
	int op;
	menu();
	scanf("%d", &op);
	while(op != 2){
		if(op == 1){
			int mat;
			printf("Informe a matricula");
			scanf("%d", &mat);
			int idx = pesquisaBrinaria(mat, n, v);
			if(idx != -1){
				v[idx].n3 = v[idx].n3 +1;
				float media = (v[idx].n1*2 + v[idx].n2 * 3 + v[idx].n3 * 4)/9;
				printf("%s: %.2f\n", v[idx].nome, media);
			}
		}
	    int op;
	    menu();	
	}
	printf("Programa finalizado!");
	return 0;
}