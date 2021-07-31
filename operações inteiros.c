/* 

Escreva uma função que recebe dois valores int, uma operação (char) 
e um ponteiro para int. Sua função deve realizar a operação indicada 
(+, -, *, /, %, |, &, ^) usando os dois valores inteiros recebidos e 
atribuir o resultado à memória apontada pelo ponteiro res.

Protótipo:

void operacao_int(int a, int b, char op, int* res);
Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main. Não use printf/puts/fprintf/fscanf e headers adicionais 
(por exemplo, stdio.h e stdlib.h).


Dica:
Os operadores bitwise (^, &, |) podem ser usados da mesma maneira que 
os operadores aritméticos (+, -, *, /, %), então:

Z = Y & X;
é uma operação válida para int.

Exemplos:
Entrada	Saída
2 3 +	5
2 3 -	-1
2 3 *	6
2 3 /	0
3 2 %	1
2 3 ^	1
2 3 |	3
2 3 &	2

*/

#include "op_ponteiro.h"

void operacao_int(int a, int b, char op, int* res) {
    
    if (op == '+')    {
        
        *res = a + b;
    }
    
    if (op == '-')    {
        
        *res = a - b;
    }
    
    if (op == '*')    {
        
        *res = a * b;
    }
    
    if (op == '/')    {
        
        *res = a / b;
    }
    
    if (op == '%')    {
        
        *res = a % b;
    }
    
    if (op == '^')    {
        
        *res = a ^ b;
    }
    
    if (op == '|')    {
        
        *res = a | b;
    }
    if (op == '&')    {
        
        *res = a & b;
    }
}