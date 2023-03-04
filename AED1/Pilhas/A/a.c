#include <stdio.h>
#include <stdlib.h>
#include "tada.h"

int main()
{
    Pilha *p;
    int *it;
    p = criar();
    push(p,11);
    push(p,34);
    pop(p,it);
    printf("\nelemento retirado: %d\n",*it);
    pop(p,it);
    printf("\nelemento retirado: %d\n",*it);
    push(p,23);
    push(p,45);
    pop(p,it);
    printf("\nelemento retirado: %d\n",*it);
    push(p,121);
    push(p,22);
    pop(p,it);
    printf("\nelemento retirado: %d\n",*it);
    pop(p,it);
    printf("\nelemento retirado: %d\n",*it);
    mostrar(p);
    return 0;
}