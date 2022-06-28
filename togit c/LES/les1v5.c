#include <stdio.h>
#include <stdlib.h>

typedef struct tLista *tLista;
struct tLista {
    int *itens;
    int quantidade;
    int tamanho;
};

void iniciaLista(struct tLista *lista, int n) {
  lista->itens = (int*) malloc(n * sizeof(int));
  lista->tamanho = n;
  lista->quantidade = 0;
}

void insereValorLES(int *LES, int valor, int *quantidade){

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

void removeValorLES(int *LES, int valor, int *quantidade){

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
				
				*quantidade -= 1;
				
				return;
		
			}
	
		}
	
	}

}

void imprimeLES(int *LES, int *quantidade){

	int i;
	
	if(*quantidade == 0){
		
		return;
	}
	
	for(i=0; i< *quantidade; i++){
		
		printf("%d\n", LES[i]);
		
	}
	
	
}

int main(void){
	
	int i=0, q, j;
	int *quantidade, qtd=0;
	int valor;
	int LES[30000];
	char operador;
	
	quantidade = &qtd;

	scanf("%d", &q);
	
	//fflush(stdin);
	
	while(i<q && (scanf("%c", &operador) != EOF)){
		
		scanf("%c", &operador);
		
		scanf(" %d", &valor);
		
		if(valor > 0){
		
		
		if(operador == 'I'){
			
			insereValorLES(LES, valor, quantidade);
			
		}
		else if(operador == 'E'){
			
			removeValorLES(LES, valor, quantidade);
			
		}
		
		}
		
		i++;
		
	}
	
	imprimeLES(LES, quantidade);
	
	return 0;

}
