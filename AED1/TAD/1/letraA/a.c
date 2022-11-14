#include <stdio.h>
#include <stdlib.h>
#include "estringue.h"

int main()
{
    String *o;
    int i=0,k,l=2;
    char h,m;
    while(1)
    {
        puts("CRIACAO DE UMA STRING");
        puts("0-sair.");
        puts("1-criar uma string.");
        if(i!=0)
        {
            puts("2-exibir o tamanho da string.");
            puts("3-exibir a string.");
            puts("4-exibir quantidade de ocorrencias de uma letra na string.");
        }
        printf("\nescreva seu comando: ");
        scanf("%d",&k);
        if(k==1)
        {
            printf("escreva uma string: ");
            scanf("%s",&h);
            o = criar(&h);
            i=1;
        }
        else if(k==2)
        {
            printf("\no tamanho da string escrita é %d\n",tamanho(o));
        }
        else if(k==3)
        {
            exibir(o);
        }
        else if(k==4)
        {
            printf("\ncom qual letra quer testar? ");
            scanf("  %c",&m);
            printf("\nas ocorrencias de %c é %d\n",m,ocorrencias(o,&m));
        }
        else if(k==0)
        {
            break;
        }
    }
    return 0;
}