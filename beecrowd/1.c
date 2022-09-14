/*
apresentação do quadrado de um número, através do uso de funções que retornam valores, que pode ser inteiro ou não.
entrada com valor digitado pelo usuário, aviso de erro caso:
1-há mais de um ponto digitado;
2-não foi digitado nenhum número;
3-foi digitado algum caractere que não é número, nem vírgula, nem ponto;
4-foram digitados mais de um único número.
o programa, também, corrige caso haja uma vírgula em vez de um ponto;
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
float quadradof(float q);
int quadradoi(int t);
int main(int argc, char *argv[])
{
    float n;
    int a,m,b=0,c=0;
    if(argc>2)
    {
        fprintf(stderr,"escreva somente UM numero!");
        return -1;
    }
    if(argv[1][0]=='\0')
    {
        fprintf(stderr,"escreva um numero!");
        return 1;
    }
    for(a=0;argv[1][a]!='\0';a++)
    {
        //printf("%s\n",argv[1]);
        if(argv[1][a]=='.')
        {
            c++;
        }
        if(argv[1][a]==',')
        {
            argv[1][a]='.';
            c++;
        }
        else if(isdigit(argv[1][a])==0 & argv[1][a]!='.' & argv[1][a]!=',')
        {
            fprintf(stderr,"escreva um numero!");
            return 2;
        }
    }
    if(c>1)
    {
        fprintf(stderr,"ponha, no maximo, um ponto!");
        return 3;
    }
    if(c==1)
    {
        n=atof(argv[1]);
        //printf("%.2f",n);
        printf("o quadrado de %.2f e %.2f",n,quadradof(n));
    }
    if(c==0)
    {
        m=atoi(argv[1]);
        //printf("%d",m);
        printf("o quadrado de %d e %d",m,quadradoi(m));
    }
    return 0;
}
float quadradof(float q)
{
    return(q*q);
}
int quadradoi(int t)
{
    return(t*t);
}