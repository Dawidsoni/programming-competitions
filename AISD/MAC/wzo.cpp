#include<iostream>
#include<limits.h>

using namespace std;

const int MAX_SIZE = 210;

typedef long long int LType;
typedef pair<LType, LType> IPair;

LType nTest;
LType nMatrix, prevDim, dim;
LType result[MAX_SIZE][MAX_SIZE];

IPair matrixArray[MAX_SIZE];

void updateResult(LType fromInd, LType toInd) {
	result[fromInd][toInd] = LONG_LONG_MAX;
	for(LType i = fromInd; i < toInd; i++) {
		LType curResult = result[fromInd][i] + result[i + 1][toInd];
		curResult += (matrixArray[fromInd].first * matrixArray[i].second * matrixArray[toInd].second);
		result[fromInd][toInd] = min(result[fromInd][toInd], curResult);		
	}
}

void solve() {	
	for(LType i = 2; i <= nMatrix; i++) {
		for(LType j = 0; (j + i - 1) < nMatrix; j++) {
			updateResult(j, j + i - 1);
		}		
	}
	cout << result[0][nMatrix - 1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(LType i = 0; i < nTest; i++) {
		cin >> nMatrix;
		cin >> dim;
		for(LType j = 1; j < nMatrix + 1; j++) {
			prevDim = dim;
			cin >> dim;
			matrixArray[j - 1] = IPair(prevDim, dim);
		}	
		solve();	
	}
	return 0;
}
