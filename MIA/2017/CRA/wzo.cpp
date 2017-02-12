#include <iostream>
using namespace std;

const int MAX_SIZE = 510000;

int lastCommit[MAX_SIZE];
int commitCount, prevUniq, partNum;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> commitCount;
  for(int i = 0; i < MAX_SIZE; i++) {
    lastCommit[i] = -1;
  }
  for(int i = 0; i < commitCount; i++) {
    cin >> prevUniq >> partNum;
    if(lastCommit[partNum] < prevUniq - 1) {
      cout << "NO\n";
      return 0;
    }
    lastCommit[partNum] = max(lastCommit[partNum], prevUniq);
  }
  cout << "YES\n";
  return 0;
}
