#include <stdlib.h>
#include <stdio.h>

int peneirar(int *v, int i, int tamanho){
	
	int j, aux;
//	printf("i recebido: %d\n", i);	
	if(((v[i] > v[(2*i) +1] && ((2*i) +1) < tamanho) || (v[i] > v[(2*i) +2]&& ((2*i) +2) < tamanho)) && i>=0){
			

		if(v[(2*i) +1] < v[(2*i) +2] || ((2*i) +2) >= tamanho){  // vai trocar pelo no da esquerda
				
			aux = v[i];
		//	printf("aux: %d\n", aux);
			v[i] = v[(2*i) +1];
		//	printf("ve[%d]: %d\n", i, v[(2*i) +1]);
			v[(2*i) +1] = aux;
		//	printf("ve2[%d]: %d\n", i, v[(2*i) +1]);
			j=(2*i) +1;	
		}
		else{                                                  // troca pelo no da direita
				
			aux = v[i];
			v[i] = v[(2*i) +2];
			v[(2*i) +2] = aux;
			j=(2*i) +2;	
		}
		
		if((v[j] > v[(2*j) +1] && ((2*j) +1) < tamanho) || (v[j] > v[(2*j) +2]&& ((2*j) +2) < tamanho)){
			
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

int removeElemento(int *v, int tamanho, int valor){
	
	int i, j, aux;
	
	
	for(i=0; i< tamanho; i++){
		
		if(v[i] == valor){
			
			break;
			
		}
	
	}
	
	v[i] = v[tamanho -1];
	
	/*for(j=i; j< tamanho; j++){
		
		v[j] = v[j+1];
		
	}*/
	
	tamanho -= 1;
	
	//construirHeap(v, tamanho);
	
	return tamanho;

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
    construirHeap(v, n);
    for (i = n-1; i >= 0; i--) {
        //mostraVetor(v, i+1);         // n = i+1
        selecionaMaximo (v, i);
        peneirar2(v, i, 0);     // n = i+1
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

void mostraMinimo(int *v, int tamanho){
	
	if(tamanho> 0){
		
		printf("%ld\n", v[tamanho-1]);
		
	}
	
	
}

int main(){
	
	int i=0, j=0, comando;  
	long int tamanho, entrada;
	int *v;
	char limpaEntrada;

	scanf("%ld", &tamanho);
	if(tamanho>100000 || tamanho <=0){

		return 1;
	}
	
//	scanf("%c", &limpaEntrada);
	
	v = malloc (tamanho * sizeof(long int));

	while(i < tamanho){

		scanf("%ld", &comando);
		//scanf("%c", &limpaEntrada);
		if(comando == 1){  // insere elemento no heap
		
			scanf("%ld", &entrada);
			if(entrada >1000000000 || entrada < -1000000000){
				
			//return 2; // sera q é isso	
			}
			else{
			
			v[j] = entrada;
			
			//heapSort(v, j+1);
			j++;
			}
			
			//scanf("%c", &limpaEntrada);
		}
		else if(comando == 2){
			
			scanf("%ld", &entrada);
			if(entrada >1000000000 || entrada < -1000000000){
				
		//	return 2;   //sera q é isso?
			}
			else{
			
			j = removeElemento(v, j, entrada);
			
			}
			
		//	scanf("%c", &limpaEntrada);
			
			if(j == 0){
			
			
				free(v);
				v = calloc(tamanho, sizeof(long int));
				j=0;
			}
			
		}
		else if(comando == 3){
			//scanf("%c", &limpaEntrada);
			heapSort(v, j);
			mostraVetor(v, j);
			mostraMinimo(v, j);
			
		}

		
		
		i++;
		
	}
	
	//free(v);
	return 0;
	
}
