#ifndef PILHADINOS_H
#define PILHADINOS_H
#include <stdio.h>
#define MAX 4

typedef struct{
    int vida;
    int dano;
    char nome[30];
} dinos;

typedef struct{
    int topo;
    dinos animais[MAX];
} tp_pilha;

void inicializarPilha(tp_pilha *p){
	p->topo = -1;
}

int vazia_pilha(tp_pilha *p){
	if(p->topo == -1){
		return 1;	
	}
	else{
		return 0;	
	}
}

int cheia_pilha(tp_pilha *p){
	if(p->topo == MAX-1){
	return 1;	
	}
	else{
	return 0;	
	}
}

void push(tp_pilha *p, dinos d){
	if(cheia_pilha(p) == 0){
	p->topo++;
	p->animais[p->topo] = d;	
	}
	else{
	printf("PILHA CHEIA\n");	
	}
}

void pop(tp_pilha *p, dinos *d){
	if(vazia_pilha(p) == 0){
		*d = p->animais[p->topo];
		p->topo--;		
	}
	else{
	printf("PILHA VAZIA\n");	
	}
	
}

int tamanho_pilha(tp_pilha *p){
	return p->topo+1;
}

void imprimirPilha(tp_pilha *p){
    int i;
    for(i=p->topo;i>=0;i--){	
    printf("Especie: %s ", p->animais[i].nome);
    printf("Vida: %d ", p->animais[i].vida);
    printf("Dano: %d\n", p->animais[i].dano);    
    }
}

#endif
