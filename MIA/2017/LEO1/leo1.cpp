#include <iostream>
using namespace std;

typedef long long int LType;
LType num;
LType MOD_P = 1000000000;

class Matrix {
public:
  LType arr[4][4];
};

Matrix mult(Matrix &m1, Matrix &m2) {
  Matrix result;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      result.arr[i][j] = 0;
      for(int k = 0; k < 4; k++) {
        result.arr[i][j] += (m1.arr[i][k] * m2.arr[k][j]);
        result.arr[i][j] %= MOD_P;
      }
    }
  }
  return result;
}

Matrix getIdMatrix() {
  Matrix result;
  result.arr[0][0] = 1;
  result.arr[0][1] = 0;
  result.arr[0][2] = 0;
  result.arr[0][3] = 0;
  result.arr[1][0] = 0;
  result.arr[1][1] = 1;
  result.arr[1][2] = 0;
  result.arr[1][3] = 0;
  result.arr[2][0] = 0;
  result.arr[2][1] = 0;
  result.arr[2][2] = 1;
  result.arr[2][3] = 0;
  result.arr[3][0] = 0;
  result.arr[3][1] = 0;
  result.arr[3][2] = 0;
  result.arr[3][3] = 1;
  return result;
}

Matrix getBaseMatrix() {
  Matrix result;
  result.arr[0][0] = 1;
  result.arr[0][1] = 1;
  result.arr[0][2] = 0;
  result.arr[0][3] = 0;
  result.arr[1][0] = 0;
  result.arr[1][1] = 1;
  result.arr[1][2] = 1;
  result.arr[1][3] = 1;
  result.arr[2][0] = 0;
  result.arr[2][1] = 1;
  result.arr[2][2] = 0;
  result.arr[2][3] = 0;
  result.arr[3][0] = 0;
  result.arr[3][1] = 0;
  result.arr[3][2] = 0;
  result.arr[3][3] = 1;
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
  return (mtx.arr[0][0] + mtx.arr[0][1] + mtx.arr[0][2] + mtx.arr[0][3]) % MOD_P;
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
