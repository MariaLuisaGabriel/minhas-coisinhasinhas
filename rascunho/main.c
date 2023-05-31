#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
}No;

typedef struct {
    No *inicio;
} fila;

fila *criaFila()
{
    fila *a = (fila*)malloc(sizeof(fila));
    a->inicio=NULL;
    return a;
}

void insereFila(fila *f, int dado)
{
    if(f = NULL)
    {
        f = criaFila();
        No *no = (No*)malloc(sizeof(no));
        no->dado = dado;
        f->inicio = no;
        return;
    }
    /*if(f->inicio==NULL) printf("AAA");return;
    No *aux = f->inicio;
    if(aux==NULL) printf("AAA");return;
    while(aux->prox!=NULL)
    {
        aux = aux->prox;
    }
    No *no = (No*)malloc(sizeof(no));
    no->dado = dado;
    aux->prox = no;*/
}

void mostraFila(fila *f)
{
    No *aux = f->inicio;
    while(aux!=NULL)
    {
        printf("%d ",aux->dado);
        aux = aux->prox;
    }
}

int main()
{
    fila *f = NULL;
    for(int i = 0; i<20; i++)
    {
        insereFila(f,i);
    }
    //mostraFila(f);
    return 0;
}