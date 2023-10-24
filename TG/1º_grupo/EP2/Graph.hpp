#include "Vertex.hpp"

class Graph
{
private:
  std::vector<Vertex*> vertices;
  int size;
  int edges;
public:
//Construtores:
  Graph();
  Graph(int size, int edges);

//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph(int n, int m);

//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);

//Dado um id retorna o vertice naquela posição:
  Vertex* getVertex(int id);

//Imprime todo o grafo:
  void print();

//Faz uma busca por profundidade e retorna caso o grafo é bipartido (true) ou não (false)
  bool dfs(int v);

//Faz uma busca por largura e retorna caso o grafo é bipartido (true) ou não (false)
  bool bfs(int v);
};