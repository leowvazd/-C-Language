/* 

Recebendo como entrada dois valores inteiros, 
calcular a quantidade de números primos entre esses dois valores 
(incluindo eles).

*/

#include <stdio.h>
#include <stdlib.h>
 
void main() {
    
    int menor;
    int maior;
    int i;
    int j;
    int x;
    int trocar;
    int resultado = 0;
    
    scanf("%d %d", &menor, &maior);
    
    trocar = menor;
    menor = menor -1;
    
    if (menor%2==0) {
        
        menor++;
        
    }
    
    for (i=menor;i<=maior;i=i+2)  {
        
        x=0;
        
        for (j=2;j<=i/2;j++)
        {
            if ((i%j)==0)
            {
                x=1;
                break;
            }
        }
        
        if (x==0)
        {
            
            resultado++;
            
        }
    }
    
    printf("%d\n",resultado);
    
}