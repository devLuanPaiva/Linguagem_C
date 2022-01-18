int main(){
	float n1, n2, n3, media;
	float mf, mp, af;
			printf("\n");
		printf("Digite a nota da primeira unidade:");
		scanf("%f", &n1);
		printf("Digite a nota da segunda unidade: ");
		scanf("%f", &n2);
		printf("Digite a nota da terceira unidade:");
		scanf("%f", &n3);
		media = (n1 + n2 + n3) /3;
		
	    if(media >= 7) {
			printf("Aprovado");
		}
		else if(media >= 3.5 ){
			printf("recuperacao");
			printf("digite sua nota da avaliacao final : ");
			scanf("%f %f", &af ,&mp);
			mf = ((mp * 6) + (af * 4))/10;
		    if(mf >= 5){
			    printf("Aprovado");
		    } 
			else printf("Reprovado");			
		}
		else printf("Reprovado");
		

return 0;
}		