#include <stdlib.h>
#include <stdio.h>

typedef struct tNo {
    int chave;
    struct tNo *pai, *esq, *dir;
} No;

No *criaNo (int x) {
    No *novo = malloc (sizeof (No));
    novo->chave = x;
    novo->pai = novo->esq = novo->dir = NULL;
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
            	free(novo);
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

void imprimeMax(Arvore *arvore){
	
	No *noAtual;
	
	if(arvore->q > 0){
		
		noAtual = arvore->raiz;
		
		while(noAtual->dir != NULL){
			
			//printf("chave atual: %d\n", noAtual->chave);
			noAtual = noAtual->dir;
			
		}
		
		//noAtual = arvore->raiz;
		
		printf("%d\n", noAtual->chave);
	
	}
	
}


int main(){
	
	int i, tamanho, entrada;
	
	Arvore *arvore = criaArvore();
	
	scanf("%d", &tamanho);
	
	if(tamanho >= 1 && tamanho <=500){
			
		for(i=0; i<tamanho; i++){
			
			scanf("%d", &entrada);
			
			/*if(entrada >= 0 && entrada <= 500){*/
				
				Inserir(arvore, entrada);
	
			/*}*/
	
		}
		
		imprimeMax(arvore);
	
	}

	return 0;
	
}
