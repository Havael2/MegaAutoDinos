#ifndef BATALHA_H
#define BATALHA_H

#include "listadinos.h"
#include "nomegrupo.h"
#include "dinos.h"
#include <string.h>

void definir_grupo_aleatorio(tp_lista_dinos *grupo) {
    while(tamanho_lista(grupo) < 3) {
        inserir_no_fim(&grupo, especies(rand() % TAMesp));
    }
}

// batalha provisoria para a segunda entrega
void batalha(tp_lista_dinos **grupo, char *nomeG) {
    
    tp_lista_dinos *clone_grupo;  
    clone_grupo = copiar_lista(*grupo);
    
    tp_lista_dinos *bot;
    bot = criar_lista();
    char nomeBot[40];
    definir_nome_aleatorio(nomeBot);
    definir_grupo_aleatorio(bot);
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n-------------------------------BATALHA 1-------------------------------\n");
    printf("\n            %s   VS   %s (bot)\n", nomeG, nomeBot);
    printf("\n-----------------------------------------------------------------------\n");
    while (!(clone_grupo == NULL) || !(bot == NULL)) {
        int rcont = 1;
        printf("\nROUND %d\n", rcont);
        printf("\n%s           %s\n", clone_grupo->dados.nome,  bot->dados.nome);
        printf("%Vida: %d    VS     %d\n", clone_grupo->dados.vida,  bot->dados.vida); 
        printf("%Dano: %d           %d\n", clone_grupo->dados.dano,  bot->dados.dano); 
        clone_grupo->dados.vida -= bot->dados.dano;
        bot->dados.vida -= clone_grupo->dados.dano;
        if (clone_grupo->dados.vida <= 0) 
            remover_por_posicao(&clone_grupo, 0);
        if (bot->dados.vida <= 0)
            remover_por_posicao(&bot, 0);
        rcont++;
        system("pause");
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
