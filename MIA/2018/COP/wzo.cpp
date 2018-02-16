#include <iostream>
#include <math.h>
using namespace std;

const int MAX_SIZE = 1100000;
typedef long long int LType;

LType numListSize, num;
LType numCountList[MAX_SIZE];
bool isComposite[MAX_SIZE];
LType primeCount[MAX_SIZE];
LType mf[MAX_SIZE];
LType result;

void countMobiusFunction() {
	for(LType i = 1; i < MAX_SIZE; i++) {
		mf[i] = 1;
	}
	for(LType i = 2; i < MAX_SIZE; i++) {
		if(isComposite[i]) {
			continue;
		}
		mf[i] = -1;
		for(LType j = i * 2; j < MAX_SIZE; j += i) {
			isComposite[j] = true;
			primeCount[j]++;
		}
		for(LType j = i * i; j < MAX_SIZE; j += i * i) {
			mf[j] = 0;
		}
	}
	for(LType i = 2; i < MAX_SIZE; i++) {
		if(primeCount[i] % 2 == 1 && mf[i] != 0) {
			mf[i] = -1;
		}
	}
}

void countResult() {
	for(LType i = 1; i < MAX_SIZE; i++) {
		if(mf[i] == 0) {
			continue;
		}
		LType mSum = 0;
		for(LType j = 1; i * j < MAX_SIZE; j++) {
			mSum += numCountList[i * j];
		}
		result += ((mSum * (mSum - 1) * (mSum - 2)) / 6) * mf[i]; 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> numListSize;
	for(LType i = 0; i < numListSize; i++) {
		cin >> num;
		numCountList[num]++;
	}
	countMobiusFunction();
	countResult();
	cout << result << "\n";
	return 0;
}
