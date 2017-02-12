#include <iostream>
using namespace std;

int testCount, pCount, a, b;

void printResult() {
	int result = 1;
	for(int i = 2; i <= pCount; i++) {
		result ^= i;
	}
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> testCount;
	for(int i = 0; i < testCount; i++) {
		cin >> pCount;
		for(int j = 0; j < pCount; j++) {
			cin >> a >> b;
		}
		printResult();
	}
	return 0;
}
