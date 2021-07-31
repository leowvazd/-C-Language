/* 

Implemente a função duplica_impares, que recebe um vetor de números inteiros. 
A função deve duplicar todos os números positivos ímpares. 
Por exemplo, para o vetor 1, 2, 3, 3, 4, -1, -1, -1, -1 o vetor seria modificado 
para 1, 1, 2, 3, 3, 3, 3, 4, -1. Para este exercício, considere que os valores -1 
são espaços livres no vetor. Assuma que haverá espaço suficiente para duplicar 
todos os ímpares.

Observação: a função deve alterar o vetor passado como argumento para a função.

A função deve seguir o seguinte protótipo (qtd é a quantidade de elementos no vetor):
void duplica_impares(int vetor[], int qtd);
Importante: submeta apenas a função. Não inclua o main e não use printf/puts.

Formato da entrada no caso de teste (que aparece ao avaliar a atividade):
11 (quantidade de elementos)
11 22 22 33 44 44 55 -1 -1 -1 -1 (elementos do vetor)

*/

#include "duplica_impares.h"
#include <stdio.h>

void duplica_impares(int vetor[], int qtd) {
    
    int i, j;
    
    scanf("%d ", &qtd);
    
    for (i=0;i<qtd;i++) {
        
        if (vetor[i]%2!=0) {
            
            for (j=qtd-1;j>i;j--)   {
                
                vetor[j] = vetor[j-1];
            }
            
            i=j+1;
        }
        
        if (vetor[i] == -1) {
            
            break;
        }
    }
}