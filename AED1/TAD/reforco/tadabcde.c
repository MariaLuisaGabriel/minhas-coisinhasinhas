#include <stdlib.h>
#include <stdio.h>
#include "tadabcde.h"
#define MAX 30

typedef struct pilha
{
    int topo;
    int valor[MAX];
} Pilha;

Pilha *criar()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

int pilhaVazia(Pilha *p)
{
    if(p->topo==0) return 0;
    return 1;
}

int pilhaCheia(Pilha *p)
{
    if(p->topo==MAX) return 0;
    return 1;
}

int push(Pilha *p, int it)
{
    if(pilhaCheia(p)==0) return 1;
    p->valor[p->topo] = it;
    p->topo++;
    return 0;
}

int pop(Pilha *p, int *it)
{
    if(pilhaVazia(p)==0) return 1;
    *it = p->valor[p->topo -1];
    p->topo--;
    return 0;
}

int mostrar(Pilha *p)
{
    if(pilhaVazia(p)==0) return 1;
    for(int i=p->topo-1;i>=0;i--)
    {
        printf("\nnumero: %d",p->valor[i]);
    }
    return 0;
}

void limpar(Pilha *p)
{
    int *y;
    while(pilhaVazia(p)!=0)
        pop(p,y);
}