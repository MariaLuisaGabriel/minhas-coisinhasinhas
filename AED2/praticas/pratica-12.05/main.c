/*
PRÁTICA DIA 12.05.2023
AUTOR: Maria Luísa Gabriel Domingues - 12121BCC010
*/

#include "arv.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  arvBin *a = NULL;
  FILE *f;
  int c;
  int qtd = 0;
  char n[1000], s[3], e[1000], cep[10];
  printf("\nlendo...");
  f = fopen("cidades.txt", "r");
  while (fscanf(f, "%[^;]; %[^;]; %[^;]; %[^\n]\n", cep, s, n, e) != EOF) {
    if(qtd==20) break;
    c = converte(cep);
    insereNo(&a, c, n, s, e, 0);
    qtd++;
  }
  fclose(f);
  printf("\n");
  mostraArvAlin(a);
  int chave;
  int i;
  printf("\nmenor CEP:\n");getValores(getmenor(a));
  printf("\nmaior CEP:\n");getValores(getmaior(a));
  altura(a,&i);
  printf("\n\naltura: %d",i-1);
  printf("\n escreva um CEP para encontrá-lo: ");
  scanf("%d", &chave);
  arvBin *b = buscaArv(a, chave);
  if(b!=NULL) {getValores(b);}
  else {printf("\nvalor nao existe na arvore");}
  return 0;
}