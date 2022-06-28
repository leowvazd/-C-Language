#include <stdio.h>

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

	for(i=(*topo); i>=0; i--){

		printf("%d\n", pilha[i]);
		
	}
	
	
}

void exibeBaseTopo(int *pilha, int *topo){

	int i;
	
	for(i=0; i<=(*topo); i++){

		printf("%d\n", pilha[i]);
		
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
		else if(operador == 'T'){
			
			exibeTopoBase(pilha, topo);
			
		}
		else if(operador == 'B'){
			
			exibeBaseTopo(pilha, topo);
			
		}	
		
	}
	
	return 0;

}
