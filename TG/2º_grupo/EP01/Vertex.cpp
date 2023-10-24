#include "Vertex.hpp"
#include <iostream>

//Getters:
int Vertex::getColor() { return color; }
char Vertex::getValue() { return value; }
std::vector<Vertex*> Vertex::getAdjacency() { return menorQue; }

//Setters:
void Vertex::setColor(int color) { this->color = color; }
char Vertex::setValue(char value) { this->value = value; }

//Construtores:
Vertex::Vertex() {
    color = 0;
    value = ' ';
}

Vertex::Vertex(char value) {
    this->color = 0;
    this->value = value;
}

//Adiciona o vertice v na lista de adjacencia:
void Vertex::addToAdjacency(char valor) 
{
    Vertex* v = new Vertex();
    v->setValue(valor);
    menorQue.push_back(v);
}

//Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "\n" << "(" << color << "," << value << ")\n"; }

//Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
    Vertex::print();
    for (auto i : menorQue) {
        std::cout << "\t";
        i->print();
    }
}