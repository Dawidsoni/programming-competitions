#include <iostream>
using namespace std;

typedef long long LType;
const LType MAX_COWS = 21;
const LType MAX_SIZE = 1100000;
const LType INF = 1000000000LL * 1000000000LL;

LType cowCount, farmerHeight, subsetCount;
LType heightList[MAX_COWS];
LType weightList[MAX_COWS];
LType strengthList[MAX_COWS];
LType result[MAX_SIZE];
LType isPossible[MAX_SIZE];

LType getSubsetWeight(LType subset) {
	LType subsetWeight = 0;
	for(LType i = 0; i < cowCount; i++) {
		if((1 << i) & subset) {
			subsetWeight += weightList[i];
		}
	}
	return subsetWeight;
}

LType getSubsetHeight(LType subset) {
	LType subsetHeight = 0;
	for(LType i = 0; i < cowCount; i++) {
		if((1 << i) & subset) {
			subsetHeight += heightList[i];
		}
	}
	return subsetHeight;
}

void updateSubset(LType setNum) {
	LType totalWeight = getSubsetWeight(setNum);
	for(LType i = 0; i < cowCount; i++) {
		if(((1 << i) & setNum) == 0) {
			continue;
		}
		LType subsetNum = (1 << i) ^ setNum;
		LType subsetWeight = totalWeight - weightList[i];
		if(strengthList[i] < subsetWeight || isPossible[subsetNum] == false) {
			continue;
		}
		isPossible[setNum] = true;
		LType subsetResult = min(result[subsetNum], strengthList[i] - subsetWeight);
		result[setNum] = max(result[setNum], subsetResult);				
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> cowCount >> farmerHeight;
	for(LType i = 0; i < cowCount; i++) {
		cin >> heightList[i] >> weightList[i] >> strengthList[i];
	}
	result[0] = INF;
	isPossible[0] = true;
	for(LType i = 1; i < (1 << cowCount); i++) {
		updateSubset(i);
	}
	LType maxResult = -1;
	for(LType i = 1; i < (1 << cowCount); i++) {
		if(getSubsetHeight(i) >= farmerHeight && isPossible[i]) {
			maxResult = max(maxResult, result[i]);
		}
	}
	if(maxResult < 0) {
		cout << "Mark is too tall\n";
	}else {
		cout << maxResult << "\n";
	}
	return 0;
}
