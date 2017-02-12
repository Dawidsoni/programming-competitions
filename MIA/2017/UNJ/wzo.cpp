#include <iostream>
using namespace std;

struct Position {
  int zeroCount, oneCount, twoCount;
};

string pattern;
Position startPos;
int targetCount;
Position targetList[60];
bool isReach[35][35][35];
int result;

Position createPos(int aNum, int bNum, int cNum) {
  Position result;
  result.zeroCount = aNum;
  result.oneCount = bNum;
  result.twoCount = cNum;
  return result;
}

Position getPosition(string pattern) {
  Position result;
  result.zeroCount = result.oneCount = result.twoCount = 0;
  for(int i = 0; i < (int)pattern.size(); i++) {
    if(pattern[i] != '*') {
      continue;
    }
    if(i % 3 == 0) {
      result.zeroCount++;
    }else if(i % 3 == 1) {
      result.oneCount++;
    }else {
      result.twoCount++;
    }
  }
  return result;
}

int getNeighArr(Position pos, Position arr[]) {
  int neighCount = 0;
  if(pos.zeroCount > 0 && pos.oneCount > 0) {
    arr[neighCount++] = createPos(pos.zeroCount - 1, pos.oneCount - 1, pos.twoCount + 1);
  }
  if(pos.oneCount > 0 && pos.twoCount > 0) {
    arr[neighCount++] = createPos(pos.zeroCount + 1, pos.oneCount - 1, pos.twoCount - 1);
  }
  if(pos.twoCount > 0 && pos.zeroCount > 0) {
    arr[neighCount++] = createPos(pos.zeroCount - 1, pos.oneCount + 1, pos.twoCount - 1);
  }
  if(pos.zeroCount > 0) {
    arr[neighCount++] = createPos(pos.zeroCount - 1, pos.oneCount + 1, pos.twoCount + 1);
  }
  if(pos.oneCount > 0) {
    arr[neighCount++] = createPos(pos.zeroCount + 1, pos.oneCount - 1, pos.twoCount + 1);
  }
  if(pos.twoCount > 0) {
    arr[neighCount++] = createPos(pos.zeroCount + 1, pos.oneCount + 1, pos.twoCount - 1);
  }
  return neighCount;
}

bool canBeReached(Position pos) {
  return isReach[pos.zeroCount][pos.oneCount][pos.twoCount];
}

bool isCorrectNeigh(Position pos) {
  return (pos.zeroCount < 35 && pos.oneCount < 35 && pos.twoCount < 35);
}

void dfs(Position pos) {
  isReach[pos.zeroCount][pos.oneCount][pos.twoCount] = true;
//  cout << pos.zeroCount << " " << pos.oneCount << " " << pos.twoCount << "\n";
  Position neighArr[6];
  int neighCount = getNeighArr(pos, neighArr);
  for(int i = 0; i < neighCount; i++) {
    if(canBeReached(neighArr[i]) == false && isCorrectNeigh(neighArr[i])) {
      dfs(neighArr[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> pattern;
  startPos = getPosition(pattern);
  cin >> targetCount;
  for(int i = 0; i < targetCount; i++) {
    cin >> pattern;
    targetList[i] = getPosition(pattern);
  }
  dfs(startPos);
  for(int i = 0; i < targetCount; i++) {
    if(canBeReached(targetList[i])) {
      result++;
    }
  }
  cout << result << "\n";
  return 0;
}
