/*

Considere o superfatorial de um número N 
como o produto dos N primeiros fatoriais de N. Assim, o superfatorial de 4 é:

superfatorial(4) = 1! * 2! * 3! * 4! = 288

Faça uma função recursiva que receba um número inteiro positivo N 
e retorne o superfatorial desse número.

A função deve ter o seguinte protótipo:

long superfatorial(int n);

Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main e não use printf/puts nas funções submetidas.

Exemplos
288 == superfatorial(4)

*/

#include "superfatorial.h"
#include <stdio.h>

long superfatorial(int n)   {
    
    int fatorial = 1;
    int i;
    
    if (n == 0) {
        
        return 1;
    }
    
    else    {
        
        for (i = 1; i <=n; i++) {
            
            fatorial = fatorial * i;
        }
    }
    
    return (fatorial * superfatorial(n-1));
}