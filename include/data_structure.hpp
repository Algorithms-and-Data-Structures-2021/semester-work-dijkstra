#pragma once
#include <vector>

// Заголовочный файл с объявлением структуры данных

namespace itis {
  struct Graph{
   public:
  std::vector<int> dijkstra(std::vector<std::vector<int>> adjacencyMatrix, int vertex);

  };

  struct BinaryHeap {
   private:
    // поля структуры
    unsigned int size_{0};
    std::vector<std::pair<int, int>>* data_{nullptr};

    void down_up_sort(int);

    void return_to_normal(int);

    void swap(int first, int second);

   public:
    BinaryHeap();

    std::pair<int, int> pop();

    void push_back(std::pair<int, int> new_pair);

    ~BinaryHeap();

    int size() const {
      return size_;
    }
  };
}  // namespace itis