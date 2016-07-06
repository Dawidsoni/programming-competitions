#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int LType;

const int MAX_SIZE = 5100;

int rowSize, colSize;
LType sevenPow[10];
LType result[8][MAX_SIZE];
LType maxResult;
string w1, w2, w3;

void countSevenPow() {
	sevenPow[0] = 1;
	for(int i = 1; i < 10; i++) {
		sevenPow[i] = sevenPow[i - 1] * 7;
	}
}

LType getVal(char sign) {
	return sevenPow[sign - '0'];
}

void countResult(int jump, string dest, LType * r1, LType * r2) {
	for(int i = 0; i < colSize; i++) {
		if(i - jump >= 0) {
			r2[i] = max(r2[i], r1[i - jump] + getVal(dest[i]));
		}
		if(i + jump < colSize) {
			r2[i] = max(r2[i], r1[i + jump] + getVal(dest[i]));
		}
	}
}

void resetResult(LType * result) {
	for(int i = 0; i < colSize; i++) {
		result[i] = 0;
	}
}

void update(bool isLast, int num) {
	int w1Num = (num - 2) & 7;
	int w2Num = (num - 1) & 7;
	int w3Num = (num) & 7;
	resetResult(result[w3Num]);
	countResult(1, w3, result[w1Num], result[w3Num]);
	if(isLast == false) {
		countResult(2, w2, result[w3Num], result[w2Num]);
	}
	w1 = w2;
	w2 = w3;
}

int main() {
	ios_base::sync_with_stdio(false);
	countSevenPow();
	cin >> rowSize >> colSize;
	cin >> w1 >> w2;
	for(int i = 0; i < colSize; i++) {
		result[0][i] = getVal(w1[i]);
	}
	for(int i = 2; i < rowSize; i++) {
		cin >> w3;
		update(i + 1 == rowSize, i);
	}
	int endNum = (rowSize - 1) & 7;
	for(int i = 0; i < colSize; i++) {
		maxResult = max(maxResult, result[endNum][i]);
	}
	cout << maxResult << "\n";
	return 0;
}
