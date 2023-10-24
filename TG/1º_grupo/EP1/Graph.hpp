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

	//Getters
	int getSize();

	//Faz toda a leitura de entrada e cria o grafo:
	static Graph* readGraph();

	//Adiciona novo vertice na lista de vertices:
	void addVertex(Vertex* v);

	//Dado um id retorna o vertice naquela posição:
	Vertex* getVertex(int id);

	//Imprime todo o grafo:
	void print();

	int dfs(Vertex* v, bool* cor);
};