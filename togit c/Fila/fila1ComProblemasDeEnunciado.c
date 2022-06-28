#include <stdio.h>

// Esse codigo funciona apenas para o exemplo 2 do enunciado
// Ao tentar inserir um valor na fila cheia, ele remove o primeiro valor,
// desloca os valores para a esquerda, e insere o novo valor.
// O enunciado diz que não é para fazer isso, mas o exemplo 2 só funciona fazendo isso!
// Devo seguir qual dos dois? Sinceramente esses enunciados estao com problemas.

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
		/*else{  // Isso nao deveria ocorrer segundo o enunciado, mas o exemplo 2 faz exatamente isso.
			
			for(i=0; i<(*fim); i++){
				
				fila[i] = fila[i+1];
				
			}
			
			fila[(*fim)] = valor;
			
		}*/
		
		
	
	}
	
}

void removeFila(int *fila, int *tamanho, int *inicio, int *fim){
	
	int valorRemovido;
	
	if((*inicio) != -1 && (*fim) != -1){
		
		valorRemovido = fila[(*inicio)];
		
		printf("%d\n", valorRemovido);
		
		(*inicio)++;
		
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
