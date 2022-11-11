#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char nome[12]={"Carla Faria"};
    char *n;//ponteiro para o vetor nome
    double *d;//ponteiro
    d = (double *)malloc(10*sizeof(double));//o ponteiro antes declarado agora é um vetor
    n=nome;
    for(int i=0;i<11;i++)
    {
        printf("%c",*(n+i));
    }
    puts("\n");
    if(d==NULL)
    {
        printf("ERRO");
    }
    else
    {
        for(int j=0;j<10;j++)
        {
            *(d+j)=3.44444 + j;//aritmética de ponteiros para preenchimento com valores!!!(d+j = andando de 1 em 1 posição no endereço, * = valor que está em cada endereço andado)
        }
        for(int f=0;f<10;f++)
        {
            printf("%lf ",d[f]);
        }
    }
    free(d);
    return 0;
}