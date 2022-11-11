#include "estringue.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct strring
{
    char *j;
    int tam;
}String;

String *criar(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++);
    String *d = (String *)malloc(sizeof(String));
    if(d==NULL)
    {
        printf("\nerro ao criar a string.");
    }
    d->tam = i;
    d->j = (char *)malloc((i+1)*sizeof(char));
    if(d->j==NULL)
    {
        printf("\nerro ao criar a string!");
    }
    for(int l=0;l<=i;l++)
    {
        d->j[l] = s[l];
    }
    d->j[i] = '\0'; 
    return d;
}

int tamanho(String *s)
{
    return (s->tam);
}

int ocorrencias(String *s, char *d)
{
    int a=0;
    for(int i=0;i<=(s->tam);i++)
    {
        if(s->j[i]==*d)
        {
            a++;
        }
    }
    return a;
}

void exibir(String *s)
{
    printf("\nstring: %s\n",s->j);
}