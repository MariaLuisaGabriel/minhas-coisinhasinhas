#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **a, **b, **c,i,j;
    a = (int **)malloc(3*sizeof(int*));
    for(i=0;i<3;i++)
        a[i]=(int *)malloc(3*sizeof(int));
    if(a==NULL)
    {
        printf("ERRO1");
        return 1;
    }
    b = (int **)malloc(3*sizeof(int*));
    for(i=0;i<3;i++)
        b[i]=(int *)malloc(3*sizeof(int));
    if(b==NULL)
    {
        printf("ERRO2");
        return 2;
    }
    c = (int **)calloc(3,sizeof(int*));
    for(i=0;i<3;i++)
        c[i]=(int *)calloc(3,sizeof(int));
    if(c==NULL)
    {
        printf("ERRO3");
        return 3;
    }
    //pode usar a matriz de ponteiros do jeito normal!
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]= i;
            b[i][j]= 2-i;
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("matriz A:\n=========\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("matriz B:\n=========\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    printf("matriz C:\n=========\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
    free(a);
    free(b);
    free(c);
    return 0;
}