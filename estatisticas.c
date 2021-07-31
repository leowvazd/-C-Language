/* 

Faça um programa que leia um inteiro N≥1 da entrada padrão. 
Na sequência leia N números reais. 
Seu programa deve imprimir, com duas casas decimais e nessa ordem:

1. menor valor;
2. maior valor;
3. média.

Seu programa não pode armazenar os valores em um vetor!

Exemplos
Entrada:
5
1.2 2.3 3.4 4.5 6.0
Saída:
1.20
6.00
3.48

*/


#include <stdio.h>

int main()
{
    double menor = 999999999;
    double maior = -999999999;
    double media = 0;
    
    int n;
    scanf("%d",&n);
    
    int i;
    double numero;
    for (i=0; i<n; i++){
        scanf("%lf",&numero);
        
        media = media+numero;
        
        if (numero>maior){
            maior=numero;
        }
        
        if (numero<menor){
            menor=numero;
        }
    }
    
    media= media/n;
    
    printf("%.2lf\n%.2lf\n%.2lf\n",menor,maior,media);
    
    return 0;
}