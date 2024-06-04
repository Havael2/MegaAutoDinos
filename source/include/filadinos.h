#ifndef FILASE_H
#define FILASE_H

typedef int
	valor;
	
typedef struct no{
	valor item;
	struct no *prox;
}no;	

typedef struct{
	no *ini;
	no *fim;
	valor tam;	
}FilaSE;

FilaSE *criar_filase();
no *aloca_no();
void enfileirase(FilaSE *f, valor e);
int desenfileirase(FilaSE *f, valor *r);
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

no *aloca_no(){
	no *f;
	f = (no*) malloc(sizeof(no));
	return f;
}

void enfileirase(FilaSE *f, valor e){
	no *NovoNo;
	
	NovoNo = aloca();
	NovoNo->item = e;
	NovoNo->prox = NULL;
	
	if(filase_vazia(f)){
	f->ini = NovoNo;
	}
	else{
	f->fim->prox = NovoNo;	
	}
	f->fim = NovoNo;
	f->tam++;
}

int desenfileirase(FilaSE *f, valor *r){
	no *aux;
	
	if(filase_vazia(f)){
	return 0;	
	}	
	
	*r = f->ini->item;
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
	no *aux;
	valor d;
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
	return f->ini->item;
}

int ultimo_filase(FilaSE *f){
	return f->fim->item;
}

int tamanho_filase(FilaSE *f){
	return f->tam;
}

void imprimir_fila(FilaSE *f){
    FilaSE *f_aux;
    valor i;
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
