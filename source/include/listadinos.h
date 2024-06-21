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
int tamanho_lista(tp_lista_dinos *l);
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
	
	if(listade_vazia(l)){
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

int listade_vazia(tp_lista_dinos *l){
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

void compra(tp_lista_dinos *loja, tp_lista_dinos *grupo) {
    no *aux;
    int p1, p2;

    do {
        printf("Digite a posicao do dinossauro a venda (1, 2, ..., 5): ");
        scanf("%d", &p1);
        if (p1 < 1 || p1 > 5) {
            printf("A posicao do dinossauro nao pode ser menor que 1 ou maior que 5.\n");
        }
    } while (p1 < 1 || p1 > 5);

    if (!listade_vazia(loja)) {
        aux = busca_por_posicao(loja, p1);
    }

    do {
        printf("Defina a posicao do dinossauro no time (1, 2, ..., 5): ");
        scanf("%d", &p2);
        if (p2 < 1 || p2 > 5) {
            printf("A posicao do dinossauro no time nao pode ser menor que 1 ou maior que 5.\n");
        }
    } while (p2 < 1 || p2 > 5);

    inserir_por_posicao(grupo, aux->dados, p2);
    remover_por_posicao(loja, p1);
	tabelaL(aux);
}

void venda(tp_lista_dinos *l){
	int p;
	printf("Digite a posicao do dinossauro no time (1,2,...): ");
	scanf("%d", &p);
	
	remover_por_posicao(l, p);
}

void embaralharGrupo(tp_lista_dinos *dloja, int n) { // Funcao que gera os dinos na loja e os imprimem
	int i;
	for(i=1;i<=n;i++){
	inserir_no_fim(dloja, especies(rand()%TAMesp));	
	}
}

void trocar_posicao(tp_lista_dinos *grupo) {
    int posicao1, posicao2;
    no *dinossauro1, *dinossauro2;

    printf("Digite a posicao do primeiro dinossauro (1 a 5): ");
    scanf("%d", &posicao1);
    printf("Digite a posicao do segundo dinossauro (1 a 5): ");
    scanf("%d", &posicao2);

    if (posicao1 < 1 || posicao1 > 5 || posicao2 < 1 || posicao2 > 5) {
        printf("Posicoes invalidas. Certifique-se de que as posicoes estao entre 1 e 5.\n");
        return;
    }

    dinossauro1 = busca_por_posicao(grupo, posicao1);
    dinossauro2 = busca_por_posicao(grupo, posicao2);

    if (dinossauro1 == NULL || dinossauro2 == NULL) {
        printf("Nao foi possivel encontrar um dinossauro em uma das posicoes especificadas.\n");
        return;
    }

    dinos temp = dinossauro1->dados;
    dinossauro1->dados = dinossauro2->dados;
    dinossauro2->dados = temp;

    printf("Dinossauros trocados de posicao com sucesso!\n");
}

void comida(tp_lista_dinos *grupo){
	no *aux;
	int p;
	char opc;
	
	printf("m - Morango(+3 de vida para o dinossauro)\n");
	printf("s - Suco(+2 de vida para o dinossauro e +1 de vida para dois antecessores)\n");
	printf("p - Pao(+3 de dano para o dinossauro)\n");
	printf("c - Carne(+4 de dano para o dinossauro e +2 de dano para dois dinossauros proximos)\n");
	printf("Escolha sua opcao: ");
	scanf(" %c", &opc);
	
	switch(opc){
		
		case 'm':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);	
		aux = busca_por_posicao(grupo, p);
		aux->dados.vida+=3;
		break;
		
		case 's':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);
		aux = busca_por_posicao(grupo, p);
		aux->dados.vida+=2;
		if(aux->ant != NULL){
		aux->ant->dados.vida+=1;	
		}
		break;
		
		case 'p':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);
		aux = busca_por_posicao(grupo, p);
		aux->dados.dano+=3;
		break;
		
		case 'c':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);
		aux = busca_por_posicao(grupo, p);
		aux->dados.dano+=4;
		if(aux->ant != NULL){
		aux->ant->dados.dano+=2;	
		}
		if(aux->prox != NULL){
		aux->prox->dados.dano+=2;	
		}
		break;
		
		default:
        return;
        break;
	}
	
}

#endif
