#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mover(int *p,int a);
int main()
{
    int *v,n,i;
    while(1)
    {
        printf("escreva o tamanho do vetor: ");
        scanf("%d",&n);
        v = (int *)malloc(n*sizeof(int));
        if(v==NULL)
        {
            printf("\nERRO, vetor nao alocado\n");
            return 9;
        }
        for(i=0;i<n;i++)
        {
            printf("\nescreva o %dº numero do vetor: ",i+1);
            scanf("%d",&*(v+i));
        }
        n = mover(v,n);
        v = (int *)realloc(v,n*sizeof(int));
        printf("\n\nvetor atualizado: ");
        for(i=0;i<n;i++)
            printf("%d",*(v+i));
        printf("\nquer continuar criando vetores?escreva 0 se nao, e 1 se sim: ");
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        else if(n!=1)
        {
            printf("ERRO, comando inexistente");
            break;
        }
    }
    return 0;
}
int mover(int *p,int a)
{
    int y;
    int z;
    for(y=1;y<a;y++)
    {
        while(*(p+y-1)==*(p+y))
        {
            for(z=y;z<a;z++)
            {
                *(p+z)=*(p+z+1);
            }
            a--;
        }
    }
    return(a);
}