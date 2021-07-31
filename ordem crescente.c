/* 

Faça um programa que leia um inteiro N da entrada padrão. 
Na sequência leia N números inteiros e imprima SIM 
se os números estão em ordem crescente e NAO caso contrário. 
Você não deve utilizar vetores para resolver esse exercício.

Obs: não esqueça de imprimir a quebra de linha após o SIM e NÃO.

ENTRADA		SAÍDA
4		SIM
1 3 7 9	 
ENTRADA		SAÍDA
4		NAO
1 8 7 9	 

*/

#include <stdio.h>

int main()
{
    int quantidade, digitado = 0;
    float num, final;
    scanf("%d", &quantidade);
    int crescente = 1;
    while(digitado < quantidade)
        {
        scanf("%f", &num);
        if (final >= num && digitado != 0)
        {
            crescente = 0; 
        }
        final = num;
        digitado++;
    }
    if(crescente == 1) 
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
    return 0;
}