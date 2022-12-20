#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct No* lista;//lista é um no ponteiro => aponta para um nó
typedef struct No no;

lista *criar();
int listavazia(lista *l);
int tamanho(lista *l);
void mostrar(lista *l,int i);
int inserirgeral(lista *l, int pos, int input);
int removergeral(lista *l, int pos);
int igual(lista *l, lista *h);
int soma(lista *l);
int mostrarev(lista *l);
int contaocorrencias(lista *l, int a);

#endif