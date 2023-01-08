#ifndef TADC_H_INCLUDED
#define TADC_H_INCLUDED

typedef struct fila Fila;

Fila *criar();
void limpar(Fila *f);
int insere(Fila *f,int it);
int remover(Fila *f,int *it);
void mostrar(Fila *f);
int excluin(Fila *f, Fila *ret);

#endif