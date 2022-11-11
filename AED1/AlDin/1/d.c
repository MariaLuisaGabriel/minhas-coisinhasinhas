#include <stdio.h>
#include <stdlib.h>
void mover(int *u,int o,int y);
int main()
{
    int *v,n,i;
    printf("escreva o comprimento do vetor:");
    scanf("%d",&n);
    printf("===============================\n");
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        printf("ERRO");
        return 1;
    }
    printf("escreva os valores a inserir no vetor:\n=========================================\n");
    for(i=0;i<n;i++)
    {
        printf("valor %d: ",i+1);
        scanf("%d",&v[i]);
    }
    puts("vetor completo:");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(v+i));
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        while((*(v+i)%2)==1)
        {
            mover(v,n,i);
            n--;
        }
    }
    v=(int*)realloc(v,n*sizeof(int));
    puts("valores pares presentes no vetor escrito:");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(v+i));
    }
    return 0;
}
void mover(int *u,int o,int y)
{
    int a;
    for(a=y;a<(o-1);a++)
    {
        *(u+a)=*(u+a+1);
    }
}