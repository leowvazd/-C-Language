#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tDisciplina {
 int cod;
 char *nome;
 int creditos;
 struct tDisciplina *requisito;
} Disciplina;

typedef struct tCurso {
 int cod_curso;
 char *nome_curso;
 Disciplina *ultima_disciplina;
} Curso;

Curso * criaCurso (int cod_curso, char *nome_curso){
	
	Curso *curso = malloc(sizeof(Curso));
	
	curso->cod_curso = cod_curso;
	curso->nome_curso = nome_curso;
	curso->ultima_disciplina = NULL;
	
	return curso;
	
}

Disciplina * criaDisciplina (int cod, char *nome, int creditos){


	Disciplina *disciplina = malloc(sizeof(Disciplina));
	
	disciplina->nome = nome;
	disciplina->cod = cod;
	disciplina->creditos = creditos;
	disciplina->requisito = NULL;
	
	return disciplina;
	
}

void insereDisciplina (Curso *curso, Disciplina *nova_disciplina){
	
	Disciplina *disciplinaAtual, *disciplinaAux;
	
	if(curso->ultima_disciplina == NULL){
		
		curso->ultima_disciplina = nova_disciplina;
		
	}
	else{
		
		disciplinaAtual = curso->ultima_disciplina;
		disciplinaAux = NULL;
		
		//printf("puxou a ultima disciplina e criou a aux\n");
		
		while(strcmp(disciplinaAtual->nome, nova_disciplina->nome) > 0 && disciplinaAtual->requisito != NULL){
			
			//printf("procurando a posicao da nova disciplina\n");
			
			disciplinaAux= disciplinaAtual;
			disciplinaAtual = disciplinaAtual->requisito;
		}
		
		//printf("passou do while\n");
		
		if(strcmp(disciplinaAtual->nome, nova_disciplina->nome) != 0){ // Se nao, a disciplina ja esta no curso, ignore a inserçao	
		
		if(disciplinaAtual->requisito == NULL){  // Estamos no inicio do curso
			
			if(disciplinaAux == NULL){  // so tem um elemento no curso
				
				if(strcmp(disciplinaAtual->nome, nova_disciplina->nome) > 0){ // a disciplina atual é maior que a nova
					
					disciplinaAtual->requisito = nova_disciplina;
					
				}
				else{                                                       // a disciplina atual é menor que a nova
					
					nova_disciplina->requisito = disciplinaAtual;
					curso->ultima_disciplina = nova_disciplina;
				}
				
			}
			else{
				
				if(strcmp(disciplinaAtual->nome, nova_disciplina->nome) > 0){ // a disciplina atual é maior que a nova
					
					disciplinaAtual->requisito = nova_disciplina;
					
				}
				else{                                                       // a disciplina atual é menor que a nova e a anterior é maior

					disciplinaAux->requisito = nova_disciplina;
					nova_disciplina->requisito = disciplinaAtual;
			
				}
	
			}
	
		}
		else{
			
			if(disciplinaAux != NULL){       // tem disciplinas para baixo, mas nao eh a primeira
			
			
			disciplinaAux->requisito = nova_disciplina;
			nova_disciplina->requisito = disciplinaAtual;
			
			}
			else{
				
				
				nova_disciplina->requisito = disciplinaAtual;
				curso->ultima_disciplina = nova_disciplina;
				
			}
			
		}
	
	}	
		
	}
	
}

void imprime (Curso *c) {
 printf ("Disciplinas do curso: cod=%d nome=%s\n",
 c->cod_curso, c->nome_curso);
 Disciplina *d = c->ultima_disciplina;
 while (d != NULL) {
 printf ("cod=%d nome=%s cred=%d\n", d->cod, d->nome, d->creditos);
 d = d->requisito;
 }
}

int main () {
 int cod_curso;
 char nome_curso[100];
 scanf ("%d", &cod_curso);
 scanf ("%s", nome_curso);
 Curso *c = criaCurso (cod_curso, nome_curso);

 int cod, creditos, i=0;
 char *nome = NULL;
 while (scanf ("%d", &cod) != EOF /*&& i< 8*/) {
 nome = malloc (100);
 scanf ("%s %d", nome, &creditos);
 Disciplina *d = criaDisciplina (cod, nome, creditos);
 insereDisciplina (c, d);
 //i++;
 }
 imprime (c);
 return 0;
}
