//Dawid Wegner
//279743
//KLO

#include<iostream>

using namespace std;

typedef long long int LType;

LType nTest, a, b, m;

LType solve() { 
	LType result = 1;
	while(b >= 1) {
		if(b % 2 == 1) {
			result *= a;
		}
		a = a * a;
		b /= 2;
		a %= m;
		result %= m;
	}	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> a >> b >> m;
		cout << solve() << "\n";
	}	
	return 0;
}
