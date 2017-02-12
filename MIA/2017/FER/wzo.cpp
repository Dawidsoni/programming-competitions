#include<iostream>
using namespace std;

const int MAX_SIZE = 32;

typedef long long int LType;

int count;
LType arr[MAX_SIZE][MAX_SIZE];
LType result;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> count;
	for(int i = 0; i < count; i++) {
		for(int j = i; j < count; j++) {
			if(i == 0 && j == 0) {
				arr[i][j] = 1;
			}else if(i == 0) {
				arr[i][j] = arr[i][j - 1] + 1;
			}else {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
			if(j + 1 == count) {
				result += arr[i][j];
			}
		}
	}
	cout << result;	
	return 0;
}
