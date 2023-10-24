#include "Graph.hpp"
#include <iostream>

//Construtores:
Graph::Graph() {
    this->size = 0;
    this->edges = 0;
}

Graph::Graph(int size, int edges) {
    this->size = size;
    this->edges = edges;
}

int Graph::getSize() { return size; }

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
Graph* Graph::readGraph()
{
    int n = 0, m = 0, value = 0, vertex1 = 0, vertex2 = 0;
    Vertex* v;
    Graph* g;
    // reading number of vertices:
    std::cin >> n;
    // reading number of edges:
    std::cin >> m;

    g = new Graph(n, m);

    for (int i = 0; i < n; i++) {
        std::cin >> value;
        v = new Vertex(i, value);
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
    for (auto i : vertices)
    {
        i->printAdjacency();
    }
}

//Busca em profundidade, para análise de transferência de dinheiro
int Graph::dfs(Vertex* v, bool* cor)
{
    cor[v->getId()] = true;
    std::vector<Vertex*> adj = v->getAdjacency();
    for (auto i : adj)
    {
        if (!cor[i->getId()])
        {
            return (Graph::dfs(i, cor) + v->getValue());
        }
    }

    return v->getValue();
}