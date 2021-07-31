/* 

Implemente um programa que lê um inteiro positivo n, 
e verifique se n é igual ao produto de 3 números inteiros consecutivos. 
Por exemplo, 120 atende ao critério, pois 4x5x6 = 120. Se atender, imprima "SIM", 
caso contrário, imprima "NAO" (e coloque uma quebra de linha depois).

*/

#include <stdio.h>

int main(){
    
int n, i, a;
int contador = 10;
int b =0;

scanf("%d",&n);

for (i = 1; i <= contador; ++i)
{
    a = i*(i+1)*(i+2);
    
    if(a==n)
    {
        b = 1;
    }
}

if (b==0)
{
    printf("NAO\n");
}

else
{
    printf("SIM\n");
}

return 0;
}