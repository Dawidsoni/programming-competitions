#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 210000;

int numCount, intervalCount, intervalLength;
int numList[MAX_SIZE];

bool isOk(int maxDiff) {
	int currInterval = 0;
	for(int i = 0; (i + intervalLength - 1) < numCount; i++) {
		if(numList[i + intervalLength - 1] - numList[i] <= maxDiff) {
			currInterval++;
			i += (intervalLength - 1);
		}
	}
	return (currInterval >= intervalCount);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> numCount >> intervalCount >> intervalLength;
	for(int i = 0; i < numCount; i++) {
		cin >> numList[i];
	}
	sort(numList, numList + numCount);
	int fromInd = 0, toInd = 1000000000;
	while(fromInd < toInd) {
		int aver = (fromInd + toInd)/2;
		if(isOk(aver)) {
			toInd = aver;
		}else {
			fromInd = aver + 1;
		}		
	}
	cout << toInd;
	return 0;
}
