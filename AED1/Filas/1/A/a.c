#include <stdio.h>
#include <stdlib.h>
#include "tada.h"

int main()
{
    Fila *f;
    int r,*it;
    f = criar();
    r = insere(f,10);
    printf("\n");
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel inserir;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = insere(f,20);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel inserir;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = remover(f,it);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            printf("\nitem removido: %d\n",*it);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel remover;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = insere(f,30);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel inserir;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = insere(f,45);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel inserir;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = insere(f,21);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel inserir;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = remover(f,it);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            printf("\nitem removido: %d\n",*it);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel remover;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    r = remover(f,it);
    switch(r)
    {
        case 0:
        {
            mostrar(f);
            printf("\nitem removido: %d\n",*it);
            break;
        }
        case 1:
        {
            printf("ERRO1:nao foi possivel remover;\n");
            break;
        }
        case 2:
        {
            printf("ERRO2:fila inexistente;\n");
            break;
        }
    }
    printf("\n");
    printf("FILA FINAL:");
    mostrar(f);
    return 0;
}