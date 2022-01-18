#include <stdio.h>

int main(){
    //!showMemory(start=65520)
    float x;   
    float y;
    float* px = &x;
    float* py = &y;
    printf("informe a coordenadas X e Y:\n");
    scanf("%f %f", px, py );

    if(*px == 0 && *py == 0){
        printf("Origem\n");
    }
    else if(*px > 0 && *py > 0){
       printf("Q1\n");
    }
	else if(*px < 0 && *py > 0){
        printf("Q2\n");
    }
    else if(*px < 0 && *py < 0 ){
        printf("Q3\n");
    }    
    else{
        printf("Q4\n");
    } 
    
    
 return 0;  
}