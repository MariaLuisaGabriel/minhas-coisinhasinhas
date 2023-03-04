#include <stdio.h>
#include <stdlib.h>
#include "tada.h"
#define MAX 30

typedef struct fila
{
    int i,e,q;
    int v[MAX];
}Fila;

Fila *criar()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->i=0;
    f->q=0;
    f->e=0;
    return f;
}

void limpar(Fila *f)
{
    free(f);
    f=NULL;
}

int insere(Fila *f,int it)
{
    if(f==NULL) return 2;
    if(f->q==MAX) return 1;
    f->v[f->e]= it;
    f->e = ((f->e)+1)%MAX;
    f->q++;
    return 0;
}

int remover(Fila *f,int *it)
{
    if(f==NULL) return 2;
    if(f->q==0) return 1;
    *it = f->v[f->i];
    f->i = ((f->i)+1)%MAX;
    f->q--;
    return 0;
}

void mostrar(Fila *f)
{
    int i = f->i;
    int q = f->q;
    printf("[");
    while(q>0)
    {
        printf("%d ",f->v[i]);
        i=(i+1)%MAX;
        q--;
    }
    printf("]");
}