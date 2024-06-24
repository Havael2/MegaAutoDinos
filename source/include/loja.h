#ifndef LOJA_H
#define LOJA_H

#include "dinos.h"
#include "listadinos.h"

void embaralharGrupo(tp_lista_dinos *dloja, int n) { // Funcao que gera os dinos na loja e os imprimem
	int i;
	for(i=1;i<=n;i++){
	inserir_no_fim(dloja, especies(rand()%TAMesp));	
	}
}

void compra(tp_lista_dinos *loja, tp_lista_dinos *grupo) {
    no *aux;
    int p1, p2;

    do {
        printf("Digite a posicao do dinossauro a venda (1, 2, ..., 5): ");
        scanf("%d", &p1);
        if (p1 < 1 || p1 > 5) {
            printf("A posicao do dinossauro nao pode ser menor que 1 ou maior que 5.\n");
        }
    } while (p1 < 1 || p1 > 5);

    if (!listade_vazia(loja)) {
        aux = busca_por_posicao(loja, p1);
    }

    do {
        printf("Defina a posicao do dinossauro no time (1, 2, ..., 5): ");
        scanf("%d", &p2);
        if (p2 < 1 || p2 > 5) {
            printf("A posicao do dinossauro no time nao pode ser menor que 1 ou maior que 5.\n");
        }
    } while (p2 < 1 || p2 > 5);

    inserir_por_posicao(grupo, aux->dados, p2);
    remover_por_posicao(loja, p1);
	tabelaL(aux,grupo);
}

void venda(tp_lista_dinos *l){
	int p;
	printf("Digite a posicao do dinossauro no time (1,2,...): ");
	scanf("%d", &p);
	
	remover_por_posicao(l, p);
}

void trocar_posicao(tp_lista_dinos *grupo) {
    int posicao1, posicao2;
    no *dinossauro1, *dinossauro2;

    printf("Digite a posicao do primeiro dinossauro (1 a 5): ");
    scanf("%d", &posicao1);
    printf("Digite a posicao do segundo dinossauro (1 a 5): ");
    scanf("%d", &posicao2);

    if (posicao1 < 1 || posicao1 > 5 || posicao2 < 1 || posicao2 > 5) {
        printf("Posicoes invalidas. Certifique-se de que as posicoes estao entre 1 e 5.\n");
        return;
    }

    dinossauro1 = busca_por_posicao(grupo, posicao1);
    dinossauro2 = busca_por_posicao(grupo, posicao2);

    if (dinossauro1 == NULL || dinossauro2 == NULL) {
        printf("Nao foi possivel encontrar um dinossauro em uma das posicoes especificadas.\n");
        return;
    }

    dinos temp = dinossauro1->dados;
    dinossauro1->dados = dinossauro2->dados;
    dinossauro2->dados = temp;

    printf("Dinossauros trocados de posicao com sucesso!\n");
}

void comida(tp_lista_dinos *grupo){
	no *aux;
	int p;
	char opc;
	
	printf("m - Morango(+3 de vida para o dinossauro)\n");
	printf("s - Suco(+2 de vida para o dinossauro e +1 de vida para dois antecessores)\n");
	printf("p - Pao(+3 de dano para o dinossauro)\n");
	printf("c - Carne(+4 de dano para o dinossauro e +2 de dano para dois dinossauros proximos)\n");
	printf("Escolha sua opcao: ");
	scanf(" %c", &opc);
	
	switch(opc){
		
		case 'm':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);	
		aux = busca_por_posicao(grupo, p);
		aux->dados.vida+=3;
		break;
		
		case 's':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);
		aux = busca_por_posicao(grupo, p);
		aux->dados.vida+=2;
		if(aux->ant != NULL){
		aux->ant->dados.vida+=1;	
		}
		break;
		
		case 'p':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);
		aux = busca_por_posicao(grupo, p);
		aux->dados.dano+=3;
		break;
		
		case 'c':
		printf("Digite a posicao do dinossauro no time (1,2,...): ");
		scanf("%d", &p);
		aux = busca_por_posicao(grupo, p);
		aux->dados.dano+=4;
		if(aux->ant != NULL){
		aux->ant->dados.dano+=2;	
		}
		if(aux->prox != NULL){
		aux->prox->dados.dano+=2;	
		}
		break;
		
		default:
        return;
        break;
	}
	
}

void loja(tp_lista_dinos *dgrupo) {
    tp_lista_dinos *loja;
    loja = criar_lista();
    int dinheiro = 10;
    char opcao;

    embaralharGrupo(loja, 4);
    while (dinheiro >= 0) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n--Loja--\n");
        imprimir_lista(loja);
        printf("\n--Time--\n");
        imprimir_lista(dgrupo);

        printf("\nDinheiro - R$%d\n\n", dinheiro);
        printf("c - Efetuar uma compra na loja (cada dinossauro custa R$3)\n");
        printf("v - Realizar uma venda para a loja\n");
        printf("a - Atualizar a loja (custa R$1)\n");
        printf("t - Trocar posicao de dois dinossauros no time\n");
        printf("f - Escolher uma comida(custa R$2)\n");
        printf("Pressione qualquer outra tecla para iniciar a batalha\n");
        printf("\nEscolha a sua opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {

            case 'c':
                if (dinheiro >= 3) {
                    compra(loja, dgrupo);
                    dinheiro -= 3;
                } else {
                    printf("DINHEIRO INSUFICIENTE\n");
                }
                break;

            case 'v':
                venda(dgrupo);
                dinheiro++;
                break;

            case 'a':
                if (dinheiro >= 1) {
                    destruir_lista(loja);
                    embaralharGrupo(loja, 4);
                    dinheiro--;
                }
                break;

            case 't': 
                trocar_posicao(dgrupo);
                break;

			case 'f':
				comida(dgrupo);
				dinheiro-=2;
				break;
			
            default:
                return;
                break;
        }

    }
}

#endif
