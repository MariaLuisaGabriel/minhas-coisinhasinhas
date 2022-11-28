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
    if(pos>i) return inserirFim(l,it);
    No *nolista = l->inicio;
    while((nolista->prox != NULL) && (j<pos-1))
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
    if(i==1) return removerInicio(l);
    /*No *nolista = l->inicio;
    while((nolista->prox != NULL) &&(j<i))
    {
        printf("------");
        nolista = nolista->prox;
        j++;
    }
    No *no = (No*)malloc(sizeof(No));
    no->prox = nolista->prox;
    nolista->prox = NULL;
    free(no);
    */
    No *noAuxiliar=NULL;
    No *noLista=l->inicio;
    while(noLista->prox!=NULL)
    {
        noAuxiliar=noLista;
        noLista=noLista->prox;
    } 
    //no fim, o noauxiliar fica em penúltimo na lista, logo, basta aponta-lo para NULL e liberar nolista.
    if(noAuxiliar==NULL) l->inicio=NULL;
    else noAuxiliar->prox=NULL;
    free(noLista);
    return 1;
}

int removerPosicao(Lista *l,int pos)
{
    int i = tamanho(l), j=1;
    if(l==NULL) return 2;
    if(l->inicio == NULL) return 0;
    if(pos<0) return 8;
    if(pos>i) pos=i;
    if(pos==1) return removerInicio(l);
    if(pos==i) return removerFim(l);
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
    int p,L=tamanho(l);
    if(l==NULL) return 2;
    if(l->inicio == NULL) return 0;
    int i = buscarItemChaveAlt(l,chave);
    if(i==-3) return -1;
    if(i==1)
    {
        int r = removerInicio(l);
        return r;
    }
    if(i==L)
    {
        int o = removerFim(l);
        return o;
    }
    while(i!=-3)
    {
        p = removerPosicao(l,i);
        i = buscarItemChaveAlt(l,chave);
    }
    return 9;
}

int removerapartir(Lista *l,int pos)
{
    int i = tamanho(l), j;
    if(l==NULL) return 2;
    if(l->inicio == NULL) return 0;
    if(pos>i||pos<0) return 8;
    if(pos==i) return removerFim(l);
    if(pos==1) 
    {
        limpar(l);
        return 1;
    }
    pos=i-pos+1;
    for(int i=1;i<=pos;i++)
    {
        j=removerFim(l);
    }
    return 1;
}

int buscarItemChave(Lista*l,int chave,struct aluno *retorno)
{
    int i = tamanho(l),j=1;
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    No *nolista = l->inicio;
    if(i==1)
    {
        if((nolista->valores).mat == chave)
        {
            *retorno = nolista->valores;
            return 1;
        }
        return 8;
    }
    while(nolista!= NULL)
    {//lembrar de por os parenteses! pelo visto faz diferença!loop q vai ate o ultimo elemento e para sem analisar ele ;-;
        if((nolista->valores).mat == chave)
        {
            *retorno = nolista->valores;
            return 1;
        }
        nolista = nolista->prox;
    }
    /*//para caso o ultimo elemento tenha a chave
    if((nolista->valores).mat == chave)
    {
        *retorno = nolista->valores;
        return 1;
    }*/
    return 8;
}

int buscarItemChaveAlt(Lista*l,int chave)
{
    int p = 1;
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    No *nolista = l->inicio;
    while(nolista->prox != NULL)
    {
        if((nolista->valores).mat == chave)
        {
            return p;
        }
        p++;
        nolista = nolista->prox;
    }
    if(p==1) return 1;
    return -3;
}

int buscarPosicao(Lista *l,int pos,struct aluno *retorno)
{
    No *nolista = l->inicio;
    int i = tamanho(l);
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    if(pos<0) return 8;
    if(pos==1) 
    {
        *retorno = nolista->valores;
        return 1;
    }
    if(pos>i) pos=i;
    for(int i=1;(nolista->prox != NULL)&&(i<pos);i++)
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
    int i=1;
    if(l->inicio == NULL) return 0;
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

int contemItem(Lista *l, int chave)
{
    printf("CONTEM ITEM");
    int i = tamanho(l),j=1;
    if(l == NULL) return 2;
    if(l->inicio == NULL) return -1;
    No *nolista = l->inicio;
    if(i==1)
    {
        if((nolista->valores).mat == chave)
        {
            return 1;
        }
        return 0;
    }
    while(nolista != NULL)//se por assim, o loop vai analisar ate o ultimo elemento(antes, chegava no ultimo e parava o loop sem analisa-lo)
    {//lembrar de por os parenteses! pelo visto faz diferença!loop q vai ate o ultimo elemento e para sem analisar ele ;-;
        if((nolista->valores).mat == chave)
        {
            return 1;
        }
        nolista = nolista->prox;
    }
    return 0;
}

int maiorNota(Lista *l,struct aluno *retorno)
{
    float m=0.0;
    int n,j;
    if(l == NULL) return 0;
    if(l->inicio == NULL) return 2;
    No *nolista = l->inicio;
    while(nolista != NULL)
    {
        printf("uai");
        if(((nolista->valores).n1)>m)
        {
            printf("uaaai");
            m=(nolista->valores).n1;
            n=(nolista->valores).mat;
        }
        nolista = nolista->prox;
    }
    j = buscarItemChave(l,n,retorno);
    return 1;
}

int concatena(Lista *l,Lista *m,Lista *result)
{
    if(l == NULL) return 0;
    if(m == NULL) return -1;
    if(result == NULL) return -2;
    No *nolista = l->inicio;
    while(nolista->prox!=NULL)
        nolista = nolista->prox;
    nolista->prox = m->inicio;
    result->inicio = l->inicio;
    return 1;
}

void listamat(Lista *l,int *n)
{
    printf("LISTAMAT");
    n = (int *)malloc(sizeof(int));
    int k = tamanho(l),j=1;
    No *nolista = l->inicio;
    while(nolista!= NULL)
    {
        n[j-1] = (nolista->valores).mat;
        n = (int *)realloc(n,(j+1)*sizeof(int));
        nolista = nolista->prox;
    }
    for(int i = 0;i<k;i++)
        printf("%d",n[i]);
}