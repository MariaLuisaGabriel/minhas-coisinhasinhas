#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

typedef struct produto Prod;
Prod *Criar(int tam);
int GeraAl(Prod *p, int tam);
int ordena(Prod *p, int a, int b, int c, int a1);

int CocktailSort(Prod *p,int a, int tam);
int ShellSort(Prod *p,int a, int tam);
int HeapSort(Prod *p,int a, int tam);
void heapify(Prod *p, int tam, int i, int a);

int QuickSort(Prod *p, int start, int end, int a);
int parte(Prod *p, int start, int end, int a);

int InsertionSort(Prod *p, int in, int tam, int a);
int PancakeSort(Prod *p, int a, int tam);
int encontraMaior(Prod *p, int tam);
void flip(Prod *p, int i);
void combsort(Prod *p, int aSize, int a);
int newgap(int gap);

int BucketSort(Prod *p, int tam);

void Mostrar(Prod *p, int tam);
void Swap(Prod *i, Prod *j);

#endif