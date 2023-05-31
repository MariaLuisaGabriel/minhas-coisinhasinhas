#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

typedef struct ab
{
    int valor;
    int nivel;
    arvBin *esq;
    arvBin *dir;
    arvBin *ant;
}arvBin;

arvBin *criaArv(int raiz)
{
    arvBin *a = (arvBin *)malloc(sizeof(arvBin));
    a->nivel = 0;
    a->valor = raiz;
    a->esq = NULL;
    a->dir = NULL;
    a->ant = NULL;
    return a;
}

void insereNo(arvBin *a, int no, int lv)
{
    if(a==NULL) return;
    arvBin *No = criaArv(no);
    No->ant = a;
    if(no>a->valor)
    {
        if(a->dir!=NULL)
        {
            insereNo(a->dir,no,lv+1);
        }
        else
        {
            a->dir = No;
            No->nivel=lv;
        }
    }
    else if(no<a->valor)
    {
        if(a->esq!=NULL)
        {
            insereNo(a->esq,no,lv+1);
        }
        else
        {
            a->esq = No;
            No->nivel=lv;
        }
    }
    else
    {
        free(No);
        //printf("\nERRO: valor ja existe na arvore.\n");
        return;
    }
}

arvBin *removeNo(arvBin *a, int chave, int tipo)
{
    if(a==NULL) return NULL;
    arvBin *pos = buscaArv(a,chave);
    if(pos==NULL)
    {
        printf("\nno nao existe.");
        return a;
    }
    arvBin *aux = (arvBin *)malloc(sizeof(arvBin));
    switch(tipo)
    {
        case 1: // troca com o menor
        {
            if(pos->esq==NULL)
            {
                printf("\nERRO, nao ha como fazer a troca pelo menor;");
                return a;
            }
            if(pos->nivel != 0)
            {
                if(pos->valor>(pos->ant)->valor) {(pos->ant)->dir = pos->esq;}
                else {(pos->ant)->esq = pos->esq;}
            }
            aux = pos->esq;
            while(aux->dir!=NULL)
                {
                    aux = aux->dir;
                }
            aux->dir = pos->dir;
            //if(pos->dir!=NULL){(pos->dir)->ant = aux;}
            if(pos->nivel!=0){(pos->esq)->ant = pos->ant;}
            else {
                (pos->esq)->ant=NULL;a = pos->esq;
            }
            break;
        }
        case 2: // troca com o maior
        {
            if(pos->dir==NULL)
            {
                printf("\nERRO, nao ha como fazer a troca pelo maior;");
                return a;
            }
            if(pos->nivel != 0)
            {
                if(pos->valor>(pos->ant)->valor) {(pos->ant)->dir = pos->dir;}
                else {(pos->ant)->esq = pos->dir;}
            }
            aux = pos->dir;
            while(aux->esq!=NULL)
                {
                    aux = aux->esq;
                }
            aux->esq = pos->esq;
            if(pos->esq!=NULL){(pos->esq)->ant = aux;}
            if(pos->nivel!=0){(pos->dir)->ant = pos->ant;}
            else {(pos->dir)->ant=NULL;a = pos->dir;}
            break;
        }
    }
    corrigenivel(a, 0);
    return a;
}

int getmenor(arvBin *a)
{
  if(a==NULL) return -1;
  if(a->esq != NULL)
  {
    return getmenor(a->esq);
  }
  else
  {
    return a->valor;
  }
}

int getmaior(arvBin *a)
{
  if(a==NULL) return -1;
  if(a->dir != NULL)
  {
    return getmaior(a->dir);
  }
  else
  {
    return a->valor;
  }
}

arvBin *buscaArv(arvBin *a, int chave)
{
    if(a==NULL) return NULL;
    if(a->valor==chave) return a;
    if(chave>a->valor ) return buscaArv(a->dir,chave);
    if(chave<a->valor ) return buscaArv(a->esq,chave);
}

void mostraArv(arvBin *a)
{
    if(a==NULL) return;
    if(a->nivel==0) {
        printf("( r");
    }
    printf("%d ",a->valor);
    if(a->dir!=NULL)
    {
        printf("d( ");
        mostraArv(a->dir);
    }
    if(a->esq!=NULL)
    {
        printf("e( ");
        mostraArv(a->esq);
    }
    printf(") ");
}

void mostraArvAlin(arvBin *a)
{
    if(a==NULL) return;
    for(int i=0; i<a->nivel; i++){printf("    ");}
    printf("%d\n",a->valor);
    if(a->dir!=NULL)
    {
        mostraArvAlin(a->dir);
    }
    if(a->esq!=NULL)
    {
        mostraArvAlin(a->esq);
    }
}

void corrigenivel(arvBin *a, int i)
{
    if(a==NULL) return;
    if(a->nivel!=i) a->nivel = i;
    if(a->dir!=NULL)
    {
        corrigenivel(a->dir,i+1);
    }
    if(a->esq!=NULL)
    {
        corrigenivel(a->esq,i+1);
    }
}

void percursos(arvBin *a, int tipo)
{
    if(a==NULL) return;
    switch(tipo)
    {
        case 1: //pre-fixada
        {
            printf(" %d, ",a->valor);
            percursos(a->dir,tipo);
            percursos(a->esq,tipo);
            break;
        }
        case 2: //central
        {
            percursos(a->dir,tipo);
            printf(" %d, ",a->valor);
            percursos(a->esq,tipo);
            break;
        }
        case 3: //pos-fixada
        {
            percursos(a->dir,tipo);
            percursos(a->esq,tipo);
            printf(" %d, ",a->valor);
            break;
        }
    }
}

int getValor(arvBin *a)
{
    return a->valor;
}

void contTAM(arvBin *a, int aux, int *res)
{
    if(a == NULL)
    {
        (*res)=aux;
        return;
    }
    int e,d;
    contTAM(a->dir, aux+1, res);
    e = (*res);
    contTAM(a->esq, aux+1, res);
    d = (*res);
    if(e>d)
    {
        (*res) = e;
    }
    else
    {
        (*res) = d;
    }
}

int maior(arvBin *a)
{
    int res = a->valor;
    int e, d;
    if(a->dir!=NULL)
    {
        d = maior(a->dir);
        if(d>res) res = d;
    }
    if(a->esq!=NULL)
    {
        e = maior(a->esq);
        if(e>res) res = e;
    }
    return res;
}