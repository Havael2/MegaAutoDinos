#include <time.h>
#include "dinos.h"
#include "nomegrupo.h"
#include "listadinos.h"
#include "filadinos.h"
#include "batalha.h"
#include "loja.h"
#include "titulo.h"


int main() {
    srand(time(NULL));
    int coracao= 5,turno=1, trofeu= 0;
    int resultado;
    char nomeGrupo[40];
    tp_lista_dinos *grupo;
    FilaSE *clone, *bot;

    titulo();
    grupo = criar_lista();
    clone = criar_filase();
    bot = criar_filase();
    definir_nome(nomeGrupo);

    while (coracao) {
      printf("Trofeus: %d\n", trofeu);
      printf("Coracoes: %d\n", coracao);	
      loja(grupo);
      clone = transferir_lista_para_fila(grupo, clone);
      resultado = batalha(clone, nomeGrupo);
      if (resultado == 1){
      trofeu++;
     }
      else if (resultado == -1){
      coracao--;
     }
      turno++;
      if(turno%3==0){
      coracao++;
    }
  }
    return 0;
}
