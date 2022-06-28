#include <stdio.h>
#include <stdlib.h>

typedef struct tLista tLista;
typedef struct tItem tItem;

struct tLista{
	
	int quantidade;
	tItem *inicio;
	
}; 



struct tItem{
	
	int valor;
	struct tItem *proximo;
	
};

tLista * iniciaLista(tLista *lista){

	lista = (tLista*)malloc(sizeof(tLista));

	if(lista != NULL){

		lista->inicio= NULL;
		lista->quantidade = 0;
		
	}
	
	return lista;
	
}

tItem * criaItem (int valor){
	
	tItem * item = (tItem*)malloc(sizeof(tItem));
	
	if(item != NULL){
		
		item->valor = valor;
		item->proximo = NULL;
	}
	
	return item;
}

void insereLista(tLista *lista, int valor){  //esse algoritmo pode ser void?
	
	tItem *item, *itemAnalisado, *itemAnterior;
	
	item = criaItem(valor);
	
	if(lista->inicio == NULL){
		
		lista->inicio = item;
		lista->quantidade++;

	}
	else{
		
		itemAnalisado = lista->inicio;
		itemAnterior = NULL;
		
		while(itemAnalisado->valor < item->valor && (itemAnalisado->proximo != NULL)){
			
			itemAnterior = itemAnalisado;
			itemAnalisado = itemAnalisado->proximo;
			
			
		}
		
		if(itemAnalisado->valor != item->valor){
		
		
		if(itemAnalisado->proximo == NULL){  // item analisado eh o ultimo da lista
			
			if(itemAnalisado->valor < item->valor){ // ultimo valor analisado eh menor do que o item a ser inserido, entao insere o novo item no fim da lista
			
			
			itemAnalisado->proximo = item;
			lista->quantidade++;
			
			}
			else if(itemAnterior == NULL){ // valor analisado é o primeiro da lista e eh maior que o item a ser inserido
				
				lista->inicio = item;
				item->proximo = itemAnalisado;
				lista->quantidade++;
				
			}
			else{  //valor analisado eh maior e tem algum valor antes dele menor, entao insere item entre eles
				
				itemAnterior->proximo = item;
				item->proximo = itemAnalisado;
				lista->quantidade++;
						
			}
			
			
		}
		else{
			
			if(itemAnterior == NULL){
				
				lista->inicio = item;
				item->proximo = itemAnalisado;
				lista->quantidade++;
				
				
			}
			else{
				
				itemAnterior->proximo = item;
				item->proximo = itemAnalisado;
				lista->quantidade++;
			}
	
		}
		
		}
		else{
			
			free(item);
			
		}
	
	}
		
}

void removeLista(tLista *lista, int valor){
	
	tItem *itemAnalisado, *itemAnterior;
	
	if(lista->quantidade == 0){
		
		return;
		
	}
	else{
		
		itemAnalisado = lista->inicio;
		itemAnterior = NULL;
		
		while(itemAnalisado->valor < valor && (itemAnalisado->proximo != NULL)){
			
			itemAnterior = itemAnalisado;
			itemAnalisado = itemAnalisado->proximo;
			
		}
		
		if(itemAnalisado->valor == valor){
			
			if(itemAnterior != NULL){	
			
			itemAnterior->proximo = itemAnalisado->proximo;
			lista->quantidade--;
			
			}
			else{
				
				lista->inicio = itemAnalisado->proximo;
				lista->quantidade--;
			}
			
		}
	
	}
	
}

void buscaValor(tLista *lista, int valor){
	
	tItem *item;
	
	item = lista->inicio;
	
	if(item != NULL){
	

	while(item->valor < valor && (item->proximo != NULL)){
	
		item = item->proximo;
		
	}
	
	if(item->valor == valor && (item != NULL)){
		
		printf("SIM\n");
		
	}
	else{
		
		printf("NAO\n");
		
	}
	
	}
	else{
		
		printf("NAO\n");
		
	}
	
	
}

void mostraLista(tLista *lista){
	
	tItem *item;
		
	if(lista->inicio != NULL){
		
		item = lista->inicio;
		
		while(item != NULL){
			
			if(item->proximo != NULL){
				
				printf("%d ", item->valor);
				item = item->proximo;
				
			}
			else{
				
				printf("%d\n", item->valor);
				item = item->proximo;
		
			}
	
		}	
		
	}
	
}



int main(){
	
	int i, valor;
	char operador;
	tLista *lista;
	
	lista = iniciaLista(lista);
	
	//printf("quantidade inicial: %d\n", lista->quantidade);
	
		
	while(scanf(" %c", &operador) != EOF){
		
		if(operador == 'L'){
			
		mostraLista(lista);
			
		}
		else{
			
			scanf(" %d", &valor);
			
			if(valor >= 0 && valor <=100000){
			
			
			if(operador == 'I'){
				
				insereLista(lista, valor);
				
			}
			else if(operador == 'R'){
				
			removeLista(lista, valor);
				
			}
			else if(operador == 'B'){
				
			buscaValor(lista, valor);
				
			}
			
			}	
			
		}

	}

	return 0;

}
