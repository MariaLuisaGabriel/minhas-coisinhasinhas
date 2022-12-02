#include <stdio.h>
#include <stdlib.h>

int *Primos(int *tam,int raizint);
int aproxraiz(int y);
int verificaprimo(int y, int *v, int t);

int main()
{
    int t=1,y,z,v;
    printf("escreva um numero inteiro positivo, para determinarmos todos os primos antes dele, até 2.\n->");
    scanf("%d",&y);
    z = aproxraiz(y);
    int *r = Primos(&t,z);
    v = verificaprimo(y,r,t);
    if(r==NULL) printf("\nVETOR NAO ALOCADO.");
    else
    {
        //printf("[");
        //for(int i = 0; i<t; i++)
        //{
        //    printf("%d ",r[i]);
        //}
        //printf("]");
        if(v==0) printf("%d EH PRIMO!",y);
        else printf("%d NAO EH PRIMO!",y);
    }
    return 0;
}

int *Primos(int *tam,int raizint)//cria um vetor de primos até o valor da raiz inteira de y, deduzido pela funçao aproxraiz
{
    int cont=0;
    int *v = (int *)malloc(sizeof(int));
    if(v==NULL) return NULL;
    v[0] = 2;
    for(int i = 3; i<=raizint; i++)
    {
        for(int j = 0; j<*tam; j++)
        {
            if(i%v[j]!=0)
                cont++;
        }
        if(cont==*tam)
        {
            (*tam)++;
            v = (int *)realloc(v,(*tam)*sizeof(int));
            v[(*tam)-1]=i;
        }
        cont=0;
    }
    return v;
}

int aproxraiz(int y)//deduz a raiz inteira aproximada(pra cima) de um numero inteiro. assim que ele encontrar um numero i que ultrapasse y quando ao quadrado, ele devolve esse valor para a main
{
    int i=1;
    while(1)
    {
        if((i*i)>=y)
        {
            return (i);
        }
        i++;
    }
}

int verificaprimo(int y,int *v, int t)
{
    for(int i=0; i<t; i++)
    {
        if(y==v[i])//caso o numero y esteja na lista de primos, ele é um primo(evitar erro quando y=2)
            return 0;
        if(y%v[i]==0)//caso esse valor seja divisivel por algum primo antes da raiz aproximada dele próprio, isso quer dizer que ele nao é primo
            return 1;
    }
    return 0;
}