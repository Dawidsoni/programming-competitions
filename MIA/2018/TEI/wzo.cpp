#include <iostream>
using namespace std;

typedef long long int LType;
LType n, m;

LType countResult() {
	if(n > m) {
		return 0;
	}
	LType result = 1;
	for(LType i = n + 1; i <= m; i++) {
		if(i % 10 == 0) {
			return 0;
		}
		result *= i;
		result %= 10;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cout << countResult() << "\n";
	return 0;
}
