#ifndef FILASE_H
#define FILASE_H
#include "dinos.h"

typedef struct nof{
	dinofs dados;
	struct nof *prox;
}nof;	

typedef struct{
	nof *ini;
	nof *fim;
	int tam;	
}FilaSE;

FilaSE *criar_filase();
nof *aloca_nof();
void enfileirase(FilaSE *f, dino e);
int desenfileirase(FilaSE *f, dino *r);
int filase_vazia(FilaSE *f);
int primeiro_fila(Fila *f);
int ultimo_fila(Fila *f);
void imprimir_fila(Fila *f);

FilaSE *criar_filase(){
	FilaSE fila;
	fila = (FilaSE*) malloc(sizeof(FilaSE));
	fila->ini = fila->fim = NULL;
	fila->tam = 0;
	return fila;	
}

nof *aloca_nof(){
	nof *f;
	f = (nof*) malloc(sizeof(nof));
	return f;
}

void enfileirase(FilaSE *f, dino e){
	nof *nofvonof;
	
	nofvonof = aloca();
	nofvonof->dados = e;
	nofvonof->prox = NULL;
	
	if(filase_vazia(f)){
	f->ini = nofvonof;
	}
	else{
	f->fim->prox = nofvonof;	
	}
	f->fim = nofvonof;
	f->tam++;
}

int desenfileirase(FilaSE *f, dino *r){
	nof *aux;
	
	if(filase_vazia(f)){
	return 0;	
	}	
	
	*r = f->ini->dados;
	aux = f->ini;
	
	if(f->ini == f->fim){
	f->ini = f->fim = NULL;	
	}
	else{
	f->ini = f->ini->prox;	
	}
	
	free(aux);
	f->tam--;
	return 1;
}

int filase_vazia(FilaSE *f){
	if(f->ini == NULL){
	return 1;	
	}
	return 0;	
}

FilaSE *destruir_fila(FilaSE *f){
	nof *aux;
	dino d;
	aux = f->ini;
	
	while(aux != NULL){
	desenfileirase(f, &d);
	aux = aux->prox;	
	}
	
	f->ini = f->fim = NULL;
	free(f);
	return NULL;
}

int primeiro_filase(FilaSE *f){
	return f->ini->dados;
}

int ultimo_filase(FilaSE *f){
	return f->fim->dados;
}

int tamanho_filase(FilaSE *f){
	return f->tam;
}

void imprimir_fila(FilaSE *f){
    FilaSE *f_aux;
    dino i;
	f_aux = criar_filase();
     
	while(!filase_vazia(f)){
    	desenfileirase(f,&i);
		printf("%d ", i);
    	enfileirase(f_aux, i);           
    }

    f->ini = f_aux->ini; 
    f->fim = f_aux->fim; 
    f_aux->ini = NULL;
    f_aux->fim = NULL;
    f_aux = destruir_fila(f_aux);
    printf("\n");
}

#endif
