#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct Adj
{
    char v[100];
    int dist;  // faz sentido para todos os vertices menos os primeiros da lista de adj
    int preco; // faz sentido para todos os vertices menos os primeiros da lista de adj
    int cor;
    int qtdd; // faz sentido para o primeiro vertice da lista de adj
} adj;

typedef struct grafo
{
    adj **a; // primeira coluna é de vertices, as demais são de adjacencias do vertice a[i][0]
    int tamlista; //  sempre constante == MAXV (1000), referente ao número máximo de linhas 
    int nv; // número de vértices
    int na; // número de arestas
} Grafo;

Grafo *criaGrafo();
void criaAresta(int *pos, char *v1, char *v2, Grafo *grafo, int dist, int preco);
void mostraGrafo(Grafo *grafo);
void grafoTranposto(Grafo *grafoO, Grafo *grafoT);
void passos(int op, Grafo *g, int dist, int pos, int pssos, int aux, int aux1);
void exibir_max100(Grafo *g, char v[]);
void dijkstra(int vertices,int origem,int destino,int *custos);
void caminho(Grafo *g, int *dir, char Vpartida[], char Vorig[], int passos,int passosOrig, int op);
void listaqtdds(int j, Grafo *g, int *dir, char inicio[], int *qtdds, int passos);

#endif