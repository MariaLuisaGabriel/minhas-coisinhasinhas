#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    struct aluno valores;
    No *prox;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criar()
{
    Lista *A = (Lista *)malloc(sizeof(Lista));
    A->inicio = NULL;
    return A;
}

void limpar(Lista*l)
{
    while(listaVazia(l)==0)
        removerInicio(l);
}

int inserirInicio(Lista *l,struct aluno it)
{
    if(l==NULL) return 2;
    No *no = (No*)malloc(sizeof(No));
    no->prox = l->inicio;
    no->valores = it;
    l->inicio = no;
    return 1;
}

int inserirFim(Lista *l,struct aluno it)
{
    if(l==NULL) return 2;
    if(l->inicio == NULL) return inserirInicio(l,it);
    No *noLista = l->inicio;
    while(noLista->prox!=NULL)
        noLista=noLista->prox;
    No *no=(No*)malloc(sizeof(No));
    no->valores=it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 1;
}

int inserirPosicao(Lista *l,struct aluno it,int pos)
{
    int i = tamanho(l),j=1;
    if(l==NULL) return 2;
    if(pos<0) return 8;
    if(pos>i) pos=i;
    No *nolista = l->inicio;
    while((nolista->prox != NULL) && (j<pos))
    {
        nolista = nolista->prox;
        j++;
    }
    No *no = (No*)malloc(sizeof(No));
    no->prox = nolista->prox;
    no->valores = it;
    nolista->prox = no;
    return 1;
}

int removerInicio(Lista *l)
{
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    No *nolista = l->inicio;
    l->inicio = nolista->prox;
    free(nolista);
    return 1;
}

int removerFim(Lista *l)
{
    int i = tamanho(l), j=1;
    if(l==NULL) return 2;
    if(l->inicio == NULL) return 0;
    No *nolista = l->inicio;
    while((nolista->prox != NULL) &&(j<i))
    {
        nolista = nolista->prox;
        j++;
    }
    No *no = (No*)malloc(sizeof(No));
    no->prox = nolista->prox;
    nolista->prox = NULL;
    free(no);
    return 1;
}

int removerPosicao(Lista *l,int pos)
{
    int i = tamanho(l), j=1;
    if(l==NULL) return 2;
    if(l->inicio == NULL) return 0;
    if(pos<0) return 8;
    if(pos>i) pos=i;
    No *nolista = l->inicio;
    while((nolista->prox != NULL) && (j<pos-1))
    {
        nolista = nolista->prox;
        j++;
    }
    No *no = (No*)malloc(sizeof(No));
    no->prox = nolista->prox;
    nolista->prox = nolista->prox->prox;
    free(no);
    return 1;
}

int removerItem(Lista *l,int chave)
{
    int p;
    if(l==NULL) return 2;
    if(l->inicio == NULL) return 0;
    int i = buscarItemChaveAlt(l,chave);
    if(i==8) return -1;
    while(i!=8)
    {
        p = removerPosicao(l,i);
        i = buscarItemChaveAlt(l,chave);
    }
    return 9;
}

int buscarItemChave(Lista*l,int chave,struct aluno *retorno)
{
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    No *nolista = l->inicio;
    while(nolista->prox != NULL)
    {
        if(nolista->valores.mat == chave)
        {
            *retorno = nolista->valores;
            return 1;
        }
        nolista = nolista->prox;
    }
    return 8;
}

int buscarItemChaveAlt(Lista*l,int chave)
{
    int p = 0;
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    No *nolista = l->inicio;
    while(nolista->prox != NULL)
    {
        if(nolista->valores.mat == chave)
        {
            return p;
        }
        p++;
        nolista = nolista->prox;
    }
    return 8;
}

int buscarPosicao(Lista *l,int pos,struct aluno *retorno)
{
    int i = tamanho(l);
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    if(pos<0) return 8;
    if(pos>i) pos=i;
    No *nolista = l->inicio;
    for(int i=1;nolista->prox != NULL&&(i<=pos);i++)
    {
        nolista = nolista->prox;
    }
    *retorno = nolista->valores;
    return 1;
}

int listaVazia(Lista *l)
{
    if(l->inicio == NULL) return 1;
    return 0;
}

int tamanho(Lista *l)
{
    int i=0;
    No *nolista = l->inicio;
    while(nolista->prox != NULL)
    {
        nolista = nolista->prox;
        i++;
    }
    return i;
}

void mostrar(Lista *l)
{
    int i=1;
    No *nolista = l->inicio;
    if(l->inicio == NULL) printf("\nlista vazia!\n");
    else
    {
        while(nolista!=NULL)
        {
            printf("\nposicao %d: ",i);
            printf("\naluno: %s.",nolista->valores.nome);
            printf("\nmatricula: %d.",nolista->valores.mat);
            printf("\nnota: %.2f.",nolista->valores.n1);
            printf("\n\n");
            nolista = nolista->prox;
            i++;
        }
    }
}

void mostrarAluno(struct aluno *a)
{
    printf("\n\naluno buscado:");
    printf("\naluno: %s.",a->nome);
    printf("\nmatricula: %d.",a->mat);
    printf("\nnota: %f.",a->n1);
    printf("\n");
}
