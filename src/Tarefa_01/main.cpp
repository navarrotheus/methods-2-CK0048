#include <iostream>

using namespace std;

int main() {
  int opt;
  cout << "Selecione a opção desejada" << "\n";
  cout << "1) Box Blur" << "\n";
  cout << "2) Gaussian Blur" << "\n";
  cin >> opt;

  switch (opt) {
    case 1:
      printf("1");
      break;
    case 2:
      printf("2");
      break;
  }
}