#include <stdio.h>
#include <stdlib.h>


typedef struct fila fila;
typedef struct item item;

typedef struct pilha pilha;
typedef struct itemPilha itemPilha;

// Pilha

struct pilha{
	
	int quantidade;
	item *topo;
	
};

struct itemPilha{
	
	int valor;
	struct itemPilha *anterior;
	
};

pilha * iniciaPilha(pilha *pilha){
	
	pilha = malloc(sizeof(pilha));
	
	if(pilha != NULL){

		pilha->topo= NULL;
		pilha->quantidade = 0;
		
	}
	
	return pilha;
	
}

itemPilha * criaItemPilha (int valor){
	
	itemPilha *itemPilha = malloc(sizeof(itemPilha));
	
	if(itemPilha != NULL){
		
		itemPilha->valor = valor;
		itemPilha->anterior = NULL;
	}
	
	return itemPilha;
}

void empilha (pilha *pilha, int valor){
	
	itemPilha *itemPilha = criaItemPilha(valor);
	
	itemPilha->anterior = pilha->topo;
	pilha->topo = itemPilha;
	pilha->quantidade++;
	
}

void mostraPilha(pilha *pilha){
	
	
	itemPilha *itemAux;
	int i;
	
	itemAux = pilha->topo;
	
	for(i=0; i< pilha->quantidade; i++){
		
		if(itemAux->anterior != NULL){
			
			printf("%d\n", itemAux->valor);
			itemAux= itemAux->anterior;
			
		}
		else{
			
			printf("%d\n", itemAux->valor);
			
		}
	
	}
	
}

pilha * invertePilha(pilha *pilha){ // tentativa de resolver bug de declaracao

	struct pilha *pilhaAux;

	pilhaAux = iniciaPilha(pilhaAux);
	
	itemPilha *itemPilhaAux;
	
	itemPilhaAux = pilha->topo;
	//itemPilhaAux= itemPilhaAux->anterior;
	while(itemPilhaAux != NULL){
		
		empilha(pilhaAux, itemPilhaAux->valor);
		itemPilhaAux = itemPilhaAux->anterior;
		
	}
	
	/*printf("pilhaAux:\n");
	mostraPilha(pilhaAux);
	printf("fim pilha aux\n");*/
	//itemPilhaAux=
	
	//if(pilhaAux->topo != NULL){
	
		//pilha = pilhaAux;
	
//	}
	
	return pilhaAux;
	
}

// Fila

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
	
	item * item = malloc(sizeof(item));
	
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
	
	}
	
}

void removeFila(fila *fila){
	
	item *itemAux;
	
	if(fila->inicio != NULL){
	
	
	itemAux = fila->inicio;
	
	//printf("<%d>\n", itemAux->valor);
	
	fila->inicio = itemAux->proximo;
	
	if(fila->inicio == NULL){
		
		fila->fim = NULL;
		
	}

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

// Algoritmo para igualar a pilha à Fila

void igualaPilhaALista(fila *fila, pilha *pilha){
	
	item *itemFilaAux;
	
	if(fila->inicio != NULL){
		
		itemFilaAux = fila->inicio;
		
		while(itemFilaAux != NULL){
			
			empilha(pilha, itemFilaAux->valor);
			itemFilaAux = itemFilaAux->proximo;
			
		}
	
	}
	
	//mostraPilha(pilha); // Até aqui ta correto porem invertido
	
	//invertePilha(pilha);
	
}






int main(){
	
	char operador;
	int valor;
	
	fila *fila;
	pilha *pilha;
	
	pilha = NULL;
	
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
			
			//mostraFila(fila);       // agora vai ser mostra pilha
			
			if(pilha != NULL){
				
				pilha = invertePilha(pilha);
				
				mostraPilha(pilha);
				
			}
			
		}
		else if(operador == 'P'){
			
			pilha = iniciaPilha(pilha);
			
			igualaPilhaALista(fila, pilha);
			
		}
	
	}
	
	free(pilha);
	free(fila);
	
	return 0;
	
}
