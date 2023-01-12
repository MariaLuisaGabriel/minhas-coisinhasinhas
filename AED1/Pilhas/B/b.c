#include <stdio.h>
#include <stdlib.h>
#include "tadb.h"

int main()
{
    Pilha *r = criar();
    char it;
    int R;
    push(r,'a');
    push(r,'n');
    push(r,'a');
    push(r,'n');
    push(r,'a');
    push(r,'b');
    R =palindromo(r);
    if(R==0)
    {
        printf("\n");
        mostrar(r);
        printf(" eh palindromo.\n");
    }
    if(R==-1)
    {
        printf("\n");
        mostrar(r);
        printf(" nao eh palindromo.\n");
    }
    limpar(r);
    push(r,'a');
    push(r,'r');
    push(r,'a');
    push(r,'r');
    push(r,'a');
    R =palindromo(r);
    if(R==0)
    {
        printf("\n");
        mostrar(r);
        printf(" eh palindromo.\n");
    }
    if(R==-1)
    {
        printf("\n");
        mostrar(r);
        printf(" nao eh palindromo.\n");
    }
    return 0;
}