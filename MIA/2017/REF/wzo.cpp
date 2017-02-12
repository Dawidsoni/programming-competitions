#include <iostream>
using namespace std;

int count, result;

void countResult(int count, int factor) {
	for(int i = factor; i * i <= count; i++) {
		if(count % i == 0) {
			countResult(count / i, i);
		}
	}
	result++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> count;
	countResult(count, 2);
	result--;
	cout << result << "\n";
	return 0;		
}
