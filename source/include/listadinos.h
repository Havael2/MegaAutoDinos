#ifndef LISTADINOS_H
#define LISTADINOS_H

#include <stdlib.h>
#include <stdio.h>
#include "dinos.h"
#include "habilidades.h"

typedef struct no{
	dinos dados;
	struct no *ant;
	struct no *prox;	
}no;

typedef struct{
	no *ini;
	no *fim;
	int tam;
}tp_lista_dinos;

tp_lista_dinos *criar_lista();
no *aloca_no();
void inserir_no_fim(tp_lista_dinos *l, dinos d);
int remover_por_posicao(tp_lista_dinos *l, int p);
no *busca_por_posicao(tp_lista_dinos *l, int p);
int lista_vazia(tp_lista_dinos *l);
int inserir_por_posicao(tp_lista_dinos *l, dinos d, int posicao);
void imprimir_lista(tp_lista_dinos *l);


tp_lista_dinos *criar_lista(){
	tp_lista_dinos *lista; 
	lista = (tp_lista_dinos*) malloc(sizeof(tp_lista_dinos));
	lista->ini = NULL;
	lista->fim = NULL;
	lista->tam = 0;
	return lista;
}

no *aloca_no(){
	no *p;
	p = (no*) malloc(sizeof(no));
	return p;
}

void inserir_no_fim(tp_lista_dinos *l, dinos d){
	no *NovoNo;
	
	NovoNo = aloca_no();
	NovoNo->dados = d;
	
	if(lista_vazia(l)){
		NovoNo->prox = NULL;	
		NovoNo->ant = NULL;
		l->ini = l->fim = NovoNo;
	}
	else{
		NovoNo->prox = NULL;
		NovoNo->ant = l->fim;
		l->fim->prox = NovoNo;
		l->fim = NovoNo;
	}
	l->tam++;
}

void inserir_no_inicio(tp_lista_dinos *l, dinos d){
	no *NovoNo;
	
	NovoNo = aloca_no();
	NovoNo->dados = d;
	
	if(listade_vazia(l)){
		NovoNo->prox = NULL;	
		NovoNo->ant = NULL;
		l->ini = l->fim = NovoNo;
	}
	else{
		NovoNo->ant = NULL;
		NovoNo->prox = l->ini;
		l->ini->ant = NovoNo;
		l->ini = NovoNo;
	}
	l->tam++;
}

int remover_por_posicao(tp_lista_dinos *l, int p){
	no *aux;
	int cont = 1;
	aux = l->ini;
	
	while(aux != NULL && p != cont){
		aux = aux->prox;
		cont++;
	}
	
	if(listade_vazia(l)){
		return 0;
	}
	
	if(l->ini == l->fim){
		l->ini = l->fim = NULL;
	}
	else if(l->ini == aux){
		l->ini = aux->prox;
		aux->prox->ant = NULL;
	}
	else if(l->fim == aux){
		l->fim = aux->ant;
		aux->ant->prox = NULL;
	}
	else{
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;	
	}
	
	free(aux);
	l->tam--;
	return 1;
}

int lista_vazia(tp_lista_dinos *l){
	if(l->ini == NULL && l->fim == NULL){
	return 1;
	}
	else{
	return 0;	
	}
}

no *busca_por_posicao(tp_lista_dinos *l, int p){
	no *aux;
	int cont = 1;
	aux = l->ini;
	
	while(aux != NULL && p != cont){
		aux = aux->prox;
		cont++;
	}
	
		if(aux == NULL){
		return NULL;	
		}
		else{
		return aux;
		}
}

void destruir_lista(tp_lista_dinos *l){
	no *aux;
	aux = l->ini;
	
	while(aux != NULL){
	l->ini = aux->prox;	
	free(aux);	
	aux = l->ini;	
	}
	
	l->ini = l->fim = NULL;
}

int inserir_por_posicao(tp_lista_dinos *l, dinos d, int posicao){
	no *aux, *NovoNo;
	int cont = 2;
	aux = l->ini;
	
	NovoNo = aloca_no();
	NovoNo->dados = d;
	
	if(posicao == 1 || listade_vazia(l)){
		NovoNo->prox = l->ini;	
		NovoNo->ant = NULL;
		l->ini = l->fim = NovoNo;
		return 1;
	}
	
	while(aux != NULL && cont < posicao){
		aux = aux->prox;
		cont++;
	}
	
	if(aux == NULL || posicao < 1){
		free(NovoNo);
		return 0;
	}
	else if(aux == l->fim){
	NovoNo->prox = NULL;
	NovoNo->ant = l->fim;
	l->fim->prox = NovoNo;
	l->fim = NovoNo;	
	}
	else{
	NovoNo->prox = aux->prox;
	NovoNo->ant = aux;
	return 1;	
	}
}

void imprimir_lista(tp_lista_dinos *l){
	no *aux;
	aux = l->ini;
	
	while(aux != NULL){
	printf("Nome: %s \n", aux->dados.nome);
	printf("Dano: %d \n", aux->dados.dano);
	printf("Vida: %d\n\n", aux->dados.vida);
	aux = aux->prox;	
	}	
	
}

#endif
