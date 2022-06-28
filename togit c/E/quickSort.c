#include <stdlib.h>
#include <stdio.h>
#include <string.h>


	
	
int particiona (int *v, int e, int d, int p, int n) {
    int i = e, pm = e-1;
    // troca v[p] <-> v[d]
    int tmp = v[p];
    v[p] = v[d];
    v[d] = tmp;
    p = d;
    while (i < d) {
        if (v[i] <= v[p]) {
            pm++;
            // troca v[i] <-> v[pm]
            tmp = v[i];
            v[i] = v[pm];
            v[pm] = tmp;
        }
        i++;
        mostraVetor (v, n);
    }
    pm++;
    // troca v[p] <-> v[pm]
    tmp = v[i];
    v[i] = v[pm];
    v[pm] = tmp;
    mostraVetor (v, n);
    
    return pm;
}

void quickSort (int *v, int e, int d, int n) {
    if (e < d) {
        int p = d;
        int pm = particiona (v, e, d, p, n);
        quickSort (v, e, pm-1, n);
        quickSort (v, pm+1, d, n);
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
	
	int i, q1, entrada;
	int *v1;
	
	scanf("%d", &q1);    // recebe tamanho

	
	if(q1 > 0 && q1 <=10000){

	v1 = malloc(q1 * sizeof(int));
	
	for(i=0; i<q1; i++){
		
		scanf("%d", &entrada);

		v1[i] = entrada;	

	}
	
	mostraVetor(v1, q1);
	
	quickSort(v1, 0, q1-1, q1);
	
	mostraVetor(v1, q1);	
		
	}
}
