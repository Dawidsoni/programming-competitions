#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Friend {
public:
  int cost, monitorCount, problemCount, problemList;

  friend bool operator<(const Friend & f1, const Friend & f2) {
    return (f1.monitorCount < f2.monitorCount);
  }

  void addProblem(int num) {
    problemList += (1 << (num - 1));
  }
};

typedef unsigned long long int LType;

int friendCount, problemCount, monitorCost, problemNum;
Friend fList[110];
LType result[1 << 21];
LType minResult;

void initResult() {
  minResult = ULLONG_MAX;
  for(int i = 1; i < (1 << problemCount); i++) {
    result[i] = ULLONG_MAX;
  }
}

void updateResult(int num) {
  LType curResult = result[(1 << problemCount) - 1];
  if(curResult == ULLONG_MAX) {
    return;
  }
  LType fullMonitorCost = (LType)monitorCost * fList[num].monitorCount;
  minResult = min(minResult, curResult + fullMonitorCost);
}

void countResult() {
  for(int i = 0; i < friendCount; i++) {
    for(int j = 1; j < (1 << problemCount); j++) {
      int setNum = j ^ (j & fList[i].problemList);
      if(result[setNum] == ULLONG_MAX) {
        continue;
      }
      LType curRes = result[setNum] + fList[i].cost;
      result[j] = min(result[j], curRes);
    }
    updateResult(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> friendCount >> problemCount >> monitorCost;
  for(int i = 0; i < friendCount; i++) {
    cin >> fList[i].cost >> fList[i].monitorCount >> fList[i].problemCount;
    for(int j = 0; j < fList[i].problemCount; j++) {
      cin >> problemNum;
      fList[i].addProblem(problemNum);
    }
  }
  sort(fList, fList + friendCount);
  initResult();
  countResult();
  if(minResult == ULLONG_MAX) {
    cout << -1 << "\n";
  }else {
    cout << minResult << "\n";
  }
  return 0;
}
