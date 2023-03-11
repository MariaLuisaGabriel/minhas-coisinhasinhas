//aluno envolvido na atividade: Maria Luisa Gabriel Domingues, 12121BCC010

#include <stdio.h>
#include <stdlib.h>

int pos = 1;
int N[50];

int pot2(int n);
int fat(int n);

int main()
{
    int in,n;
    printf("escreva 1 para calcular o valor de 2^n e 2 para calcular o fatorial de um numero n \n->");
    scanf("%d",&in);
    if(in == 1)
    {
        printf("\nescreva o valor de n: ");
        scanf("%d",&n);
        printf("2^%d = %d",n,pot2(n));
    }
    else
    {
        printf("\nescreva o valor de n: ");
        scanf("%d",&n);
        printf("%d! = %d",n,fat(n));
    }
    return 0;
}

//questao 1: Implemente uma função recursiva para calcular o valor de 2^n
int pot2(int n)
{
    if(n==0) return 1;
    return 2*pot2(n-1);
}

//questao 2: Construa um algoritmo que calcule o fatorial de um número utilizando programação dinâmica. Compare o resultado obtido com os algoritmos iterativo e recursivo apresentados em aula.
int fat(int n)
{
    int fat;
    N[0]=1;
    N[1]=1;
    for(int i = pos;i<=n;i++)
    {
        fat = 1;
        for(int j = i;j>1;j--)
        {
            fat = fat * j;
        }
        N[i]=fat;
    }
    if(n>1) pos = n;
    return N[n];
}