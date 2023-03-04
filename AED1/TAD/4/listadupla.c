#include "listadupla.h"
#include <stdio.h>
#include <stdlib.h>
//padrão: 0 para sucesso, 1 para fracasso e qualquer outro valor para erro;

typedef struct No
{
    AL valores;
    no *prox;
    no *ant;
}no;
typedef struct lista
{
    no *inicio;
    int tam;
}Lista;

Lista *criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

void mostrarAluno(AL *a)
{
    printf("\n\naluno buscado:");
    printf("\naluno: %s.",a->nome);
    printf("\nmatricula: %d.",a->mat);
    printf("\nnota: %f.",a->nota);
    printf("\n");
}

int cadastrarinicio(Lista *l, AL *aluno)
{
    if(l==NULL) return -1;
    no *n = (no *)malloc(sizeof(no));
    n->prox = l->inicio;
    if(l->inicio!=NULL) (l->inicio)->ant = n;
    l->inicio = n;
    n->ant = NULL;
    n->valores = *aluno;
    (l->tam)++;
    return 0;
}

int cadastrarfim(Lista *l, AL *aluno)
{
    if(l==NULL) return -1;
    no *n = (no *)malloc(sizeof(no));
    if(l->inicio==NULL) return cadastrarinicio(l,aluno);
    no *nolista = l->inicio;
    while(nolista->prox != NULL)
        nolista = nolista->prox;
    nolista->prox = n;
    n->ant = nolista;
    n->prox = NULL;
    n->valores = *aluno;
    (l->tam)++;
    return 0;
}

int cadastrarposicao(Lista *l, AL *aluno, int pos)
{
    if(l==NULL) return -1;
    if(pos>l->tam) return cadastrarfim(l,aluno);
    if(l->inicio==NULL) return cadastrarinicio(l,aluno);
    if(pos<0) return 1;
    int j=1;
    no *nolista = l->inicio;
    no *n = (no *)malloc(sizeof(no));
    while((j<pos-1)&&(nolista->prox!=NULL))
    {
        nolista = nolista->prox;
        j++;
    }
    n->prox = nolista->prox;
    (nolista->prox)->ant = n;
    n->ant = nolista;
    nolista->prox = n;
    n->valores = *aluno;
    (l->tam)++;
    return 0;
}

int removerinicio(Lista *l)
{
    if(l==NULL) return -1;
    if(l->inicio == NULL) return 1;
    no *nolista = l->inicio;
    l->inicio = nolista->prox;//o inicio anda 1 posicao pra frente
    if(l->inicio != NULL)//condicional para quando a lista tem mais de um elemento.Se ela tiver so um elemento, a operaçao da linha 82 basta.
        (l->inicio)->ant = NULL;//se ainda sobrar elemento dentro da lista, o novo primeiro elemento deve apontar para NULL
    (l->tam)--;
    free(nolista);//tira o antigo inicio
    return 0;
}

int removerfim(Lista *l)
{
    if(l==NULL) return -1;
    if(l->inicio == NULL) return 1;
    no *nolista = l->inicio;
    while(nolista->prox!=NULL)
        nolista = nolista->prox;
    nolista = nolista->ant;//penultimo elemento
    no *aux = nolista->prox;//ultimo elemento(velho)
    nolista->prox = NULL;//o penultimo elemento se torna o ultimo
    (l->tam)--;
    free(aux);//libera o antigo fim
    return 0;
}

int removerposicao(Lista *l, int pos)
{
    int j = 1;
    if(l==NULL) return -1;
    if(l->inicio == NULL) return -3;
    if(pos>=l->tam) return removerfim(l);
    if(pos<0) return 1;
    if(pos==1) return removerinicio(l);
    no *nolista = l->inicio;
    while((nolista->prox!=NULL)&&(j<pos))
    {
        nolista = nolista->prox;
        j++;
    }
    no *aux = nolista;//aux na posicao pos
    no *aux2 = nolista->prox;//aux2 na posicao pos+1
    nolista = nolista->ant;//nolista na posicao pos-1
    nolista->prox = aux2;//o proximo de pos-1 é pos+1
    aux2->ant = nolista;//o anterior de pos+1 é pos-1
    (l->tam)--;
    free(aux);
    return 0;
}

void mostrar(Lista *l)
{
    puts("LISTA DE ALUNOS CADASTRADOS:");
    puts("============================");
    no *nolista = l->inicio;
    while(nolista != NULL)
    {
        printf("\n->nome do aluno: %s.",(nolista->valores).nome);
        printf("\n->matricula do aluno: %d.",(nolista->valores).mat);
        printf("\n->nota do aluno: %f.",(nolista->valores).nota);
        printf("\n");
        nolista = nolista->prox;
    }
}

void limpar(Lista *l)//apagar os elementos só
{
    l->tam = 0;
    while(l->inicio != NULL)
        removerinicio(l);
}

int maiornota(Lista *l,AL *aluno)
{
    float m=0.0;
    if(l == NULL) return -1;
    if(l->inicio == NULL) return 1;
    no *nolista = l->inicio;
    while(nolista != NULL)
    {
        if(nolista->valores.nota>m)
        {
            m=nolista->valores.nota;
            *aluno = nolista->valores;
        }
        nolista = nolista->prox;
    }
    return 0;
}

int tamanho(Lista *l)
{
    int i=1;
    if(l->inicio == NULL) return 0;
    no *nolista = l->inicio;
    while(nolista->prox != NULL)
    {
        nolista = nolista->prox;
        i++;
    }
    return i;
}

int troca(Lista *l,int pos1, int pos2)
{
    int a;
    if(l==NULL) return -1;
    if(pos1>l->tam) pos1 = l->tam;
    if(pos2>l->tam) pos2 = l->tam;
    if(l->inicio==NULL) return -3;
    if(pos1<0||pos2<0) return 1;
    AL *aluno1 = (AL *)malloc(sizeof(AL));
    AL *aluno2 = (AL *)malloc(sizeof(AL));
    a = buscarPosicao(l,pos1,aluno1);
    a = buscarPosicao(l,pos2,aluno2);
    a = removerposicao(l,pos1);
    a = removerposicao(l,pos2);
    a = cadastrarposicao(l,aluno1,pos2);
    a = cadastrarposicao(l,aluno2,pos1);
    return 0;
}

int buscarPosicao(Lista *l,int pos,AL *retorno)
{
    no *nolista = l->inicio;
    int i = l->tam;
    if(l == NULL) return -1;
    if(l->inicio == NULL) return 1;
    if(pos<0) return 1;
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
    return 0;
}

int ordemmat(Lista *l)
{
    int ant;
    if(l == NULL) return -1;
    if(l->inicio == NULL) return 2;
    ant = ((l->inicio)->valores).mat;
    no *nolista = (l->inicio)->prox;
    while(nolista->prox != NULL)
    {
        if(ant>(nolista->valores).mat)
            return 1;
        ant = (nolista->valores).mat;
        nolista = nolista->prox;
    }
    return 0;
}

int semelhanca(Lista *l, Lista *k)
{
    int j = 0,j1;
    if((l == NULL)||(k == NULL)) return -1;
    if((l->inicio == NULL)&&(k->inicio == NULL)) return 0;
    if(l->tam != k->tam) return 1;//se nao tiverem o mesmo tamanho, já nao têm os mesmos elementos
    no *nolistal = l->inicio;
    no *nolistak = k->inicio;
    while(nolistal!=NULL)
    {
        j1=j;
        while(nolistak!=NULL)
        {
            if((nolistal->valores).mat == (nolistak->valores).mat)
                j++;
            nolistak = nolistak->prox;
        }
        if(j-j1>1) return 1;
        nolistak = k->inicio;
        nolistal = nolistal->prox;
    }
    if(j==l->tam) return 0;
    else return 1;
}
