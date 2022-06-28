#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	
	int i, j, q1, q2, q3, verificador=0;
	char entrada;
	char entradaS[20000];
	char *v1, *v2,*v3;
	
	scanf("%s", entradaS);
	
	for(i=0; i<strlen(entradaS); i++){
		
		if(entradaS[i] == '\n'){
			
			break;
		}
		else if(entradaS[i] < 'a' || entradaS[i] > 'z'){
			
			printf("i: %d, char %c invalido!\n", i, entradaS[i]);
			verificador=1;
			break;
		}
		
	}
	
	if(verificador == 0){
	
		scanf("%d %d", &q1, &q2);    // recebe tamanho q1
	
		if((q1>0 && q2<=10000) && (q2>0 && q2<=10000)){
		
		q3 = q1 +q2;
		
		v3 = malloc (q3 * sizeof(char));
		
		for(i=0 ;i< q3; i++){
		
			v3[i] = entradaS[i];

		}

	

	
		//	mostraVetor(v3, q3);

			mergeSort(v3, 0, q3-1, q3);
	
			mostraVetor(v3, q3);
		
		
	}
	}
	return 0;	
}

