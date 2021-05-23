
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>

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
  vector<string> files = {"100.csv", "500.csv", "1000.csv", "5000.csv", "10000.csv"};
  int a, b;
  for (string file : files) {         // Проходим по всем 10 .csv файлам
    for (string folder : folders) {   // Проходим по всем 10 папкам с файлами
      for (int i = 1; i < 11; i++) {  // Запускаем замерку времени 10 раз
        // string line = "1";
        auto input_file = ifstream(path + "/" + folder + "/" + file + ".csv");
        auto time_diff = chrono::nanoseconds::zero();
        cout << (path + "/" + folder + "/" + file) << endl;
        // здесь находится участок кода, время которого необходимо замерить
        input_file >> a;
        input_file >> b;
        Graph graph(a + 1);
        int mass[3];
        for (int i = 0; i < b; i++) {
          for (int i = 0; i < 3; ++i) {
            input_file >> mass[i];
          }
          graph.addEdge(mass[0], mass[1], mass[2]);
        }
        const auto time_point_before_insert = chrono::steady_clock::now();
        graph.dijkstra(0);
        const auto time_point_after_insert = chrono::steady_clock::now();
        time_diff += time_point_after_insert - time_point_before_insert;
        const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
        cout << time_elapsed_ns_insert << endl;

        input_file.close();

        // Открываем файл для записи и вносим полученые данные
        auto output_file = fstream(output_path, ios::app);
        output_file << folder << "," << file << "," << i << "," << time_elapsed_ns_insert << endl;
        output_file.close();
      }
    }
  }
  return 0;
}