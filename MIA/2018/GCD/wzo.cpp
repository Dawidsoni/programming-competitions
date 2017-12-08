#include <iostream>
using namespace std;

const int MAX_SIZE = 1000010;
typedef long long int LType;

int num;
LType result[MAX_SIZE];
LType eulerTot[MAX_SIZE];

void countEulerTot() {
	for(int i = 1; i < MAX_SIZE; i++) {
		eulerTot[i] = i;
	}
	for(int i = 2; i < MAX_SIZE; i++) {
		if(eulerTot[i] != i) {
			continue;
		}
		eulerTot[i] = i - 1;
		for(int j = 2 * i; j < MAX_SIZE; j += i) {
			eulerTot[j] = (eulerTot[j] / i) * (i - 1);
		}
	}
}

void countResult() {
	countEulerTot();
	for(int i = 1; i < MAX_SIZE; i++) {
		for(int j = 2; i * j < MAX_SIZE; j++) {
			result[i * j] += eulerTot[j] * i;
		}
	}
	for(int i = 1; i < MAX_SIZE; i++) {
		result[i] += result[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	countResult();
	while(true) {
		cin >> num;
		if(num == 0) {
			break;
		}
		cout << result[num] << "\n";
	}
	return 0;
}
