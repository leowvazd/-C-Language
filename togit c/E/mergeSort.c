#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void intercalaSort (int *v, int esq, int meio, int dir) {
    int n = dir - esq + 1;
    int *vaux = malloc (n * sizeof (int));
    int i = esq, j = meio+1, k = 0;
    
    while (i <= meio && j <= dir) {
        if (v[i] <= v[j]) { 
            vaux[k++] = v[i++];
        }
        else {
            vaux[k++] = v[j++];
        }
    }
    while (i <= meio) {
        vaux[k++] = v[i++];
    }
    while (j <= dir) {
        vaux[k++] = v[j++];
    }
    for (i = esq; i <= dir; i++) {
        v[i] = vaux[i-esq];  
    }
    
    
    free (vaux);
}
	
	


void mergeSort (int *v, int e, int d, int n) {
    int meio;
    if (e < d) {
    	
        meio = (d+e)/2;
        mergeSort (v, e, meio, n);
        mergeSort (v, meio+1, d, n);
        mostraVetor(v, n);
        intercalaSort (v, e, meio, d);
    }

}

void mostraVetor(int *v, int q){
	
	int i;
	
	for(i=0; i< q; i++){
		
		if(i<q-1){
		
		printf("%d ", v[i]);
		}
		else{
			
			printf("%d\n", v[i]);
		}
	}
	
}

int main(){
	
	int i, q1, p, entrada;
	int *v1;
	
	scanf("%d", &q1);    // recebe tamanho
	
	scanf("%d", &p);     // recebe indice para particionar
	
	if((q1 > 0 && q1 <=1000000) && (p>=0 && p<1000000)){
	
	//q3 = q1 +q2;
	
	v1 = malloc(q1 * sizeof(int));
	
	for(i=0; i<q1; i++){
		
		scanf("%d", &entrada);
		
		if(entrada >=0 && entrada<= 10000){
		
		v1[i] = entrada;	
		
	}
	
	}
	mostraVetor(v1, q1);

	mergeSort(v1, 0, q1-1, q1);
	
	mostraVetor(v1, q1);	
		
	}
}
