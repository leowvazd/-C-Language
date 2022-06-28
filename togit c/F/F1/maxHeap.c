#include <stdlib.h>
#include <stdio.h>

/*typedef struct tNo no;
typedef struct tArvore arvore;
struct tNo {
    int chave;
    struct tNo *pai, *esq, *dir;
};

no *criaNo (int x) {
    no *novo = malloc (sizeof (no));
    novo->chave = x;
    novo->pai = novo->esq = novo->dir = NULL;
    return novo;
}

struct tArvore {
    no *raiz;
    int q;
};

arvore *criaArvore (arvore *arv) {
    arvore *t = malloc (sizeof (arvore));
    t->raiz = NULL;
    t->q = 0;
    return t;
}*/


/*void peneirar(int *v, int tamanho){  // algoritmo nao volta pra re peneirar
	
	printf("peneirando:\n");
	
	int i, aux;
	
	for(i = ((tamanho)/2)-1; i>=0; i--){
		
		if((v[i] < v[(2*i) +1] && ((2*i) +1) < tamanho) || (v[i] < v[(2*i) +2]&& ((2*i) +2) < tamanho)){
			
			printf("     v[%d]:%d     \n", i, v[i]);
			printf("ve[%d]:%d    vd[%d]:%d\n", ((2*i) +1), v[(2*i) +1], ((2*i) +2), v[(2*i) +2]);
			
			if(v[(2*i) +1] > v[(2*i) +2] || ((2*i) +2) >= tamanho){
				
				aux = v[i];
				printf("aux: %d\n", aux);
				v[i] = v[(2*i) +1];
				printf("v[%d]:%d\n", i, v[i]);
				v[(2*i) +1] = aux;
				printf("v[%d]:%d\n", ((2*i) +1), v[(2*i) +1]);
			}
			else{
				
				aux = v[i];
				v[i] = v[(2*i) +2];
				v[(2*i) +2] = aux;
				
			}
	
		}	
		
	}
	
}*/

int peneirar(int *v, int i, int tamanho){
	
//	printf("peneirando:\n");
//	printf("i recebido: %d\n", i);
	int j, aux;
		
	if((v[i] < v[(2*i) +1] && ((2*i) +1) < tamanho) || (v[i] < v[(2*i) +2]&& ((2*i) +2) < tamanho)){
			
	//	printf("     v[%d]:%d     \n", i, v[i]);
	//	printf("ve[%d]:%d    vd[%d]:%d\n", ((2*i) +1), v[(2*i) +1], ((2*i) +2), v[(2*i) +2]);
			
		if(v[(2*i) +1] > v[(2*i) +2] || ((2*i) +2) >= tamanho){  // vai trocar pelo no da esquerda
				
			aux = v[i];
		//	printf("aux: %d\n", aux);
			v[i] = v[(2*i) +1];
		//	printf("v[%d]:%d\n", i, v[i]);
			v[(2*i) +1] = aux;
		//	printf("v[%d]:%d\n", ((2*i) +1), v[(2*i) +1]);
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
	
	//	printf("i: %d\n", i);
		i =peneirar(v, i, tamanho);
	
	}
	
//	printf("i: %d\n", i);	
	
}

/*void mostraArvore(no *atual){

	if(atual != NULL){
		
		printf("%d ", atual->chave);
		
		mostraArvore(atual->esq);
		
		mostraArvore(atual->dir);
		
		
	}
	
}*/

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
	char c;
	//arvore *arv;
	
	scanf("%d", &tamanho);
	if(tamanho>100 || tamanho <=0){
		
		return;
	}
	//fflush(stdin);
	while(tamanho != 0){
		
		//printf("recebendo primeiro vetor\n");
		v = malloc (tamanho * sizeof(int));
	//	printf("vetor alocado!\n");
		//mostraVetor(v, tamanho);
		//arv = criaArvore(arv);
		
		for(i=0; i< tamanho; i++){
		//	printf("i: %d\n", i);
			scanf("%d%c", &entrada, &c);
			v[i] = entrada;
		//	printf("c: %c    entrada: %d\n", c, entrada);
		//	printf("v[%d]:%d\n", i, v[i]);
		//Inserir(arv, entrada);
			
			
		}
		
		//printf("iniciando heap\n");
		//peneirar(v, tamanho);
		construirHeap(v, tamanho);
		//printf("heap concluido\n");
		//mostraArvore(arv->raiz);
		
		mostraVetor(v, tamanho);
		
		//free(v);
		
		scanf("%d", &tamanho);	
		
		if(tamanho>100 || tamanho <=0){
		
			return;
		}
		
	}
	
	
	
	return 0;
	
}
