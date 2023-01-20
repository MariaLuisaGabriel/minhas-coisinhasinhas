#include <stdlib.h>
#include <stdio.h>
#include "tadabcde.h"
#define MAX 100

int main()
{
    Pilha *p = criar();
    //letra A.
    char v[MAX];
    printf("escreva uma expressao: ");
    scanf("%s",v);
    int i = 0,j,k,l;
    while(v[i]!='\0')
    {
        j = v[i] - '0';
        if(0<=j && j<=9)
            push(p,j);
        else
        {
            switch(v[i])
            {
                case '+':
                {
                    pop(p,&k);
                    pop(p,&l);
                    k = k + l;
                    push(p,k);
                    break;
                }
                case '-':
                {
                    pop(p,&k);
                    pop(p,&l);
                    k = l - k;
                    push(p,k);
                    break;
                }
                case '*':
                {
                    pop(p,&k);
                    pop(p,&l);
                    k = l * k;
                    push(p,k);
                    break;
                }
                case '/':
                {
                    pop(p,&k);
                    pop(p,&l);
                    k = l/k;
                    push(p,k);
                    break;
                }
            }
        }
        i++;
    }
    mostrar(p);
    limpar(p);
    //letra B.
    return 0;
}