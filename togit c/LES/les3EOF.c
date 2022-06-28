#include <stdio.h>
#include <stdlib.h>

void insereValorLES(char *LES, char valor, int *quantidade){

	int i, j, reservaOld, reserva, verificador=0;
	
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
	
}

void removeValorLES(char *LES, char valor, int *quantidade){

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

void buscaLES(char *LES, int *quantidade, int valor){
	
	int i;
	
	for(i=0; i<*quantidade; i++){
	
		if(valor == LES[i]){
			
			printf("SIM\n");
			return;
			
		}
		
	}
	
	printf("NAO\n");
	
	
}

void mostraLES(char *LES, int *quantidade){
	
	int i;
	
	for(i=0; i<*quantidade; i++){
		
		if(i < (*quantidade) -1){
			
			printf("%c ", LES[i]);
			
		}
		else{
			
			printf("%c\n", LES[i]);
			
		}
		
	}
	
	
}

void imprimeLES(int *LES, int *quantidade){

	int i;
	
	if(*quantidade == 0){

		return;
	}
	
	for(i=0; i< *quantidade; i++){
		
		printf("%c\n", LES[i]);
		
	}	
}

int main(){
	
	int i=0, q, j;
	int *quantidade, qtd=0;
	char valor;
	char *LES;
	char operador;
	
	quantidade = &qtd;

	scanf("%d", &q);
	
	LES = calloc (q, sizeof(int));


	while(scanf(" %c", &operador) != EOF){

		if(operador == 'M'){
			
			mostraLES(LES, quantidade);
			
		}
		else{
			
		scanf(" %c", &valor);	
		
		
		if(operador == 'I'){
			
			insereValorLES(LES, valor, quantidade);
			
		}
		else if(operador == 'R'){
			
			removeValorLES(LES, valor, quantidade);
			
		}
		else if(operador == 'B'){
			
			buscaLES(LES, quantidade, valor);
			
		}
	}	
		i++;
		
	}

	return 0;

}
