#include <iostream>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 1000010;
const int MOD_P = 1000003;

int nTest, nNum, lNum, rNum;
int fac[MAX_SIZE];
int baseCounter;
int upBase[MAX_SIZE];
int downBase[MAX_SIZE];

void countFac() {
	fac[0] = 1;
	for(int i = 1; i < MAX_SIZE; i++) {
		fac[i] = ((LType)fac[i - 1] * i) % MOD_P;
	}
}

int countBase(int num, int arr[]) {
	int counter = 0;
	while(num > 0) {
		arr[counter] = (num % MOD_P);
		num /= MOD_P;
		counter++;
	}
	baseCounter = max(counter, baseCounter);
	return counter;
}

LType getInv(LType num) {
	int pot = MOD_P - 2;
	LType result = 1;
	while(pot > 0) {
		if(pot % 2 == 1) {
			result = (result * num) % MOD_P;
		}
		num = (num * num) % MOD_P;
		pot /= 2;
	}
	return result;	
}

void countResult() {
	int result = 1;
	for(int i = 0; i < baseCounter; i++) {
		if(downBase[i] > upBase[i]) {
			result = 0;
		}		
		result = ((LType)result * fac[upBase[i]]) % MOD_P;
		int down = ((LType)fac[downBase[i]] * fac[upBase[i] - downBase[i]]) % MOD_P;
		int invDown = getInv(down);
		result = ((LType)result * invDown) % MOD_P;
	}
	if(result == 0) {
		result = MOD_P - 1;
	}else {
		result--;
	}
	cout << result << "\n";
}

void solve() {
	int upNum = nNum + rNum - lNum + 1;
	int downNum = nNum;
	countBase(upNum, upBase);
	countBase(downNum, downBase);
	countResult();
}

int main() {
	ios_base::sync_with_stdio(false);
	countFac();
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> nNum >> lNum >> rNum;
		solve();
	}
	return 0;
}
