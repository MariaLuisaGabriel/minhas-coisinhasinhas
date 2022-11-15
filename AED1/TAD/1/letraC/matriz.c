#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct matriz 
{
    int **m;
    int i,j;
}Matriz;

Matriz *criar(int i, int j)
{
    Matriz *A = (Matriz *)malloc(sizeof(Matriz));
    A->m = (int **)malloc(i*sizeof(int));
    for(int k=0;k<i;k++)
        A->m[k] = (int *)calloc(j,sizeof(int));
    A->i = i;
    A->j = j;
    return A;
}

void destruir(Matriz *a)
{
    free(a);
}

void atribuir(Matriz *a,int i, int j)
{
    printf("\nescreva o valor que quer atribuir: ");
    scanf("%d",&(a->m[i][j]));
    printf("\nvalor atribuido com sucesso.\n");
}

void atribuirtudo(Matriz *a)
{
    for(int i=0;i<a->i;i++)
    {
        for(int j=0; j<a->j; j++)
        {
            atribuir(a,i,j);
        }
    }
}

int acessavalor(Matriz *a, int i, int j)
{
    if(i>a->i||i<0)
        return -1;
    else if(j>a->j||j<0)
        return -1;
    else
        return a->m[i-1][j-1];
}

int linhas(Matriz *a)
{
    return a->i;
}

int colunas(Matriz *a)
{
    return a->j;
}

void preencher(Matriz *a, int min, int max)
{
    srand(time(NULL));
    for(int i = 0; i<a->i; i++)
    {
        for(int j = 0; j<a->j; j++)
        {
            a->m[i][j]=min + rand() % (max-min);
        }
    }
}

Matriz *somar(Matriz *a, Matriz *b)
{
    Matriz *r = (Matriz *)malloc(sizeof(Matriz));
    if(a->i == b->i && a->j == b->j)
    {
        r = criar(a->i,a->j);
        for(int i = 0; i<a->i; i++)
        {
            for(int j = 0; j<a->j; j++)
            {
                r->m[i][j] = a->m[i][j] + b->m[i][j];
            }
        }
        return r;
    }
    else
    {
        free(r);
        printf("\nmatrizes imcompativeis para a soma, numero de linhas e/ou colunas diferentes entre as matrizes.\n");
    }
}

void mostrar(Matriz *a)
{
    printf("\n\n");
    for(int i=0;i<a->i;i++)
    {
        for(int j=0;j<a->j;j++)
        {
            printf("%d ",a->m[i][j]);
        }
        printf("\n");
    }
}
