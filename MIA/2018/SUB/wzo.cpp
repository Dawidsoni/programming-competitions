#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 55, INF = 100000000;

int cowCount;
int cow[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

void initResult() {
	for(int i = 0; i < MAX_SIZE; i++) {
		for(int j = 0; j < MAX_SIZE; j++) {
			for(int k = 0; k < MAX_SIZE; k++) {
				for(int l = 0; l < MAX_SIZE; l++) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
}

int countResult(int fromInd, int toInd, int minElem, int maxElem) {
	if(dp[fromInd][toInd][minElem][maxElem] != -1) {
		return dp[fromInd][toInd][minElem][maxElem];
	}
	if(minElem > maxElem) {
		return -INF;
	}
	if(fromInd > toInd) {
		return 0;
	}
	if(fromInd == toInd && minElem <= cow[fromInd] && maxElem >= cow[toInd]) {
		return 1;
	}else if(fromInd == toInd) {
		return 0;
	}
	int result = 0;
	result = max(result, countResult(fromInd + 1, toInd, minElem, maxElem));
	result = max(result, countResult(fromInd, toInd - 1, minElem, maxElem));
	if(cow[fromInd] >= minElem) {
		result = max(result, countResult(fromInd + 1, toInd, cow[fromInd], maxElem) + 1);
	}
	if(cow[toInd] <= maxElem) {
		result = max(result, countResult(fromInd, toInd - 1, minElem, cow[toInd]) + 1);
	}
	if(cow[fromInd] <= maxElem) {
		result = max(result, countResult(fromInd + 1, toInd - 1, minElem, cow[fromInd]) + 1);
	}
	if(cow[toInd] >= minElem) {
		result = max(result, countResult(fromInd + 1, toInd - 1, cow[toInd], maxElem) + 1);
	}
	if(cow[fromInd] <= maxElem && cow[toInd] >= minElem) {
		result = max(result, countResult(fromInd + 1, toInd - 1, cow[toInd], cow[fromInd]) + 2);
	}
	dp[fromInd][toInd][minElem][maxElem] = result;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> cowCount;
	for(int i = 0; i < cowCount; i++) {
		cin >> cow[i];
	}
	initResult();
	countResult(0, cowCount - 1, 0, 51);
	cout << dp[0][cowCount - 1][0][51] << "\n";
	return 0;
}
