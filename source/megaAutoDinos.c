#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dinos.h"
#include "nome.h"
#include "listadinos.h"

void embaralharGrupo(Listadinos **dloja, int n){ // Funçao que gera os dinos na loja e os imprimem
	int i;
	for(i=1;i<=n;i++){
	inserir_no_fim(dloja, especies(rand()%TAMesp));	
	}
}

int loja(Listadinos **dgrupo){ // Função loja
	Listadinos *loja;
	int dinheiro=10;
	char opcao;
	
	loja = criar_lista();
	embaralharGrupo(&loja, 4);
	
	while(dinheiro >= 0){
	printf("Loja\n");
	imprimir_lista(loja);	
	printf("Time\n");
	imprimir_lista(*dgrupo);	
		
	printf("Dinheiro - R$%d\n", dinheiro);	
	printf("c - Efetuar uma compra na loja(cada dinossauro custa R$3)\n");	
	printf("v - Realizar uma venda para a loja\n");	
	printf("a - Atualizar a loja(custa R$1)\n");
	printf("Pressione qualquer outra tecla para iniciar a batalha\n");
	printf("Escolha a sua opcao: ");	
	scanf(" %c", &opcao);	
	
	switch(opcao){
		
	case 'c':	
	if(dinheiro >= 3){
	compra(&loja, dgrupo); 
	dinheiro-=3;	
	}
	else{
	printf("DINHEIRO INSUFICIENTE\n");	
	}	
	break;
		
	case 'v':
	venda(dgrupo);
	dinheiro++;
	break;
	
	case 'a':
	if(dinheiro >= 1){
	destruir_lista(&loja);
	embaralharGrupo(&loja, 4);
	dinheiro--;	
	}	
	break;
	
	default:
	return 1;		
	break;	
	}	
		
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

    printf("%s??%d|??%d",espaco,a.dano,a.vida);
    printf("%s??%d|??%d",espaco2,b.dano,b.vida);
    printf("\n%s ?? %s\n",a.nome,b.nome);

    a.vida -= b.dano;
    b.vida -= a.dano;

    for(int i=strlen(a.nome)+1;i>0;i--)
      printf("-");
    printf("??");
    for(int i=strlen(b.nome)+1;i>0;i--)
      printf("-");

    printf("\n%s??%d|??%d",espaco,a.dano, a.vida);
    printf("%s??%d|??%d",espaco2,b.dano, b.vida);
    printf("\n%s ?? %s\n", a.nome, b.nome);
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
        printf("??");
    
    printf("\nEMPATE...");
    
  }else if(vazia_pilha(&grupo)){
    system("clear||cls");
    for(int i=*coracao-1;i>0;i--)
        printf("??");

    printf("\nMAIS SORTE NA PROXIMA... -1??");
    *coracao--;
    
  }else if(vazia_pilha(&op)){
    system("clear||cls");
    for(int i=*coracao;i>0;i--)
        printf("??");
    
    printf("\nPARABENS!!!");
    
  }
}

int main(){
    srand(time(NULL));
    int coracao=5;
    char nomeGrupo[20];
    Listadinos *grupo;
    tp_pilha time;

    grupo = criar_lista();
    inicializarPilha(&time);
    definirNome(nomeGrupo);

    printf("Nome do grupo: %s\n", nomeGrupo);
	
	loja(&grupo);
	
	
    while (!cheia_pilha(&grupo))	{ //time aleatorio para testar batalha
		push(&grupo, especies(rand()%TAMesp));
	}
    batalha(grupo,nomeGrupo,&coracao);
	
    return 0;
}
