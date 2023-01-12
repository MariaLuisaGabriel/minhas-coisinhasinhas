#ifndef TADB_H_INCLUDED
#define TADB_H_INCLUDED

typedef struct pilha Pilha;
Pilha *criar();
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
int mostrar(Pilha *p);
int push(Pilha *p, char it);
int pop(Pilha *p, char *it);
int palindromo(Pilha *p);
int limpar(Pilha *p);

#endif