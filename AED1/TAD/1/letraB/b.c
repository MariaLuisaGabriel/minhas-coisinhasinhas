#include "conjuntos.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,k,q,*p;
    printf("\nescreva o tamanho do seu primeiro conjunto: ");
    scanf("%d",&t);
    p = (int *)malloc(t*sizeof(int));
    printf("\nescreva os elementos dele: ");
    for(int i=0;i<t;i++)
    {
        scanf("%d",&p[i]);
    }
    Conj *a = criar(p,t);
    free(p);
    printf("\nescreva o tamanho do seu segundo conjunto: ");
    scanf("%d",&t);
    p = (int *)malloc(t*sizeof(int));
    printf("\nescreva os elementos dele: ");
    for(int i=0;i<t;i++)
    {
        scanf("%d",&p[i]);
    }
    Conj *b = criar(p,t);
    free(p);
    puts("\n");
    mostrar(a);
    mostrar(b);
    puts("\n");
    puts("VERIFICAR SE EH MEMBRO:");
    printf("\nescreva um valor que quer verificar: ");
    scanf("%d",&t);
    k = membro(a,t);
    if(k==0)
    {
        printf("\n%d nao eh elemento do primeiro conjunto.",t);
    }
    else
        printf("\n%d eh elemento do primeiro conjunto.",t);
    q = membro(b,t);
    if(q==0)
    {
        printf("\n%d nao eh elemento do segundo conjunto.\n",t);
    }
    else
        printf("\n%d eh elemento do segundo conjunto.\n",t);
    puts("INSERIR ELEMENTO:");
    printf("\nescreva um valor que quer acrescentar: ");
    scanf("%d",&t);
    printf("\nquer inserir no primeiro(1) ou segundo(2) ou nos dois(3) conjuntos? ");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
        {
            insere(a,t);
            mostrar(a);
            break;
        }
        case 2:
        {
            insere(b,t);
            mostrar(b);
            break;
        }
        case 3:
        {
            insere(a,t);
            insere(b,t);
            mostrar(a);
            printf("\n");
            mostrar(b);
            break;
        }
    }
    puts("\nREMOVER ELEMENTO: ");
    mostrar(a);
    printf("\nque elemento quer tirar do primeiro conjunto? ");
    scanf("%d",&k);
    remover(a,k);
    mostrar(a);
    printf("\n");
    mostrar(b);
    printf("\nque elemento quer tirar do segundo conjunto? ");
    scanf("%d",&k);
    remover(b,k);
    mostrar(b);

    puts("\nUNIR CONJUNTOS: ");
    Conj *o = uniao(a,b);
    printf("\nuniao dos conjuntos escritos: ");
    mostrar(o);

    puts("\nINSERSECCAO DE CONJUNTOS: ");
    Conj *i = intersecao(a,b);
    printf("\nintersecao dos conjuntos escritos: ");
    mostrar(i);

    printf("\n");

    puts("\nDIFERENCA DE CONJUNTOS: ");
    puts("diferenca do primeiro com o segundo: ");
    diferenca(a);
    puts("\ndiferenca do segundo com o primeiro: ");
    diferenca(b);
    return 0;
}