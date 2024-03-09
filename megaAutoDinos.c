#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int vida;
    int dano;
    char nome[30];

} atributos;

atributos especies(int spc) // Preencher com 21 animais relativos aos números inteiros de 0 a 20.
{
    atributos bicho;
    if (spc==0)
    {
        strcpy(bicho.nome, "Tiranossauro Rex"); //Habilidade(opcional): Dá 2 de dano aos aliados adjacentes a cada rodada.
        bicho.vida = 12;
        bicho.dano = 17;
    }
    if (spc==1)
    {
        strcpy(bicho.nome, "Velociraptor"); //Habilidade (opcional): Ao morrer, invoca mais 2 velociraptors caso haja espaço.
        bicho.vida = 3;
        bicho.dano = 4;
    }
    // continua...
 
    return bicho;
}

int definirLoja(int *lj) //Definição da loja a cada início de turno.
{
    int i;
    atributos bichos[3];
    for (i=0; i<3; i++)
    {
        lj+i = rand() % 21;
    }
    for (i=0; i<3; i++) //Exibição do funcionamento da função rand().
    {
        printf(" %d", *lj+i);
    }
}

int main ()
{
    int loja[3], i;
    atributos grupo[5];
    definirLoja(loja);
    return 0;
}