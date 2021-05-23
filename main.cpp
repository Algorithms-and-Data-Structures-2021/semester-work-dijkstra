#include <algorithm>
#include <climits>
#include <iostream>
#include "data_structure.hpp"

//#include <iostream>
//
//#include "data_structure.hpp"
//
//using namespace std;
//
//int main(int argc, char *argv[]) {
//  for (int index = 0; index < argc; index++) {
//    cout << index << ": " << argv[index] << endl;
//  }
//  return 0;
//}

using namespace std;

int main() {
  auto *graph = new itis::Graph;
  graph->addEdge(0, 2, 3);
  graph->addEdge(0, 3, 2);
  graph->addEdge(1, 2, 5);
  graph->addEdge(1, 3, 8);
  graph->addEdge(2, 0, 3);
  graph->addEdge(2, 1, 5);
  graph->addEdge(3, 0, 2);
  graph->addEdge(3, 1, 8);

  graph->dijkstra(0);
}