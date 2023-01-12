#include <stdio.h>
#include <stdlib.h>
#include "tadc.h"
#include <string.h>
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
    if(pilhaVazia(p)==0) return 2;
    for(int i=p->topo-1;i>=0;i--)
    {
        if(p->valor[i]!=p->valor[j])
            y=1;
        j++;
    }
    if(y==0) return 0;
    else return 1;
}

int limpar(Pilha *p)
{
    if(p==NULL) return -1;
    p->topo = 0;
    return 0;
}

int delimitadores(Pilha *p)
{
    if(p==NULL) return -1;
    int chaves = 0, parenteses = 0;
    for(int i=0;i<p->topo;i++)
    {
        if((p->valor[i]=='(')||(p->valor[i]==')'))
            parenteses++;
        if((p->valor[i]=='{')||(p->valor[i]=='}'))
            chaves++;
    }
    if((parenteses%2==0) && (chaves%2==0))
        return 0;
    return 1;
}

int copia(Pilha *p, char it[])
{
    if(p==NULL) return -1;
    int i = strlen(it);
    strcpy(p->valor,it);
    p->topo = i;
    return 0;
}