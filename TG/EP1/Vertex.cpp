#include "Vertex.hpp"
#include <iostream>

//Getters:
int Vertex::getId() { return id; }
int Vertex::getValue() { return value; }
std::vector<Vertex*> Vertex::getAdjacency() { return adjacency; }

//Setters:
void Vertex::setId(int id) { this->id = id; }
void Vertex::setValue(int value) { this->value = value; }

//Construtores:
Vertex::Vertex() {
    id = 0;
    value = 0;
}

Vertex::Vertex(int id, int value) {
    this->id = id;
    this->value = value;
}

//Adiciona o vertice v na lista de adjacencia:
void Vertex::addToAdjacency(Vertex* v) { adjacency.push_back(v); }

//Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << "," << value << ")\n"; }

//Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
    Vertex::print();
    for (auto i : adjacency) {
        std::cout << "\t";
        i->print();
    }
}