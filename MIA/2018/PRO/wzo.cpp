#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 110000;
const int TREE_SIZE = (1 << 17);
typedef pair<int, int> IPair;

int nodeCount, val, parent, prefNum;
int tree[TREE_SIZE * 2];
IPair nodeVal[MAX_SIZE];
int fromIntervalMap[MAX_SIZE];
int toIntervalMap[MAX_SIZE];
vector<int> childList[MAX_SIZE];
int resultList[MAX_SIZE];

void assignInterval(int node) {
	fromIntervalMap[node] = prefNum;	
	for(int i = 0; i < (int)childList[node].size(); i++) {
		assignInterval(childList[node][i]);
	}
	toIntervalMap[node] = prefNum;
	prefNum++;
}

void addVal(int node) {
	node += TREE_SIZE;
	while(node > 0) {
		tree[node]++;
		node /= 2;
	}
}

int getSum(int fromInd, int toInd) {
	fromInd += TREE_SIZE;
	toInd += TREE_SIZE;
	int result = tree[fromInd];
	if(fromInd != toInd) {
		result += tree[toInd];
	}
	while(fromInd / 2 < toInd / 2) {
		if(fromInd % 2 == 0) {
			result += tree[fromInd + 1];
		}
		if(toInd % 2 == 1) {
			result += tree[toInd - 1];
		}
		fromInd /= 2;
		toInd /= 2;
	}
	return result;
}

void retrieveNode(int nodeNum) {
	resultList[nodeNum] = getSum(fromIntervalMap[nodeNum], toIntervalMap[nodeNum]);
	addVal(toIntervalMap[nodeNum]);
}

void countResult() {
	for(int i = 0; i < nodeCount; i++) {
		int nodeNum = nodeVal[i].second;
		retrieveNode(nodeNum);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nodeCount;
	for(int i = 0; i < nodeCount; i++) {
		cin >> val;
		nodeVal[i] = IPair(-val, i + 1);
	}
	sort(nodeVal, nodeVal + nodeCount);
	for(int node = 2; node <= nodeCount; node++) {
		cin >> parent;
		childList[parent].push_back(node);
	}	
	assignInterval(1);
	countResult();
	for(int i = 1; i <= nodeCount; i++) {
		cout << resultList[i] << "\n";
	}
	return 0;
}
