#include <iostream>
using namespace std;

typedef long long int LType;
LType nTest, n, k, p;

LType getInverse(LType num) {
	LType result = 1;
	int power = p - 2;
	while(power > 0) {
		if(power % 2 == 1) {
			result *= num;
			result %= p;
		}
		num *= num;
		num %= p;
		power /= 2;
	}
	return result;
}

LType solve() {
	LType nominator = 1, denominator = 1;
	for(int i = 2; i <= n; i++) {
		nominator *= i;
		nominator %= p;
	}
	for(int i = 2; i <= k; i++) {
		denominator *= i;
		denominator %= p;
	}
	for(int i = 2; i <= n - k; i++) {
		denominator *= i;
		denominator %= p;
	}
	return (nominator * getInverse(denominator)) % p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> n >> k >> p;
		cout << solve() << "\n";
	}
	return 0;
}
