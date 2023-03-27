#include <stdio.h>
#include <stdlib.h>

int particao (int vet[], int esq, int dir){
    int i, j, pivo, temp ;
    pivo = vet[(esq + dir) / 2];
    i = esq - 1;
    j = dir + 1;
    while (i < j) {
        do{ i++;} while (vet[i] < pivo);
        do{ j--;} while (vet[j] > pivo);
        if (i < j) 
        {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }
    return (j);
}

void q_sort (int vetor[], int esq, int dir) 
    {   
        int meio;
        if (esq < dir) 
        {
            meio = particao (vetor, esq, dir);
            q_sort (vetor, esq, meio);
            q_sort (vetor, meio + 1, dir);
        }
}

void quicksort (int vetor[], int n) 
{
    q_sort (vetor, 0, n-1);
}

int main()
{
    int v[10];
    for(int i=0; i<10; i++)
    {
        v[i]=rand()%20;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ",v[i]);
    }
    quicksort(v,10);
    printf("\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}