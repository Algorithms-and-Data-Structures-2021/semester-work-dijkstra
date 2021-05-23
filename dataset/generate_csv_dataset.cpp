#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main(int argc, char** argv) {

  // Tip 1: можете передать путь до входного/выходного файла в качестве аргумента
  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  const auto path = string(kDatasetPath);  // конвертация string_view в string
  cout << "Dataset path: " << path << endl;

//  // Пример: чтение набора данных
//  auto input_stream = ifstream(path + "/dataset-example.csv");
//
//  if (input_stream) {
//    int line_number = 0;
//
//    // построчное чтение
//    for (string line; getline(input_stream, line); /* ... */) {
//      auto ss = stringstream(line);  // оборачиваем строку в объект "поток"
//
//      for (string token; getline(ss, token, ','); /* ... */) {
//        cout << "Token: [" << token << "] at line " << line_number << '\n';
//      }
//
//      cout << line << '\n';
//      line_number++;
//    }
//  }

  // Пример: генерация набора данных
  auto output_stream = ofstream(path + "/insert/10/10000.csv", ios::ios_base::trunc);
  const auto seed = chrono::system_clock::now().time_since_epoch().count();
  auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
  auto  ves = uniform_int_distribution(1, 10);  // равновероятное распределение генерируемых чисел
  auto  vershrandom = uniform_int_distribution(1, 10);  // равновероятное распределение генерируемых чисел
  int rebra = 10000;
  float con = 0.4;
  float noc = 0.6;
  int vershini =  (rebra * con);
  auto versh = uniform_int_distribution(0, vershini-1);
  int colvoreber = rebra;
  int nocColvoreber = (noc * colvoreber);
  if (output_stream) {

    output_stream << vershini  << " ";
    output_stream << colvoreber;
    output_stream << endl;
    for(int i = 0; i< vershini; i++){
      output_stream << i << " " << (i + 1)<< " " << ves(engine) << endl;
    }

    for (int counter = 0; counter <nocColvoreber ; counter++) {
      output_stream << versh(engine) << " " << versh(engine) << " " << ves(engine) << endl;
    }
  }

  return 0;
}