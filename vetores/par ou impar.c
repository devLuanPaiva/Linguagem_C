int main(){
    int i, contpar, contimpar;
	int x[10];
	
	// Responsável por inicializar o vetor
    printf("Digite 10 numeros reais! ");
	for(i = 0; i < 10; i++){
		scanf("%d", &x[i]);
	}
	contpar = 0;
    contimpar = 0;
	for(i = 0; i < 10; i++){
		if(x[i] %2 == 0){
            contpar += 1; 
		}
        else contimpar += 1;
	}  
 
    printf("\n O vetor teve %i numeros pares", contpar);
    printf("\n O vetor teve %i numeros impares", contimpar);
	printf("\n\n");
	system("pause");
	return(0);
  }
