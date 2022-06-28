#include <stdlib.h>
#include <stdio.h>

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

int filhoE (int i) {
    return 2*i + 1;
}
int filhoD (int i) {
    return 2*i + 2;
}

void troca (int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void peneirar2 (int *v, int n, int i) {
    int e = filhoE(i), d = filhoD(i), maior = e;
    
   // printf("no raiz da arvore: %d\n", v[i]);
    
   // printf("filhoE: %d\n", e);
   if(i>=0){
    if (e < n) {
        if (d < n && v[d] >= v[maior]) {
        //	printf("primeira regra da peneira\n");
            maior = d;
        }
        if (v[i] < v[maior]) {
        //	printf("segunda regra da peneira\n");
            troca (v, i, maior);
            peneirar2 (v, n, maior);
        }
    }
	}
}


void selecionaMaximo (int *v, int i) {
    troca (v, 0, i);
}

void heapSort (int *v, int n) {
    int i;
    //constroiHeap (v, n); //ja fiz na main
    for (i = n-1; i >= 0; i--) {
        mostraVetor(v, i+1);         // n = i+1
        selecionaMaximo (v, i);
        peneirar2(v, i, 0);     // n = i+1
    }
    
    
}





int main(){
	
	int i, tamanho, entrada;
	int *v;

	
	scanf("%d", &tamanho);
	if(tamanho>100 || tamanho <=0){

		return 1;
	}
	
	v = malloc (tamanho * sizeof(int));

	for(i=0; i< tamanho; i++){

		scanf("%d", &entrada);
		v[i] = entrada;
	
	}
		
	mostraVetor(v, tamanho);
		
	construirHeap(v, tamanho);

	//mostraVetor(v, tamanho);
	
	heapSort(v, tamanho);
	//heapSort(v, tamanho);
	
	mostraVetor(v, tamanho);
		
	//free(v);


	return 0;
	
}
