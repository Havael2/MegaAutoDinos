#ifndef BATALHA_H
#define BATALHA_H

#include "listadinos.h"
#include "filadinos.h"
#include "nomegrupo.h"
#include "dinos.h"
#include <string.h>

FilaSE* transferir_lista_para_fila(tp_lista_dinos *l, FilaSE *f) {
    no *aux;
    aux = l->ini;

    while (aux != NULL) {
        enfileirase(f, aux->dados);
        aux = aux->prox;
    }
    return f;
}

void embaralha_fila (FilaSE *f){
	
 	for (int i = 1; i <= 4; i++){
 		enfileirase (f,especies(rand()%TAMesp));
	 }
}

int batalha(FilaSE *clone, char *nomeG) {
    dinos d;
    FilaSE *bot;
    int rcont = 1;
    bot = criar_filase();
    char nomeBot[40];
    definir_nome_aleatorio(nomeBot);
    embaralha_fila(bot);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n-------------------------------BATALHA 1-------------------------------\n");
    printf("\n            %s   VS   %s (bot)\n", nomeG, nomeBot);
    printf("\n-----------------------------------------------------------------------\n");
    system("pause");
    
    while (!filase_vazia(clone) && !filase_vazia(bot)) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n--Formacao do grupo %s--\n\n", nomeG);
        imprimir_fila(clone);
        printf("\n--Formacao do grupo: %s--\n\n", nomeBot);
        imprimir_fila(bot);

        clone->ini->dados.vida -= bot->ini->dados.dano;
        bot->ini->dados.vida -= clone->ini->dados.dano;

        printf("\n\nROUND %d\n", rcont);
        printf("\n%s      VS     %s\n", clone->ini->dados.nome, bot->ini->dados.nome);
        printf("\nVida: %d           %d\n", clone->ini->dados.vida, bot->ini->dados.vida); 
        printf("\nDano: %d           %d\n", clone->ini->dados.dano, bot->ini->dados.dano); 
        
        if (clone->ini->dados.vida <= 0) 
            desenfileirase(clone, &d);
        if (bot->ini->dados.vida <= 0)
            desenfileirase(bot, &d);
        
        rcont++;
        system("pause");
    }

    if (filase_vazia(clone) && filase_vazia(bot)) {
        printf("\n\nFim da batalha\nResultado: EMPATE\n");
        system("pause");
        return 0; 
    }
    if (filase_vazia(clone)) {
        printf("\n\nFim da batalha\nResultado: DERROTA\n");
        system("pause");
        return -1; 
    }
    if (filase_vazia(bot)) {
        printf("\n\nFim da batalha\nResultado: VITORIA\n");
        system("pause");
        return 1; 
    }
}

#endif

