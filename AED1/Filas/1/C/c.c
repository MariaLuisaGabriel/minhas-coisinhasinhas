#include <stdio.h>
#include <stdlib.h>
#include "tadc.h"

int main()
{
    Fila *f,*ret;
    int r,*it;
    f = criar();
    ret = criar();
    insere(f,-1);
    insere(f,3);
    insere(f,5);
    insere(f,-1);
    insere(f,3);
    insere(f,-5);
    insere(f,1);
    insere(f,-3);
    insere(f,-5);
    excluin(f,ret);
    mostrar(ret);
    return 0;
}