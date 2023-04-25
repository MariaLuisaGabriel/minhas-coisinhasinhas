#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#define MAXV 1000

// obs: lembrando que a lista de adjacentes, nesse caso, é uma lista circular

Grafo *criaGrafo()
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->nv = 0;
    g->na = 0;
    g->tamlista = MAXV;
    g->a = (adj **)malloc(g->tamlista * sizeof(adj *)); // alocação dinâmica de vetor
    for (int i = 0; i < g->tamlista; i++)
    {
        g->a[i] = (adj *)malloc((MAXV + 1) * sizeof(adj)); // alocação dinâmica de lista de adjacência
        g->a[i][0].qtdd = 0;
        g->a[i][0].cor = 0;
        g->a[i][0].dist = 0;
        g->a[i][0].preco = 0;
        g->a[i][0].v[0] = '\0';
    }
    return g;
}

void criaAresta(int *pos, char *v1, char *v2, Grafo *grafo, int dist, int preco)
{
    if (grafo->nv == grafo->tamlista)// verifica se a lista de vértices está cheia
    {                                                                          
        printf("Lista de vértices cheia");
    }
    
    int i, j, k;
    for (i = 0; i < grafo->nv; i++)
    {
        if (strcmp(v1, grafo->a[i][0].v) == 0)// procura o vértice v1 na lista de adjacência, como a inicialização foi  " g->a[i][0].v[0] = '\0';" se o primeiro caractere for == 0 o vertice não existe
        { 
            for (j = 1; j <= grafo->a[i][0].qtdd; j++) // percorre a lista de adjacência do vértice v1 usando o for com o j
            { 
                if (strcmp(v2, grafo->a[i][j].v) == 0) // se existe um v2 adjacente ele atualiza os vetores,
                { 
                    grafo->a[i][j].dist = dist;
                    grafo->a[i][j].preco = preco;
                    return;
                }
            }
            // se v2 não existe na lista de adjacência de v1, adiciona v2 aloca mais espaço para a lista de adjacência
            if (grafo->a[i][0].qtdd == grafo->tamlista - 1) // verifica se a lista de adjacência está cheia
            {                                                                             
                grafo->a[i] = (adj *)realloc(grafo->a[i], sizeof(adj)); // realoca o array de adjacência com o novo tamanho
            }
            k = ++(grafo->a[i][0].qtdd);  // incrementa a quantidade de vértices adjacentes a v1 e armazena o índice da nova posição na lista de adjacência
            strcpy(grafo->a[i][k].v, v2); // copia o nome de v2 para a nova posição na lista de adjacência
            grafo->a[i][k].dist = dist;   // armazena a distância da aresta
            grafo->a[i][k].preco = preco; // armazena o preço da aresta
            grafo->na++;                  // incrementa o número total de arestas no grafo
            return;
        }
    }
    // se v1 não existe no grafo, adiciona v1 e v2 e cria a aresta
    strcpy(grafo->a[grafo->nv][0].v, v1); // copia o nome de v1 para a nova posição na lista de vértices
    k = ++(grafo->a[grafo->nv][0].qtdd);  // incrementa a quantidade de vértices adjacentes a v1 e armazena o índice da nova posição na lista de adjacência
    strcpy(grafo->a[grafo->nv][k].v, v2); // copia o nome de v2 para a nova posição na lista de adjacência
    grafo->a[grafo->nv][k].dist = dist;   // armazena a distância da aresta
    grafo->a[grafo->nv][k].preco = preco; // armazena o preço da aresta
    grafo->a[grafo->nv][0].cor = 0;       // inicializa a cor do vértice com 0
    grafo->nv++;                          // incrementa o número total de vértices no grafo
    grafo->na++;                          // incrementa o número total de arestas no grafo
    *pos = grafo->nv - 1;                 // atualiza a posição do último elemento na lista de adjacência de v1
}

void mostraGrafo(Grafo *grafo)
{
    int i, j;
    printf("Grafo: %d vertices, %d arestas\n", grafo->nv, grafo->na);
    for (i = 0; i < grafo->nv; i++)
    {
        printf("Vertice %s: ", grafo->a[i][0].v);
        for (j = 1; j <= grafo->a[i][0].qtdd; j++)
        {
            printf("%s(D:%d,P:%d) ", grafo->a[i][j].v, grafo->a[i][j].dist, grafo->a[i][j].preco);
        }
        printf("\n");
    }
}

void grafoTranposto(Grafo *grafoO, Grafo *grafoT)
{
    int i, j;
    for (i = 0; i < grafoO->nv; i++)
    {
        for (j = 1; j <= grafoO->a[i][0].qtdd; j++)
        {
            criaAresta(NULL, grafoO->a[i][j].v, grafoO->a[i][0].v, grafoT, grafoO->a[i][j].dist, grafoO->a[i][j].preco);
        }
    }
}

void adjacentes(Grafo *g, int pos, int *pos1, int *pos2)
{
    int aux = 1;
    int i,j;
    for(i = 1; i<=g->a[pos][0].qtdd; i++)
    {
        for(j=0;j<g->tamlista;j++)
        {
            if(strcmp(g->a[pos][i].v,g->a[j][0].v))
            {
                *pos1 = i;
                *pos2 = j;
            }
            else aux++;
        }
    }
}

void exibir_max100(Grafo *g, char v[])
{
    int i;
    for(i=0; i<g->nv; i++)
    {
        if(strcmp(v, g->a[i][0].v)==0)
            break;
    }
    printf("\ncidades proximas de %s em , no maximo, 100km: ",g->a[i][0].v);
    for(int j=1; j<=g->a[i][0].qtdd; j++)
    {
        if(g->a[i][j].dist<=100)
        {
            printf("%s;",g->a[i][j].v);
        }
    }
}

void caminho(Grafo *g, int *dir, char Vpartida[], char Vorig[], int passos,int passosOrig, int op)
{
    int qtdds[passosOrig], ac = 0;
    //faz uma lista das quantidades de adjacentes de cada vertice
    listaqtdds(0,g,dir,Vorig,qtdds,passosOrig);
    int i = 0;
    //acha a lista de adjacentes do vertice de partida
    for(;i<g->nv;i++)
    {
        if(strcmp(Vpartida, g->a[i][0].v)==0) break;
    }
    if(i>=g->nv) return; //se nao achar sai

    //quando chega no inicio, caso o vetor diretor indique que tudo ja foi printado, ele sai
    if(strcmp(Vpartida,Vorig)==0)
    {
        if(dir[passosOrig-passos]>g->a[i][0].qtdd) return;
    }

    //correção de valores do vetor diretor (caso um elemento esteja apontando para mais que sua quantidade, a posicao anterior recebe uma redireção, e a atual se reinicia)
    for(int i = passosOrig-1; i>0; i--)
    {
        if(dir[i]>qtdds[i])
        {
            dir[i-1]++;
            dir[i]=1;
        }
    }
    
    //imprime a aresta e o custo desejado
    if(dir[passosOrig-passos]<=qtdds[passosOrig-passos]) //medida de segurança para nao printar a mais
    {
        if(op==0) printf("%s %s (%d); ",Vpartida,g->a[i][dir[passosOrig-passos]].v,g->a[i][dir[passosOrig-passos]].dist);
        else printf("%s %s (%d); ",Vpartida,g->a[i][dir[passosOrig-passos]].v,g->a[i][dir[passosOrig-passos]].preco);
    }
    else {return;}

    //caso esteja no ultimo passo, significa que aquela é a ultima vez que essa aresta será acessada, logo ja se altera o valor no vetor diretor e manda de volta pro inicio
    if(passos==1)
    {
        dir[passosOrig-passos] ++;
        printf("\n");
        caminho(g,dir,Vorig,Vorig,passosOrig,passosOrig,op);
        return;
    }

    //andando os passos
    caminho(g,dir,g->a[i][dir[passosOrig-passos]].v,Vorig,passos-1,passosOrig,op);
    return;
}

void listaqtdds(int j, Grafo *g, int *dir, char inicio[], int *qtdds, int passos)
{
    //varre o trajeto dito pelo vetor diretor, catando so as quantidades de cada lista de adjacentes
    int i = 0;
    for(;i<g->tamlista && j<passos;i++)
    {
        if(strcmp(inicio, g->a[i][0].v)==0)
        {
            qtdds[j] = g->a[i][0].qtdd;
            if(dir[j]>g->a[i][0].qtdd)
            {
                listaqtdds(j+1,g,dir,g->a[i][dir[j]-1].v,qtdds,passos);
            }
            else listaqtdds(j+1,g,dir,g->a[i][dir[j]].v,qtdds,passos);
        }
    }
}