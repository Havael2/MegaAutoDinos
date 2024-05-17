#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 201

typedef int tp_item;

typedef struct{
  int tras, frente;
  tp_item item[MAX];
}tp_fila;

void filaInit(tp_fila *f){
  f->tras=f->frente=MAX-1;
}

int filaVazia(tp_fila *f){
  if(f->tras==f->frente) return 1;
  return 0;
}

int filaCheia(tp_fila *f){
  int i;
  i=(1+f->tras)%MAX;
  if(i==f->frente) return 1;
  return 0;
}

int filaTam(tp_fila *f){
  int i;
  i=f->tras-f->frente;
  if(i>=0)return i;
  else return MAX+i;
}

int enfileirar(tp_fila *f,tp_item e){
  if(filaCheia(f)) return 0;
  if(filaVazia(f)){
    f->frente=++f->frente%MAX;
    f->tras=++f->tras%MAX;
  }
  f->item[f->tras]=e;
  f->tras=++f->tras%MAX;
  return 1;
}

int desenfileirar(tp_fila *f,tp_item *e){
  if(filaVazia(f)) return 0;
  *e=f->item[f->frente];
  f->frente=++f->frente%MAX;
  return 1;
}

void filaprint(tp_fila f){
  int e,i=0;
  printf("\n[");
  while(!filaVazia(&f)){
    desenfileirar(&f,&e);
    printf("%d,",e);
    i++;
  }
  if(i==0) printf("]");
  printf("\b]");
}

#endif