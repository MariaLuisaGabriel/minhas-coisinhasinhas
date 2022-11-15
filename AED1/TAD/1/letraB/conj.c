#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

typedef struct conj
{
    int *c;
    int tam;
    int *precaucao,tam1;
}Conj;

Conj *criar(int *u,int t)
{
    Conj *A = (Conj *)malloc(sizeof(Conj));
    if(t==0)
    {
        A->c = (int *)malloc(sizeof(int));
        A->c = 0;
        A->tam = 0;
        return A;
    }
    for(int y=0;y<t;y++)
    {
        for(int o=y+1;o<t;o++)
        {
            if(u[y]==u[o])
            {
                for(int j=o;j<t;j++)
                {
                    u[j]=u[j+1];
                }
                t--;
            }
        }
    }
    A->tam=t;
    A->c = (int *)malloc(t*sizeof(int)); 
    for(int i=0;i<t;i++)
    {
    A->c[i]=u[i];
    }
    return A;
}

int membro(Conj *a,int l)
{
    if(a->tam == 0)
    {
        printf("\nesse conjunto nao tem elementos.\n");
        return 2;
    }
    else
    {
        for(int i=0;i<(a->tam);i++)
        {
            if(a->c[i]==l)
            {
            return 1;
            }
        }
        return 0;
    }
}

void insere(Conj *a, int el)
{
    int w = membro(a,el);
    if(w==0)
    {
        a->tam = a->tam + 1;
        a->c = (int *)realloc(a->c,(a->tam)*sizeof(int));
        a->c[a->tam-1] = el;
    }
    else
    {
        printf("\nelemento ja existe no conjunto.");
    }
}

void remover(Conj *a, int el)
{
    int h = membro(a,el);
    if(h==1)
    {
        for(int i=0;i<(a->tam);i++)
        {
            if(a->c[i]==el)
            {
                for(int z=i;z<(a->tam);z++)
                {
                    a->c[z]=a->c[z+1];
                }
                (a->tam)--;
                a->c = (int *)realloc(a->c,(a->tam)*sizeof(int));
            }
        }
    }
    else
        printf("\nelemento nao existe no conjunto, nao ha como ser removido.");
}

Conj *uniao(Conj *a,Conj *b)
{
    int i;
    int h = a->tam + b->tam;
    int *p = (int *)malloc(h*sizeof(int));
    if(a->tam == 0)
    {
        return b;
    }
    else if(b->tam == 0)
    {
        return a;
    }
    else
    {
        for(i=0;i<(a->tam);i++)
        {
            p[i]=a->c[i];
        }
        i=0;
        for(int j=(a->tam);j<h;j++)
        {
            p[j]=b->c[i];
            i++;
        }
        printf("\n");
        Conj *y = criar(p,h);
        return y;
    }
}

Conj *intersecao(Conj *a,Conj *b)
{
    int u=0;
    a->precaucao = (int *)malloc(sizeof(int));
    int *p = (int *)malloc(sizeof(int));
    if(a->tam == 0 || b->tam ==0)
    {
        a->precaucao[0] = 0;
        a->tam1=0; 
        Conj *l = criar(p,u);
        return l;
    }
    else
    {
        for(int i=0;i<a->tam;i++)
        {
            for(int j=0;j<b->tam;j++)
            {
                if(a->c[i]==b->c[j])
                {
                    p[u]=a->c[i];
                    a->precaucao[u]=a->c[i];
                    u++;
                    p = (int *)realloc(p,u*sizeof(int));
                    a->precaucao = (int *)realloc(a->precaucao,u*sizeof(int));
                }
            }
        }
        a->tam1 = u-1;
        Conj *x = criar(p,u);
        return x;
    }
}

void diferenca(Conj *a)
{
    int v=0;
    for(int i=0;i<a->tam;i++)
    {
        printf("%d",a->tam1);
        for(int j=0;j<a->tam1;j++)
        {
            if(a->c[i]==a->precaucao[j])
            {
                for(int f=i;f<a->tam;f++)
                {
                    a->c[f]=a->c[f+1];
                }
                a->tam = a->tam - 1;
                v++;
            }
        }
    }
    if(a->tam == 0||v==a->tam)
    {
        printf("\nconjunto: vazio\n");
    }
    else
    {
        printf("\nconjunto: {");
        for(int i=0;i<a->tam;i++)
        {
            printf("%d ",a->c[i]);
        }
        printf("}");
    }
}

void mostrar(Conj *a)
{
    printf("\nconjunto: {");
    for(int i=0;i<a->tam;i++)
    {
        printf("%d ",a->c[i]);
    }
    printf("}");
}