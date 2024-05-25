#include <time.h>
#include "dinos.h"
#include "nomegrupo.h"
#include "listadinos.h"
#include "batalha.h"
#include "loja.h"

//testes
int main() {
    srand(time(NULL));
    int coracao = 10, trofeis = 0;
    char nomeGrupo[40];
    tp_lista_dinos *grupo;  
    grupo = criar_lista();
    definir_nome(nomeGrupo);
    loja(&grupo);
    batalha(&grupo, nomeGrupo);
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
