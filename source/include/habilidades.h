#ifndef HAB_H
#define HAB_H
#include "dinos.h"
#include "batalha.h"

typedef struct arv{

}

void tabelaH(tp_lista_dinos *clone_grupo){
    switch(clone_grupo->dados.hab){
        case 0:
            trex(clone_grupo);
        break;
        case 1:
            veloc(clone_grupo);
        break;
        case 2:
            tric(clone_grupo);
        break;
        case 3:
            ptera(clone_grupo);
        break;
        case 4:
            steg(clone_grupo);
        break;
        case 5:
            spino(clone_grupo);
        break;
        case 6:
            anqui(clone_grupo);
        break;
        case 7:
            dilopho(clone_grupo);
        break;
        case 8:
            brach(clone_grupo);
        break;
        case 9:
            suss(clone_grupo);
        break;
        case 10:
            allo(clone_grupo);
        break;
        case 11:
            archa(clone_grupo);
        break;
        case 12:
            igua(clone_grupo);
        break;
        case 13:
            carnot(clone_grupo);
        break;
        case 14:
            amarg(clone_grupo);
        break;
        case 15:
            cerat(clone_grupo);
        break;
        case 16:
            ouran(clone_grupo);
        break;
        case 17:
            megalo(clone_grupo);
        break;
        case 18:
            teriz(clone_grupo);
        break;
        case 19:
            trood(clone_grupo);
        break;
        case 20:
            pachy(clone_grupo);
        break;
    }
}
void trex();
void veloc();
void tric();
void ptera();
void steg();
void spino();
void anqui();
void dilopho();
void brach();
void suss();
void allo();
void archa();
void igua();
void carnot();
void amarg();
void cerat();
void ouran();
void megalo();
void teriz();
void trood();
void pachy();

#endif