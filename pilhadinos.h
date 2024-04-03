#ifndef PILHADINOS_H
#define PILHADINOS_H
#define MAX 21

typedef struct{
    int vida;
    int dano;
    char nome[30];
} dinos;

typedef struct{
    int topo;
    dinos animais[MAX];
} tp_pilha;

void inicializarPilha(tp_pilha *p);
void push(tp_pilha *p, dinos l);
void pop(tp_pilha *p, dinos *l);
int vazia_pilha(tp_pilha *p);
int cheia_pilha(tp_pilha *p);
dinos topo_pilha(tp_pilha *p);
int tamanho_pilha(tp_pilha *p);
void imprimirPilha(tp_pilha *p);

void inicializarPilha(tp_pilha *p){
	p->topo = -1;
}

void push(tp_pilha *p, dinos d){
	if(cheia_pilha(p) == 0){
	p->topo++;
	p->dados[p->topo] = l;	
	}
	else{
	printf("tp_pilha CHEIA\n");	
	}
}

void pop(tp_pilha *p, dinos *d){
	if(vazia_pilha(p) == 0){
	*l = p->dados[p->topo];
	p->topo--;		
	}
	else{
	printf("tp_pilha VAZIA\n");	
	}
	
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

dinos topo_pilha(tp_pilha *p){
	return p->dados[p->topo];
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
