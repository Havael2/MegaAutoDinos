#ifndef NOMEGRUPO_H
#define NOMEGRUPO_H

#define TAMadj 11 // Deve estar de acordo com a quantidade de adjetivos já feitos. TAMadj será 11 ao final.
#define TAMsubs 11 // Deve estar de acordo com a quantidade de substantivos já feitos. TAMsubs será 11 ao final.

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char *definir_substantivo(int nS) { // Função que recebe um indice e retorna uma string que é o substantivo do nome do grupo
    if (nS==0)
        return "Vulcanos";
    if (nS==1)
        return "Dentes";
    if (nS==2)
        return "Uga-ugas";
    if (nS==3)
        return "Bichos";
    if (nS==4)
        return "Esqueletos";
    if (nS==5)
        return "Fosseis";
    if (nS==6)
        return "Rugidos";
    if (nS==7)
        return "Cacadores";
    if (nS==8)
        return "Ancestrais";
    if (nS==9)
        return "Meteoritos";
    if (nS==10)
        return "Largatos";
}

char *definir_adjetivo(int nA) { // Função que recebe um indice e retorna uma string que é o adjetivo do nome do grupo
    if (nA==0)
       return "Jurassicos";
    if (nA==1)
        return "Insanos";
    if (nA==2)
        return "Flamejantes";
    if (nA==3)
	    return "Fofos";
    if (nA==4)
	    return "Tiranos";
    if (nA==5)
	    return "Ferozes";
    if (nA==6)
	    return "Sabios";
    if (nA==7)
	    return "Saltitantes";
    if (nA==8)
	    return "Extintos";
    if (nA==9)
	    return "Majestosos";
    if (nA==10)
	    return "Velhos";
}

void definir_nome(char *nmG) {
    int iSubs[3], iAdj[3], i;
    printf("\n\nEscolha um nome para o seu novo grupo:\nAdjetivos        Substantivos\n");
    for (i=0; i<3; i++)
    {
        iAdj[i] = rand() % TAMadj;                  //loop que gera três pares de números aleatórios e que nao se repetem para gerar os subs e adjs a serem escolhidos
        while((i==1 && iAdj[i]==iAdj[i-1]) || (i==2 && (iAdj[i]==iAdj[i-1] || iAdj[i]==iAdj[i-2])))
        {
            iAdj[i] = rand() % TAMadj;
        }
        printf("%d.%s        ", (i+1), definir_adjetivo(iAdj[i]));
        iSubs[i] = rand() % TAMsubs;
        while((i==1 && iSubs[i]==iSubs[i-1]) || (i==2 && (iSubs[i]==iSubs[i-1] || iSubs[i]==iSubs[i-2])))
        {
            iSubs[i] = rand() % TAMsubs;
        }
        printf("%d.%s\n", (i+1), definir_substantivo(iSubs[i]));
    }

    int escolherAdj, escolherSubs;  //interface para escolher um adjetivo e um substantivo da lista gerada
    printf("\nEscolha o adjetivo (1-3): ");
    scanf("%d", &escolherAdj);
    printf("Escolha o substantivo (1-3): ");
    scanf("%d", &escolherSubs);

    char adjetivoEscolhido[20], substantivoEscolhido[20];
    switch (escolherAdj) {
        case 1:
            strcpy(adjetivoEscolhido, definir_adjetivo(iAdj[0]));
            break;
        case 2:
            strcpy(adjetivoEscolhido, definir_adjetivo(iAdj[1]));
            break;
        case 3:
            strcpy(adjetivoEscolhido, definir_adjetivo(iAdj[2]));
            break;
    }
    switch (escolherSubs) {
        case 1:
            strcpy(substantivoEscolhido, definir_substantivo(iSubs[0]));
            break;
        case 2:
            strcpy(substantivoEscolhido, definir_substantivo(iSubs[1]));
            break;
        case 3:
            strcpy(substantivoEscolhido, definir_substantivo(iSubs[2]));
            break;
    }

    strcpy(nmG, substantivoEscolhido); //concatena os substantivos e adjetivos escolhidos e os armazena
    strcat(nmG, " ");
    strcat(nmG, adjetivoEscolhido);
}

void definir_nome_aleatorio(char *nmG) {

    int escolherAdj, escolherSubs;  // escolher aleatoriamente um adjetivo e um substantivo da lista gerada
    escolherAdj = rand() % TAMadj + 1;
    escolherSubs = rand() % TAMsubs + 1;

    char adjetivoEscolhido[20], substantivoEscolhido[20];

    strcpy(adjetivoEscolhido, definir_adjetivo(escolherAdj));
    strcpy(substantivoEscolhido, definir_substantivo(escolherAdj));


    strcpy(nmG, substantivoEscolhido); //concatena os substantivos e adjetivos escolhidos e os armazena
    strcat(nmG, " ");
    strcat(nmG, adjetivoEscolhido);
}

#endif
