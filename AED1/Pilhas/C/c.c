#include <stdio.h>
#include <stdlib.h>
#include "tadc.h"
#include <string.h>
#define MAX 30

int main()
{
    Pilha *p = criar();
    char it[MAX];
    int r;
    printf("\nescreva uma expressao numerica: ");
    scanf("%[^\n]s",&it);
    copia(p,it);
    r = delimitadores(p);
    if(r==0)
        printf("\nsequencia correta.");
    if(r==1)
        printf("\nsequencia incorreta.");
    return 0;
}