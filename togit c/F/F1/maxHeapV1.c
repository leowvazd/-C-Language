#include <stdlib.h>
#include <stdio.h>

int peneirar(int *v, int i, int tamanho){
	
	int j, aux;
		
	if(((v[i] < v[(2*i) +1] && ((2*i) +1) < tamanho) || (v[i] < v[(2*i) +2]&& ((2*i) +2) < tamanho)) && i>=0){ // adcionei essa regra do i
			

		if(v[(2*i) +1] > v[(2*i) +2] || ((2*i) +2) >= tamanho){  // vai trocar pelo no da esquerda
				
			aux = v[i];
	
			v[i] = v[(2*i) +1];

			v[(2*i) +1] = aux;

			j=(2*i) +1;	
		}
		else{                                                  // troca pelo no da direita
				
			aux = v[i];
			v[i] = v[(2*i) +2];
			v[(2*i) +2] = aux;
			j=(2*i) +2;	
		}
		
		if((v[j] < v[(2*j) +1] && ((2*j) +1) < tamanho) || (v[j] < v[(2*j) +2]&& ((2*j) +2) < tamanho)){
			
			return j;
	
		}
		else{

			return i-=1;
			
		}	
	}
	else if(i>0){

		return i -= 1;
		
	}
	else{

		return tamanho+1;
	}
}


void construirHeap(int *v, int tamanho){
	
	int i=peneirar(v, ((tamanho/2)-1), tamanho);
	
	while(i != tamanho+1){
	
		i =peneirar(v, i, tamanho);
	
	}

}



void mostraVetor(int *v, int tamanho){
	
	int i;
	
	for(i=0; i<tamanho; i++){
		
		if(i<tamanho-1){
			
			printf("%d ", v[i]);
		}
		else{
			
			printf("%d\n", v[i]);
		}
		
		
	}
	
}

int main(){
	
	int i, tamanho, entrada;
	int *v;

	
	scanf("%d", &tamanho);
	if(tamanho>100 || tamanho <=0){

		return 1;
	}

	while(tamanho != 0){
		
		v = malloc (tamanho * sizeof(int));

		for(i=0; i< tamanho; i++){

			scanf("%d", &entrada);
			v[i] = entrada;
	
		}
		

		construirHeap(v, tamanho);

		mostraVetor(v, tamanho);
		
		//free(v);
		
		scanf("%d", &tamanho);	
		
		if(tamanho>100 || tamanho <0){
		
			return 1;
		}
		
	}
	

	return 0;
	
}
