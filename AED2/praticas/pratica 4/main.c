#include <stdio.h>
#include "TAD.h"

int main(void) {
  Cep c[999];
  int tam = 1;
  FILE *f;
  char n[1000],s[3],e[1000],cep[10];
  printf("\nlendo...");
  f = fopen("cidades.txt","r");
  while(fscanf(f,"%[^;]; %[^;]; %[^;]; %[^\n]\n",cep,s,n,e)!=EOF)
  {
    InsereLista(c,cep,n,s,e,tam);
    tam++;
  }
  fclose(f);
  printf("\ncombsort...");
  combsort(c,tam-1);
  
  int chave;
  printf("\n escreva um CEP para encontrá-lo: ");
  scanf("%d",&chave);
  int pos = buscaBinaria(c, 0, tam-2, chave);
  if(pos!=-1)printf("cidade: %d, %s, %s, %s",c[pos].CEP,c[pos].sigla,c[pos].nome,c[pos].end);
  else if(pos==-1){printf("aaaaaaaaaaaaaaaa");}
  else printf("help");
  return 0;
}