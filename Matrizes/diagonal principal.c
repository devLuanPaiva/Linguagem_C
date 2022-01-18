#include <stdio.h>
#include <math.h>

int main() {
    int a[5][5], i, j;
     
    a[i][j] = 0;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if( i == j){
                a[i][j] = 1;
            } 
            else if (i > j) {
				a[i][j] = -2;
			}
			else if (i < j) {
				a[i][j] = 2;
			}
                printf("%d ", a[i][j]);
        }
        putchar('\n');
    }  
   
    return 0;
}
 
 