#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

typedef struct cep
{
  int CEP;
  char nome[1000];
  char sigla[2];
  char end[1000];
}Cep;

void InsereLista(Cep C[], char c[], char n[], char s[], char e[], int tam);
void combsort(Cep *C, int tam);
int newgap(int gap);
void Swap(Cep *i, Cep *j);
int buscaBinaria(Cep *c,int inf, int sup, int chave);
int converte(char c[]);
#endif