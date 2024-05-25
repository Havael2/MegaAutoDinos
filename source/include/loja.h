#ifndef LOJA_H
#define LOJA_H

#include "listadinos.h"

void embaralharGrupo(tp_lista_dinos **dloja, int n) { // Funçao que gera os dinos na loja e os imprimem
	int i;
	for(i=1;i<=n;i++){
	inserir_no_fim(dloja, especies(rand()%TAMesp));	
	}
}

void loja(tp_lista_dinos **dgrupo) { // Função loja
	tp_lista_dinos *loja;   loja = criar_lista();
	int dinheiro=10;
	char opcao;
	
	embaralharGrupo(&loja, 4);
	while(dinheiro >= 0){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n--Loja--\n");
	imprimir_lista(loja);	
	printf("\n--Time--\n");
	imprimir_lista(*dgrupo);	
		
	printf("\nDinheiro - R$%d\n\n", dinheiro);	
	printf("c - Efetuar uma compra na loja(cada dinossauro custa R$3)\n");	
	printf("v - Realizar uma venda para a loja\n");	
	printf("a - Atualizar a loja(custa R$1)\n");
	printf("Pressione qualquer outra tecla para iniciar a batalha\n");
	printf("\nEscolha a sua opcao: ");	
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

#endif
