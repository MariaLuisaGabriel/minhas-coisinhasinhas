#include <iostream>
#include "Graph.hpp"

int main() {
  Graph *g = Graph::readGraph();
  
  g->printVertices();
  //g->print();

  return 0;
}