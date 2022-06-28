#include <stdio.h>
#include <stdlib.h>

typedef struct tLista tLista;
typedef struct tItem tItem;

struct tLista{
	
	int quantidade;
	tItem *inicio;
	tItem *ultimo;
	
}; 



struct tItem{
	
	int valor;
	struct tItem *proximo, *anterior;
	
};

tLista * iniciaLista(tLista *lista){

	lista = (tLista *)malloc(sizeof(tLista));

	if(lista != NULL){

		lista->inicio= NULL;
		lista->ultimo= NULL;
		lista->quantidade = 0;
		
	}
	
	return lista;
	
}

tItem * criaItem (int valor){
	
	tItem * item = malloc(sizeof(tItem));
	
	if(item != NULL){
		
		item->valor = valor;
		item->proximo = NULL;
		item->anterior = NULL;
	}
	
	return item;
}

void insereLista(tLista *lista, int valor){  //esse algoritmo pode ser void?
	
	tItem *item, *itemAnalisado, *itemAnterior;
	
	item = criaItem(valor);
	
	if(lista->inicio == NULL){
		
		lista->inicio = item;
		lista->ultimo = item;
		lista->quantidade++;

	}
	else{
		
		itemAnalisado = lista->inicio;
		//itemAnterior = NULL;
		
		while(itemAnalisado->valor < item->valor && (itemAnalisado->proximo != NULL)){
			
			//itemAnterior = itemAnalisado;     //nao sera mais necesessario dado que tenho acesso ao anterior
			itemAnalisado = itemAnalisado->proximo;
				
		}
		
		if(itemAnalisado->valor != item->valor){
		
		
		if(itemAnalisado->proximo == NULL){  // item analisado eh o ultimo da lista
			
			if(itemAnalisado->valor < item->valor){ // ultimo valor analisado eh menor do que o item a ser inserido, entao insere o novo item no fim da lista
			
			
			itemAnalisado->proximo = item;
			item->anterior = itemAnalisado;
			lista->ultimo = item;
			lista->quantidade++;
			
			}
			else if(itemAnalisado->anterior == NULL){ // valor analisado é o primeiro da lista e eh maior que o item a ser inserido
				
				lista->inicio = item;
				item->proximo = itemAnalisado;
				itemAnalisado->anterior = item; 
				lista->quantidade++;
				
			}
			else{  //valor analisado eh maior e tem algum valor antes dele menor, entao insere item entre eles
				
				item->proximo = itemAnalisado;
				
				itemAnalisado = itemAnalisado->anterior;
				itemAnalisado->proximo = item;
				item->anterior = itemAnalisado;
				itemAnalisado = item->proximo;
				itemAnalisado->anterior = item;
				lista->quantidade++;
						
			}
			
			
		}
		else{
			
			if(itemAnalisado->anterior == NULL){
				
				lista->inicio = item;
				item->proximo = itemAnalisado;
				itemAnalisado->anterior = item;
				lista->quantidade++;
				
				
			}
			else{
					
				item->proximo = itemAnalisado;
				
				itemAnalisado = itemAnalisado->anterior;
				itemAnalisado->proximo = item;
				item->anterior = itemAnalisado;
				itemAnalisado = item->proximo;
				itemAnalisado->anterior = item;
				lista->quantidade++;
				
				
				/*item->proximo = itemAnalisado;
				item->anterior = itemAnalisado->anterior;
				itemAnalisado = itemAnalisado->anterior;
				itemAnalisado->proximo = item;
				lista->quantidade++;*/
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
		//itemAnterior = NULL;
		
		while(itemAnalisado->valor < valor && (itemAnalisado->proximo != NULL)){
			
			//itemAnterior = itemAnalisado;
			itemAnalisado = itemAnalisado->proximo;
			
		}
		
		if(itemAnalisado->valor == valor){
			
			if(itemAnalisado->anterior != NULL){	
			
		//	itemAnterior->proximo = itemAnalisado->proximo;
		
			if(itemAnalisado->proximo != NULL){
			
			
			itemAnalisado->proximo->anterior = itemAnalisado->anterior;
			itemAnalisado->anterior->proximo = itemAnalisado->proximo;
			
			lista->quantidade--;
			
			}
			else{
				
				itemAnalisado->anterior->proximo = NULL;
				lista->ultimo = itemAnalisado->anterior;
				lista->quantidade--;
				
				
			}
			
			}
			else{
				
				if(itemAnalisado->anterior != NULL || itemAnalisado->proximo != NULL){
				
				
				lista->inicio = itemAnalisado->proximo;
				itemAnalisado->proximo->anterior = NULL;
				lista->quantidade--;
				
				}
				else{
					
					lista->inicio = NULL;
					lista->ultimo = NULL;
					lista->quantidade--;
					
				}
			}
		
		free(itemAnalisado);
			
		}

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

void mostraListaInverso(tLista *lista){
	
	tItem *item;
		
	if(lista->ultimo != NULL){
		
		item = lista->ultimo;
		
		while(item != NULL){
			
			if(item->anterior != NULL){
				
				printf("%d ", item->valor);
				item = item->anterior;
				
			}
			else{
				
				printf("%d\n", item->valor);
				item = item->anterior;
		
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
		
		if(operador == 'M'){
			
		mostraLista(lista);
			
		}
		else if(operador == 'R'){
				
				mostraListaInverso(lista);
				
			}
		
		else{
			
			scanf(" %d", &valor);
			
			if(valor > 0 ){
			
			
			if(operador == 'I'){
				
				insereLista(lista, valor);
				
			}
			else if(operador == 'E'){
				
				removeLista(lista, valor);
				
			}
	
			}	
			
		}

	}

	return 0;

}
