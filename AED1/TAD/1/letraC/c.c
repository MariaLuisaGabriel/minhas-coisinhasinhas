#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,y,z;
    Matriz *a,*b;
    printf("linhas da primeira matriz: ");
    scanf("%d",&i);
    printf("colunas da primeira matriz: ");
    scanf("%d",&j);
    a = criar(i,j);
    printf("\n");
    printf("linhas da segunda matriz: ");
    scanf("%d",&i);
    printf("colunas da segunda matriz: ");
    scanf("%d",&j);
    b = criar(i,j);
    printf("\n");

    puts("PREENCHER MATRIZ;");
    printf("\nquer preencher com numeros aleatorios a primeira(1), segunda(2), nas duas matrizes(3) ou em nenhuma(0)?");
    scanf("%d",&i);
    switch(i)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            printf("\nescolha os limites do aleatorio;\nminimo: ");
            scanf("%d",&y);
            printf("\nmaximo: ");
            scanf("%d",&z);
            preencher(a,y,z);
            mostrar(a);
            break;
        }
        case 2:
        {
            printf("\nescolha os limites do aleatorio;\nminimo: ");
            scanf("%d",&y);
            printf("\nmaximo: ");
            scanf("%d",&z);
            preencher(b,y,z);
            mostrar(b);
            break;
        }
        case 3:
        {
            printf("\nescolha os limites do aleatorio;\nminimo: ");
            scanf("%d",&y);
            printf("\nmaximo: ");
            scanf("%d",&z);
            preencher(a,y,z);
            printf("\n");
            mostrar(a);
            printf("\nescolha os limites do aleatorio;\nminimo: ");
            scanf("%d",&y);
            printf("\nmaximo: ");
            scanf("%d",&z);
            preencher(b,y,z);
            printf("\n");
            mostrar(b);
            break;
        }
    }

    puts("\nATRIBUIR VALOR MANUALMENTE A MATRIZ;");
    printf("\ndeseja preencher a primeira(1), segunda(2), as duas matrizes(3) ou nenhuma(0)?");
    scanf("%d",&j);
    switch(j)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            printf("deseja preencher toda a matriz(0) ou so alguns elementos(1)?");
            scanf("%d",&i);
            switch(i)
            {
                case 0:
                {
                    atribuirtudo(a);
                    mostrar(a);
                    break;
                }
                case 1:
                {
                    while(1)
                    {
                        printf("qual a linha? ");
                        scanf("%d",&y);
                        printf("qual a coluna? ");
                        scanf("%d",&z);
                        atribuir(a,y,z);
                        printf("sair = 0, continuar = 1 : ");
                        scanf("%d",&z);
                        if(z==0)
                        {
                            break;
                        }
                    }
                    mostrar(a);
                    break;
                }
            }
            break;
        }
        case 2:
        {
            printf("deseja preencher toda a matriz(0) ou so alguns elementos(1)?");
            scanf("%d",&i);
            switch(i)
            {
                case 0:
                {
                    atribuirtudo(b);
                    mostrar(b);
                    break;
                }
                case 1:
                {
                    while(1)
                    {
                        printf("qual a linha? ");
                        scanf("%d",&y);
                        printf("qual a coluna? ");
                        scanf("%d",&z);
                        atribuir(b,y,z);
                        printf("sair = 0, continuar = 1 : ");
                        scanf("%d",&z);
                        if(z==0)
                        {
                            break;
                        }
                    }
                    mostrar(b);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            printf("deseja preencher toda a primeira matriz(0) ou so alguns elementos(1)?");
            scanf("%d",&i);
            switch(i)
            {
                case 0:
                {
                    atribuirtudo(a);
                    mostrar(a);
                    break;
                }
                case 1:
                {
                    while(1)
                    {
                        printf("qual a linha? ");
                        scanf("%d",&y);
                        printf("qual a coluna? ");
                        scanf("%d",&z);
                        atribuir(a,y,z);
                        printf("sair = 0, continuar = 1 : ");
                        scanf("%d",&z);
                        if(z==0)
                        {
                            break;
                        }
                    }
                    mostrar(a);
                    break;
                }
            }
            printf("deseja preencher toda a segunda matriz(0) ou so alguns elementos(1)?");
            scanf("%d",&i);
            switch(i)
            {
                case 0:
                {
                    atribuirtudo(b);
                    mostrar(b);
                    break;
                }
                case 1:
                {
                    while(1)
                    {
                        printf("qual a linha? ");
                        scanf("%d",&y);
                        printf("qual a coluna? ");
                        scanf("%d",&z);
                        atribuir(b,y,z);
                        printf("sair = 0, continuar = 1 : ");
                        scanf("%d",&z);
                        if(z==0)
                        {
                            break;
                        }
                    }
                    mostrar(b);
                    break;
                }
            }
            break;
        }
    }
    y=linhas(a);
    z=colunas(a);
    puts("\nACESSAR UM VALOR DA MATRIZ;");
    printf("\nque posicao deseja acessar da primeira matriz %dx%d ?\nlinha: ",y,z);
    scanf("%d",&i);
    printf("\ncoluna:");
    scanf("%d",&j);
    y = acessavalor(a,i,j);
    if(y==-1)
    {
        printf("\nposicao nao existe na matriz.");
    }
    else
        printf("\no valor acessado eh: %d",y);
    y=linhas(b);
    z=colunas(b);
    puts("\nACESSAR UM VALOR DA MATRIZ;");
    printf("\nque posicao deseja acessar da segunda matriz %dx%d ?\nlinha: ",y,z);
    scanf("%d",&i);
    printf("\ncoluna:");
    scanf("%d",&j);
    y = acessavalor(b,i,j);
    if(y==-1)
    {
        printf("\nposicao nao existe na matriz.");
    }
    else
        printf("\no valor acessado eh: %d",y);

    puts("\nSOMA DE MATRIZES;");
    printf("\n1)a soma da primeira matriz com ela mesma é: ");
    Matriz *s1 = criar(y,z);
    s1 = somar(a,a);
    mostrar(s1);
    printf("\n");
    printf("\n1)a soma da segunda matriz com ela mesma é: ");
    Matriz *s2 = criar(y,z);
    s2 = somar(b,b);
    mostrar(s2);
    printf("\n");
    printf("\n1)a soma da primeira matriz com a segunda matriz é: ");
    Matriz *s3 = criar(y,z);
    s3 = somar(a,b);
    mostrar(s3);

    puts("\nDESTRUIR MATRIZES;");
    destruir(a);
    printf("\nsucesso em destruir a primeira matriz.");
    destruir(b);
    printf("\nsucesso em destruir a segunda matriz.");
    return 0;
}