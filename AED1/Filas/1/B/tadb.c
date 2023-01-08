#include <stdio.h>
#include <stdlib.h>
#include "tadb.h"
#define MAX 30
#define MAX2 60

typedef struct fila
{
    int i,e,q;
    int v[MAX];
}Fila;
typedef struct fila2
{
    int i,e,q;
    int v[MAX2];
}Fila2;

Fila *criar()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->i=0;
    f->q=0;
    f->e=0;
    return f;
}

Fila2 *criar2()
{
    Fila2 *f = (Fila2 *)malloc(sizeof(Fila2));
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

int insere2(Fila2 *f,int it)
{
    if(f==NULL) return 2;
    if(f->q==MAX) return 1;
    f->v[f->e]= it;
    f->e = ((f->e)+1)%MAX2;
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

void mostrar2(Fila2 *f)
{
    int i = f->i;
    int q = f->q;
    printf("[");
    while(q>0)
    {
        printf("%d ",f->v[i]);
        i=(i+1)%MAX2;
        q--;
    }
    printf("]");
}

int intercala(Fila *f, Fila *g, Fila2 *r)
{
    if(f==NULL||g==NULL) return 2;
    int o,i,i1,q,q1;
    if((f->q==0) && (g->q==0)) return 1;
    if(g->q==0)
    {
        o=0;
        q = f->q;
        i = f->i;
        while(q>0)
        {
            r->v[o] = f->v[i];
            i++;
            q--;
        }
        r->q = f->q;
        return 0;
    }
    if(f->q==0)
    {
        o=0;
        q = g->q;
        i = g->i;
        while(q>0)
        {
            r->v[o] = g->v[i];
            i++;
            q--;
        }
        r->q = g->q;
        return 0;
    }
    i = g->i;
    i1 = f->i;
    if(f->q>g->q) 
    {
        q=g->q;
        q1=f->q;
        o=1;
    }
    else if(g->q>f->q) 
    {
        q=f->q;
        q1=g->q;
        o=2;
    }
    else 
    {
        q=g->q;
        q1=f->q;
    }
    while(q>0)
    {
        insere2(r,g->v[i]);
        insere2(r,f->v[i1]);
        i=(i+1)%MAX;
        i1=(i1+1)%MAX;
        q--;
        q1--;
    }
    switch(o)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            while(q1>0)
            {
                insere2(r,f->v[i1]);
                i1 = (i1+1)%MAX;
                q1--;
            }
            break;
        }
        case 2:
        {
            while(q1>0)
            {
                insere2(r,g->v[i]);
                i = (i+1)%MAX;
                q1--;
            }
            break;
        }
    }
    return 0;
}