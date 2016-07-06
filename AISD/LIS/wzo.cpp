#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1100000;

int arrCount;
int arr[MAX_SIZE];
int lis[MAX_SIZE];
int ind[MAX_SIZE];
int pred[MAX_SIZE];
int result[MAX_SIZE];
int maxLength;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> arrCount;
	for(int i = 0; i < arrCount; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < arrCount; i++) {
		int* ptr = lower_bound(lis, lis + maxLength, arr[i]);
		*ptr = arr[i];
		ind[ptr - lis] = i;
		if(ptr != lis) {
			pred[i] = ind[ptr - lis - 1];
		}
		if(ptr == (lis + maxLength)) {
			maxLength++;
		}
	}
	int curInd = ind[maxLength - 1];
	for(int i = 0; i < maxLength; i++) {
		result[i] = arr[curInd];
		curInd = pred[curInd];
	}	
	cout << maxLength << "\n";	
	for(int i = maxLength - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	return 0;
}
