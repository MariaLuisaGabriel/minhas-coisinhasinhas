#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int num;
    struct No *prox;
}no;

lista *criar()
{
    lista *a = (lista*)malloc(sizeof(lista));
    *a = NULL;
    return a;
}
int tamanho(lista *l)
{
    if(listavazia(l)==0) return 0;
    else
    {
        return (1 + tamanho(&((*l)->prox)));
    }
}
void mostrar(lista *l,int i)
{
    if(listavazia(l)!=0)
    {
        printf("%dº valor: \n",i);
        printf("->%d;\n",(*l)->num);
        i++;
        mostrar(&((*l)->prox),i);//recursão: vai mostrar os elementos de l um por um na tática de lista cabeça-cauda.
    }
}
int inserirgeral(lista *l, int pos, int input)
{
    int j = 1;
    if(l==NULL) return -1;
    no *NO = (*l);
    if(pos==1)
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->num = input;
        novo->prox = NO;
        (*l) = novo;
        return 0;
    }
    else if(pos>tamanho(l))
    {
        while(NO->prox!=NULL)
        {
            NO = NO->prox;
        }
        no *novo = (no *)malloc(sizeof(no));
        NO->prox = novo;
        novo->num = input;
        novo->prox = NULL;
        return 0;
    }
    else
    {
        while((NO->prox!=NULL)&&(j<pos-1))
        {
            j++;
            NO = NO->prox;
        }
        no *novo = (no *)malloc(sizeof(no));
        novo->prox = NO->prox->prox;
        NO->prox = novo;
        novo->num = input;
        return 0;
    }
    return 1;
}
int removergeral(lista *l, int pos)
{
    int j = 1;
    if(l==NULL) return -1;
    if(listavazia(l)==0) return 1;
    no *NO = (*l);
    if(pos==1)
    {
        (*l) = NO->prox;
        free(NO);
        return 0;
    }
    else if(pos>tamanho(l))
    {
        no *aux = (*l);
        while(NO->prox!=NULL)
        {
            aux = NO;
            NO = NO->prox;
        }
        aux->prox = NULL;
        free(NO);
        return 0;
    }
    else
    {
        no *aux = (*l);
        while((NO->prox != NULL)&&(j<=pos))
        {
            j++;
            aux=NO;
            NO = NO->prox;
        }
        aux->prox = NO->prox;
        free(NO);
        return 0;
    }
    return 1;
}
int igual(lista *l, lista *h)
{
    if((l==NULL)||(h==NULL)) return -1;
    if(tamanho(l)!=tamanho(h)) return -2;
    if(listavazia(l)!=0)
    {
        if((*l)->num==(*h)->num)
            return (1 + igual(&((*l)->prox),&((*h)->prox)));
        else
            return (0 + igual(&((*l)->prox),&((*h)->prox)));
    }
    return 0;//lista está vazia
}
int soma(lista *l)
{
    if(l==NULL) return -1;
    if(listavazia(l)!=0)
    {
        return ((*l)->num + soma(&((*l)->prox)));
    }
    return 0;//lista está vazia
}
int mostrarev(lista *l)
{
    if(l==NULL) return 1;
    if(((*l)->prox)!=NULL)
    {
        mostrarev(&((*l)->prox));
    }
    printf("%d",(*l)->num);
    return 0;
}
int contaocorrencias(lista *l, int a)
{
    if(l==NULL) return -1;
    if((*l)==NULL) return 0;
    if(listavazia(l)==0) return 1;
    if((*l)->num==a)
        return 1 + contaocorrencias(&((*l)->prox),a);
    else
        return contaocorrencias(&((*l)->prox),a);
}
int listavazia(lista *l)
{
    if(*l == NULL) return 0;//vazio
    else return 1;//não vazio
}