#include <stdio.h>
#include <stdlib.h>
#include "tadd.h"
#include <string.h>
#define MAX 30

int main()
{
    Pilha *p = criar();
    char it[MAX],y;
    int r;
    printf("\nescreva um numero binario, finalizando-o em -1: ");
    scanf("%c",&it);
    copia(p,it);
    pop(p,&y);
    if(y=='1') printf("ok");
    pop(p,&y);
    if(y=='-') printf("ok");
    r = converte(p);
    if(r>=0)
    {
        printf("\nconversao de ");
        mostrar(p);
        printf(" eh %d",r);
    }
    return 0;
}