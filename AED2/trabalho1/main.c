/* Documentação:
 * https://docs.google.com/document/d/1mW1zgmeDuLK04JJ2wWW4e91UpDhl5_mBgtz4Mu6YWDo/edit#
 */
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
  FILE *f;
  Prod *p[5];
  int a=1, i=0, j, op, bc;
  float tempo, media = 0.0;
  char metodos[7][100] = {"CocktailSort",  "ShellSort", "HeapSort", "Quicksort",  "CombSort", "PancakeSort", "BucketSort"};

  int tam[5] = {10000, 30000, 50000, 75000, 90000};
  //int tam[5] = {1000, 1020, 1030, 1040, 1050};
  f = fopen("medias.txt", "w+");
  
  //for(i = 0; i<5; i++) {
    p[i] = Criar(tam[i]);
    fprintf(f, "\n\n\nPara tamanho %d\n", tam[i]);
    for(op = 7; op < 8; op++) {
      fprintf(f, "\n\n=> %s: ", metodos[op-1]);
      //for (a = 1; a < 4; a++) {
        media = 0.0;
        for(j = 0; j < 10; j++) {
          GeraAl(p[i], tam[i]);
          clock_t start_time = clock();
          switch(op)
          {
          case 1:
            CocktailSort(p[i], a, tam[i]);
            break;
          case 2:
            ShellSort(p[i], a, tam[i]);
            break;
          case 3:
            HeapSort(p[i], a, tam[i]);
            break;
          case 4:
            QuickSort(p[i], 0, tam[i], a);
            break;
          case 5:
            combsort(p[i], tam[i], a);
            break;
          case 6:
            PancakeSort(p[i], a, tam[i]);
            break;
          case 7:
            if(a>1) break;
            switch(i)
              {
                case 3:
                bc = 400;
                break;
                case 4:
                bc = 1000;
                break;
                default:
                bc = 100;
                break;
              }
            BucketSort(p[i], tam[i]);
            break;
          }
          clock_t end_time = clock();
          tempo = ((float)end_time - start_time) / CLOCKS_PER_SEC;
          media = media + tempo;
        }
        switch(a) {
        case 1: 
          fprintf(f, "\n-para codigo: ");
          break;
        case 2:
          if(op==7) break;
          fprintf(f, "\n-para descricao: ");
          break;
        case 3:
          if(op==7) break;
          fprintf(f, "\n-para valor: ");
          break;
        }
        if (!(op == 7 && a > 1)) fprintf(f, "%f", media/10);
      //}
    }
  //}
  fclose(f);
  return 0;
}