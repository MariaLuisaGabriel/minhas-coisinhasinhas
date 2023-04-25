#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int main()
{  
  int i,j,op;
  //grafoHTML();
    FILE* fp;
  fp = fopen("grafo.txt", "r");
  if (fp == NULL){
    printf("Erro na abertura de arquivo\n");
    return 1;
  }

  
    char V1[100], V2[100];
    
    Grafo *grafo0 = criaGrafo();
    Grafo *grafo1 = criaGrafo();
    int dist, preco,v = -1;
  
    /*printf("Leitura do grafo\n");
    printf("No. vertices:");
    scanf("%d%*[^\n]", &NVertices);
    getchar();
    printf("No. arestas:");
    scanf("%hd%*[^\n]", &NArestas);
    getchar();
    Grafo.NumVertices = NVertices;
    Grafo.NumArestas=0;
    FGVazio(&Grafo);*/

  
    while (!feof(fp)) {
      fscanf(fp, "%s %s %d %d\n", V1, V2, &dist, &preco);
      criaAresta(&v, V1, V2, grafo0, dist, preco);
    }
  fclose(fp);
    // for (i = 0; i <= NArestas - 1; i++) {
        // printf("Insere V1 -- V2 -- Peso:");
        // scanf("%s %s %d %d%*[^\n]", &V1, &V2, &Peso, &Peso2);
        // getchar();
        // Grafo.NumArestas++;
        // InsereAresta(&V1, &V2, &Peso, &Grafo);  
    // }
    //BL(grafo);
    mostraGrafo(grafo0);
    //grafoTransposto(grafo0,grafo1);
    //mostraGrafo(grafo1);

  printf("\nescreva um vertice para ver todos os seus caminhos: ");
  scanf("%s",V1);
  printf("\nescreva quantos passos quer dar: ");
  scanf("%d",&j);
  printf("\nmostrar preco ou distancia?: \n-mostrar preco = 1;\n-mostrar distancia = 0;\n->");
  scanf("%d",&op);
  int *dir;
  dir = (int *)calloc(j,sizeof(int));
  for(int i = 0; i<j; i++)
  {
    dir[i]++;
  }
  caminho(grafo0, dir, V1, V1, j, j, op);
  printf("\n\n");
  exibir_max100(grafo0, grafo0->a[0][0].v);
  
  return 0;
}