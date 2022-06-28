#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void empilhaValor(char **pilha, int *topo, char *valor, int tamanho){
	
	//printf("empilha valor iniciada\n");

	if(*topo == tamanho - 1){
		
		return;
		
	}
	else{
	
	(*topo)++;
	
	//pilha[*topo] = valor;
	strcpy(pilha[*topo], valor);
	
	return;
	
	}
}

void desempilhaValor(char **pilha, int *topo){
	
	if(*topo == -1){
		
		return;
		
	}
	else{
		
		(*topo)--;
		
	}
	
	return;
	
}

void exibeTopoBase(char **pilha, int *topo){
	
	int i;
	
	/*for(i=(*topo); i>=0; i--){

			printf("%s\n", pilha[i]);

	}*/
	
	if((*topo) != -1){

	for(i=(*topo); i>=0; i--){

		if(i != 0){
			
			printf("%s ", pilha[i]);
			
		}
		else{
			
			printf("%s\n", pilha[i]);
			
		}
	
	}
	
	}
	
	

}

void exibeBaseTopo(char **pilha, int *topo){

	int i;
	
	/*for(i=0; i<=(*topo); i++){   // Enunciado diz uma coisa mas saida de exemplo diz outra?

			printf("%s\n", pilha[i]);
	
	}*/
	
	if((*topo) != -1){
	
	
	for(i=0; i<=(*topo); i++){

		if(i != *topo){
			
			printf("%s ", pilha[i]);
			
		}
		else{
			
			printf("%s\n", pilha[i]);
			
		}
	
	}
	
	}

}

void exibeTopo(char **pilha, int *topo){
	
	if((*topo) != -1){
	
	
	printf("%s\n", pilha[(*topo)]);

	}
	
}
	

int main(){
	
	int i, j, tamanho, /*valor,*/ *topo, top=-1;
	char stringEntrada[50];
	char **pilha;
	char operador;
	
	topo = &top;
	
	scanf("%d", &tamanho);
	
	pilha = malloc (tamanho * sizeof(char *));
	//printf("alocou o array de array de char\n");
	
	for(j=0; j< tamanho; j++){
		
		pilha[j] = malloc(50 * sizeof(char));
			
	}
	
	/*for(j=0; j< tamanho; j++){
		
		printf("%s\n", pilha[j]);
			
	}*/
	
	//printf("alocou um array de 50 chars em cada indice do array de array de chars\n");
	
	while(scanf(" %c", &operador) != EOF){
		
		if(operador == 'E'){
			
			scanf(" %s", stringEntrada);
			
		//	printf("recebeu a string entrada\n");
			
			empilhaValor(pilha, topo, stringEntrada, tamanho);
			
		}
		else if(operador == 'D'){
			
			desempilhaValor(pilha, topo);
			
		}
		else if(operador == 'X'){
			
			exibeTopoBase(pilha, topo); //bug?
			
		}
		else if(operador == 'B'){
			
			exibeBaseTopo(pilha, topo);
			
		}
		else if(operador == 'T'){
			
			exibeTopo(pilha, topo);
			
		}
		
		fflush(stdin);	
		
	}
	
	return 0;

}
