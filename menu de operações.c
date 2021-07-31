/*

Faça um programa conforme descrito a seguir:

 1.    Leia um código de operação:

·         1: soma dois números (a + b)

·         2: soma três números (a + b + c)

·         3: multiplicação de dois números (a * b)

·         0: sair

2.    Se o usuário digitar a operação sair, o programa mostra o menor 
resultado obtido e encerra;

3.    Caso contrário, solicitará a entrada dos números (a e b ou a, b e  c) e 
imprimirá o resultado da operação (soma ou multiplicação); 
Após isso, o programa volta ao item 1 (ler código de operação).

Observação: inclua uma quebra de linha após a impressão do resultado.

Exemplo 1:
Entrada
Saída
1
300
207
0
507
507

Exemplo 2:
Entrada
Saída
1
-2
1
3
2
90
2
80
2
5
0
-1
180
87
-1

*/

#include <stdio.h>

int
main ()
{
  int i = 1;
  int menu = 1;
  int a = 0;
  int b = 0;
  int c = 0;
  int menor = 999999999;
  int resultado = 0;

  while (menu != 0)
    {
    scanf ("%d",&menu);
    
    switch(menu){
        case 1: {
            scanf ("%d",&a);
            scanf ("%d",&b);
            resultado = a+b;
            printf ("%.d\n",resultado);
            break;
        }
        
        case 2: {
            scanf ("%d",&a);
            scanf ("%d",&b);
            scanf ("%d",&c);
            resultado = a+b+c;
            printf ("%d\n",resultado);
            break;
        }
        
        case 3: {
            scanf ("%d",&a);
            scanf ("%d",&b);
            resultado = a*b;
            printf ("%d\n",resultado);
            break;
        }
        
        case 0: {
            break;
        }
    }
        
    if (resultado<menor) {
        menor = resultado;
    }
        
    if (menu==0) {
        break;
    }
        
    }
    
  printf ("\n%d",menor);
  return 0;
  
}
