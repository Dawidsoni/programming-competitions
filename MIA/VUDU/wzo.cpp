#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1100000;
const int TREE_SIZE = 1 << 20;

typedef long long int LType;
typedef pair<LType, LType> IPair;

LType arraySize;
LType array[MAX_SIZE];
LType averNumber;
IPair prefList[MAX_SIZE];
LType result;
LType sumArray[MAX_SIZE];
LType tree[TREE_SIZE * 2];

void changeAver() {
	for(int i = 0; i < arraySize; i++) {
		array[i] = array[i] - averNumber;
	}
}

void countPref() {
	prefList[0] = IPair(array[0], 0);
	for(int i = 1; i < arraySize; i++) {
		prefList[i] = IPair(prefList[i - 1].first + array[i], i);
	}
}

LType getSum(LType fromInd, LType toInd) {
	LType result = 0;
	fromInd += TREE_SIZE;
	toInd += TREE_SIZE;
	result += tree[fromInd];
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

void increaseSum(LType index) {
	index += TREE_SIZE;
	while(index > 0) {
		tree[index]++;
		index /= 2;
	}
}

void countResult() {
	for(int i = 0; i < arraySize; i++) {
		result += getSum(0, prefList[i].second - 1);
		increaseSum(prefList[i].second);
		if(prefList[i].first >= 0) {
			result++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> arraySize;
	for(int i = 0; i < arraySize; i++) {
		cin >> array[i];
	}
	cin >> averNumber;
	changeAver();
	countPref();
	sort(prefList, prefList + arraySize);
	countResult();
	cout << result << "\n";
	return 0;
}
