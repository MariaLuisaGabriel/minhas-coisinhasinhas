#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **m,*v,l,c,k=0;
    printf("escreva o numero de linhas da matriz: ");
    scanf("%d",&l);
    m = (int **)malloc(l*sizeof(int *));
    printf("escreva o numero de colunas da matriz: ");
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        m[i]=(int *)malloc(c*sizeof(int));
    }
    v=(int *)malloc(c*l*sizeof(int));
    //preenchimento da matriz por linhas e colunas:
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("escreva o valor da %dº linha e %dº coluna: ",i+1,j+1);
            scanf("%d",&m[i][j]);
            //preenchimento do vetor:
            *(v+k)=m[i][j];
            /*após o primeiro elemento alocado, verificar se outros que entrarem forem ou nao iguais aos ja alocados
            (ou seja, só fica no vetor os elementos que nao se repetirem com os anteriores)*/
            if(k>0)
            {
                for(int a=0;a<k;a++)//escaneamento de tras para frente do vetor, afim de encontrar elementos iguais e retira-los.
                {
                    if(*(v+a)==*(v+k))
                    {
                        k--;
                    }
                }
            }
            k++;      
        }
    }
    //o valor final de k representa quantos elementos realmente ficaram em v.
    v=(int *)realloc(v,k*sizeof(int));
    printf("numeros da matriz: ");
    printf("[");
    for(int i=0;i<k;i++)
    {
        printf("%d ",*(v+i));
    }
    printf("]");
    return 0;
}