#include <stdlib.h>
#include <stdio.h>
#include <string.h>


	
	
void particiona (int *v, int e, int d, int p, int n) {
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
        //imprime (v, n);
    }
    pm++;
    // troca v[p] <-> v[pm]
    tmp = v[i];
    v[i] = v[pm];
    v[pm] = tmp;
    //imprime (v, n);
    
}



void mostraVetor(int *v, int q){
	
	int i;
	
	for(i=0; i< q; i++){
		
		printf("%d\n", v[i]);
	
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

		v1[i] = entrada;	

	}
	
	particiona(v1, 0, q1-1, p, q1);
	
	mostraVetor(v1, q1);	
		
	}
}
