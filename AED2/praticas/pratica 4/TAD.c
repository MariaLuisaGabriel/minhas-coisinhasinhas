#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TAD.h"

void InsereLista(Cep C[], char c[], char n[], char s[], char e[], int tam)
{
  int cep;
  cep = converte(c);
  C[tam-1].CEP = cep;
  strcpy(C[tam-1].nome,n);
  strncpy(C[tam-1].sigla,s,2);
  strcpy(C[tam-1].end,e);
}

int converte(char c[])
{
  int v=0;
  int j=7;
  for(int i = 0; i<9; i++)
    {
      if(c[i]!='-')
      {
        v+=(c[i]-'0')*pow(10,j);
        j--;
      }
    }
  return v;
}

void combsort(Cep *C, int tam)
{
  int gap = tam;
  int temp, i;
  for (;;)
      {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < (tam) - gap; i++) 
        {
            int j = i + gap;
            if (C[i].CEP> C[j].CEP)
            {
                Swap(&C[i],&C[j]);
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
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

void Swap(Cep *i, Cep *j) 
{
  Cep t;
  t = *i;
  *i = *j;
  *j = t;
}

int buscaBinaria(Cep *c, int inf, int sup, int chave)
{
  int meio;
  if(c==NULL) return -2;
  if(inf<=sup)
  {
    meio = inf + ((sup-inf)/2);
    if(c[meio].CEP == chave)
    {
      return meio;
    }
    else if(c[meio].CEP > chave) return buscaBinaria(c,inf,meio-1,chave);
    else return buscaBinaria(c,meio+1,sup,chave);
  }
  return -1;
}