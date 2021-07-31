/*

Faça um programa que leia uma frase (no máximo 100 caracteres) 
e imprima a quantidade de palavras na frase lida.

Entrada:
Este eh um teste.

Saída:
4

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    
    char frase[100];
    int i = 0;
    int palavra = 1;
	
    fgets(frase, sizeof frase, stdin);	

    while(frase[i]!='\0')   {
        
        if(frase[i]=='\n'||frase[i]=='\t'||frase[i]==' ')   {
            
            palavra++;
        }

        i++;
    }

    printf("%d ", palavra-1);
}