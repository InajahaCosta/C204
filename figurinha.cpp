#include <iostream>
using namespace std;

// função para calcular o maior divisor comum
int mdc(int F1, int F2) {

  int maior_divisor_comum = 1; // iniciando com 1

  for (int i = 1; i <= F1 && i <= F2; i++) {
    if (F1 % i == 0 && F2 % i == 0) {
      maior_divisor_comum = i;
    }
  }

  return maior_divisor_comum;
}

int main() {
  int N;
  int F1, F2;

  cin >> N;
  if (N >= 1 && N <= 3000) {
    for (int i = 0; i < N; i++) {
      cin >> F1 >> F2;
      if (F1 >= 1 && F1 <= 1000 && F2 >= 1 && F2 <= 1000) {
        cout << mdc(F1, F2) << endl;
      }
    }
  }

  return 0;
}
