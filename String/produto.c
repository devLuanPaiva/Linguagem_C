#include <stdio.h>
#include <string.h>


int main(){
	char s[10];
	char y[] = sim;
	char n[] = nao;
	char g[10], m[] = 'mulher', h[] ='homem';
	
	int i, n;

	printf("informe o numero de pessoas!\n");
	scanf("%d", &n);
	int gosta = 0;
	int naogosta = 0;
	printf("Qual seu sexo?\n");
	for(i=0; i<n; i++){
		scanf("%s", s);
	}
	printf("Voce gostou ou nao do produto");
	for(i=0; i<n; i++){
		scanf("%s", g);
	}
	for(i=0; i<n; i++){
		if(strcmp(s, m) == 0  && strcmp(g, y) == 0){
			gosta++;
		}
		else if(strcmp(s, h) = 0 && strcmp(g, n) == 0){
			naogosta++;
		}
	}
	float gostou;
	gostou = gosta/n;
	float naogostou;
	naogostou = naogosta/n;
	printf("A porcentagem de mulheres que gostaram e de: %.2f\n", gostou);
	printf("A porcentagem de homens que  nao gostaram e de: %.2f\n", naogostou);
	return 0;
	
	
}