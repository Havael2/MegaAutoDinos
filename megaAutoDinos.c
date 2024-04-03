#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pilhadinos.h"
#define TAMesp 2 // Deve estar de acordo com a quantidade de espécies já feitas. TAMesp será 14 ao final.
#define TAMadj 3 // Deve estar de acordo com a quantidade de adjetivos já feitos. TAMadj será 9 ao final.
#define TAMsubs 3 // Deve estar de acordo com a quantidade de substantivos já feitos. TAMsubs será 9 ao final.

dinos especies(int spc) {
    dinos bicho;
    if (spc==0)
    {
        strcpy(bicho.nome, "Tiranossauro Rex"); // Habilidade(opcional): Dá 2 de dano aos aliados adjacentes a cada rodada.
        bicho.vida = 12;
        bicho.dano = 17;
    }
    if (spc==1)
    {
        strcpy(bicho.nome, "Velociraptor"); // Habilidade (opcional): Ao morrer, invoca mais 2 velociraptors caso haja espaço.
        bicho.vida = 3;
        bicho.dano = 4;
    }
    // continua...
    return bicho;
}

char *definirSubstantivo(int nS) {
    if (nS==0)
        return "Vulcano";
    if (nS==1)
        return "Pangeia";
    if (nS==2)
        return "OS Roqueiros";
	 if (nS==3)
        return "OS Radicais";
	 if (nS==4)
        return "Os Dinos";
	 if (nS==5)
        return "Fosseis";
	 if (nS==6)
        return "Os Rugidos";
	 if (nS==7)
        return "Os Brilhosos";
	 if (nS==8)
        return "Os Divos";
	 if (nS==9)
        return "Os loucos";
	 if (nS==10)
        return "As Lendas";
	
    // continua...
}

char *definirAdjetivo(int nA)
{
    if (nA==0)
       return "Jurássico";
    if (nA==1)
        return "Insana";
    if (nA==2)
        return "Flamejante";
    if (nA==3)
	    return "fofo";
    if (nA==4)
	    return "Sensivel";
    if (nA==5)
	    return "Feroz";
    if (nA==6)
	    return "Sabio";
	  if (nA==7)
	    return "Saltitante";
	  if (nA==8)
	    return "Cintilante";
	  if (nA==9)
	    return "Majestoso";
	 if (nA==10)
	    return "Alegre";
}

void definirNome(char *nmG)
{
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

    /*Falta fazer um switch para a entrada dos números que representam o adjetivo e o substantivo 
    (ou novas strings pra guardar a decisão)*/

    // Posterior junção do adj. e subs.: *nmG = strcat(substantivo, adjetivo);

}

void embaralharGrupo(tp_pilha *pGrupo) {
	dinos e;
	while (!cheia_pilha(pGrupo))	{
		push(pGrupo, especies(rand()%TAMesp));
	}
	while (!vazia_pilha(pGrupo)) {
		pop(pGrupo, &e);
		printf(" %s\n", e.nome);
   	}
}

int main ()
{
    srand(time(NULL));
    char nomeGrupo[20];
    tp_pilha grupo;
    inicializarPilha(&grupo);
    definirNome(nomeGrupo);
    printf("\nComposicao do seu grupo:\n");
    embaralharGrupo(&grupo);
    return 0;
}

void definirNome(char *nmG)
{
    int numSubs[3], numAdj[3], i;
    printf("\n\nEscolha um nome para o seu novo grupo:\nAdjetivos        Substantivos\n");
    for (i=0; i<3; i++)
    {
        numAdj[i] = rand() % TAMadj;                  //loop que gera três pares de números aleatórios e que nao se repetem 
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

    int escolhaAdj, escolhaSubs;  //escolher um adjetivo e um substantivo da lista 
    printf("\nEscolha o adjetivo (1-3): ");
    scanf("%d", &escolhaAdj);
    printf("Escolha o substantivo (1-3): ");
    scanf("%d", &escolhaSubs);

    char adjetivoEscolhido[20], substantivoEscolhido[20];
    switch (escolhaAdj) {
        case 1:
            strcpy(adjetivoEscolhido, definirAdjetivo(numAdj[0]));
            break;
        case 2:
            strcpy(adjetivoEscolhido, definirAdjetivo(numAdj[1]));
            break;
        case 3:
            strcpy(adjetivoEscolhido, definirAdjetivo(numAdj[2]));
            break;
    }
    switch (escolhaSubs) {
        case 1:
            strcpy(substantivoEscolhido, definirSubstantivo(numSubs[0]));
            break;
        case 2:
            strcpy(substantivoEscolhido, definirSubstantivo(numSubs[1]));
            break;
        case 3:
            strcpy(substantivoEscolhido, definirSubstantivo(numSubs[2]));
            break;
    }

    strcpy(nmG, adjetivoEscolhido);
    strcat(nmG, " ");
    strcat(nmG, substantivoEscolhido);
}

