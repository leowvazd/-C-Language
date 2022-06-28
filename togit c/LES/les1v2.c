#include <stdio.h>
#include <stdlib.h>

void insereValorLES(int *LES, int valor, int *quantidade){
	
	//printf("Funcao insereValor iniciada:\n");
	
	int i, j, reservaOld, reserva, verificador=0;
//	printf("quantidade eh: %d\n", *quantidade);
	
	if(*quantidade == 0){   // insere na primeira casada lista caso a quantidade seja 0.
		
		LES[0] = valor;
		
		*quantidade += 1;

	}
	else{
		
		for(i=0; i<*quantidade; i++){   // verifica se o valor ja esta na lista, e para o algoritmo caso verdade.
			
			if(LES[i] == valor){
				
				return;
			}
			
		}
		
		if(valor > LES[(*quantidade) - 1]){   // se o valor for maior que o ultimo elemento da lista, aumenta a qtd e insere no novo ultimo indice
			//printf("insere no ultimo iniciada\n");
		//	printf("valor a ser inserido: %d\n", valor);
			
			LES[*quantidade] = valor;
			*quantidade += 1;
			
			return;
			
		}
		
		for(i=0; i<*quantidade; i++){
			
			if(i == 0){        // insere no primeiro indice e desloca o restante.
				
				if(LES[i] > valor){
					
					reservaOld = LES[i];
					LES[i] = valor;
					*quantidade += 1;
					
					for(j=i+1; j< *quantidade; j++){
						
						reserva = LES[j];
						LES[j] = reservaOld;
						reservaOld = reserva;
						
					}
					
				}

			}
			else{
				
				//printf("insere no meio iniciada\n", *quantidade);
				
				if(LES[i] > valor && LES[i-1] < valor){   // insere valor no meio da lista
					
					reservaOld = LES[i];
					LES[i] = valor;
					*quantidade += 1;
					
					for(j=i+1; j< *quantidade; j++){
						
						reserva = LES[j];
						LES[j] = reservaOld;
						reservaOld = reserva;
						
					}
					
				}
	
			}
	
		}
	
	}
	
	//printf("nova quantidade eh: %d\n", *quantidade);
	
}

void removeValorLES(int *LES, int valor, int *quantidade){
	
	//printf("Funcao remover iniciada\n");
	
	int i, j, reserva, reservaOld;
	
	if(*quantidade == 0){
		
		return;
		
	}
	else if(valor == LES[(*quantidade) - 1]){
		
		LES[(*quantidade) - 1] = 0;
		*quantidade -= 1;
		
		return;
		
	}
	else{
		
		for(i=0; i < *quantidade; i++){
			
			if(LES[i] == valor){
				
				for(j= i; j< (*quantidade) - 1; j++){
					
					LES[j] = LES[j+1];
			
				}
				
				LES[(*quantidade) - 1] = 0;
				*quantidade -= 1;
				
				return;
		
			}
	
		}
	
	}

}

void imprimeLES(int *LES, int *quantidade){
	
	//printf("Imprimindo LES: \n");
	//printf("quantidade final eh: %d\n", *quantidade);
	
	int i;
	
	if(*quantidade == 0){
		
		//printf("A lista esta vazia\n");
		return;
	}
	
	for(i=0; i< *quantidade; i++){
		
		printf("%d\n", LES[i]);
		
	}
	
	
}

int main(){
	
	int i=0, q, j;
	int *quantidade, qtd=0;
	int valor;
	int LES[30000];
	char operador;
	
	quantidade = &qtd;
	
	//printf("%d %d\n", quantidade, *quantidade);
	
	scanf("%d", &q);
	
	//LES = malloc (30000 * sizeof(int));
	//valor = malloc (q * sizeof(int));
	//operador = malloc (q * sizeof(char));
	
	/*for(j=0; j<q; j++){
		
		scanf(" %c %d", &operador[j], &valor[j]);
	
	}*/

	while(i<q){
		
		scanf(" %c %d", &operador, &valor);
		
		if(operador == 'I'){
			
			insereValorLES(LES, valor, quantidade);
			
		}
		else if(operador == 'E'){
			
			removeValorLES(LES, valor, quantidade);
			
		}
		
		i++;
		
	}
	
	imprimeLES(LES, quantidade);
	
	return 0;

}
