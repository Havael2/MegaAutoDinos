#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pilhadinos.h"
#define TAMesp 21 // Deve estar de acordo com a quantidade de espécies já feitas. TAMesp será 21 ao final.
#define TAMadj 11 // Deve estar de acordo com a quantidade de adjetivos já feitos. TAMadj será 11 ao final.
#define TAMsubs 11 // Deve estar de acordo com a quantidade de substantivos já feitos. TAMsubs será 11 ao final.

dinos especies(int spc) {
dinos bicho;
    if (spc == 0) {
        strcpy(bicho.nome, "Tiranossauro Rex");
        bicho.vida = 12;
        bicho.dano = 17;
        // Habilidade(opcional): Dá 2 de dano aos aliados adjacentes a cada rodada.
    }
    if (spc == 1) {
        strcpy(bicho.nome, "Velociraptor");
        bicho.vida = 4;
        bicho.dano = 3;
        // Habilidade (opcional): Ao morrer, invoca mais 2 velociraptors caso haja espaço.
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
        // Habilidade (opcional): Causa 1 de dano em algum inimigo aleatório
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
        bicho.dano = 4;
        // Habilidade (opcional): Cospe veneno, dando 2 de dano entra a cada rodada.
    }
    if (spc == 8) {
        strcpy(bicho.nome, "Brachiosaurus");
        bicho.vida = 6;
        bicho.dano = 4;
        // Habilidade (opcional): Ao morrer, concede 3 de vida a todos os dinossauros em campo.
    }
    if (spc == 9) {
        strcpy(bicho.nome, "Deinonychus");
        bicho.vida = 6;
        bicho.dano = 13;
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
        // Habilidade (opcional): Ao morrer, diminui a armadura do oponente em 2 ( ele sofrerá 2 de dano a mais)
    }	    
    if (spc == 13) {
        strcpy(bicho.nome, "Carnotaurus");
        bicho.vida = 15;
        bicho.dano = 9;
        // Habilidade (opcional): Pode atacar somente duas vezes e depois se elimina.
    }
    if (spc == 14) {
        strcpy(bicho.nome, "Amargasaurus");
        bicho.vida = 8;
        bicho.dano = 5;
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
        // Habilidade (opcional): Ataques em inimigos são ricocheteados e causam 2 de dano em um aliado aleatório.
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
        // Habilidade (opcional): Invocações aliadas recebem 2 de ataque e vida.
    }
    if (spc == 20) {
        strcpy(bicho.nome, "Pachycephalosaurus");
        bicho.vida = 6;
        bicho.dano = 3;
        // Habilidade (opcional): Ao ser comprado, presenteia 2 aliados aleatórios com 3 de vida e ataque.
    }
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

