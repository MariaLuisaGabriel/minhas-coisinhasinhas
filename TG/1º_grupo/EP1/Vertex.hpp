#include <vector>
class Vertex
{
private:
	int id;
	int value;
	std::vector<Vertex*> adjacency;
public:
	//Construtores:
	Vertex();
	Vertex(int id, int value);
	//Getters:
	int getId();
	int getValue();
	std::vector<Vertex*> getAdjacency();
	//Setters:
	void setId(int id);
	void setValue(int value);
	//Adiciona o vertice v na lista de adjacencia
	void addToAdjacency(Vertex* v);
	//Printa as informacoes de id e valor do vertice atual
	void print();
	//Printa a lista de adjacencia do vertice atual
	void printAdjacency();
};