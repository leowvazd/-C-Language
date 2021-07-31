/*

Cria uma função que ordena os argumentos passados nos parâmetros.

A função deve ter o seguinte protótipo:

void ordena(int *a, int *b, int *c);

Os valores referenciados pelos parâmetros a, b e c devem ser trocados, 
caso necessário, para que a <= b <= c.

Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main. Não use printf/puts e headers adicionais 
(por exemplo, stdio.h e stdlib.h).

Formato do caso de teste: esse é o formato dos casos de teste que 
aparecem ao avaliar a atividade; não inclua impressão de dados no código, 
essa impressão é feita automaticamente pelo sistema de correção de acordo com 
o retorno da função submetida.

Entrada:
valores de *a, *b e *c
Saída:
valores de *a, *b e *c após a execução da função ordena.


Exemplo 1
Entrada
1 2 3
Saída

1 2 3
Exemplo 2
Entrada
2 3 1
Saída

1 2 3
Exemplo 3
Entrada
3 2 1
Saída

1 2 3


*/

void ordena(int *a, int *b, int *c) {
    
    int t;
    
    if (*a > *b)    {
        
        t = *a;
        *a = *b;
        *b = t;
    }
    
    if (*a > *c)    {
        
        t = *a;
        *a = *c;
        *c = t;
    }
    
    if (*b > *c)    {
        
        t = *b;
        *b = *c;
        *c = t;
    }
}