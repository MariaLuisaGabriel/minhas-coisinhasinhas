#ifndef TADABCDE_H_INCLUDED
#define TADABCDE_H_INCLUDED

typedef struct pilha Pilha;
Pilha *criar();
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
int mostrar(Pilha *p);
int push(Pilha *p, int it);
int pop(Pilha *p, int *it);
void limpar(Pilha *p);

#endif