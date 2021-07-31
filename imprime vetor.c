/* 

Implemente a função imprime_vetor, que recebe um vetor de números inteiros. 
A função deve imprimir o vetor em forma de triângulo. 
Por exemplo, o vetor 1, 2, 3, 4, 5, 6 seria impresso como:

1
2 3
4 5 6
Observação: há um caractere espaço separando cada número por linha, 
mas não há um caractere espaço ao final de cada linha (após o último número).

A função deve seguir o seguinte protótipo:

void imprime_vetor(int vetor[], int qtd);

Importante: submeta apenas a função. Não inclua o main.

*/

#include <stdio.h>
#include "imprime_vetor.h"

void imprime_vetor(int vetor[], int qtd) {
    
    int i, j;
    int k = 2;
    int l = 3;
    
    scanf("%d ",&qtd);
    
    for (i=0; i < qtd-1; i++)   {
 
        if (i == 0) {
            
            printf ("%d", vetor[0]);
            printf("\n");
            i++;
        }
        
        if (i == k)    {
            
            printf ("%d", vetor[i]);
            printf("\n");
            i++;
            k = k + l;
            l++;
        }

        printf ("%d ", vetor[i]);
    }
    
    printf ("%d", vetor[qtd-1]);
    printf ("\n");
}