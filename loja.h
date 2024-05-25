void definirLoja(int *lj) // Definição da loja a cada início de turno.
{
    int i;
    dinos bichosLoja[3];
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

///////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para representar um item na loja
typedef struct {
int id;
char nome[50];
int preco;
} Item;

// Definição da estrutura para representar o inventário do jogador
typedef struct {
int id;
char nome[50];
} Inventario;

// Função para exibir os itens disponíveis na loja
void exibirLoja(Item loja[], int numItens) {
printf("Itens disponiveis na loja:\n");
for (int i = 0; i < numItens; i++) {
printf("%d. %s - Preco: %d\n", loja[i].id, loja[i].nome, loja[i].preco);
}
printf("\n");
}

// Função para realizar a compra de um item
void comprarItem(Item loja[], Inventario *inventario, int itemId, int numItens) {
for (int i = 0; i < numItens; i++) {
if (loja[i].id == itemId) {
if (inventario->id != 0) {
printf("Voce ja possui um item no inventario. Venda ou descarte o item antes de comprar outro.\n");
return;
}
if (inventario->id == 0 && loja[i].preco > 0) {
printf("Item comprado: %s\n", loja[i].nome);
inventario->id = loja[i].id;
strcpy(inventario->nome, loja[i].nome);
return;
} else {
printf("Voce nao possui dinheiro suficiente para comprar este item.\n");
return;
}
}
}
printf("Item nao encontrado na loja.\n");
}

// Função principal
int main() {
// Itens disponíveis na loja
Item loja[3] = {{1, "Espada", 100}, {2, "Poção de Vida", 50}, {3, "Armadura", 150}};
int numItens = 3;

// Inicializa o inventário do jogador
Inventario inventario = {0, ""};

// Exibe os itens disponíveis na loja
exibirLoja(loja, numItens);

// Simula a compra de um item (o jogador digita o ID do item)
int itemId;
printf("Digite o ID do item que deseja comprar: ");
scanf("%d", &itemId);
comprarItem(loja, &inventario, itemId, numItens);

// Exibe o inventário do jogador
printf("\nInventario do jogador:\n");
if (inventario.id != 0) {
    printf("Item: %s\n", inventario.nome);
} else {
    printf("Inventario vazio.\n");
}

return 0;

}
