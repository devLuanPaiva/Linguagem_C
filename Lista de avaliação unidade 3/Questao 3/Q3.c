#include <stdio.h>
#include <string.h>

/*
NOME: Luan Alves de Paiva
MATRICULA: 2020022483
*/
#define Tamanho_Max 10   //Deine o tamanho da pilha
typedef char palindromo; // Define o tipo da pilha

palindromo pa[Tamanho_Max]; //Define 
int Reverter = -1; /*Essa variavel global vai ser utilizada abaixo para fazer o 
processo de reversao para assim, poder inverter a palavra colocando a ultima letra 
no lugar da primeira e assim por diante*/

void pop( palindromo *palavra ){
    if( Reverter == -1 ) {
        printf("Pilha vazia\n");
	}
	else {
        *palavra = pa[Reverter];
        Reverter--;
    }
	
	/*Essa função pop vai verificar se a pilha esta vazia, caso nao esteja,
	vai remove os elementos da mesma. Em outras palavras, ela vai olhar se a pilha tem
	alguma palavra, caso tenha, ela vai retirar caractere por caractere e vai adicionar na outra
	funcao abaixo de forma invertida.*/
}  
void push( palindromo palavra ){
    if( Reverter == Tamanho_Max){
        printf("Pilha cheia\n");
 	}       
    else {
        Reverter++;   
        pa[Reverter] = palavra; 
    }
	/*Como dito na funcao anterior, essa funcao push vai adicionar a uma nova variavel
	os caracteres da palavra anterior so que de forma invertida. Essa variavel vai ser denominada
	de copiaPalindroma.*/
} 

int main(void){
    char palavraOriginal[Tamanho_Max], copiaPalindroma[Tamanho_Max];  
	int i, tamanho;
	printf("Digite uma palavra para verificar-mos se e palindroma\n");      
	scanf("%s", palavraOriginal);

    tamanho = strlen(palavraOriginal);
	/*Essa funcao strlen anterior vai servir para somar os caracteres da palavra
	e assim dar valor a variavel tamanho que sera usada nos proximos for*/
    for( i = 0; i < tamanho; i++ ){
        push(palavraOriginal[i]);
		/*Esse for vai percorrer toda a palavra e vai enviar ela para a funcao push
		onde vai fazer aquele processo todo citado anterioemente*/
	}	
    for( i = 0; i < tamanho; i++ ){
        pop( &copiaPalindroma[i]);
		/*Esse for vai ler toda a palavra invertida da funcao pop */
	}	
	copiaPalindroma[tamanho] = '\0';
		// esse '\0' identifica o fim da string

    printf("Frase Invertida: %s", copiaPalindroma);
	
    //O proximo if vai verificar se as duas string sao iguais ou nao
    if(strcmp(palavraOriginal, copiaPalindroma) == 0){
		printf("\nResultado: Eh palindroma sim!\n");
	}
	else{
		printf("\nResultado: Nao eh palindroma!\n");
	}

    return 0;
    
}   

