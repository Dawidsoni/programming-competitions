#include <iostream>
using namespace std;

int n, m;

int firstType(int n) {
  return 2 * (n / 4) + min(n % 4, 2);
}

int secondType(int n) {
  return 2 * (n / 4) + max((n % 4) - 2, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int result = firstType(n) * firstType(m) + secondType(n) * secondType(m);
  cout << result << "\n";
  return 0;
}
