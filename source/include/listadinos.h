#ifndef LISTA_H
#define LISTA_H
#define NMAX 30
#include "dinos.h"

typedef struct no{
	dinos inscricao;
	struct no *prox;	
}Listadinos;	

Lista *criar_lista();
Lista *aloca_no();
void inserir_no_fim(Lista **l, dinos ins);
int remover_no(Lista **l, dinos rnc);
Lista *buscar_no(Lista *l, dinos busca);
int lista_vazia(Lista *l);
void tamanho_lista(Lista *l, int *cont);
void imprimir_lista(Lista *l);


Lista *criar_lista(){
	return NULL;
}

Lista *aloca_no(){
	Lista *NovoNo;
	NovoNo = (Lista*) malloc(sizeof(Lista));
	return NovoNo;
}

void inserir_no_fim(Lista **l, Candidato ins){
	Lista *aux, *NovoNo;
	aux = *l;
	
	NovoNo = aloca_no();
	NovoNo->inscricao = ins;
	NovoNo->prox = NULL;
	
	if(lista_vazia(*l)){
	*l = NovoNo;	
	}
	else{
		while(aux->prox != NULL){
		aux = aux->prox;
		}
		aux->prox = NovoNo;	
	}
	
}

void inserir_no_inicio(Lista **l, Candidato inc){
	Lista *aux, *NovoNo;
	aux = *l;
	
	NovoNo = aloca_no();
	NovoNo->inscricao = inc;
	NovoNo->prox = NULL;
	
	if(lista_vazia(*l)){
	*l = NovoNo;	
	}
	else{	
	NovoNo->prox = aux;
	*l = NovoNo;		
	}
}

int remover_no(Lista **l, char rnc[NMAX]){
	Lista *aux, *ant;
	aux = *l;
	ant = NULL;
	
	while(aux != NULL && strcmp(aux->inscricao.nome, rnc) != 0){
		ant = aux;
		aux = aux->prox;
	}

	if(lista_vazia(*l)){
	printf("LISTA VAZIA\n");
	return 0;	
	}
	if(ant == NULL){
	*l = aux->prox;	
	}
	else{
	ant->prox = aux->prox;
	}
	
	free(aux);
	aux = NULL;
	return 1;
}

Lista *buscar_no(Lista *l, char busca[NMAX]){
	Lista *aux;
	aux = l;
	
	while(aux != NULL && strcmp(aux->inscricao.nome, busca) != 0){
		aux = aux->prox;
	}	

		if(aux == NULL){
		return NULL;	
		}
		else{
		return aux;
		}		
				
}

int lista_vazia(Lista *l){
	if(l == NULL){
	return 1;	
	}
	else{
	return 0;	
	}
}

void tamanho_lista(Lista *l, int *cont){
	Lista *aux;
	*cont = 0;
	aux = l;
	
	while(aux != NULL){
	(*cont)++;
	aux = aux->prox;	
	}
	
}

void destruir_lista(Lista **l){
	Lista *aux;
	aux = *l;
	
	while(aux != NULL){
	*l = aux->prox;
	free(aux);
	aux = *l;	
	}
	*l = NULL;
}

int inserir_por_posicao(Lista **l, Candidato ip, int posicao){
	Lista *aux, *NovoNo;	
	int cont = 1;
	aux = *l;
	
	NovoNo = aloca_no();
	NovoNo->inscricao = ip;
	NovoNo->prox = NULL;
	
	if(posicao == 0 || lista_vazia(*l)){
		NovoNo->prox = *l;
		*l = NovoNo;
		return 1;
	}
	
	while(aux != NULL && cont < posicao){
		aux = aux->prox;
		cont++;
	}
	
	if(aux == NULL || posicao < 0){
		free(NovoNo);
		return 0;
	}
	else{
	NovoNo->prox = aux->prox;
	aux->prox = NovoNo;
	return 1;	
	}
}

void imprimir_lista(Lista *l){
	Lista *aux;
	aux = l;
	
	while(aux != NULL){
	printf("Nome: %s ", aux->inscricao.nome);
	printf("Registro: %d\n", aux->inscricao.registro);
	aux = aux->prox;	
	}	
	
}

#endif	
