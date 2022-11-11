#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *n,i;//ponteiro e contador
    n = (int *)calloc(5,sizeof(int));//ponteiro-vetor de 5 int
    for(i=0;i<5;i++)
    {
        printf("valor %d: ",i+1);
        scanf("%d",&n[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",*(n+i));//*(n+i): acesso ao valor que está naquele endereço!!!!
    }
    free(n);
    return 0;
}