/*

Escreva uma função que recebe um vetor de inteiros de comprimento n e 
retorne o valor de algumas estatísticas sobre esses números. 
O retorno será realizado por parâmetros passados por referência.

Protótipo da função:
void estatisticas_vetor(int vetor[], int n, int *min, int *max, int *soma, double *media, double *desvio);
Valores que devem ser retornados:

min: menor valor
max: maior valor
soma: soma dos valores
media: média dos valores
desvio: desvio padrão (std) dos valores, conforme fórmula a seguir, em que xi é o valor i e n é a quantidade de valores:
std=1n∑i=√1/n(xi−média)^2√

Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main. Não use printf/puts/fprintf/fscanf e 
headers adicionais (por exemplo, stdio.h e stdlib.h). 
Neste exercício, pode usar a função sqrt de math.h.



Formato do caso de teste: esse é o formato dos casos de teste que aparecem 
ao avaliar a atividade; não inclua impressão de dados no código, 
essa impressão é feita automaticamente pelo sistema de correção 
de acordo com o retorno da função submetida.

Entrada:
quantidade de itens no vetor
itens do vetor
Saída:
valores das estatísticas após executar a função estatisticas_vetor

*/

#include "vetor.h"
#include <math.h>

void estatisticas_vetor(int vetor[], int n, int *min, int *max, int *soma, double *media, double *desvio) {
    
    *soma = vetor[0];
    *min = vetor[0];
    *max = vetor[0];
    
    int i;
    
    for (i = 1; i < n; i++) {
        
        *soma = *soma + vetor[i];
        
        if (vetor[i] < *min)   {
            
            *min = vetor[i];
        }
        
        if (vetor[i] > *max)   {
            
            *max = vetor[i];
        }
    }
    
    *media = *soma/((double)n);
    
    // ERRO: desvio = 0;
    *desvio = 0; // ERRO CORRIGIDO!
    
    for (i = 0; i < n; i++) {
        
        *desvio = *desvio + ((vetor[i] - *media) * (vetor[i] - *media));
    }
    
    // ERRO: *desvio = sqrt(*soma/n);
    *desvio = sqrt(*desvio/n); // ERRO CORRIGIDO!
}
