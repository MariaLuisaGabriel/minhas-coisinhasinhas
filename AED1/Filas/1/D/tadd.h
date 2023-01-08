#ifndef TADC_H_INCLUDED
#define TADC_H_INCLUDED

typedef struct fila Fila;
typedef struct pacientes Pac;

Fila *criar();
void limpar(Fila *f);
int insere(Fila *f,char it[]);
int remover(Fila *f,char it[]);
void mostrar(Fila *f);

#endif