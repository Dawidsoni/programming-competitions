#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 60;
typedef long long int LType;

int arrCount;
string arr[MAX_SIZE];
int count44, count47, count74, count77;
int wordLen;
LType MOD_P = 1234567891;

bool isLucky(string &text) {
  for(int i = 0; i < (int)text.size(); i++) {
    if(text[i] != '4' && text[i] != '7') {
      return false;
    }
  }
  return true;
}

void updateCounter(string &text) {
  char firstL = text[0];
  char lastL = text[text.size() - 1];
  if(isLucky(text) == false) {
    return;
  }
  if(firstL == '4' && lastL == '4') {
    count44++;
  }else if(firstL == '4' && lastL == '7') {
    count47++;
  }else if(firstL == '7' && lastL == '4') {
    count74++;
  }else if(firstL == '7' && lastL == '7') {
    count77++;
  }
}

class Matrix {
public:
  LType arr[2][2];
};

Matrix mult(Matrix &m1, Matrix &m2) {
  Matrix result;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      result.arr[i][j] = 0;
      for(int k = 0; k < 2; k++) {
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
  result.arr[1][0] = 0;
  result.arr[1][1] = 1;
  return result;
}

Matrix getBaseMatrix() {
  Matrix result;
  result.arr[0][0] = count44;
  result.arr[0][1] = count47;
  result.arr[1][0] = count74;
  result.arr[1][1] = count77;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin >> arrCount;
  for(int i = 0; i < arrCount; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + arrCount);
  for(int i = 0; i < arrCount; i++) {
    if(i == 0 || arr[i - 1] != arr[i]) {
      updateCounter(arr[i]);
    }
  }
  cin >> wordLen;
  Matrix mtx = countPow(wordLen);
  LType result = 0;
//  cout << count44 << " " << count47 << " " << count74 << " " << count77 << "\n";
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      result += mtx.arr[i][j];
      result %= MOD_P;
    }
  }
  cout << result << "\n";
  return 0;
}
