#include <time.h>
#include "dinos.h"
#include "nomegrupo.h"
#include "listadinos.h"
#include "filadinos.h"
#include "batalha.h"
#include "habilidades.h"
#include "loja.h"
#include "titulo.h"

//testes
int main() {
    srand(time(NULL));
    int coracao=5,turno=1;
    char nomeGrupo[40];
    tp_lista_dinos *grupo;
    FilaSE *clone;

    titulo();
    grupo = criar_lista();
    definir_nome(nomeGrupo);

    while(coracao){
        loja(grupo);

        clone = lisFil(grupo);
        coracao-=batalha(&clone, nomeGrupo);
        turno++;
        if(turno%3==0){
            coracao++;
        }
    }

    return 0;
}

/* previa da main final

int main() {
    srand(time(NULL));
    int coracao = 10, trofeis = 0;
    char nomeGrupo[40];
    tp_lista_dinos *grupo; 
    grupo = criar_lista();

    definirNome(nomeGrupo);
    printf("Nome do grupo: %s\n", nomeGrupo);
    while (coracao > 0 || trofeis < 10) {
        loja(&grupo);
        batalha(&coracao, &trofeis, &grupo);
    }

    return 0;
} */
