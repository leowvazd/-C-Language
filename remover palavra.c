/*

Implemente uma função que receba uma string (vetor de caracteres) contendo uma 
frase e remova a palavra de índice i do vetor passado no parâmetro frase da função. 
Considere que a primeira palavra tem índice 1. Ao remover uma palavra, é necessário 
remover caracteres espaço adjacentes à palavra removida. 
A string de entrada possui no máximo 100 caracteres e pode conter pontuação.

Importante: submeta apenas a função. Não use variáveis globais. 
Não inclua o main. Não use printf/puts e não use string.h.

Protótipo da função:

void remover_palavra(int i, char frase[]);

Exemplo de teste 1:

Entrada:
3 (índice da palavra)
Primeira frase de teste (frase de entrada)
Saída:
Primeira frase teste

Exemplo de teste 2:

Entrada:
2 (índice da palavra)
Neste exercicio, a funcao envolve uso de string. (frase de entrada)
Saída:

Neste, a funcao envolve uso de string.

*/

#include "remover_palavra.h"
#include <stdio.h>

void remover_palavra(int i, char frase[]) {
    
    int a, b, c, d, e, f;
    
    a = 0;
    b = 0;
    
    while   (frase[a] != '\0')  {
        
        if  (frase[a] == ' ')   {
            
            b++;
        }
        
        if  (b == i-1)    {
            
            d = a;
            
            for (e = d + 1; e < 100; e++)  {
                
                if  (!(frase[e] >= '0' && frase[e] <= '9'))   {
                    
                    if(!(frase[e] >= 'a' && frase[e] <= 'z'))   {
                        
                        if(!(frase[e] >= 'A' && frase[e] <= 'Z'))   {
                            
                            c = e;
                            break;
                        }
                    }
                }
            }
            
            if (b == 0)   {
                
                for(f = 0; f < 100; f++)  {
                    
                    frase[f] = frase[f+1];
                }
            }
            
            for (f = d; f < 100; f++) {
                
                frase[f]= frase[c];
                c++;
            }
            
            break;
        }
        
        a++;
    }
}