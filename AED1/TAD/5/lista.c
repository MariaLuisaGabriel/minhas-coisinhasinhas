#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    AL valores;
    no *prox;
}no;
typedef struct lista
{
    no *final;
    int tam;
}Lista;

Lista *criar()
{
    Lista *A = (Lista *)malloc(sizeof(Lista));
    A->final = NULL;
    A->tam = 0;
    return A;
}

int cadastrarinicio(Lista *l,AL *aluno)
{
    if(l==NULL) return -1;
    no *No = (no *)malloc(sizeof(no));
    if(l->final == NULL)
    {
        l->final = No;
        No->prox = l->final;
        No->valores = *aluno;
        l->tam++;
        return 0;
    }
    No->prox = l->final->prox;
    l->final->prox = No;
    No->valores = *aluno;
    l->tam++;
    return 0;
}

int cadastrarfim(Lista *l,AL *aluno)
{
    if(l==NULL) return 2;
    if(l->final == NULL) return cadastrarinicio(l,aluno);
    no *No = (no *)malloc(sizeof(no));
    No->prox = l->final;
    l->final = No;
    No->valores = *aluno;
    l->tam ++;
    return 0;
}

int cadastrarposicao(Lista *l,AL *aluno,int pos)
{
    int i = l->tam,j=1;
    if(l==NULL) return -1;
    if(pos<0) return 1;
    if(i==0) return cadastrarinicio(l,aluno);
    if(pos>=i) return cadastrarfim(l,aluno);
    no *nolista;
    nolista = l->final->prox;
    while(j<=pos-1)
    {
        nolista = nolista->prox;
        j++;
    }
    no *No = (no*)malloc(sizeof(no));
    No->prox = nolista->prox;
    No->valores = *aluno;
    nolista->prox = No;
    l->tam++;
    return 0;
}

int removerinicio(Lista *l)
{
    if(l==NULL) return -1;
    if(l->tam == 0) return 1;
    if(l->tam == 1)
    {
        no *nolista = l->final;
        l->final = NULL;
        (l->tam)--;
        free(nolista);
    } 
    no *nolista = l->final->prox;
    l->final->prox = nolista->prox;//o final anda 1 posicao pra frente
    (l->tam)--;
    free(nolista);//tira o antigo inicio
    return 0;
}

int removerfim(Lista *l)
{
    if(l==NULL) return -1;
    if(l->tam == 0) return 1;
    if(l->tam==1) return removerinicio(l);
    no *nolista = l->final->prox;
    while(nolista->prox!=l->final)
        nolista = nolista->prox;
    no *aux = nolista->prox;//ultimo elemento(velho)
    nolista->prox = nolista->prox->prox;
    l->final = nolista;
    (l->tam)--;
    free(aux);//libera o antigo fim
    return 0;
}