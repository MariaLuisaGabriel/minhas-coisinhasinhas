#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

typedef struct matriz Matriz;

Matriz *criar(int i, int j);

void destruir(Matriz *a);

void atribuir(Matriz *a, int i, int j);

void atribuirtudo(Matriz *a);

int acessavalor(Matriz *a ,int i, int j);

int linhas(Matriz *a);

int colunas(Matriz *a);

void preencher(Matriz *a, int min, int max);

Matriz *somar(Matriz *a, Matriz *b);

void mostrar(Matriz *a);

#endif