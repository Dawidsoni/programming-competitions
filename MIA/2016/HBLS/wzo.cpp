#include<iostream>
using namespace std;

int pairCount;
int x, y;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> pairCount;
	for(int i = 0; i < pairCount; i++) {
		cin >> x >> y;
		if(x > y) {
			result += (x - y);
		}
	}
	cout << result;
	return 0;
}

