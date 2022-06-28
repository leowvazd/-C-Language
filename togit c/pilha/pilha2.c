#include <stdio.h>
#include <stdlib.h>

void empilhaValor(int *pilha, int *topo, int valor, int tamanho){

	if(*topo == tamanho - 1){
		
		return;
		
	}
	else{
	
	(*topo)++;
	
	pilha[*topo] = valor;
	
	return;
	
	}
}

void desempilhaValor(int *pilha, int *topo){
	
	if(*topo == -1){
		
		return;
		
	}
	else{
		
		(*topo)--;
		
	}
	
	return;
	
}

void exibeTopoBase(int *pilha, int *topo){
	
	int i;
	
	/*for(i=(*topo); i>=0; i--){

		if(i != 0){

			printf("%d\n", pilha[i]);

	}*/

	if((*topo) != -1){
	

	for(i=(*topo); i>=0; i--){

		if(i != 0){
			
			printf("%d ", pilha[i]);
			
		}
		else{
			
			printf("%d\n", pilha[i]);
			
		}
	
	}
	}
	
	return;
	
	}



void exibeBaseTopo(int *pilha, int *topo){

	int i;
	
	/*for(i=0; i<=(*topo); i++){   // Enunciado diz uma coisa mas saida de exemplo diz outra?

			printf("%d\n", pilha[i]);
	
	}*/
	
	if((*topo) != -1){
	
	
	for(i=0; i<=(*topo); i++){

		if(i != *topo){
			
			printf("%d ", pilha[i]);
			
		}
		else{
			
			printf("%d\n", pilha[i]);
			
		}
	
	}
	
	}
	
	return;

}

void exibeTopo(int *pilha, int *topo){
	
	if(*topo != -1){
	
	printf("%d\n", pilha[*topo]);
	
	}
}
	

int main(){
	
	int i, j, tamanho, valor, *topo, top=-1;
	int *pilha;
	char operador;
	
	topo = &top;
	
	scanf("%d", &tamanho);
	
	pilha = malloc (tamanho * sizeof(int));
	
	while(scanf(" %c", &operador) != EOF){
		
		if(operador == 'E'){
			
			scanf(" %d", &valor);
			
			empilhaValor(pilha, topo, valor, tamanho);
			
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
