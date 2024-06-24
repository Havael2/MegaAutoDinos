#ifndef BATALHA_H
#define BATALHA_H

#include <string.h>
#include "dinos.h"
#include "nomegrupo.h"
#include "habilidades.h"
#include "listadinos.h"
#include "filadinos.h"

FilaSE* lisFil(tp_lista_dinos *l){

    FilaSE *f = criar_filase();
    no *n = l->ini;

    while(n!=NULL){
        enfileirase(f,n->dados);
        n=n->prox;
    }
}

// batalha provisoria para a segunda entrega
int batalha(FilaSE *clone, char *nomeG) {
    
    tp_lista_dinos *tbot;
    FilaSE *bot;
    int rcont = 1;
    tbot = criar_lista();
    bot = criar_filase();
    char nomeBot[40];
    definir_nome_aleatorio(nomeBot);
    embaralharGrupo(tbot, 3);
    bot = lisFil(tbot);
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n-------------------------------BATALHA 1-------------------------------\n");
    printf("\n            %s   VS   %s (bot)\n", nomeG, nomeBot);
    printf("\n-----------------------------------------------------------------------\n");
    system("pause");
    while (clone != NULL && bot != NULL) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n--Formacao do grupo %s--\n\n", nomeG);
        imprimir_fila(clone);
        printf("\n--Formacao do grupo: %s--\n\n", nomeBot);
        imprimir_fila(bot);

        tabela0(clone->ini,clone,bot);
        tabela0(bot->ini,clone,bot);

        tabela1(clone->ini,clone,bot);
        tabela1(bot->ini,clone,bot);

        clone->ini->dados.vida -= bot->ini->dados.dano;
        bot->ini->dados.vida -= clone->ini->dados.dano;

        tabela2(clone->ini,clone,bot);
        tabela2(bot->ini,clone,bot);
        
        printf("\n\nROUND %d\n", rcont);
        printf("\n%s      VS     %s\n", clone->ini->dados.nome,  bot->ini->dados.nome);
        printf("\nVida: %d           %d\n", clone->ini->dados.vida,  bot->ini->dados.vida); 
        printf("\nDano: %d           %d\n", clone->ini->dados.dano,  bot->ini->dados.dano); 
        if (clone->ini->dados.vida <= 0) 
            remover_por_posicao(clone, 1);
        if (bot->ini->dados.vida <= 0)
            remover_por_posicao(bot, 1);
        rcont++;
        system("pause");
    }
    if (clone == NULL && bot == NULL) {
        printf("\n\nFim da batalha\nResultado: EMPATE\n");
        return 0;
    }
    if (clone == NULL){
        printf("\n\nFim da batalha\nResultado: DERROTA\n");
        return 1;
    }
    if (bot == NULL) {
        printf("\n\nFim da batalha\nResultado: VITORIA\n");
        return 0;
    }
}

/* previa da funcao final:

void batalha(int *coracao, int *trofeis, FilaSE **grupo) {
    FilaSE *clone;  clone = copiar_lista(*grupo);
    imprimir_lista(clone);
    remover_por_posicao(&clone, 1);
    imprimir_lista(clone);
    imprimir_lista(*grupo);





} */

#endif
