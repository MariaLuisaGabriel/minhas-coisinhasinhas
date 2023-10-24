#include <iostream>
#include "Graph.hpp"

int main() {
	Graph* g = Graph::readGraph();
	//g->print();
	int gSize = g->getSize();
	bool Vpintado[gSize];
	int resultado = 0;

	for (int i = 0; i < gSize; i++)
	{
		Vpintado[i] = false;
	}

	for (int i = 0; i < gSize; i++)
	{
		if (Vpintado[i] == false)
		{
			resultado = g->dfs(g->getVertex(i), Vpintado);
			if (resultado != 0)
			{
				std::cout << "INVALIDO";
				return 0;
			}
		}
	}

	std::cout << "VALIDO";
	return 0;
}