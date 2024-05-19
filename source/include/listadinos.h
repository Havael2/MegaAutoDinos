#ifndef LISTA_H
#define LISTA_H
#define NMAX 30
#include "dinos.h"

typedef struct no{
	dinos dados;
	struct no *prox;	
}Listadinos;	

Listadinos *criar_lista();
Listadinos *aloca_no();
void inserir_no_fim(Listadinos **l, dinos d);
int remover_no(Listadinos **l, char dn[NMAX]);
Listadinos *buscar_no(Listadinos *l, dinos busca);
int lista_vazia(Listadinos *l);
void tamanho_lista(Listadinos *l, int *cont);
int inserir_por_posicao(Listadinos **l, dinos d, int posicao);
void imprimir_lista(Listadinos *l);


Listadinos *criar_lista(){
	return NULL;
}

Listadinos *aloca_no(){
	Listadinos *NovoNo;
	NovoNo = (Listadinos*) malloc(sizeof(Listadinos));
	return NovoNo;
}

void inserir_no_fim(Listadinos **l, dinos d){
	Listadinos *aux, *NovoNo;
	aux = *l;
	
	NovoNo = aloca_no();
	NovoNo->dados = d;
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

void inserir_no_inicio(Listadinos **l, dinos d){
	Listadinos *aux, *NovoNo;
	aux = *l;
	
	NovoNo = aloca_no();
	NovoNo->dados = d;
	NovoNo->prox = NULL;
	
	if(lista_vazia(*l)){
	*l = NovoNo;	
	}
	else{	
	NovoNo->prox = aux;
	*l = NovoNo;		
	}
}

int remover_no(Listadinos **l, char dn[NMAX]){
	Listadinos *aux, *ant;
	aux = *l;
	ant = NULL;
	
	while(aux != NULL && strcmp(aux->dados.nome, dn) != 0){
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

Listadinos *buscar_no(Listadinos *l, char busca[NMAX]){
	Listadinos *aux;
	aux = l;
	
	while(aux != NULL && strcmp(aux->dados.nome, busca) != 0){
		aux = aux->prox;
	}	

		if(aux == NULL){
		return NULL;	
		}
		else{
		return aux;
		}		
				
}

int lista_vazia(Listadinos *l){
	if(l == NULL){
	return 1;	
	}
	else{
	return 0;	
	}
}

int tamanho_lista(Listadinos *l){
	Listadinos *aux;
	int cont = 0;
	aux = l;
	
	while(aux != NULL){
	cont++;
	aux = aux->prox;	
	}
	
	return cont;
	
}

void destruir_lista(Listadinos **l){
	Listadinos *aux;
	aux = *l;
	
	while(aux != NULL){
	*l = aux->prox;
	free(aux);
	aux = *l;	
	}
	*l = NULL;
}

int inserir_por_posicao(Listadinos **l, dinos d, int posicao){
	Listadinos *aux, *NovoNo;	
	int cont = 1;
	aux = *l;
	
	NovoNo = aloca_no();
	NovoNo->dados = d;
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

void compra(Listadinos **l1, Listadinos **l2){
	Listadinos *aux;
	int p;
	char de[NMAX];
	
	printf("Digite o nome do dinossauro: ");
	scanf(" %[^\n]s", &de);
	
	if(!lista_vazia(*l1)){
	aux = buscar_no(*l1, de);	
	}
	
	printf("Digite a posicao do dinossauro: ");
	scanf("%d", &p);
	inserir_por_posicao(l2, aux->dados, p);
	remover_no(l1, de);
}

void venda(Listadinos **l){
	char dv[NMAX];
	
	printf("Digite o nome do dinossauro: ");
	scanf(" %[^\n]s", &dv);
	
	remover_no(l, dv);
}

void imprimir_lista(Listadinos *l){
	Listadinos *aux;
	aux = l;
	
	while(aux != NULL){
	printf("Nome: %s ", aux->dados.nome);
	printf("Dano: %d ", aux->dados.dano);
	printf("Vida: %d\n\n", aux->dados.vida);
	aux = aux->prox;	
	}	
	
}

#endif	
