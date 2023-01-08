#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadd.h"
#define MAX 30

typedef struct pacientes
{
    char paciente[MAX];
}Pac;

typedef struct fila
{
    int i,e,q;
    Pac p[MAX];
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

int insere(Fila *f,char it[])
{
    if(f==NULL) return 2;
    if(f->q==MAX) return 1;
    strcpy((f->p[f->e]).paciente,it);
    f->e = ((f->e)+1)%MAX;
    f->q++;
    return 0;
}

int remover(Fila *f,char it[])
{
    if(f==NULL) return 2;
    if(f->q==0) return 1;
    strcpy(it,(f->p[f->i]).paciente);
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
        printf("%s ",(f->p[i]).paciente);
        i=(i+1)%MAX;
        q--;
    }
    printf("]");
}