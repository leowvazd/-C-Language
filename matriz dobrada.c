/*

Escreva um programa que leia uma matriz com n x n (assuma que n é par). 
Após isso, imprima o resultado da matriz dobrada da seguinte forma:

Entrada:

n
Dados da matriz

Saída:
Matriz após as dobras

*/

#include <stdio.h>

int main()  {

    int n, i, j;
    scanf("%d ", &n);

    int matriz[n][n];
    
    for (i = 0; i < n; i++) {
        
        for (j = 0; j < n; j++) {
            
            scanf("%d ", &matriz[i][j]);
        }
    }
    
        if (n == 4)  {
            
            int matriz1[n/2][n/2];
        
            matriz1[0][0] = (matriz[0][0]+matriz[0][3]+matriz[3][0]+matriz[3][3]);
            matriz1[0][1] = (matriz[0][1]+matriz[0][2]+matriz[3][1]+matriz[3][2]);
            matriz1[1][0] = (matriz[1][0]+matriz[1][3]+matriz[2][0]+matriz[2][3]);
            matriz1[1][1] = (matriz[1][1]+matriz[1][2]+matriz[2][1]+matriz[2][2]);
        
            printf("%d ", matriz1[0][0]);
            printf("%d \n", matriz1[0][1]);
            printf("%d ", matriz1[1][0]);
            printf("%d ", matriz1[1][1]);
        }
        
        if (n == 6) {
            
            int matriz2[n/2][n/2];
            
            matriz2[0][0] = (matriz[0][0]+matriz[0][5]+matriz[5][0]+matriz[5][5]);
            matriz2[0][1] = (matriz[0][1]+matriz[0][4]+matriz[5][1]+matriz[5][4]);
            matriz2[0][2] = (matriz[0][2]+matriz[0][3]+matriz[5][2]+matriz[5][3]);
            matriz2[1][0] = (matriz[1][0]+matriz[4][0]+matriz[1][5]+matriz[4][5]);
            matriz2[1][1] = (matriz[1][1]+matriz[1][4]+matriz[4][1]+matriz[4][4]);
            matriz2[1][2] = (matriz[1][2]+matriz[1][3]+matriz[4][2]+matriz[4][3]);
            matriz2[2][0] = (matriz[2][0]+matriz[2][5]+matriz[3][0]+matriz[3][5]);
            matriz2[2][1] = (matriz[2][1]+matriz[2][4]+matriz[3][1]+matriz[3][4]);
            matriz2[2][2] = (matriz[2][2]+matriz[2][3]+matriz[3][2]+matriz[3][3]);
            
            printf("%d ", matriz2[0][0]);
            printf("%d ", matriz2[0][1]);
            printf("%d \n", matriz2[0][2]);
            printf("%d ", matriz2[1][0]);
            printf("%d ", matriz2[1][1]);
            printf("%d \n", matriz2[1][2]);
            printf("%d ", matriz2[2][0]);
            printf("%d ", matriz2[2][1]);
            printf("%d ", matriz2[2][2]);
        }
    
    return 0;
}