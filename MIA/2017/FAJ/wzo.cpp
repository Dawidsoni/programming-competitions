#include <iostream>
#include <set>
using namespace std;

const int MAX_SIZE = 510000;
const int TREE_SIZE = 1 << 19;

int arrCount, queryCount, fromIndQuery, toIndQuery;
int arr[MAX_SIZE];
int minTree[TREE_SIZE * 2];
int maxTree[TREE_SIZE * 2];
int dubArr[MAX_SIZE];

void buildTree() {
  for(int i = 0; i < arrCount; i++) {
    minTree[i + TREE_SIZE] = arr[i];
    maxTree[i + TREE_SIZE] = arr[i];
  }
  for(int i = TREE_SIZE - 1; i >= 1; i--) {
    minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
    maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
  }
}

int getMin(int fromInd, int toInd) {
  fromInd += TREE_SIZE;
  toInd += TREE_SIZE;
  int result = min(minTree[fromInd], minTree[toInd]);
  while(fromInd / 2 < toInd / 2) {
    if(fromInd % 2 == 0) {
      result = min(result, minTree[fromInd + 1]);
    }
    if(toInd % 2 == 1) {
      result = min(result, minTree[toInd - 1]);
    }
    fromInd /= 2;
    toInd /= 2;
  }
  return result;
}

int getMax(int fromInd, int toInd) {
  fromInd += TREE_SIZE;
  toInd += TREE_SIZE;
  int result = max(maxTree[fromInd], maxTree[toInd]);
  while(fromInd / 2 < toInd / 2) {
    if(fromInd % 2 == 0) {
      result = max(result, maxTree[fromInd + 1]);
    }
    if(toInd % 2 == 1) {
      result = max(result, maxTree[toInd - 1]);
    }
    fromInd /= 2;
    toInd /= 2;
  }
  return result;
}

void buildDub() {
  multiset<int> dubSet;
  int rightInd = 0;
  for(int i = 0; i < arrCount; i++) {
    if(i > 0) {
      if(dubSet.count(arr[i - 1]) > 1) {
        rightInd++;
        dubSet.erase(arr[i - 1]);
        dubSet.insert(arr[i - 1]);        
      }else {
        dubSet.erase(arr[i - 1]);
      }
    }
    if(rightInd < arrCount && dubSet.count(arr[rightInd]) > 1) {
      dubArr[i] = rightInd;
      continue;
    }
    while(rightInd < arrCount) {
      dubSet.insert(arr[rightInd]);
      if(dubSet.count(arr[rightInd]) > 1) {
        break;
      }
      rightInd++;
    }
    dubArr[i] = rightInd;
  }
}

void readInput() {
  ios_base::sync_with_stdio(false);
  cin >> arrCount >> queryCount;
  for(int i = 0; i < arrCount; i++) {
    cin >> arr[i];
  }
}

bool solve(int fromInd, int toInd) {
  int maxVal = getMax(fromInd, toInd);
  int minVal = getMin(fromInd, toInd);
  if(maxVal - minVal != toInd - fromInd) {
    return false;
  }
  return (dubArr[fromInd] > toInd);
}

void ansQuery() {
  for(int i = 0; i < queryCount; i++) {
    cin >> fromIndQuery >> toIndQuery;
    fromIndQuery--;
    toIndQuery--;
    if(solve(fromIndQuery, toIndQuery)) {
      cout << "TAK\n";
    }else {
      cout << "NIE\n";
    }
  }
}

int main() {
  readInput();
  buildTree();
  buildDub();
  ansQuery();
  return 0;
}
