(NÃO COLOCAR)
    (NÃO COLOCAR)
    (NÃO COLOCAR)
    (NÃO COLOCAR)
    (NÃO COLOCAR)
    



#ifndef HAB_H
#define HAB_H
#include "time.h"
#include "dinos.h"
#include "filadinos.h"

void trex();
void veloc();
void tric();
void ptera();
void steg();
void spino(FilaSE *desaf){
    nof *d;
    srand(time(NULL));

    d=busca_fila(rand()%22);
    d->dados.vida-=1;
}
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

void tabelaL(no *no, FilaSE *grupo){
    if(nof->dados->hab==20)
        pachy(grupo);
    else
        printf("\nhabilidade invalida");
}

void tabela0(nof *no, FilaSE *grupo, FilaSE *desaf){
    switch(nof->dados->hab){
        case 3:
            ptera(grupo,desaf);
        break;
        case 7:
            dilopho(grupo,desaf);
        break;
        case 11:
            archa(grupo,desaf);
        break;
        case 16:
            ouran(grupo,desaf);
        break;
        default:
            printf("\nhabilidade invalida");
    }
}

void tabela1(nof *no, FilaSE *grupo, FilaSE *desaf){
    switch(nof->dados->hab){
        case 2:
            tric(grupo,desaf);
        break;
        case 5:
            spino(desaf);
        break;
        case 6:
            anqui(grupo,desaf);
        break;
        case 9:
            suss(grupo,desaf);
        break;
        case 13:
            carnot(grupo,desaf);
        break;
        case 14:
            amarg(grupo,desaf);
        break;
        case 17:
            megalo(grupo,desaf);
        break;
        default:
            printf("\nhabilidade invalida");
    }
}

void tabela2(nof *no, FilaSE *grupo, FilaSE *desaf){
    switch(nof->dados->hab){
        case 0:
            trex(grupo,desaf);
        break;
        case 1:
            veloc(grupo,desaf);
        break;
        case 4:
            steg(grupo,desaf);
        break;
        case 8:
            brach(grupo,desaf);
        break;
        case 10:
            allo(grupo,desaf);
        break;
        case 12:
            igua(grupo,desaf);
        break;
        case 15:
            cerat(grupo,desaf);
        break;
        case 18:
            teriz(grupo,desaf);
        break;
        case 19:
            trood(grupo,desaf);
        break;
        default:
            printf("\nhabilidade invalida");
    }
}

#endif
