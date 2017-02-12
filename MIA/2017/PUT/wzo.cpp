#include<iostream>

using namespace std;

const int MAX_SIZE = 1100;

int count, arr[MAX_SIZE];
int maxSum, result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> count >> maxSum;
	for(int i = 0; i < count; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < count; i++) {
		int j = i;
		int sum = 0, eatenCount = 0;
		while(j < count) {
			if(sum + arr[j] <= maxSum) {
				sum += arr[j];
				eatenCount++;
			}
			j++;
		}
		result = max(result, eatenCount);
	}
	cout << result << "\n";	
	return 0;
}
