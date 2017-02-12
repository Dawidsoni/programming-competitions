#include <iostream>
using namespace std;

typedef long long int LType;
LType num;
LType MOD_P = 1000000000;

class Matrix {
public:
  LType arr[7][7];
};

Matrix mult(Matrix &m1, Matrix &m2) {
  Matrix result;
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 7; j++) {
      result.arr[i][j] = 0;
      for(int k = 0; k < 7; k++) {
        result.arr[i][j] += (m1.arr[i][k] * m2.arr[k][j]);
        result.arr[i][j] %= MOD_P;
      }
    }
  }
  return result;
}

Matrix getIdMatrix() {
  Matrix result;
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 7; j++) {
      if(i == j) {
        result.arr[i][j] = 1;
      }else {
        result.arr[i][j] = 0;
      }
    }
  }
  return result;
}

Matrix getBaseMatrix() {
  LType arr[7][7] = {
    {1, 1, 0, 0, 0, 0, 0},
    {0, 1, 2, 1, 2, 2, 1},
    {0, 1, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1}
  };
  Matrix result;
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 7; j++) {
      result.arr[i][j] = arr[i][j];
    }
  }
  return result;
}

Matrix countPow(LType num) {
  Matrix result = getIdMatrix();
  Matrix base = getBaseMatrix();
  while(num > 0) {
    if(num % 2 == 1) {
      result = mult(result, base);
    }
    base = mult(base, base);
    num /= 2;
  }
  return result;
}

LType solve() {
  Matrix mtx = countPow(num);
  LType result = 0;
  for(int i = 0; i < 7; i++) {
    result += mtx.arr[0][i];
  }
  return result % MOD_P;
}

LType getNmberDigits(LType num) {
  LType digits = 1;
  while(num >= 10) {
    num /= 10;
    digits++;
  }
  return digits;
}

void printResult(LType num) {
  LType digits = getNmberDigits(num);
  for(int i = 0; i < 9 - digits; i++) {
    cout << '0';
  }
  cout << num << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  for(int i = 0; i < 30; i++) {
    cin >> num;
    printResult(solve());
  }
  return 0;
}
