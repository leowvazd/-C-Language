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


void removeNo(Arvore *arvore, int valor){
	
	No *noAtual, *noPai, *noAux, *noAux2;
	
	noPai = NULL;
	noAtual = arvore->raiz;
	
	while(noAtual != NULL && noAtual->chave != valor){
		
		noPai = noAtual;
		
		if(noAtual->chave > valor){
			
			noAtual= noAtual->esq;
			
		}
		else{
			
			noAtual= noAtual->dir;
			
		}	
		
	}
	
	if(noAtual != NULL){ // se for null, o valor nao esta na arvore
		
		if(noAtual->dir == NULL && noAtual->esq == NULL){ // no encontrado eh folha
			
			if(noPai == NULL){
				
				arvore->raiz = NULL;
				arvore->q--;
				
			}
			else if(noAtual == noPai->esq){
				
				noPai->esq = NULL;
				free(noAtual);
			}
			else{
				
				noPai->dir = NULL;
				free(noAtual);
			}
			
			arvore->q--;
			
		}
		else{
			
			if(noPai != NULL){
			
			
			if(noAtual->dir == NULL){
				
				noAux= noAtual->esq;
				
				if(noAtual->pai == NULL){ // raiz da arvore
					
					arvore->raiz = noAux
					
					free(noAtual);
					
				}			
				else if(noAtual == noPai->esq){
					
					noPai->esq = noAux;
					noAux->pai = noPai;
					free(noAtual);
				}
				else{
					
					noPai->dir = noAux;
					noAux->pai = noPai;
					free(noAtual);
				}
				
				arvore->q--;
				
			}
			else if(noAtual->esq == NULL){
				
				noAux= noAtual->dir;
				
				if(noAtual->pai == NULL){ // raiz da arvore
					
					arvore->raiz = noAux
					
					free(noAtual);
					
				}			
				else if(noAtual == noPai->esq){
					
					noPai->esq = noAux;
					noAux->pai = noPai;
					free(noAtual);
				}
				else{
					
					noPai->dir = noAux;
					noAux->pai = noPai;
					free(noAtual);
				}
				
				arvore->q--;
					
			}
			else{ // no tem dois filhos
				
				noAux= noAtual->dir;
				
				while(noAux->esq != NULL){
					
					noAux= noAux->esq;
				}
				
				noAux2 = noAux->pai;
				
				
				if(noAux == noAux2->dir){
					
					if(noAtual == noPai->esq){
						
						noPai->esq = noAux;
						noAux->pai = noPai;
						arvore->q--;
						free(noAtual);
					}
					else{
						
						noPai->dir = noAux;
						noAux->pai = noPai;
						arvore->q--;
						free(noAtual);
					}	
				}
				else{
					
					
					
				}
				
				
			}
		
		}
			
			
		}
		
		
		
		
		
	}
	
	
	
	
	
	
	
}

int main(){
	
	int i, tamanho, entrada, qRemove;
	
	
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
		//folha(arvore->raiz);
	
	}
	
	scanf("%d", &qRemove);
	
	if(qRemove>= 1 && qRemove <= tamanho){
		
		
		for(i=0; i<qRemove; i++){
			
			scanf("%d", &entrada);
			//removeNo(arvore, entrada);
			
		}
		
		
		
	}
	

	return 0;
	
}
