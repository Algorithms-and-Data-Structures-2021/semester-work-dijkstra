#include "data_structure.hpp"
#include <vector>
#include <stdexcept>

#define INF 1000000

namespace itis {

  BinaryHeap::BinaryHeap() {
    data_ = new std::vector<std::pair<int, int>>;
  };

  BinaryHeap::~BinaryHeap() {
    size_ = 0;
    data_->clear();
    delete data_;
    data_ = nullptr;
  }

  std::pair<int, int> BinaryHeap::pop() {
    if (size_ <= 0) {
      throw std::logic_error("error");
    }

    size_ -= 1;
    std::pair<int, int> pair_to_return = data_->at(0);
    data_->at(0) = data_->at(size_);
    data_->pop_back();

    return_to_normal(0);
    return pair_to_return;
  }

  void BinaryHeap::return_to_normal(int vertex) {
    int left_child = vertex * 2 + 1;
    int right_child = vertex * 2 + 2;
    int current_vert = vertex;
    int min_child;

    if (left_child >= size_) {
      return;
    }

    if (right_child >= size_) {
      min_child = left_child;
    } else {
      if (data_->at(left_child).first < data_->at(right_child).first) {
        min_child = left_child;
      } else {
        min_child = right_child;
      }
    }

    if (data_->at(min_child).first < data_->at(current_vert).first) {
      swap(current_vert, min_child);
      current_vert = min_child;
    }

    if (current_vert == vertex) {
      return;
    }

    return_to_normal(current_vert);
  }

  void BinaryHeap::swap(int first, int second) {
    std::pair<int, int> to_swap = data_->at(first);
    data_->at(first) = data_->at(second);
    data_->at(second) = to_swap;
  }

  void BinaryHeap::push_back(std::pair<int, int> new_pair) {
    data_->push_back(new_pair);
    down_up_sort(size_);
    size_ += 1;
  }

  void BinaryHeap::down_up_sort(int index) {
    if (index == 0) {
      return;
    }

    int parent = (index - 1) / 2;
    if (data_->at(parent).first > data_->at(index).first) {
      swap(parent, index);
      down_up_sort(parent);
    }
  }

  std::vector<int> Graph::dijkstra(std::vector<std::vector<int>> adjacencyMatrix, int vertex) {
    int vert_in_graph = adjacencyMatrix.size();
    vertex -= 1;
    std::vector<int> d(vert_in_graph, INF);
    d[vertex] = 0;
    BinaryHeap heap = BinaryHeap();
    heap.push_back(std::make_pair(0, vertex));
    std::pair<int, int> highest_pair;

    while (heap.size() != 0) {
      highest_pair = heap.pop();

      if (highest_pair.first > d[highest_pair.second]) {
        continue;
      }

      for (int i = 0; i < vert_in_graph; i++) {
        int len = adjacencyMatrix[highest_pair.second][i];
        if ((d[i] > d[highest_pair.second] + len) && (len >= 0)) {
          d[i] = d[highest_pair.second] + len;
          heap.push_back(std::make_pair(d[i], i));
        }
      }
    }

    return d;
  }
}  // namespace itis