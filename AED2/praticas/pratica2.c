#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraAl(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100000;
    }
}

// questão 1)

void swap(int *v, int i, int j) {

int temp = v[i];

v[i] = v[j];

v[j] = temp;

}


void ShellSort(int *v, int n)
{
    int i, j;
    int valor;
    int intervalo = 1;
    // determina o intervalo
    do
    {
        intervalo = 3 * intervalo + 1;
    } while (intervalo < n);
    do
    {
        intervalo /= 3;
        for (i = intervalo; i < n; i++)
        {
            valor = v[i];      // posicao 2
            j = i - intervalo; // posicao 1
            while (j >= 0 && valor < v[j])
            {
                v[j + intervalo] = v[j]; // pos1 passa para 2
                j -= intervalo;
            }
            v[j + intervalo] = valor; // pos2 passa para 1
        }
    } while (intervalo > 1);
}

void bubbleSort(int *v, int n)
{
    int temp;
    for (int x = 0; x < n - 1; x++)
    {

        for (int y = 0; y < n - x - 1; y++)
        {

            if (v[y] > v[y + 1])
            {

                temp = v[y];

                v[y] = v[y + 1];

                v[y + 1] = temp;
            }
        }
    }
}

void insertionSort(int *v, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void SelectionSort(int *v, int n)
{
    int vMenor;
    int vAux;
    int vTemp;
    int vTroca;

    for (vAux = 0; vAux < n - 1; vAux++) // Percorre todo o vetor até n-1, pois a ultima posição não precisa testar pois ja estara ordenada;
    {
        vMenor = vAux; // Menor valor recebe a posição que está passando;

        for (vTemp = vAux + 1; vTemp < n; vTemp++) // Percorre o vetor da posição vAux+1 até o final;
        {
            if (v[vTemp] < v[vMenor]) // Testa se a posição que está passando é menor que o menor valor;
            {
                vMenor = vTemp; // vMenor recebe a posição do menor valor;
            }
        }

        if (vMenor != vAux) // Se a posição for diferente da que está passando, ocorre a troca;
        {
            vTroca = v[vAux];
            v[vAux] = v[vMenor];
            v[vMenor] = vTroca;
        }
    }
}

void merge(int *v, int *c, int i, int m, int f)
{
    int z,
        iv = i, ic = m + 1;

    for (z = i; z <= f; z++)
        c[z] = v[z];

    z = i;

    while (iv <= m && ic <= f)
    {
        /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

        if (c[iv] <= c[ic])
            v[z++] = c[iv++];
        else
            v[z++] = c[ic++];
    }

    while (iv <= m)
        v[z++] = c[iv++];

    while (ic <= f)
        v[z++] = c[ic++];
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f)
{
    if (i >= f)
        return;

    int m = (i + f) / 2;

    sort(v, c, i, m);
    sort(v, c, m + 1, f);

    /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
    if (v[m] <= v[m + 1])
        return;

    merge(v, c, i, m, f);
}

void mergesort(int *v, int n)
{
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n - 1);
    free(c);
}

void stoogesort(int *v, int i, int j) {

int k;

if (v[i] > v[j]) swap(v, i, j);

if (i + 1 >= j) return;

k = (j - i + 1) / 3;

stoogesort(v, i, j - k);

stoogesort(v, i + k, j);

stoogesort(v, i, j-k);

}

int main()
{
    int N[3] = {10, 50000, 100000};
    int i;
    float tempo;
    int v1[N[0]], v2[N[1]], v3[N[2]];
    int *v;
    for (int j = 0; j < 1; j++)
    {
        switch (j)
        {
        case 0:
        {
            v = v1;
            break;
        }
        case 1:
        {
            v = v2;
            break;
        }
        case 2:
        {
            v = v3;
            break;
        }
        }
        for (int i = 0; i < 6; i++)
        {
            geraAl(v, N[j]); // gerando elementos aleatórios para um vetor com 10000 posições
            clock_t start_time = clock();
            switch (i + 1)
            {
            case 1:
                bubbleSort(v, N[j]);
                printf("\n=>bubble: ");
                break;
            case 2:
                ShellSort(v, N[j]);
                printf("\n=>shell: ");
                break;
            case 3:
                insertionSort(v, N[j]);
                printf("\n=>insertion: ");
                break;
            case 4:
                SelectionSort(v, N[j]);
                printf("\n=>selection: ");
                break;
            case 5:
                mergesort(v, N[j]);
                printf("\n=>merge: ");
                break;
            case 6:
                stoogesort(v, 0, N[j]);
                printf("\n=>stooge: ");
                break;
            }
            clock_t end_time = clock();
            tempo = ((float)end_time - start_time) / CLOCKS_PER_SEC;
            printf("tempo: %f",tempo);
            printf("\n\n");
            for(int o=0;o < N[j];o++)
                printf("%d ", v[o]);
            printf("\n\n");
        }
    }
    return 0;
}