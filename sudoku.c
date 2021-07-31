/*

Faça um programa que leia um tabuleiro 9x9 de inteiros. 
Seu programa deve verificar se o tabuleiro é válido para o jogo Sudoku. 
Lembrando que, neste jogo, cada linha pode conter apenas números inteiros de 1 a 9 
sem repetições. Essa mesma regra vale para as colunas e para cada bloco 3x3 
conforme exemplificado na figura abaixo.

O seu programa receberá os 81 números, linha por linha do tabuleiro 9x9. 
Note que é possível que não se saiba alguns valores do tabuleiro 
(o objetivo do jogo seria preenchê-los, mas não vamos fazer isso agora). 
Para indicar que não se sabe o número em alguma posição será utilizado o valor 0. 
Seu programa deve imprimir SIM se for um tabuleiro válido, e NAO caso contrário. 
Não esqueça de adicionar uma quebra de linha no fim.

Exemplos
Teste 01
Entrada:

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 9
Saída:

SIM
Teste 02
Entrada:

4 0 0 0 0 0 8 0 5
0 3 0 0 0 0 0 0 0
0 0 0 7 0 0 0 0 0
0 2 0 0 0 0 0 6 0 
0 0 0 0 8 0 4 0 0
0 0 0 0 1 0 0 0 0
0 0 0 6 0 3 0 7 0
5 0 0 2 0 0 0 0 0
1 0 4 0 0 0 0 0 5
Saída:

NAO
Teste 03
Entrada:

4 1 7 3 6 9 8 2 5 
6 3 2 1 5 8 9 4 7
9 5 8 7 2 4 3 1 6 
8 2 5 4 3 7 1 6 9 
7 9 1 5 8 6 4 3 2 
3 4 6 9 1 2 7 5 8 
2 8 9 6 4 3 5 7 1 
5 7 3 2 9 1 6 8 4 
1 6 4 8 7 5 2 9 3 
Saída:

SIM

*/

#include <stdio.h>

int main()  {
    
    //variaveis
    int sudoku[9][9];
    int i, j, k, l;
    int fail = 0;
    int cub = 3;
    int linha = 9;
    int coluna = 9;
    
    //entradas
    for (i = 0; i < linha; i++)    {
        
        for (j = 0; j < coluna; j++)    {
            
            scanf("%d ", & sudoku[i][j]);
        }
    }
    
    //3x3
    for (i = 0; i < linha; i = i + cub) {
        
        for (j = 0; j < coluna; j = j + cub) {
            
            for (k = 0; k < cub; k++)    {
                
                for (l = 0; l < cub; l++)    {
                    
                    if (k != 0 || l != 0 )   {
                        
                        if (sudoku[i][j] == sudoku[i+k][j+l] && sudoku[i][j] != 0) {
                            
                            fail++;
                        }
                    }
                }
            }
        }
    }
    
    //diagonais
    if (sudoku[0][8] != 0 && sudoku[0][8] == sudoku[1][7] && sudoku[0][8] == sudoku[2][6] && sudoku[0][8] == sudoku[8][0])   {
                
                fail++;
            }

    //linhas & colunas
    for (i = 0; i < linha; i++)    {
        
        for (j = 0; j < coluna; j++)    {
            
            for (k = 0; k < linha; k++)    {
                
                for (l = 0; l < coluna; l++)    {
                    
                    if (l != j && k != i)   {
                        
                        if (sudoku[i][j] == sudoku[i][l] && sudoku[i][j] != 0)    {
                            
                            fail++;
                        }
                        
                        else    {
                            
                            if (sudoku[i][j] == sudoku[k][j] != 0 && sudoku[i][j])    {
                                
                                fail++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (fail == 0)   {
        
        printf("SIM\n");
    }
    
    if (fail != 0)   {
        
        printf("NAO\n");
    }

    return 0;
}