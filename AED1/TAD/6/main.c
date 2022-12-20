#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    int r;
    lista *a;
    lista *b;
    a = criar();
    inserirgeral(a,1,0);
    inserirgeral(a,2,1);
    inserirgeral(a,3,2);
    inserirgeral(a,1,1);
    inserirgeral(a,1,0);
    inserirgeral(a,1,0);
    inserirgeral(a,1,0);
    mostrar(a,1);
    removergeral(a,1);
    removergeral(a,3);
    removergeral(a,25);
    printf("\n");
    mostrar(a,1);
    printf("Tamanho: %d\n",tamanho(a));
    mostrarev(a);
    r = contaocorrencias(a,1);
    printf("\n");
    printf("%d",r);
    printf("\n");
    mostrar(a,1);
    printf("\n");


    b = criar();
    inserirgeral(b,1,0);
    inserirgeral(b,2,1);
    inserirgeral(b,3,2);
    inserirgeral(b,1,1);
    inserirgeral(b,1,0);
    inserirgeral(b,1,0);
    inserirgeral(b,1,0);
    mostrar(b,1);
    printf("\n");
    removergeral(b,1);
    removergeral(b,3);
    removergeral(b,25);
    mostrar(b,1);
    printf("\n");
    printf("Tamanho: %d\n",tamanho(b));
    mostrarev(b);
    r = contaocorrencias(b,1);
    printf("\n");
    printf("%d",r);
    mostrar(b,1);

    r = igual(a,b);
    if(r==0) printf("\neh igual");

    printf("\nsoma eh: %d\n",soma(a));
    printf("\nsoma eh: %d\n",soma(b));
    return 0;
}
