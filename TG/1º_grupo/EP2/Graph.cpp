#include "Graph.hpp"
#include <iostream>
#include <stack>
#include <queue>

//Construtores:
Graph::Graph(){
  this->size = 0;
  this->edges = 0;
}

Graph::Graph(int size, int edges){
  this->size = size;
  this->edges = edges;
}

//Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex* v)
{
  vertices.push_back(v);
}

//Dado um id retorna o vertice naquela posição:
Vertex* Graph::getVertex(int id)
{
  return vertices.at(id);
}

//Faz toda a leitura de entrada e cria o grafo:
Graph* Graph::readGraph(int n, int m)
{
  int vertex1 = 0, vertex2 = 0;
  Vertex *v;
  Graph *g;
  
  g = new Graph(n,m);
  
  for (int i = 0; i < n; i++) {
    v = new Vertex(i);
    g->addVertex(v);
  }
  for (int i = 0; i < m; i++)
  {
    std::cin >> vertex1;
    std::cin >> vertex2;
    g->getVertex(vertex1)->addToAdjacency(g->getVertex(vertex2));
    g->getVertex(vertex2)->addToAdjacency(g->getVertex(vertex1));
  }
  return g;
}

//Imprime todo o grafo:
void Graph::print()
{
  for(auto i : vertices)
  {
      i->printAdjacency();
  }
}

//Faz uma busca por profundidade e retorna caso o grafo é bipartido (true) ou não (false)
bool Graph::dfs(int e){
  int u;
  bool flag = true;
  std::stack<int> stack;
  stack.push(e);
  getVertex(e)->setColour(1);
  while(!stack.empty()){
    u = stack.top();
    stack.pop();
    Vertex *v = getVertex(u);
    bool vmark = v->getMark();
    int vcolour = v->getColour();
    if(!vmark){
      v->setMark(true);
      for(auto i:v->getAdjacency()){
        if(!i->getMark()){
          if(vcolour == 1)
            i->setColour(2);
          else
            i->setColour(1);
          stack.push(i->getId());
        }
        else if(vcolour == i->getColour()){
         flag = false;
        }
      }
    }
  } 
  if(!flag)
    return false;
  return true;
}

//Faz uma busca por largura e retorna caso o grafo é bipartido (true) ou não (false)
bool Graph::bfs(int v)
{
  int a;
  bool flag = true;
  std::queue<int> queue;
  queue.push(v);
  getVertex(v)->setColour(1);
  getVertex(v)->setMark(true);
  while(!queue.empty())
    {
      a = queue.front();
      queue.pop();
      Vertex* v = getVertex(a);
      bool vmark = v->getMark();
      int colour = v->getColour();
        for(auto i : v->getAdjacency())
          {
            if(!i->getMark())
            {
              i->setMark(true);
              if(colour == 1)
              {
                i->setColour(2);
              }
              else i->setColour(1);
              queue.push(i->getId());
            }
            else if(colour == i->getColour())
              flag = false;
          }
    }
  if(!flag)
  {
    return false;
  }
  return true;
}