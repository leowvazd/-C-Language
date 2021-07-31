/*

Implemente a função remover_duplicados, que recebe um vetor de números 
inteiros positivos organizados em ordem crescente. 
A função deve eliminar o mínimo de elementos para que o vetor não contenha nenhum 
valor positivo repetido. Ao eliminar um elemento, os elementos à direita
serão deslocados à esquerda e será adicionado um valor -1 na última posição.

Por exemplo, para uma lista com os elementos 1, 2, 2, 2, 3, 3, 4, 8, 10, 10, 
a função deixará a lista com os elementos 1, 2, 3, 4, 8, 10, -1, -1, -1, -1.

Observação: a função deve alterar o vetor passado como argumento para a função.

A função deve seguir o seguinte protótipo (qtd é a quantidade de elementos no vetor):

void remover_duplicados(int vetor[], int qtd);
Importante: submeta apenas a função. Não inclua o main e não use printf/puts.

Formato da entrada no caso de teste (que aparece ao avaliar a atividade):
7 (tamanho do vetor)
11 22 22 33 44 44 55 (elementos do vetor)

*/

#include "remover_duplicados.h"

void remover_duplicados(int vetor[], int qtd) {
    
    int a, b, c, d = 0;
    int vet2[qtd];
    
    for (a = 0; a < qtd; a++)   {
        
        vet2[a] = -1;
    }
    
    for (b = 0; b < qtd; b++)   {
        
        for (c = 0; c < d; c++) {
            
            if (vetor[b] == vet2[c])  {
                
                break;
            }
        }
        
        if (c==d)   {
            
            vet2[d] = vetor[b];
            d++;
        }
    }
    
    for(a = 0; a < qtd; a++ )   {
        
        vetor[a] = -1;
        vetor[a] = vet2[a];
    }
}