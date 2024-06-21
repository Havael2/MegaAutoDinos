#ifndef BATALHA_H
#define BATALHA_H

#include "listadinos.h"
#include "nomegrupo.h"
#include "dinos.h"
#include "habilidades.h"
#include <string.h>

// batalha provisoria para a segunda entrega
void batalha(tp_lista_dinos **grupo, char *nomeG) {
    
    tp_lista_dinos *clone_grupo;  
    clone_grupo = copiar_lista(*grupo);
    
    tp_lista_dinos *bot;
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
    while (clone_grupo != NULL && bot != NULL) {
        //tabelaH(clone_grupo->dados.hab);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n--Formacao do grupo %s--\n\n", nomeG);
        imprimir_lista(clone_grupo);
        printf("\n--Formacao do grupo: %s--\n\n", nomeBot);
        imprimir_lista(bot);
        clone_grupo->dados.vida -= bot->dados.dano;
        bot->dados.vida -= clone_grupo->dados.dano;
        printf("\n\nROUND %d\n", rcont);
        printf("\n%s      VS     %s\n", clone_grupo->dados.nome,  bot->dados.nome);
        printf("\nVida: %d           %d\n", clone_grupo->dados.vida,  bot->dados.vida); 
        printf("\nDano: %d           %d\n", clone_grupo->dados.dano,  bot->dados.dano); 
        if (clone_grupo->dados.vida <= 0) 
            remover_por_posicao(&clone_grupo, 1);
        if (bot->dados.vida <= 0)
            remover_por_posicao(&bot, 1);
        rcont++;
        system("pause");
    }
    if (clone_grupo == NULL && bot == NULL) {
        printf("\n\nFim da batalha\nResultado: EMPATE\n");
        return;
    }
    if (clone_grupo == NULL){
        printf("\n\nFim da batalha\nResultado: DERROTA\n");
        return;
    }
    if (bot == NULL) {
        printf("\n\nFim da batalha\nResultado: VITORIA\n");
        return;
    }
}

/* previa da funcao final:

void batalha(int *coracao, int *trofeis, tp_lista_dinos **grupo) {
    tp_lista_dinos *clone_grupo;  clone_grupo = copiar_lista(*grupo);
    imprimir_lista(clone_grupo);
    remover_por_posicao(&clone_grupo, 1);
    imprimir_lista(clone_grupo);
    imprimir_lista(*grupo);





} */

#endif
