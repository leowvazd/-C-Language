/*

Implemente a função logaritmo, que recebe um valor x e um valor n. 
A função deve calcular o valor de ln(x) usando n termos da série Maclaurin, 
conforme fórmula a seguir. 

O valor de x está na faixa (0, 2]. Nesta fórmula, x deve estar na faixa (-1, +1].

Observação: não utilize math.h e não use vetor.

A função deve seguir o seguinte protótipo:

double logaritmo(double x, int n);

Importante: submeta apenas a função. 
Não inclua o main, não use printf/puts, math.h e vetor.

*/

#include "logaritmo.h"

double logaritmo(double x, int n) {
    
    double t=-1;
    double soma=0;
    double a = 1;
    double i;
    double f;
    
    x=x-1;
    
    for (i=0;i<n;i++)   {
        
        t=t*-1;
        f=1/(i+1);
        a=a*x;
        soma=(t*f*a)+soma;
    }
    
    return soma;
}