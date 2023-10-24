#include "Vertex.hpp"
#include <string>
#include <iostream>
using std::string;

class Graph
{
private:
	std::vector<Vertex*> vertices;
	int size;
public:
	//Construtores:
	Graph();
	Graph(int size);

	//Getters e Setters
	int getSize();
    void setSize(int size);

	//Faz toda a leitura de entrada e cria o grafo:
	static Graph* readGraph();

	//Adiciona novo vertice na lista de vertices:
	void addVertex(char valor);

	//Dado um id retorna o vertice naquela posi��o:
	Vertex* getVertex(int id);

	//Imprime todo o grafo:
	void print();
    void printVertices();

	//int dfs();

    string captureVertices(std::vector <string> matriz, int linhas);

    void hierarquia(std::vector <string> matriz);
};