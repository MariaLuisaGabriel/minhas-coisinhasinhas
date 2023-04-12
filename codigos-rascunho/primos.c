#include <stdio.h>
#include <stdlib.h>

/*ABC-SORT(A, i, j)
1   if A[i] > A[j]
2 then trocar A[i] e A[j]
3   if i + 1 >= j
4 then return
5   k (j-i+1)/3   // divisão inteira (arredondar para baixo)
6   ABC-SORT(A, i, j-k)
7   ABC-SORT(A, i+k, j)
8   ABC-SORT(A, i, j-k)*/

void ABCsort(int *a, int i, int j){
    int temp;
    if(a[i]>a[j])
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    if(i+1>=j) return;
    int k = (j-i+1)/3;
    ABCsort(a,i,j-k);
    ABCsort(a,i+k,j);
    ABCsort(a,i,j-k);
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
    ABCsort(v,0,9);
    printf("\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}