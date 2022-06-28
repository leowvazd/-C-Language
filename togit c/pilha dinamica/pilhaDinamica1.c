#include <stdio.h>
#include <stdlib.h>


typedef struct pilha pilha;
typedef struct item item;

struct pilha{
	
	int quantidade;
	item *topo;
	
};

struct item{
	
	int valor;
	struct item *anterior;
	
};

pilha * iniciaPilha(pilha *pilha){
	
	pilha = malloc(sizeof(pilha));
	
	if(pilha != NULL){

		pilha->topo= NULL;
		pilha->quantidade = 0;
		
	}
	
	return pilha;
	
}

item * criaItem (int valor){
	
	item * item = malloc(sizeof(item));
	
	if(item != NULL){
		
		item->valor = valor;
		item->anterior = NULL;
	}
	
	return item;
}

void empilha (pilha *pilha, int valor){
	
	item *item = criaItem(valor);
	
	item->anterior = pilha->topo;
	pilha->topo = item;
	pilha->quantidade++;
	
}

void desempilha(pilha *pilha){
	
	item *itemAux;
	
	if(pilha->topo != NULL){
		
		itemAux= pilha->topo;
		pilha->topo = itemAux->anterior;
		pilha->quantidade--;
		
		printf("[%d]\n", itemAux->valor);
		
		free(itemAux);
		
	}
	
}

void mostraPilha(pilha *pilha){
	
	item *itemAux;
	int i;
	
	itemAux = pilha->topo;
	
	for(i=0; i< pilha->quantidade; i++){
		
		if(itemAux->anterior != NULL){
			
			printf("%d ", itemAux->valor);
			itemAux= itemAux->anterior;
			
		}
		else{
			
			printf("%d\n", itemAux->valor);
			
		}
	
	}
	
}



int main(){
	
	char operador;
	int valor;
	pilha *pilha;
	
	pilha = iniciaPilha(pilha);
	
	while(scanf(" %c", &operador) != EOF){
		
		if(operador == 'E'){
			
			scanf(" %d", &valor);
			
			empilha(pilha, valor);
			
		}
		else if(operador == 'D'){
			
			desempilha(pilha);
			
		}
		else if(operador == 'M'){
			
			mostraPilha(pilha);
			
		}

	}
	
	return 0;

}


