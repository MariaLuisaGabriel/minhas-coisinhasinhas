#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char nome[12]={"Carla Faria"};
    char *n;
    n=nome;
    for(int i=0;i<11;i++)
    {
        printf("%c",*(n+i));
    }
    return 0;
}