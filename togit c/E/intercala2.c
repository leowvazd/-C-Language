#include <stdlib.h>
#include <stdio.h>

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
        
        intercalaSort (v, e, meio, d);
    }
}

void mostraVetor(int *v, int q){
	
	int i;
	
	for(i=0; i< q; i++){
		
		printf("%d\n", v[i]);
		
	}
	
}

int main(){
	
	int i, q1, q2, q3, entrada;
	int *v3;
	
	scanf("%d", &q1);    // recebe tamanhos
	scanf("%d", &q2);
	
	if((q1 > 0 && q1 <=500000) && (q2 > 0 && q2 <=500000)){
	
	q3 = q1 +q2;
	
	v3 = malloc(q3 * sizeof(int));
	
	for(i=0; i<(q1 + q2); i++){
		
		scanf("%d", &entrada);
		
		if(entrada >=0 && entrada<= 999999){
		
		v3[i] = entrada;	
		
	}
	
	}
	

	mergeSort(v3, 0, q3-1, q3);
	
	mostraVetor(v3, q3);	
		
	}
}
