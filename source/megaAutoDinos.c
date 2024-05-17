#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dinos.h"
#include "nome.h"
#include "pilhadinos.h"

void embaralharGrupo(tp_pilha *pGrupo) { // Funçao que gera os dinos na loja e os imprimem
	dinos e;
	while (!cheia_pilha(pGrupo))	{ //gerar
		push(pGrupo, especies(rand()%TAMesp));
	}
	while (!vazia_pilha(pGrupo)) { //imprimir
		pop(pGrupo, &e);
		printf("Especie: %s ", e.nome);
    		printf("Vida: %d ", e.vida);
    		printf("Dano: %d\n", e.dano);
   	}
}

void batalha(tp_pilha grupo, char nomeGrupo[20], int *coracao) {
  char temp[5],espaco[10]="",*espaco2;
  dinos a, b;
  tp_pilha op;
  inicializarPilha(&op);
  while (!cheia_pilha(&op)) {
    push(&op, especies(rand() % TAMesp));
  }

  while (!(vazia_pilha(&grupo)||vazia_pilha(&op))) {
    system("clear||cls");
    printf("---BATALHA---\n");
    printf("\n%s   VS   OPONENTES\n\n", nomeGrupo);
    imprimirPilha(&grupo);
    printf("\n_____________________________\n\n");
    imprimirPilha(&op);

    scanf(" %[^\n]",temp);

    pop(&grupo, &a);
    pop(&op, &b);

    system("clear||cls");

    for(int i=strlen(a.nome)/4;i>0;i--)
      strcat(espaco," ");
    espaco2=strdup(espaco);
    for(int i=strlen(b.nome)/4+3;i>0;i--)
      strcat(espaco2," ");

    printf("%s👊%d|💕%d",espaco,a.dano,a.vida);
    printf("%s👊%d|💕%d",espaco2,b.dano,b.vida);
    printf("\n%s 💥 %s\n",a.nome,b.nome);

    a.vida -= b.dano;
    b.vida -= a.dano;

    for(int i=strlen(a.nome)+1;i>0;i--)
      printf("-");
    printf("⬇⬇");
    for(int i=strlen(b.nome)+1;i>0;i--)
      printf("-");

    printf("\n%s👊%d|💕%d",espaco,a.dano, a.vida);
    printf("%s👊%d|💕%d",espaco2,b.dano, b.vida);
    printf("\n%s 💥 %s\n", a.nome, b.nome);
    free(espaco2);
    strcpy(espaco,"");

    if(a.vida > 0)
      push(&grupo, a);
    else
      printf("\n%s DERROTADO", a.nome);
    if(b.vida > 0)
      push(&op, b);
    else
      printf("\n%s DERROTADO", b.nome);

    scanf(" %[^\n]",temp);
  }

  if(vazia_pilha(&grupo)&&vazia_pilha(&op)){
    system("clear||cls");
    for(int i=*coracao;i>0;i--)
        printf("💖");
    
    printf("\nEMPATE...");
    
  }else if(vazia_pilha(&grupo)){
    system("clear||cls");
    for(int i=*coracao-1;i>0;i--)
        printf("💖");

    printf("\nMAIS SORTE NA PROXIMA... -1💕");
    *coracao--;
    
  }else if(vazia_pilha(&op)){
    system("clear||cls");
    for(int i=*coracao;i>0;i--)
        printf("💖");
    
    printf("\nPARABENS!!!");
    
  }
}

int main(){
    srand(time(NULL));
    int coracao=5;
    char nomeGrupo[20];
    tp_pilha grupo;

    inicializarPilha(&grupo);
    definirNome(nomeGrupo);

    printf("Nome do grupo: %s", nomeGrupo);
    printf("\nComposicao do seu grupo:\n");

    embaralharGrupo(&grupo);

    while (!cheia_pilha(&grupo))	{ //time aleatorio para testar batalha
		push(&grupo, especies(rand()%TAMesp));
	}
    batalha(grupo,nomeGrupo,&coracao);

    return 0;
}
