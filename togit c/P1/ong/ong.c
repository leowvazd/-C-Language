#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estou acessando algo errado em count, perdendo o count do primeiro valor 

typedef struct tLista lista;
typedef struct tItem item;

void mostraLista(lista *lista);
lista * iniciaLista(lista *lista);
item * criaItem (char *palavra);
void insereLista(lista *lista, char *palavra);
void mostraLista(lista *lista);

struct tLista{
	
	int quantidade;
	item *inicio;
	item *ultimo;
	
}; 



struct tItem{
	
	char palavra[101];
	int count;
	item *proximo, *anterior;
	
};

lista * iniciaLista(lista *lista){
	
	lista = calloc(1, sizeof(lista));

	if(lista != NULL){

		lista->inicio= NULL;
		lista->ultimo= NULL;
		lista->quantidade = 0;
		
	
	
	return lista;
	
	}
}

item * criaItem (char *palavra){
	
	item * item = calloc(1, sizeof(item));
	if(item != NULL){
		
		strcpy(item->palavra, palavra);
		
		item->count = 0;
		item->proximo = NULL;
		item->anterior = NULL;
	
	
	return item;
	
	}
}


void insereLista(lista *lista, char *palavra){
	
	item *item, *itemAnalisado, *itemAnterior, *itemAux;
	
	printf("\n");
	printf("lista atual no algoritmo de insercao:\n");
	mostraLista(lista);
	printf("\n");
	
	item = criaItem(palavra);
	printf("item criado, palavra: [%s], count: %d\n", item->palavra, item->count);
	if(item->anterior == NULL && item->proximo == NULL){
		
		printf("anterior e proximos nulos!\n");
		
	}
	
	if(lista->inicio == NULL){
		
		lista->inicio = item;
		lista->ultimo = item;
		lista->quantidade++;
		item->count += 1;
		
	}
	else{
		
		itemAnterior = NULL;
		itemAnalisado = lista->inicio;
		
		printf("procurando a palavra na lista...\n");
		
		while((strcmp(itemAnalisado->palavra, item->palavra)) != 0 && (itemAnalisado->proximo != NULL)){
			
			//itemAnterior = itemAnalisado;
			itemAnalisado = itemAnalisado->proximo;
		}
		
		if(strcmp(itemAnalisado->palavra, item->palavra) == 0){  // palavra ja esta na lista
			
			
			
			
			
			
		}
		else{                                                    // palavra nao esta na lista
			
			printf("palavra nao ta na lista\n");
			
			itemAux= lista->inicio;
			
			
			item->proximo = itemAux;
			
			if(lista->ultimo == itemAnalisado){
				
				printf("algoritmo procurou até o ultimo elemento da lista\n");
				printf("ultimo elemento: [ %s ], count: %d\n", itemAnalisado->palavra, itemAnalisado->count);
				
			}
			itemAux->anterior = item;
			lista->quantidade += 1;
			lista->inicio = item;
			item->count++;
			
		/*	//lista->ultimo = itemAnalisado;
			item->count++;
			item->proximo = lista->inicio;
			//lista->inicio->anterior = item;
			lista->inicio = item;
			lista->quantidade++;
		*/
		}
		
}

}

void mostraLista(lista *lista){
	
	item *item;
	
	printf("qntd: %d\n", lista->quantidade);
		
	if(lista->inicio != NULL){
		
		item = lista->inicio;
		
		printf("lista: [ ");
		
		while(item != NULL){
			
			if(item->proximo != NULL){
				
				if(item->anterior == NULL){
					
					printf("aNULL ");
					
				}
				
				printf("%s [COUNT: %d]", item->palavra, item->count);
				item = item->proximo;
				
			}
			else{
				
				if(item->anterior == NULL){
					
					printf("aNULL ");
					
				}
				
				printf("%s [COUNT: %d]  ", item->palavra, item->count);
				//item = NULL;
				
				if(item->proximo == NULL){
					
					printf(" pNULL ]\n");
				}
				
				break;
		
			}
	
		}
		
			
		
	}
	
}



int main(){
	
	lista *lista;
	
	lista = iniciaLista(lista);
	
	char operador, palavra[101];
	
	while(scanf(" %s", palavra) != EOF){
		
		insereLista(lista, palavra);
		mostraLista(lista);
		printf("\n");
	
	}
	
	mostraLista(lista);
	
	return 0;
}
