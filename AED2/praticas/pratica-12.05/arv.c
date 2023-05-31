#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arv.h"

typedef struct ab
{
    int valor;//CEP
    char nome[1000];
    char sigla[3];
    char end[1000];
    int nivel;
    arvBin *esq;
    arvBin *dir;
    arvBin *ant;
}arvBin;

arvBin *criaArv()
{
    arvBin *a = (arvBin *)malloc(sizeof(arvBin));
    a->nivel = 0;
    a->esq = NULL;
    a->dir = NULL;
    a->ant = NULL;
    return a;
}

void insereNo(arvBin **raiz, int valor, char nome[], char sigla[], char end[], int nivel){
    if (*raiz == NULL){
        *raiz = (arvBin*)malloc(sizeof(arvBin));
        (*raiz)->valor = valor;
        (*raiz)->nivel = nivel;
        strcpy((*raiz)->nome, nome);
        strcpy((*raiz)->sigla, sigla);
        strcpy((*raiz)->end, end);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->ant = NULL;
    } else {
        if (valor < (*raiz)->valor){
            insereNo(&(*raiz)->esq, valor, nome, sigla, end, nivel+1);
            (*raiz)->esq->ant = *raiz;
        } else {
            insereNo(&(*raiz)->dir, valor, nome, sigla, end, nivel+1);
            (*raiz)->dir->ant = *raiz;
        }
    }
}

/*
void insereNo(arvBin *a, int no, int lv, char n[], char s[], char end[])
{
    if(a==NULL) 
    {
        a = criaArv();
        a->valor=no;
        strcpy(a->end,end);
        strcpy(a->nome,n);
        strcpy(a->sigla,s);
        return;
    }
    arvBin *No;
    No = criaArv();
    No->valor=no;
    strcpy(No->end,end);
    strcpy(No->nome,n);
    strcpy(No->sigla,s);
    No->nivel=lv;
    No->ant = a;
    if(no>(*a).valor)
    {
        if((*a).dir!=NULL)
        {
            insereNo(((*a).dir),no,lv+1,n,s,end);
        }
        else
        {
            (*a).dir = No;
        }
    }
    else if(no<(*a).valor)
    {
        if((*a).esq!=NULL)
        {
            insereNo(((*a).esq),no,lv+1,n,s,end);
        }
        else
        {
            (*a).esq = No;
        }
    }
    else
    {
        free(No);
        return;
    }
}*/

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

arvBin *buscaArv(arvBin *a, int chave)
{
    if(a==NULL) return NULL;
    if(a->valor==chave) return a;
    if(chave>a->valor && a->dir!=NULL) return buscaArv(a->dir,chave);
    if(chave<a->valor && a->esq!=NULL) return buscaArv(a->esq,chave);
    return NULL;
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

void getValores(arvBin *a)
{
  if(a==NULL) return;
    printf("\n->%d - %s - %s - %s",a->valor,a->sigla,a->nome,a->end);
}

int converte(char c[])
{
  int v=0;
  int j=0;
  char aux[9];
  for(int i = 0; i<9; i++)
    {
      if(c[i]!='-')
      {
        aux[j]=c[i];
        j++;
      }
    }
    v = atoi(aux);
  return v;
}

arvBin *getmenor(arvBin *a)
{
  if(a==NULL)
  {
    return NULL;
  }
  arvBin *aux = a;
  while(aux->esq!=NULL)
  {
    aux = aux->esq;
  }
  return aux;
}

arvBin *getmaior(arvBin *a)
{
  if(a==NULL) 
  {
    return NULL;
  }
  arvBin *aux = a;
  while(aux->dir!=NULL)
  {
    aux = aux->dir;
  }
  return aux;
}

void altura(arvBin *a, int *i)
{
  if(a==NULL) return;
  if(a->nivel==0) {*i=0;}
  else if((a->nivel) > *i) {*i=(a->nivel);}
  if(a->esq!=NULL)
  {
    altura(a->esq,i);
  }
  if(a->dir!=NULL)
  {
    altura(a->dir,i);
  }
}