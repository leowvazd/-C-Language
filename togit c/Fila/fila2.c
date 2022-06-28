#include <stdio.h>


void insereFila(int *fila, int *tamanho, int *inicio, int *fim, int valor){

	int i;
	
	if((*inicio) == -1 && (*fim) == -1){
		
		*inicio = 0;
		*fim = 0;
		
		fila[0] = valor;
		
	}
	else{
		
		if((*fim) < (*tamanho) - 1){
			
			(*fim)++;
			
			fila[(*fim)] = valor;
			
			
		}
	
	}
	
}

void removeFila(int *fila, int *tamanho, int *inicio, int *fim){
	
	int valorRemovido, i;
	
	if((*inicio) != -1 && (*fim) != -1){
		
		valorRemovido = fila[(*inicio)];
		
		printf("%d\n", valorRemovido);
		
		for(i=0; i< *tamanho; i++){
			
			fila[i] = fila[i+1];
			
			
		}
		
		(*fim)--;
		
		if((*inicio) > (*fim)){
			
			(*inicio) = -1;
			(*fim) = -1;
		}
		
	}
	
	
}

int main(){
	
	int i, tamanho, fila[1000], valor;
	int inicio=-1, fim=-1;
	char operador;
	
	scanf("%d", &tamanho);
	
	tamanho--;
	
	while(scanf(" %c", &operador) != EOF){
		
		if(operador == 'E'){
			
			scanf(" %d", &valor);
			
			if(valor > 0){
						
			insereFila(fila, &tamanho, &inicio, &fim, valor);
			
			}
			
		}
		else if(operador == 'D'){
			
			removeFila(fila, &tamanho, &inicio, &fim);
			
		}
		
		
		
	}

	return 0;
	
}
