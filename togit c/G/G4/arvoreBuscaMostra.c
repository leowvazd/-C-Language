#include <stdlib.h>
#include <stdio.h>

typedef struct tNo {
    int chave;
    struct tNo *pai, *esq, *dir;
} No;

No *criaNo (int x) {
    No *novo = malloc (sizeof (No));
    novo->chave = x;
    novo->pai = NULL;
	novo->esq = NULL;
	novo->dir = NULL;
    return novo;
}

typedef struct tArvore {
    No *raiz;
    int q;
} Arvore;

Arvore *criaArvore () {
    Arvore *t = malloc (sizeof (Arvore));
    t->raiz = NULL;
    t->q = 0;
    return t;
}

void Inserir (Arvore *arv, int x) {
    No *novo = criaNo (x);
    No *pai, *filho;
    // caso particular: arvore vazia
    if(arv->q == 0) {
        arv->raiz = novo;
        arv->q++;
    }
    // caso geral: arvore nao vazia
    else{
        // busca posicao de insercao na ABB
        pai = NULL;
        filho = arv->raiz;
        while(filho != NULL) {
            pai = filho;
            if(x > filho->chave) {
                filho = filho->dir;
            }
            else if(x < filho->chave){ // modificar se nao quiser inserir chaves repetidas!
                filho = filho->esq;
            }
            else{
            	
            	//printf("Chave %d ja existe na arvore!\n", x);
            	//free(novo);
            	return;
			}
        }
        // Neste ponto, temos que filho == NULL e pai != NULL.
        if(x > pai->chave) {
            pai->dir = novo;
        }
        else if(x < pai->chave){
            pai->esq = novo;
        }
        novo->pai = pai;
        arv->q++;
    }
} 

void imprimeMin(Arvore *arvore){
	
	No *noAtual;
	
	if(arvore->q > 0){
		
		noAtual = arvore->raiz;
		
		while(noAtual->esq != NULL){
			
			//printf("chave atual: %d\n", noAtual->chave);
			noAtual = noAtual->esq;
			
		}
		
		printf("%d\n", noAtual->chave);
	
	}
	
}

void imprimeFolha(Arvore *arvore){
	
	int i;
	No *noAtual, *noAux, *noAuxEsq, *noMax;
	
	noAtual= arvore->raiz;
	noAux= noAtual;
	noAuxEsq = noAux;
	//noAtual = noAtual->esq;  //começa na sub arvore da esquerda
	
	//printf("Busca de folha inciada!\n");
	
	if(arvore->q == 1){
		
		noAtual= arvore->raiz;
		printf("%d\n", noAtual->chave);
		
	}
	else if(arvore->q > 1){
	
	if(noAtual->esq != NULL){
	
	noAtual= noAtual->esq;
	
	while(noAtual != arvore->raiz){
		
	//	printf("procurando...\n");
		
		//printf("No atual: %d\n", noAtual->chave);
	//	printf("Aux: %d,   AuxEsq: %d\n", noAux->chave, noAuxEsq->chave);
		if(noAtual->esq == NULL && noAtual->dir == NULL/* && noAtual->esq != noAux*/){
			
		//	printf("imprimindo folha: ");
			printf("%d\n", noAtual->chave);
			
			noAuxEsq = noAux;
			noAux= noAtual;
			noAtual = noAtual->pai;
			
		}
		else if(noAtual->esq != NULL && (noAtual->esq != noAux && noAtual->esq != noAuxEsq)){
			
		//	printf("indo para esquerda\n");
			
			noAtual= noAtual->esq;
			
		}
		else if(noAtual->dir != NULL && noAtual->dir != noAux){
			
		//	printf("indo pra direita\n");
			noAtual = noAtual->dir;
			
		}
		else{
			
		//	printf("voltando para o no pai\n");
			noAux= noAtual;
			noAtual = noAtual->pai;
			
		}
	
	}
	
	}
	
	noAtual= arvore->raiz;
	noAux= noAtual;
	noAuxEsq = noAux;
	//noAtual = noAtual->dir;
	
	//printf("\n");
	//printf("Busca na sub arvore da direita:\n");
//	printf("No raiz da subarvore direita: %d\n", noAtual->chave);


	if(noAtual->dir != NULL){
		
		while(noAtual->dir != NULL){
			
			//printf("chave atual: %d\n", noAtual->chave);
			noAtual = noAtual->dir;
			
		}
	noMax = noAtual;
		
	noAtual = arvore->raiz;	
	
	noAtual= noAtual->dir;
	
	while(noAtual != arvore->raiz){
		
		//printf("procurando...\n");
		
	//	printf("No atual: %d\n", noAtual->chave);
		//printf("Aux: %d,   AuxEsq: %d\n", noAux->chave, noAuxEsq->chave);
		
		if(noAtual->esq == NULL && noAtual->dir == NULL/* && noAtual->esq != noAux*/){
			
		//	printf("imprimindo folha: ");
			printf("%d\n", noAtual->chave);
			
			if(noAtual == noMax){  // ao imprimir o maior valor da arvore, para, pq é a ultima folha
				
				return;
				
			}
			
			noAuxEsq = noAux;
			noAux= noAtual;
			noAtual = noAtual->pai;
			
		}
		else if(noAtual->esq != NULL && (noAtual->esq != noAux && noAtual->esq != noAuxEsq)){
			
		//	printf("indo para esquerda\n");
			noAtual= noAtual->esq;
			
		}
		else if(noAtual->dir != NULL && noAtual->dir != noAux){
			
		//	printf("indo pra direita\n");
			noAtual = noAtual->dir;
			
		}
		else{
			
		//	printf("voltando para o no pai\n");
			noAux= noAtual;
			noAtual = noAtual->pai;
			
		}
	
	}
	
	}
	
	}
	
}

void folha(No *no){
	
	if(no->esq == NULL && no->dir == NULL){
		
		printf("%d\n", no->chave);
		
	}
	else{
		
		if(no->esq != NULL){
			
			folha(no->esq);
			
		}
		
		if(no->dir){
			
			folha(no->dir);
			
		}
	
	}

}


int main(){
	
	int i, tamanho, entrada;
	
	Arvore *arvore = criaArvore();
	
	scanf("%d", &tamanho);
	
	if(tamanho >= 1 && tamanho <=500){
			
		for(i=0; i<tamanho; i++){
			
			scanf("%d", &entrada);
			
		/*	if(entrada >= 1 && entrada <= 500){*/
				
				Inserir(arvore, entrada);
	
			/*}*/
	
		}
		
		//imprimeFolha(arvore);
		folha(arvore->raiz);
	
	}

	return 0;
	
}
