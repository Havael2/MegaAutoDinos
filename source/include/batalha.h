#ifndef BATALHA_H
#define BATALHA_H

#include "listadinos.h"
#include "filadinos.h"
#include "nomegrupo.h"
#include "dinos.h"
#include "habilidades.h"
#include <string.h>

FilaSE* lisFil(tp_lista_dinos *l){

    FilaSE *f = criar_filase();
    no *n = l->fim;

    while(n!=NULL){
        enfileirase(f,n->dados);
        n=n->ant;
    }
}

// batalha provisoria para a segunda entrega
int batalha(FilaSE **clone, char *nomeG) {
    
    FilaSE *bot;
    int rcont = 1;
    bot = criar_lista();
    char nomeBot[40];
    definir_nome_aleatorio(nomeBot);
    embaralharGrupo(&bot, 3);
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n-------------------------------BATALHA 1-------------------------------\n");
    printf("\n            %s   VS   %s (bot)\n", nomeG, nomeBot);
    printf("\n-----------------------------------------------------------------------\n");
    system("pause");
    while (clone != NULL && bot != NULL) {
        //tabelaH(clone->dados.hab);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n--Formacao do grupo %s--\n\n", nomeG);
        imprimir_lista(clone);
        printf("\n--Formacao do grupo: %s--\n\n", nomeBot);
        imprimir_lista(bot);

        tabela0(clone->dados,clone,bot);
        tabela0(bot->dados,clone,bot);

        tabela1(clone->dados,clone,bot);
        tabela1(bot->dados,clone,bot);

        clone->dados.vida -= bot->dados.dano;
        bot->dados.vida -= clone->dados.dano;

        tabela2(clone->dados,clone,bot);
        tabela2(bot->dados,clone,bot);
        
        printf("\n\nROUND %d\n", rcont);
        printf("\n%s      VS     %s\n", clone->dados.nome,  bot->dados.nome);
        printf("\nVida: %d           %d\n", clone->dados.vida,  bot->dados.vida); 
        printf("\nDano: %d           %d\n", clone->dados.dano,  bot->dados.dano); 
        if (clone->dados.vida <= 0) 
            remover_por_posicao(&clone, 1);
        if (bot->dados.vida <= 0)
            remover_por_posicao(&bot, 1);
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
