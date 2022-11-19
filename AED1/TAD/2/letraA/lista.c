#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct lista {
    int total;
    struct aluno valores[MAX];
}Lista;

Lista *criar()
{
    Lista *A = (Lista *)malloc(sizeof(Lista));
    for(int i=0;i<MAX;i++)
    {
        A->valores[i].mat = 0;
    }
    return A;
}

void limpar(Lista*l)
{
    l->total = 0;
}

int inserirInicio(Lista *l,struct aluno it)
{
    if(l==NULL) return 2;
    if(l->total==MAX) return 0;
    if(l->total==1)
    {
        l->valores[1] = l->valores[0];
        l->valores[0] = it;
        l->total++;
        return 1;
    }
    if(l->total>1)
    {
        for(int i=l->total-1;i>=0;i--)
            l->valores[i+1] = l->valores[i];
        l->valores[0] = it;
        l->total++;
        return 1;
    }
    if(l->total==0)
    {
        l->valores[0] = it;
        l->total++;
        return 1;
    }
}

int inserirFim(Lista *l,struct aluno it)
{
    if(l==NULL) return 2;
    if(l->total==MAX) return 0;
    else
    {
        l->valores[l->total] = it;
        l->total++;
        return 1;
    }
}

int inserirPosicao(Lista *l,struct aluno it,int pos)
{
    if(l==NULL) return 2;
    if(pos>MAX||pos<1) return 8;
    if(l->total==MAX) return 0;
    if(pos == l->total)
    {
        l->valores[pos-1] = it;
        l->total++;
        return 1;
    }
    else
    {
        for(int i=l->total-1;i>=pos-1;i--)
            l->valores[i+1] = l->valores[i];
        l->valores[pos-1] = it;
        l->total++;
        return 1;
    }
}

int removerInicio(Lista *l)
{
    if(l==NULL) return 2;
    if(l->total == 0) return 0;
    for(int i=1;i<=l->total-1;i++)
        l->valores[i-1] = l->valores[i];
    l->total--;
    return 1;
}

int removerFim(Lista *l)
{
    if(l==NULL) return 2;
    if(l->total == 0) return 0;
    l->total--;
    return 1;
}

int removerPosicao(Lista *l,int pos)
{
    int h;
    if(l==NULL) return 2;
    if(l->total == 0) return 0;
    if(pos>MAX||pos<1) return 8;
    if(pos == l->total)
    {
        h = removerFim(l);
        return h;
    }
    else
    {
        for(int i=pos;i<=l->total-1;i++)
            l->valores[i-1] = l->valores[i];
        l->total--;
        return 1; 
    }
}

int removerItem(Lista *l,int chave)
{
    int j;
    if(l==NULL) return 2;
    if(l->total==0) return 0;
    for(int i=0;i<l->total;i++)
    {
        if(l->valores[i].mat == chave)
        {
            j = removerPosicao(l,i+1);
            return j;
        }
    }
}

int buscarItemChave(Lista*l,int chave,struct aluno *retorno)
{
    if(l == NULL) return 2;
    if(l->total == 0) return 0;
    for(int i=0;i<l->total;i++)
    {
        if(l->valores[i].mat == chave)
        {
            *retorno = l->valores[i];
        }
    }
    return 1;
}

int buscarPosicao(Lista *l,int pos,struct aluno *retorno)
{
    if(l == NULL) return 2;
    if(l->total == 0) return 0;
    if(pos>MAX||pos<1) return 8;
    *retorno = l->valores[pos-1];
    return 1;
}

int listaVazia(Lista *l)
{
    if(l->total == 0) return 1;
    return 0;
}

int listaCheia(Lista *l)
{
    if(l->total == MAX) return 1;
    return 0;
}

int tamanho(Lista *l)
{
    return l->total;
}

void mostrar(Lista *l)
{
    if(l->total == 0) printf("\nlista vazia!\n");
    else
    {
        for(int i=0;i<l->total;i++)
        {
            printf("\nposicao %d: ",i+1);
            printf("\naluno: %s.",l->valores[i].nome);
            printf("\nmatricula: %d.",l->valores[i].mat);
            printf("\nnota: %.2f.",l->valores[i].n1);
            printf("\n\n");
        }
    }
}

void mostrarAluno(struct aluno *a)
{
    printf("\n\naluno buscado:");
    printf("\naluno: %s.",a->nome);
    printf("\nmatricula: %d.",a->mat);
    printf("\nnota: %f.",a->n1);
}
