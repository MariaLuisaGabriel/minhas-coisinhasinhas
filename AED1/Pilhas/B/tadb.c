#include <stdio.h>
#include <stdlib.h>
#include "tadb.h"
#define MAX 30

typedef struct pilha
{
    int topo;
    char valor[MAX];
} Pilha;

Pilha *criar()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

int pilhaVazia(Pilha *p)
{
    if(p==NULL) return -1;
    if(p->topo==0) return 0;
    return 1;
}

int pilhaCheia(Pilha *p)
{
    if(p==NULL) return -1;
    if(p->topo==MAX) return 0;
    return 1;
}

int push(Pilha *p, char it)
{
    if(p==NULL) return -1;
    if(pilhaCheia(p)==0) return 1;
    p->valor[p->topo] = it;
    p->topo++;
    return 0;
}

int pop(Pilha *p, char *it)
{
    if(p==NULL) return -1;
    if(pilhaVazia(p)==0) return 1;
    *it = p->valor[p->topo -1];
    p->topo--;
    return 0;
}

int mostrar(Pilha *p)
{
    if(p==NULL) return -1;
    if(pilhaVazia(p)==0) return 1;
    for(int i=p->topo-1;i>=0;i--)
    {
        printf("%c",p->valor[i]);
    }
    return 0;
}

int palindromo(Pilha *p)
{
    if(p==NULL) return -1;
    int j=0,y=0;
    if(pilhaVazia(p)==0) return 1;
    for(int i=p->topo-1;i>=0;i--)
    {
        if(p->valor[i]!=p->valor[j])
            y=1;
        j++;
    }
    if(y==0) return 0;
    else return -1;
}

int limpar(Pilha *p)
{
    if(p==NULL) return -1;
    p->topo = 0;
    return 0;
}