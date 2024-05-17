char *definirSubstantivo(int nS) { // Função que recebe um indice e retorna uma string que é o substantivo do nome do grupo
    if (nS==0)
        return "Vulcano";
    if (nS==1)
        return "Pangeia";
    if (nS==2)
        return "Os Roqueiros";
    if (nS==3)
        return "Os Radicais";
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
}

char *definirAdjetivo(int nA){ // Função que recebe um indice e retorna uma string que é o adjetivo do nome do grupo
    if (nA==0)
       return "Jurassico";
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
        numAdj[i] = rand() % TAMadj;                  //loop que gera três pares de números aleatórios e que nao se repetem para gerar os subs e adjs a serem escolhidos
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

    int escolhaAdj, escolhaSubs;  //interface para escolher um adjetivo e um substantivo da lista gerada
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

    strcpy(nmG, adjetivoEscolhido); //concatena os substantivos e adjetivos escolhidos e os armazena
    strcat(nmG, " ");
    strcat(nmG, substantivoEscolhido);
}