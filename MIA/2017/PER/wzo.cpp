#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100010;
const int MOD_P = 1000000007;

typedef long long int LType;

int arrCount, numPer;
int arr[MAX_SIZE];
int fac[MAX_SIZE][50];
LType result;

void initFac() {
	for(int i = 1; i <= arrCount; i++) {
		fac[i][0] = 1;
	}
	fac[0][1] = 1;
	for(int i = 1; i < numPer; i++) {
		for(int j = i; j < arrCount; j++) {
			LType sum = (LType)fac[j - 1][i - 1] + fac[j - 1][i];			
			fac[j][i] = sum % MOD_P;
//			cout << "j = " << j << ", i = " << i << "\n";
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> arrCount >> numPer;
	for(int i = 0; i < arrCount; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + arrCount);
	initFac();	
	for(int i = arrCount - 1; i >= numPer - 1; i--) {
		LType sum = (LType)fac[i][numPer - 1] * arr[i];
		sum %= MOD_P;
		result += sum;		
	}
	result %= MOD_P;
	cout << result << "\n";
}
