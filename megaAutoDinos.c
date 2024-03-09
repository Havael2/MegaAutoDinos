#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMesp 2 // Deve estar de acordo com a quantidade de espécies já feitas. TAMe será 21 ao final.
#define TAMadj 3 // Deve estar de acordo com a quantidade de adjetivos já feitos. TAMa será 9 ao final.
#define TAMsubs 3 // Deve estar de acordo com a quantidade de espécies já feitas. TAMs será 9 ao final.

typedef struct
{
    int vida;
    int dano;
    char nome[30];

} atributos;

atributos especies(int *spc) // Preencher com 21 animais relativos aos números inteiros de 0 a 20. (obs: não é nescessário que spc seja um ponteiro, mas como não sei o porquê mantive assim.)
{
    atributos bicho;
    if (*spc==0)
    {
        strcpy(bicho.nome, "Tiranossauro Rex"); // Habilidade(opcional): Dá 2 de dano aos aliados adjacentes a cada rodada.
        bicho.vida = 12;
        bicho.dano = 17;
    }
    if (*spc==1)
    {
        strcpy(bicho.nome, "Velociraptor"); // Habilidade (opcional): Ao morrer, invoca mais 2 velociraptors caso haja espaço.
        bicho.vida = 3;
        bicho.dano = 4;
    }
    // continua...
    return bicho;
}

void definirLoja(int *lj) // Definição da loja a cada início de turno.
{
    time_t t;
    srand((unsigned) time(&t));
    int i;
    atributos bichosLoja[3];
    for (i=0; i<3; i++)
    {
        *(lj+i) = rand() % TAMesp;
        bichosLoja[i] = especies(lj+i);
    }
    printf("Bichos na loja:\n");
    for (i=0; i<3; i++) // Exibição dos bichos na loja.
    {
        printf("%d.%s  ", (i+1), bichosLoja[i].nome);
    }
}

char *definirSubstantivo(int nS)
{
    if (nS==0)
        return "Vulcane";
    if (nS==1)
        return "Pangea";
    if (nS==2)
        return "Rockers";
    // continua...
}

char *definirAdjetivo(int nA)
{
    if (nA==0)
       return "Jurassic";
    if (nA==1)
        return "Insane";
    if (nA==2)
        return "Flaming";
    // continua...
}

void definirNome(char *nmG)
{
    time_t t;
    srand((unsigned) time(&t));
    int numSubs[3], numAdj[3], i;
    printf("\n\nEscolha um nome para o seu novo grupo:\nAdjetivos        Substantivos\n");
    for (i=0; i<3; i++)
    {
        numAdj[i] = rand() % TAMadj;
        while((i==1 && numAdj[i]==numAdj[i-1]) || (i==2 && (numAdj[i]==numAdj[i-1] || numAdj[i]==numAdj[i-2])))
        {
            numAdj[i] = rand() % TAMadj;
        }
        printf("%d.%s        ", (i+1), definirAdjetivo(numAdj[i]));
        numSubs[i] = rand() % TAMsubs;
        while((i==1 && numSubs[i]==numSubs[i-1]) || (i==2 && (numSubs[i]==numSubs[i-1] || numSubs[i]==numSubs[i-2])))
        {
            numSubs[i] = rand() % TAMsubs;
        }
        printf("%d.%s\n", (i+1), definirSubstantivo(numSubs[i]));
    }
    // **Falta fazer um switch para a entrada dos números que representam o adjetivo e o substantivo 
    // (ou novas strings pra guardar a decisão)**
    // Posterior junção do adj. e subs.: *nmG = strcat(substantivo, adjetivo);

}
int main ()
{
    char nomeGrupo[20];
    atributos grupo[5];
    int loja[3], i;
    printf("\n");
    definirLoja(loja);
    definirNome(nomeGrupo);
    return 0;
}