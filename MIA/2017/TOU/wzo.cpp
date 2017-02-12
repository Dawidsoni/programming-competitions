#include<iostream>
using namespace std;

int teamCount, winCount;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> teamCount >> winCount;
  if(winCount > (teamCount - 1) / 2) {
    cout << -1 << "\n";
    return 0;
  }
  cout << (teamCount * winCount) << "\n";
  for(int i = 1; i <= teamCount; i++) {
    for(int j = 1; j <= winCount; j++) {
      if(i + j > teamCount) {
        cout << i << " " <<  (i + j - teamCount) << "\n";
      }else {
        cout << i << " " << (i + j) << "\n";
      }
    }
  }
  return 0;
}
