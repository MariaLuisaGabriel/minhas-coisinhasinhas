#include <stdio.h>
#include <stdlib.h>
#include "tadb.h"

int main()
{
    Fila *f,*h;
    Fila2 *g;
    int r,*it;
    g = criar2();
    f = criar();
    h = criar();
    insere(f,1);
    insere(f,3);
    insere(f,5);
    insere(h,2);
    insere(h,4);
    insere(h,6);
    r = intercala(h,f,g);
    printf("\n");
    mostrar2(g);
    printf("\n");
    return 0;
}