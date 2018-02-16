#include <iostream>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 1100000;
const LType P_MOD = 1000000007;

bool isPrime[MAX_SIZE];
LType maxN, result;

void findPrimes() {
	for(int i = 2; i <= maxN; i++) {
		isPrime[i] = true;
	}
	for(int i = 2; i <= maxN; i++) {
		if(isPrime[i] == false) {
			continue;
		}
		isPrime[i] = true;
		for(int j = i * 2; j <= maxN; j += i) {
			isPrime[j] = false;
		}
	}
}

LType twoPower(int destPower) {
	LType sumPow = 1;
	LType powerNum = 2;
	while(destPower > 0) {
		if(destPower % 2 == 1) {
			sumPow *= powerNum;
			sumPow %= P_MOD;
		}
		powerNum *= powerNum;
		powerNum %= P_MOD;
		destPower /= 2;
	}
	return sumPow;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> maxN;
	findPrimes();
	int currentPower = 0;
	for(int i = 2; i <= maxN; i++) {
		if(isPrime[i]) {
			currentPower++;
		}
		result += twoPower(currentPower - 1);
		result %= P_MOD;
	}
	cout << result << "\n";
	return 0;
}
