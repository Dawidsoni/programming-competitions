#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int MAX_SIZE = 510000;

typedef pair<int, int> IPair;

int arrCount, queryCount;
int arr[MAX_SIZE];
IPair query[MAX_SIZE]; 
stack<int> minStack, maxStack;
vector<int> queryList[MAX_SIZE];
int result[MAX_SIZE];

void killVertex(int pos) {
	
}

void setOffset(int pos, int offset) {
	
}

void setMax(int fromInd, int toInd, int val) {
	
}

int getMax(int fromInd, int toInd) {
	
}

void readData() {
	cin >> arrCount;
	for(int i = 0; i < arrCount; i++) {
		cin >> arr[i];
	}
	cin >> queryCount;
	for(int i = 0; i < queryCount; i++) {
		cin >> query[i].first >> query[i].second;
		query[i].first--;
		query[i].second--;
		queryList[query[i].second].push_back(i);
	}	
}

void updateMaxStack(int pos) {
	while(maxStack.size() > 0 && arr[maxStack.top()] <= arr[pos]) {
		maxStack.pop();
	}
}

void updateMinStack(int pos) {
	while(minStack.size() > 0 && arr[minStack.top()] > arr[pos]) {
		killVertex(minStack.top());
		minStack.pop();
	}
}

void updateResult(int pos) {
	updateMaxStack(pos);
	updateMinStack(pos);
	int fromInd = (maxStack.size() == 0 ? 0 : maxStack.top());
	setOffset(pos, pos);
	setMax(fromInd, pos, pos + 1);
	maxStack.push(pos);
	minStack.push(pos);
}

void updateQueryList(int pos) {
	for(int ind : queryList[pos]) {
		int val = getMax(query[ind].first, query[ind].second);
		result[ind] = max(result[ind], val);
	}
}

void updateResult() {
	for(int i = 0; i < arrCount; i++) {
		updateResult(i);
		updateQueryList(i);
	}	
}

void reverseData() {
	for(int i = 0; i < arrCount; i++) {
		arr[i] = -arr[i];
	}
}

void clearData() {
	maxStack = stack<int>();
	minStack = stack<int>();
	//TODO
}

void printResult() {
	for(int i = 0; i < queryCount; i++) {
		cout << result[i] << "\n";
	}	
}

int main() {
	readData();
	updateResult();
	reverseData();
	clearData();
	updateResult();
	printResult();	
	return 0;
}
