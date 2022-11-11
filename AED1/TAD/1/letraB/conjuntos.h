#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED

typedef struct conj Conj;

Conj *criar(int *u,int t);

int membro(Conj *a,int l);

void insere(Conj *a, int el);

void remover(Conj *a, int el);

Conj *uniao(Conj *a,Conj *b);

Conj *intersecao(Conj *a,Conj *b);

void diferenca(Conj *a);

void mostrar(Conj *a);

#endif