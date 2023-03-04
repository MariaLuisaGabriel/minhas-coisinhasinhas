#ifndef TADB_H_INCLUDED
#define TADB_H_INCLUDED

typedef struct fila Fila;
typedef struct fila2 Fila2;

Fila *criar();
Fila2 *criar2();
void limpar(Fila *f);
int insere(Fila *f,int it);
int insere2(Fila2 *f,int it);
int remover(Fila *f,int *it);
void mostrar(Fila *f);
void mostrar2(Fila2 *f);
int intercala(Fila *f, Fila *g, Fila2 *r);

#endif