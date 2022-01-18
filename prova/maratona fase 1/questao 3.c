int main() {

int X,y ;
float preco, valor;
    scanf("%d %d",&X,&y);
    preco = 0;
    if (X==1) {
		valor = 4.00 * y;
		preco += valor;
	}

    else if (X==2){
        valor = 4.50 * y;
		preco += valor;
    }
    else if (X==3){
        valor = 5.00 * y;
		preco += valor;
	}
    else if (X==4){
        valor = 2.00 * y;
		preco += valor;
	}
    else if (X==5){
        valor = 1.50 * y;
		preco += valor;
    }
	printf("Total: R$ %.2f\n", preco);

return 0;

}
  