#ifndef DINOS_H
#define DINOS_H

#define TAMesp 21 // Deve estar de acordo com a quantidade de espÃ©cies jÃ¡ feitas. TAMesp serÃ¡ 21 ao final.
#define NMAX 30

#include <string.h>

typedef struct {
    int vida;
    int dano;
    char nome[NMAX];
} dinos;

dinos especies(int spc) { // FunÃ§Ã£o que recebe um indice e retorna um "struct dinos" com as devidas informaÃ§Ãµes de cada dino listadas abaixo

    dinos bicho;

    if (spc == 0) {
        strcpy(bicho.nome, "Tiranossauro Rex");
        bicho.vida = 12;
        bicho.dano = 17;
        // Habilidade(opcional): DÃ¡ 2 de dano aos aliados adjacentes a cada rodada.
    }
    if (spc == 1) {
        strcpy(bicho.nome, "Velociraptor");
        bicho.vida = 4;
        bicho.dano = 3;
        // Habilidade (opcional): Ao morrer, invoca mais 2 velociraptors caso haja espaÃ§o.
    }
    if (spc == 2) {
        strcpy(bicho.nome, "Triceratops");
        bicho.vida = 7;
        bicho.dano = 8;
        // Habilidade (opcional): Ataca duas vezes e dorme durante uma rodada. 
    }
    if (spc == 3) {
        strcpy(bicho.nome, "Pteranodonte");
        bicho.vida = 5;
        bicho.dano = 8;
        // Habilidade (opcional): Pode voar, evitando ataques terrestres por uma rodada.
    }
    if (spc == 4) {
        strcpy(bicho.nome, "Stegossauro");
        bicho.vida = 6;
        bicho.dano = 7;
        // Habilidade (opcional): Ao morrer, presenteia os aliados com 1 de vida e 1 de dano extra
    }
    if (spc == 5) {
        strcpy(bicho.nome, "Spinosaurus");
        bicho.vida = 9 ;
        bicho.dano = 2;
        // Habilidade (opcional): Causa 1 de dano em algum inimigo aleatÃ³rio
    }
    if (spc == 6) {
        strcpy(bicho.nome, "Anquilossauro");
        bicho.vida = 5;
        bicho.dano = 5;
        // Habilidade (opcional): Pode atordoar o inimigo por uma rodada.
    }
    if (spc == 7) {
        strcpy(bicho.nome, "Dilophosaurus");
        bicho.vida = 7;
        bicho.dano = 2;
        // Habilidade (opcional): Cospe veneno, dando 2 de dano entra a cada rodada.
    }
    if (spc == 8) {
        strcpy(bicho.nome, "Brachiosaurus");
        bicho.vida = 6;
        bicho.dano = 4;
        // Habilidade (opcional): Ao morrer, concede 3 de vida a todos os dinossauros em campo.
    }
    if (spc == 9) {
        strcpy(bicho.nome, "Marcio Soussa");
        bicho.vida = 13;
        bicho.dano = 4;
        // Habilidade (opcional): Pode atacar rapidamente, ignorando parte da defesa do inimigo.
    }
    if (spc == 10) {
        strcpy(bicho.nome, "Allosaurus");
        bicho.vida = 4;
        bicho.dano = 4;
        // Habilidade (opcional): Cada fim de turno, ganha 1 de ataque e 1 de vida permanente.
    }
    if (spc == 11) {
        strcpy(bicho.nome, "Archaeopteryx");
        bicho.vida = 4;
        bicho.dano = 6;
        // Habilidade (opcional): Pode voar e esquivar de ataques.
    }
    if (spc == 12) {
        strcpy(bicho.nome, "Iguanodon");
        bicho.vida = 5;
        bicho.dano = 7;
        // Habilidade (opcional): Ao morrer, diminui a armadura do oponente em 2 ( ele sofrerÃ¡ 2 de dano a mais)
    }	    
    if (spc == 13) {
        strcpy(bicho.nome, "Carnotaurus");
        bicho.vida = 13;
        bicho.dano = 9;
        // Habilidade (opcional): Pode atacar somente duas vezes e depois se elimina.
    }
    if (spc == 14) {
        strcpy(bicho.nome, "Amargasaurus");
        bicho.vida = 8;
        bicho.dano = 4;
        // Habilidade (opcional): Pode atacar dois alvos simultaneamente.
    }
    if  (spc == 15) {
        strcpy(bicho.nome, "Ceratosaurus");
        bicho.vida = 4;
        bicho.dano = 4;
        // Habilidade (opcional): Cada vez que o aliado da frente atacar, recebe 2 de vida e dano.
    }
    if (spc == 16) {
        strcpy(bicho.nome, "Ouranossauro");
        bicho.vida = 5;
        bicho.dano = 7;
        // Habilidade (opcional): Pode aumentar temporariamente sua defesa ( toma menos dano ).
    }
    if (spc == 17) {
        strcpy(bicho.nome, "Megalosaurus");
        bicho.vida = 12;
        bicho.dano = 8;
        // Habilidade (opcional): Ataques em inimigos sÃ£o ricocheteados e causam 2 de dano em um aliado aleatÃ³rio.
    }
    if (spc == 18) {
        strcpy(bicho.nome, "Therizinosaurus");
        bicho.vida = 4;
        bicho.dano = 5;
        // Habilidade (opcional): Cada vez que um aliado for invocado, ganha 3 de vida.
    }
    if (spc == 19) {
        strcpy(bicho.nome, "Troodon");
        bicho.vida = 3;
        bicho.dano = 6;
        // Habilidade (opcional): InvocaÃ§Ãµes aliadas recebem 2 de ataque e vida.
    }
    if (spc == 20) {
        strcpy(bicho.nome, "Pachycephalosaurus");
        bicho.vida = 6;
        bicho.dano = 3;
        // Habilidade (opcional): Ao ser comprado, presenteia 2 aliados aleatÃ³rios com 3 de vida e ataque.
    }
    return bicho;
}

#endif
