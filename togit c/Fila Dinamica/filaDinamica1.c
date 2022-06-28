#include <stdio.h>
#include <stdlib.h>


typedef struct fila fila;
typedef struct item item;

struct item{

	int valor;
	struct item *proximo;

};

struct fila{
	
	item *inicio;
	item *fim;
	
};

fila * iniciaFila(fila *fila){
	
	fila = malloc(sizeof(fila));
	
	if(fila != NULL){
		
		fila->fim = NULL;
		fila->inicio = NULL;
		
	}
	
	return fila;	
	
}

item * criaItem(int valor){
	
	item *item = malloc(sizeof(item));
	
	if(item != NULL){
		
		item->valor = valor;
		item->proximo = NULL;
		
	}
	
	return item;
	
}

void insereFila(fila *fila, int valor){
	
	item *itemAtual, *itemAnterior = NULL;
	item *item= criaItem(valor);
	
	if(fila->fim == NULL && fila->inicio == NULL){
		
		fila->inicio = item;
		fila->fim = item;
		
	}
	else{
		
		itemAtual = fila->fim;
		itemAtual->proximo = item;
		fila->fim = item;
			
		
		/*itemAtual = fila->inicio;
		itemAnterior = NULL;
		
		while(itemAtual->proximo != NULL && itemAtual->valor < item->valor){
			
			itemAnterior = itemAtual;
			itemAtual = itemAtual->proximo;
			
		}
		
		if(itemAtual->valor != item->valor){
			
			if(itemAtual->proximo == NULL){
				
				if(itemAtual->valor > item->valor){
					
					if(itemAnterior != NULL){
					
					
					itemAnterior->proximo = item;
					item->proximo = itemAtual;
					
					}
					else{
						
						fila->inicio = item;
						item->proximo = itemAtual;
						
					}
					
				}
				else{
					
					itemAtual->proximo = item;
					fila->fim = item;
					
				}	
				
			}
			else{
				
				if(itemAnterior != NULL){
		
				itemAnterior->proximo = item;
				item->proximo = itemAtual;
				
				}
				else{
					
					item->proximo = itemAtual;
					fila->inicio = item;
					
				}
				
			}
	
		}*/
	
	}
	
}

void removeFila(fila *fila){
	
	item *itemAux;
	
	if(fila->inicio != NULL){
	
	
	itemAux = fila->inicio;
	
	printf("<%d>\n", itemAux->valor);
	
	fila->inicio = itemAux->proximo;
	
	if(fila->inicio == NULL){
		
		fila->fim = NULL;
		
	}
	
	//free(itemAux);    //sera?
	
	}
}

void mostraFila(fila *fila){
	
	item *item;
	
	if(fila->fim != NULL){
		
		item = fila->inicio;
		
		while(item->proximo != NULL){
			
			printf("%d ", item->valor);
			item = item->proximo;
			
		}
		
		printf("%d\n", item->valor);
		
	}
		
}





int main(){
	
	char operador;
	int valor;
	
	fila *fila;
	
	fila = iniciaFila(fila);
	
	while(scanf(" %c", &operador) != EOF){
		
		if(operador == 'E'){
			
			scanf(" %d", &valor);
			
			if(valor >= 0 && valor <= 100000){
				
				insereFila(fila, valor);
				
			}
			
		}
		else if(operador == 'D'){
			
			removeFila(fila);
			
		}
		else if(operador == 'M'){
			
			mostraFila(fila);
			
		}
	
	}
	
	free(fila);
	
	return 0;
	
}
