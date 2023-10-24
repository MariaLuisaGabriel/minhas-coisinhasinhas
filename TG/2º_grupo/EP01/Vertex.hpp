#include <vector>

class Vertex
{
private:
	int color;
	char value;
	std::vector<Vertex*> menorQue;
public:
	//Construtores:
	Vertex();
	Vertex(char value);
	//Getters:
	int getColor();
	char getValue();
	std::vector<Vertex*> getAdjacency();
	//Setters:
	void setColor(int color);
	char setValue(char value);
	//Adiciona o vertice v na lista de adjacencia
	void addToAdjacency(char valor);
	//Printa as informacoes de id e valor do vertice atual
	void print();
	//Printa a lista de adjacencia do vertice atual
	void printAdjacency();
};