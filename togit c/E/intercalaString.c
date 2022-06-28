#include <stdlib.h>
#include <stdio.h>

void intercalaSort (char *v, int esq, int meio, int dir) {
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
	
	


void mergeSort (char *v, int e, int d, int n) {
    int meio;
    if (e < d) {
        meio = (d+e)/2;
        mergeSort (v, e, meio, n);
        mergeSort (v, meio+1, d, n);
        
        intercalaSort (v, e, meio, d);
    }
}

void mostraVetor(char *v, int q){
	
	int i;
	
	for(i=0; i< q; i++){
		
		if(i<q-1){
		
		
		printf("%c", v[i]);
		
		}
		else{
			
			printf("%c\n", v[i]);
		}
		
	}
	
}

int main(){
	
	int i, j, q1, q2, q3;
	char entrada;
	char entradaS[10000];
	char *v1, *v2,*v3;
	
	scanf("%d ", &q1);    // recebe tamanho q1
	
	if(q1>0 && q1<=10000){
		
		v1 = malloc(q1 * sizeof(char));
		
		scanf("%s", entradaS);
			
		for(i=0 ;i< q1; i++){
		
			//printf("for da primeira string, i: %d\n", i);
			//scanf("%c", &entrada);
		
			if(entradaS[i]>= 'a' && entradaS[i] < '{'){
			
			v1[i] = entradaS[i];
			
			}
		
			}
		
		//scanf("%c", &entrada);   // captura o \n
		
		//mostraVetor(v1, q1);
		
		scanf("%d ", &q2);
		
		if(q2>0 && q2<=10000){
			
			v2 = malloc(q2 * sizeof(char));
			
			scanf("%s", entradaS);
			
			for(i=0 ;i< q2; i++){
		
			//printf("for da segunda string, i: %d\n", i);
			//scanf("%c", &entrada);
		
			if(entradaS[i]>= 'a' && entradaS[i] < '{'){
			
			v2[i] = entradaS[i];
			
			}
		
			}
			
			//scanf("%c", &entrada);   // captura o EOF
			
		//	mostraVetor(v2,q2);
			
		//	printf("agora juntar tudo no vetor 3\n");
			q3 = q1 + q2;
			
			v3 = (char*)malloc(q3 * sizeof(char));
		
			for(i=0; i< q3; i++){
				
				if(i<q1){
					
					v3[i] = v1[i];
					
				}
				else{
					
					v3[i] = v2[i -q1];
					
				}
				
				
			}

	

	
		//	mostraVetor(v3, q3);

			mergeSort(v3, 0, q3-1, q3);
	
			mostraVetor(v3, q3);
		}
		
	}
	
	return 0;	
}

