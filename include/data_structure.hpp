#pragma once

using namespace std;
namespace itis {

  struct Graph {
   public:
    void addEdge(int u, int v, int length);
    void dijkstra(int s);
  };

}  // namespace itis