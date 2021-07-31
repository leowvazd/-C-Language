/*

Implemente uma função recursiva chamada multiplicacao_russa 
que recebe dois números inteiros e retorne a sua multiplicação. 
Utilize o método de multiplicação à Russa ou multiplicação Etíope. 
Uma descrição informal do método é:

Escreva os números A e B, que se deseja multiplicar na parte superior das colunas.
Dividir A por 2, sucessivamente, ignorando o resto até chegar à unidade, 
escrever os resultados da coluna A.
Multiplicar B por 2 tantas vezes quantas se haja dividido A por 2, 
escrever os resultados sucessivos na coluna B.
Somar todos os números da coluna B que estejam ao lado de 
um número ímpar da coluna A.
Sua função deve ter o seguinte protótipo:

    int multiplicacao_russa(int a, int b);
Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main e não use printf/puts nas funções submetidas.

Exemplos
Entrada

123 21
Saída

2583

*/

#include "multiplicacao.h"

int multiplicacao_russa(int a, int b)   {
    
    if (a == 0) {
        
        return 0;
    }
    
    if (a % 2 != 0) {
        
        return b + multiplicacao_russa(a/2, b*2);
    }
    
    return multiplicacao_russa(a/2, b*2);
}