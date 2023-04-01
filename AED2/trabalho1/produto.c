#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000

typedef struct produto {
  int cod;
  char desc[61];
  float valor;
} Prod;

typedef struct bucket {
  int qtd;
  Prod p[TAM];
} Bucket;

Prod *Criar(int tam) {
  Prod *p = (Prod *)malloc(tam * sizeof(Prod));
  GeraAl(p, tam);
  return p;
}

int GeraAl(Prod *p, int tam) {
  if (p == NULL)
    return -1;
  for (int i = 0; i < tam; i++) {
    p[i].cod = rand() % 100000;
    for (int j = 0; j < 61; j++) {
      if (j == 0) {
        p[i].desc[j] = 65 + (rand() % 26);
      } else if (j <= 59) {
        p[i].desc[j] = 32 + (rand() % 95);
      } else
        p[i].desc[j] = '\0';
    }
    p[i].valor = (float)(rand() % 100000) / 100;
  }
  return 0;
}

/*
LEGENDA: 1 - ordenação por codigo, 2 - ordenação por descrição, 3 - ordenação
por valor Ordenação da ordem O(n²), em ordem crescente varrendo o vetor do
inicio ao fim, e do fim para o início, consecutivamente. para de ordenar no
momento em que o inicio e o fim da parte do vetor a ser ordenada se alcançam
*/
int CocktailSort(Prod *p, int a, int tam) {
  if (p == NULL)
    return -1;
  int i = 0, f = tam - 1;
  int trocou = 1;
  if (a == 1) {
    while (trocou) {
      trocou = 0;
      for (int j = i; j < f; j++) {
        if (p[j].cod > p[j + 1].cod) {
          Swap(&p[j], &p[j + 1]);
          trocou = 1;
        }
      }
      f--;
      if (trocou == 0)
        break;
      trocou = 0;
      for (int j = f - 1; j >= i; j--) {
        if (p[j].cod > p[j + 1].cod) {
          Swap(&p[j], &p[j + 1]);
          trocou = 1;
        }
      }
      i++;
    }
  } else if (a == 2) {
    while (trocou) {
      trocou = 0;
      for (int j = i; j < f; j++) {
        for (int k = 0; k < 60; k++) {
          if (p[j].desc[k] > p[j + 1].desc[k]) {
            Swap(&p[j], &p[j + 1]);
            trocou = 1;
            break;
          } else if (p[j].desc[k] < p[j + 1].desc[k]) {
            break;
          }
        }
      }
      f--;
      if (trocou == 0)
        break;
      trocou = 0;
      for (int j = f - 1; j >= i; j--) {
        for (int k = 0; k < 60; k++) {
          if (p[j].desc[k] > p[j + 1].desc[k]) {
            Swap(&p[j], &p[j + 1]);
            trocou = 1;
            break;
          } else if (p[j].desc[k] < p[j + 1].desc[k]) {
            break;
          }
        }
      }
      i++;
    }
  } else {
    while (trocou) {
      trocou = 0;
      for (int j = i; j < f; j++) {
        if (p[j].valor > p[j + 1].valor) {
          Swap(&p[j], &p[j + 1]);
          trocou = 1;
        }
      }
      f--;
      if (trocou == 0)
        break;
      trocou = 0;
      for (int j = f - 1; j >= i; j--) {
        if (p[j].valor > p[j + 1].valor) {
          Swap(&p[j], &p[j + 1]);
          trocou = 1;
        }
      }
      i++;
    }
  }
  return 0;
}

// https://www.geeksforgeeks.org/heap-sort/
int HeapSort(Prod *p, int a, int tam) {
  if (p == NULL)
    return -1;
  //gera o heap de uma posiçao i, no fim do for ele gera a arvore binaria completa, para todos os i do vetor (a arvore também já organizada de acordo c a regra da arvore binaria)
  for (int i = tam / 2 - 1; i >= 0; i--)
    heapify(p, tam, i, a);

  //troca o primeiro elemento c o ultimo, e gera a arvore binaria organizada novamente. no fim desse for a arvore estará ordenada
  for (int i = tam - 1; i >= 0; i--) {
    Swap(&p[0], &p[i]);

    heapify(p, i, 0, a);
  }

  return 0;
}

void heapify(Prod *p, int tam, int i, int a) {
  int maior = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  switch (a) {
  case 1: {
    if (esq < tam && p[esq].cod > p[maior].cod)
      maior = esq;

    if (dir < tam && p[dir].cod > p[maior].cod)
      maior = dir;

    if (maior != i) {
      Swap(&p[i], &p[maior]);
      heapify(p, tam, maior, a);
    }
    break;
  }
  case 2: {
    if (esq < tam && strcmp(p[esq].desc, p[maior].desc) > 0)
      maior = esq;

    if (dir < tam && strcmp(p[dir].desc, p[maior].desc) > 0)
      maior = dir;

    if (maior != i) {
      Swap(&p[i], &p[maior]);
      heapify(p, tam, maior, a);
    }
    break;
  }
  case 3: {
    if (esq < tam && p[esq].valor > p[maior].valor)
      maior = esq;

    if (dir < tam && p[dir].valor > p[maior].valor)
      maior = dir;

    if (maior != i) {
      Swap(&p[i], &p[maior]);
      heapify(p, tam, maior, a);
    }
    break;
  }
  }
}

/*
  QuickSort com Mediana de 3
  InsertionSort
*/
int QuickSort(Prod *p, int start, int end, int a) {
  if (p == NULL)
    return -1;
  int meio;
  if (start - end <= 4) {
    InsertionSort(p, start + 1, end, a);
  } else {
    meio = parte(p, start, end, a); //é aqui que ocorrem as trocas
    QuickSort(p, start, meio, a);   // chama uma sublista
    QuickSort(p, meio + 1, end, a); // chama outra sublista
  }
  return 0;
}

int parte(Prod *p, int start, int end, int a) {
  if (p == NULL)
    return -1;
  int pivot;
  char pivotD[61];
  float pivotF;
  if (a == 1) {
    pivot = ordena(p, rand()%(end-start)+start, rand()%(end-start)+start, rand()%(end-start)+start, a);
  } else if (a == 2) {
    strcpy(pivotD, p[ordena(p,rand()%(end-start)+start, rand()%(end-start)+start, rand()%(end-start)+start, a)].desc);
  } else if (a == 3) {
    pivotF = p[ordena(p,rand()%(end-start)+start, rand()%(end-start)+start, rand()%(end-start)+start, a)].valor;
  }
  int i = start - 1;
  int j = end + 1;
  Prod temp;
  while (i < j) {
    if (a == 1) {
      while (p[i].cod < pivot) {
        i++;
      }
    } else if (a == 2) {
      while (strcmp(pivotD, p[i].desc) > 0) {
        i++;
      }
    } else {
      while (p[i].cod < pivotF) {
        i++;
      }
    }
    if (a == 1) {
      while (p[j].cod > pivot) {
        j--;
      }
    } else if (a == 2) {
      while (strcmp(pivotD, p[j].desc) < 0) {
        j--;
      }
    } else {
      while (p[i].cod > pivotF) {
        j--;
      }
    }
    if (i < j)
      Swap(&p[i], &p[j]);
  }
  return j;
}

int ordena(Prod *p, int a, int b, int c, int a1) {
  int i = 0, f = 2, temp;
  int trocou = 1;
  if (a1 == 1) {
    int aux[3];
    aux[0] = p[a].cod;
    aux[1] = p[b].cod;
    aux[2] = p[c].cod;
    while (trocou) {
      trocou = 0;
      for (int j = i; j < f; j++) {
        if (aux[j] > aux[j + 1]) {
          temp = aux[j];
          aux[j] = aux[j + 1];
          aux[j + 1] = temp;
          trocou = 1;
        }
      }
      f--;
      if (trocou == 0)
        break;
      trocou = 0;
      for (int j = f - 1; j >= i; j--) {
        if (aux[j] > aux[j + 1]) {
          temp = aux[j];
          aux[j] = aux[j + 1];
          aux[j + 1] = temp;
          trocou = 1;
        }
      }
      i++;
    }
    return aux[1];
  } else if (a1 == 2) {
    char tempD[61];
    char auxD[3][61];
    strcpy(auxD[0], p[a].desc);
    strcpy(auxD[1], p[b].desc);
    strcpy(auxD[2], p[c].desc);
    while (trocou) {
      trocou = 0;
      for (int j = i; j < f; j++) {
        for (int k = 0; k < 60; k++) {
          if (auxD[j][k] > auxD[j + 1][k]) {
            Swap(&p[j], &p[j + 1]);
            trocou = 1;
            break;
          } else if (p[j].desc[k] < p[j + 1].desc[k]) {
            break;
          }
        }
      }
      f--;
      if (trocou == 0)
        break;
      trocou = 0;
      for (int j = f - 1; j >= i; j--) {
        for (int k = 0; k < 60; k++) {
          if (auxD[j][k] > auxD[j + 1][k]) {
            strcpy(tempD, auxD[j]);
            strcpy(auxD[j], auxD[j + 1]);
            strcpy(auxD[j + 1], tempD);
            trocou = 1;
            break;
          } else if (p[j].desc[k] < p[j + 1].desc[k]) {
            break;
          }
        }
      }
      i++;
    }
    int y;
    y = strcmp(auxD[1], p[a].desc);
    if (y == 0)
      return a;
    y = strcmp(auxD[1], p[b].desc);
    if (y == 0)
      return b;
    y = strcmp(auxD[1], p[c].desc);
    if (y == 0)
      return c;
  } else if (a1 == 3) {
    float auxF[3];
    auxF[0] = p[a].valor;
    auxF[1] = p[b].valor;
    auxF[2] = p[c].valor;
    while (trocou) {
      trocou = 0;
      for (int j = i; j < f; j++) {
        if (auxF[j] > auxF[j + 1]) {
          temp = auxF[j];
          auxF[j] = auxF[j + 1];
          auxF[j + 1] = temp;
          trocou = 1;
        }
      }
      f--;
      if (trocou == 0)
        break;
      trocou = 0;
      for (int j = f - 1; j >= i; j--) {
        if (auxF[j] > auxF[j + 1]) {
          temp = auxF[j];
          auxF[j] = auxF[j + 1];
          auxF[j + 1] = temp;
          trocou = 1;
        }
      }
      i++;
    }
    if (auxF[1] == p[a].valor)
      return a;
    if (auxF[1] == p[b].valor)
      return b;
    if (auxF[1] == p[c].valor)
      return c;
  }
  return 0;
}

int InsertionSort(Prod *p, int in, int tam, int a) {
  if (p == NULL)
    return -1;

  if (a == 1) {
    for (int i = in; i < tam; i++) {
      int j = i;
      while (j > 0 && p[j - 1].cod > p[j].cod) {
        Swap(&p[j], &p[j - 1]);
        j--;
      }
    }
  } else if (a == 2) {
    for (int i = in; i < tam; i++) {
      int j = i;
      while (j > 0 && strcmp(p[j - 1].desc, p[j].desc) > 0) {
        Swap(&p[j], &p[j - 1]);
        j--;
      }
    }
  } else {
    for (int i = in; i < tam; i++) {
      int j = i;
      while (j > 0 && p[j - 1].valor > p[j].valor) {
        Swap(&p[j], &p[j - 1]);
        j--;
      }
    }
  }
  return 0;
}

// https://www.geeksforgeeks.org/pancake-sorting/
int PancakeSort(Prod *p, int a, int tam) {
  if (p == NULL)
    return -1;
  int mi;
  for (int tamAtual = tam; tamAtual > 1; tamAtual--) {
    mi = encontraMaior(p, tamAtual);
    if (mi != tamAtual - 1) {
      flip(p, mi);
      flip(p, tamAtual - 1);
    }
  }
  return 0;
}

int encontraMaior(Prod *p, int tam) {
  int mi = 0, i = 0;
  while (i < tam) {
    if (p[i].cod > p[mi].cod)
      mi = i;
    i++;
  }
  return mi;
}

void flip(Prod *p, int i) {
  int start = 0;
  while (start < i) {
    Swap(&p[start], &p[i]);
    start++;
    i--;
  }
}

void Mostrar(Prod *p, int tam) {
  if (p != NULL) {
    for (int i = 0; i < tam; i++) {
      printf("\n-> %dº Produto: \n\t| Codigo: %d "
             "\n\t| Valor: R$ %.2f \n\t| Descricao: %s\n",
             i + 1, p[i].cod, p[i].valor, p[i].desc);
    }
  }
}

void Swap(Prod *i, Prod *j) {
  Prod t;
  t = *i;
  *i = *j;
  *j = t;
}

int ShellSort(Prod *p, int a, int n) {
  if (p == NULL)
    return -1;
  int i, j;
  Prod valor;
  int intervalo = 1;
  // determina o intervalo
  do {
    intervalo = 3 * intervalo + 1;
  } while (intervalo < n);
  if (a == 1) {
    do {
      intervalo /= 3;
      for (i = intervalo; i < n; i++) {
        valor = p[i];      // posicao 2
        j = i - intervalo; // posicao 1
        while (j >= 0 && valor.cod < p[j].cod) {
          p[j + intervalo] = p[j]; // pos1 passa para 2
          j -= intervalo;
        }
        p[j + intervalo] = valor; // pos2 passa para 1
      }
    } while (intervalo > 1);
  }
  else if(a==2)
  {
    do {
      intervalo /= 3;
      for (i = intervalo; i < n; i++) {
        valor = p[i];      // posicao 2
        j = i - intervalo; // posicao 1
        while (j >= 0 && strcmp(valor.desc,p[j].desc)<0) {
          p[j + intervalo] = p[j]; // pos1 passa para 2
          j -= intervalo;
        }
        p[j + intervalo] = valor; // pos2 passa para 1
      }
    } while (intervalo > 1);
  }
  else{
    do {
      intervalo /= 3;
      for (i = intervalo; i < n; i++) {
        valor = p[i];      // posicao 2
        j = i - intervalo; // posicao 1
        while (j >= 0 && valor.valor < p[j].valor) {
          p[j + intervalo] = p[j]; // pos1 passa para 2
          j -= intervalo;
        }
        p[j + intervalo] = valor; // pos2 passa para 1
      }
    } while (intervalo > 1);
  }
  return 0;
}

int BucketSort(Prod *p, int tam) {
  if (p == NULL)
    return -1;
  int i, j,  maior, menor, nroBaldes, pos;
  Bucket *bc;
  
  maior = p[0].cod;
  menor = p[0].cod;
  for (i = 0; i < tam; i++) {
    if (p[i].cod > maior) maior = p[i].cod;
    if (p[i].cod < menor) menor = p[i].cod;
  }
  
  nroBaldes = (maior - menor) / (TAM + 1);
  bc = (Bucket *)malloc(nroBaldes * sizeof(Bucket));

  for (i = 0; i < nroBaldes; i++){
    bc[i].qtd = 0;
  }

  for (i = 0; i < tam; i++) {
    pos = (p[i].cod - menor) / (TAM + 1);
    bc[pos].p[bc[pos].qtd] = p[i];
    bc[pos].qtd++;
  }

  pos = 0;
  for (i = 0; i <= nroBaldes; i++) {
    InsertionSort(bc[i].p, 0, bc[i].qtd, 1);
    for (j = 0; j < bc[i].qtd; j++){
      p[pos] = bc[i].p[j];
      pos++;
    }
  }
  
  return 0;
}
 
//fonte: https://www.sanfoundry.com/c-program-implement-comb-sort/
/*Function to implement the combsort*/
void combsort(Prod *p, int aSize, int a)
{
    int gap = aSize;
    int temp, i;
    if(a==1){
      for (;;)
      {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < aSize - gap; i++) 
        {
            int j = i + gap;
            if (p[i].cod > p[j].cod)
            {
                Swap(&p[i],&p[j]);
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
      }
    } else if (a==2) {
      for (;;)
      {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < aSize - gap; i++) 
        {
            int j = i + gap;
            if (strcmp(p[i].desc,p[j].desc)>0)
            {
                Swap(&p[i],&p[j]);
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
      }
    } else {
      for (;;)
      {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < aSize - gap; i++) 
        {
            int j = i + gap;
            if (p[i].valor > p[j].valor)
            {
                Swap(&p[i],&p[j]);
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
      }
    }
}

int newgap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}