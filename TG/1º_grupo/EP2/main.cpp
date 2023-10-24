#include <iostream>
#include "Graph.hpp"
#include <queue>

int main() {
  int n = 1, m = 0;
  std::queue<bool> results;
  std::queue<bool> results2;
  while(n != 0){
    // reading number of vertices:
    std::cin >> n;
    if(n == 0 || n > 200){
      break;
    }
    // reading number of edges:
    std::cin >> m;
    Graph* g = Graph::readGraph(n,m);
    results.push(g->dfs(0));
    results2.push(g->bfs(0));
    //g->print();
  }
  //std::cout << "DFS : ";
  /*
  while(!results.empty()){
    if(!results.front())
      std::cout << "NOT BICOLORABLE.\n";
    else
      std::cout << "BICOLORABLE.\n";
    results.pop();
  }
  */
  //std::cout << "BFS : ";
  while(!results2.empty()){
    if(!results2.front())
      std::cout << "NOT BICOLORABLE.\n";
    else
      std::cout << "BICOLORABLE.\n";
    results2.pop();
  }
  return 0;
}