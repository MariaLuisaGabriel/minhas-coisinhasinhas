#ifndef TADA_H_INCLUDED
#define TADA_H_INCLUDED

typedef struct fila Fila;

Fila *criar();
void limpar(Fila *f);
int insere(Fila *f,int it);
int remover(Fila *f,int *it);
void mostrar(Fila *f);

#endif