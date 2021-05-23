#include <string>
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include <sstream>      // stringstream

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;
// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы
  const auto path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/result/benchmark_result.csv";

  // работа с набором данных
  vector<string> folders = {"01", "02", "03", "04", "05"};
  vector<string> files = {"100x100 adjacency matrix.csv", "500x500 adjacency matrix.csv",
                          "1000x1000 adjacency matrix.csv", "5000x5000 adjacency matrix.csv",
                          "10000x10000 adjacency matrix.csv"};
  std::vector<std::vector<int>> parsedMatrix;
  Graph graph;
  int line_number = 1;
  for (string file : files) {
    for (string folder : folders) {
      auto input_file = ifstream(path + "/" + folder + "/" + file + ".csv");
      for (string line; getline(input_file, line, ','); /* ... */) {
        for (int i = 0; i < 100; i++) {
          for (int j = 0; j < 100; j++) {
            parsedMatrix[i][j] = stoi(line);
          }
        }
        line_number++;
      }

        const auto time_point_before_insert = chrono::steady_clock::now();
      graph.dijkstra(parsedMatrix,0);
      const auto time_point_after_insert = chrono::steady_clock::now();
      auto time_diff = chrono::nanoseconds::zero();
      time_diff += time_point_after_insert - time_point_before_insert;
      const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
      cout << time_elapsed_ns_insert << endl;

      input_file.close();
    }
  }
  return 0;
}