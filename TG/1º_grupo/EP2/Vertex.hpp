#include <vector>
class Vertex
{
private:
  int id;
  std::vector<Vertex*> adjacency;
  bool mark;
  int colour;
  
public:
  //Construtores:
  Vertex();
  Vertex(int id);
  //Getters:
  int getId();
  int getValue();
  bool getMark();
  std::vector<Vertex*> getAdjacency();
  int getColour(); // 1 = preto, 2 = vermelho
  //Setters:
  void setId(int id);
  void setValue(int value);
  void setMark(bool mark);
  void setColour(int colour);
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();
};