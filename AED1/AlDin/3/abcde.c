#include <stdio.h>
#include <stdlib.h>
int q, r;
int soma(int n);
int power(int x, int y);
int fatorial(int f);
float exptaylor(int b,int p);
int divi(int a,int b);
void calculaHexagono(float l,float *area,float *perimetro);
int main()
{
    int num,so,base,pot,res;
    float result,ba,po;
    while(1)
    {
        printf("\n");
        puts("funcoes do programa: ");
        puts("*escreva o numero da opcao que deseja usar!*");
        puts("1- soma de 1 ate N.");
        puts("2- X a potencia de Y.");
        puts("3- aproximacao da potencia exponencial de euler na serie de taylor.");
        puts("4- divisao de a por b.");
        puts("5- area e perimetro de um hexagono de lado l.");
        puts("0- sair.");
        scanf("%d",&num);
        fflush(stdin);
        if(num==0)
        {
            break;
        }
        if(num==1)
        {
            printf("\nescreva o valor do numero inteiro positivo N: ");
            scanf("%d",&so);
            res= soma(so);
            printf("\na soma de 1 ate %d eh: %d",so,res);
        }
        if(num==2)
        {
            printf("\nescreva o valor de X(inteiro positivo): ");
            scanf("%d",&base);
            printf("\nescreva o valor de Y(inteiro positivo): ");
            scanf("%d",&pot);
            res=power(base,pot);
            printf("\n%d na potencia de %d eh: %d",base,pot,res);
        }
        if(num==3)
        {
            printf("\nescreva a potencia para o numero de euler: ");
            scanf("%d",&base);
            printf("\nescreva o nivel de aproximacao que se deseja: ");
            scanf("%d",&pot);
            result=exptaylor(base,pot);
            printf("\n o resultado da potencia %d no numero de euler, na aproximacao %d eh: %f",base,pot,result);
        }
        if(num==4)
        {
            printf("\nescreva o dividendo a: ");
            scanf("%d",&base);
            printf("\nescreva o divisor b: ");
            scanf("%d",&pot);
            res=divi(base,pot);
            if(res==0)
            {
                printf("\nnumero nao existe!");
            }
            if(res==1)
            {
                printf("o quociente e o resto sao, respectivamente: %d %d",q,r);
            }
            else
            {
                printf("o quociente e o resto sao, respectivamente: %d 0",res);
            }
        }
        if(num==5)
        {
            printf("\nescreva o tamanho do lado do hexagono: ");
            scanf("%d",&so);
            calculaHexagono(so,&ba,&po);
            printf("\na area(aproximadamente) e o perimetro do hexagono de lado %d sao: %f %f",so,ba,po);
        }
    }
    return 0;
}
int soma(int n)
{
    int m=0;
    if(n==0)
    {
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            m = m + i;
        }
        return m;
    }
}
int power(int x,int y)
{
    int m=x;
    if(y==0)
    {
        return 1;
    }
    else if(y==1)
    {
        return x;
    }
    else
    {
        for(int i=1;i<=(y-1);i++)
        {
            x = x*m;
        }
        return x;
    }
}
int fatorial(int f)
{
    int m=1;
    if(f==0)
    {
        return 1;
    }
    else
    {
        for(int i=1;i<=f;i++)
        {
            m = m*i;
        }
        return m;
    }
}
float exptaylor(int b,int p)
{
    float m=1.0;
    if(p==0)
    {
        return 1;
    }
    else
    {
        for(int i=0;i<p;i++)
        {
            m = m + ((power(b,p-i)/(float)fatorial(p-i)));
        }
        return m;
    }
}
int divi(int a,int b)
{
    if(b==0)
    {
        return 0;
    }
    if(b==1)
    {
        return a;
    }
    else
    {
        q = a/b;
        r = a%b;
        return 1;
    }
}
void calculaHexagono(float l,float *area,float *perimetro)
{
    *area=6*l*l*1.73/4;
    *perimetro=6*l;
}