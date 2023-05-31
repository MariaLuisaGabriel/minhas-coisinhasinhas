#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"

typedef struct palavra{
    char palavra[50];
    char estrofe[101];
    int frequencia;
    int cont_total;
    char nome[50];
    char autor[50];
    pal *dir;
    pal *esq;
} pal;

void mostraFila(pal *fila)
{
    pal *aux = fila;
    while(aux->dir!=NULL)
    {
        printf("%s, %d ",aux->palavra,aux->frequencia);
        aux = aux->dir;
    }
}

pal *criaFila()
{
    pal *a = (pal *)malloc(sizeof(pal));
    a->dir = NULL;
    a->esq = NULL;
    a->frequencia = 1;
    a->cont_total = 1;
    return a;
}

void insereFila(pal *fila, char *palavra, char *estrofe, char *nome, char *autor)
{
    if(fila==NULL)
    {//fila vazia, cria a fila e insere o primeiro elemento
        fila = criaFila();
        strcpy(fila->palavra,palavra);
        strncpy(fila->estrofe,estrofe,100);
        strcpy(fila->nome,nome);
        strcpy(fila->autor,autor);
        return;
    }

    int flag = 0;
    pal *aux = fila;
    while(aux->dir!=NULL)
    {
        if(strcmp(palavra, aux->palavra)==0)//palavra já existe na fila, só precisa incrementar na frequência
        {
            flag = 1;//mostra que o elemento foi achado entre os da fila
            aux->frequencia++;
            aux->cont_total++;
        }
        aux = aux->dir;
    }

    if(flag==0)//caso o elemento nao tenha sido achado, é necessário inseri-lo na fila
    {
        pal *new = criaFila();
        aux->dir = new;
        strcpy(new->palavra,palavra);
        strcpy(new->estrofe,estrofe);
        strcpy(new->nome,nome);
        strcpy(new->autor,autor);
    }
}

pal *POPFila(pal *fila)
{
    if(fila==NULL) return NULL;
    pal *no = (pal *)malloc(sizeof(pal));
    no = fila;//nó fica com o endereço do primeiro elemento
    fila = (*fila).dir;//o primeiro elemento se torna o próximo
    return no;
}

void insereBuscaBin(pal *buscaBin, int *tam, pal *no)
{
    if(buscaBin==NULL)
    {//vetor vazio, preenche ele com seu primeiro valor
        buscaBin = (pal *)malloc(sizeof(pal));
        buscaBin = no;
        return;
    }
    int flag=0;
    for(int i=0; i<(*tam); i++)
    {
        if(strcmp(no->palavra,buscaBin[i].palavra)==0)
        {//se a palavra entregue ja existe, deve-se verificar se sua frequencia no texto atual é maior doq a que ja existe, para assim substitui-la
            flag=1;
            if(no->frequencia>buscaBin[i].frequencia)
            {
                buscaBin[i].frequencia = no->frequencia;
                strcpy(buscaBin[i].estrofe,no->estrofe);
                strcpy(buscaBin[i].nome,no->nome);
                strcpy(buscaBin[i].autor,no->autor);
            }
            buscaBin[i].cont_total += no->cont_total;//deve acontecer caso haja troca ou nao de valores como nome, estrofe e autor
        }
    }

    if(flag==0)//caso elemento nao exista, ele precisa ser inserido no vetor
    {
        (*tam)++;
        buscaBin = (pal *)realloc(buscaBin,(*tam)*sizeof(pal));
        buscaBin[(*tam)-1] = (*no);//pensando que tamanho começa em 1
    }
}

void Swap(pal *i, pal *j) {
  pal t;
  t = *i;
  *i = *j;
  *j = t;
}

void ordenaVetor(pal *buscaBin, int tam)
{//insertionsort de malandro
    int j;
    for (int i = 1; i < tam; i++) {
      j = i;
      while (j > 0 && strcmp(buscaBin[j - 1].palavra, buscaBin[j].palavra) > 0) {
        Swap(&buscaBin[j], &buscaBin[j - 1]);
        j--;
      }
    }
}

pal *criaArvBin()
{
    //...
}