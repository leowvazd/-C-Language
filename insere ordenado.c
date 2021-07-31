/*

Faça um programa que fique lendo números inteiros positivos:

• Cada número deverá ser inserido ordenado (ordem crescente) em um vetor 
(assuma que haverá no máximo 100 números).
• Após cada inserção, imprima o vetor completo. 
O programa encerra quando o usuário digitar o número -1 
(não imprima o vetor após o usuário digitar -1, apenas encerre o programa).

Exemplo de funcionamento:
Digite: 5
5
Digite: 8
5 8
Digite: 2
2 5 8
Digite: 7
2 5 7 8
Digite: -1

*/

#include <stdio.h>

int
main ()
{

  int vetor[100] = { 0 };
  int i, j;
  int t = 0;
  int l = sizeof (vetor) / sizeof (vetor[0]);

  for (i = 0; i < 100; i++)
    {

      scanf ("%d", &vetor[i]);


      for (int p = 0; p < l; p++)
	{
	  for (int w = p + 1; w < l; w++)
	    {
	      if (vetor[p] > vetor[w])
		{
		  t = vetor[p];
		  vetor[p] = vetor[w];
		  vetor[w] = t;
		}
	    }
	}

      if (vetor[i] == -1)
	{

	  break;

	}

      if (vetor[i] != -1)
	{

	  for (j = 0; j < 100; j++)
	    if (vetor[j] != 0)
	      {

		printf ("%d ", vetor[j]);

	      }

	  printf ("\n");

	}

    }

  return 0;
}