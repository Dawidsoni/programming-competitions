#include<iostream>
using namespace std;

const int MAX_SIZE = 1100000;

int count, arr[MAX_SIZE], result;
typedef long long int LType;

void countResult() {
	int startInd = 0, endInd = count - 1;
	LType leftSum = 0, rightSum = 0;
	while(startInd < endInd) {
		leftSum = arr[startInd];
		rightSum = arr[endInd];
		while(startInd < endInd && leftSum != rightSum) {
			if(leftSum < rightSum) {
				leftSum += arr[startInd + 1];
				startInd++;
			}else {
				rightSum += arr[endInd - 1];
				endInd--;				
			}
			result++;
		}
		startInd++;
		endInd--;		
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> count;
	for(int i = 0; i < count; i++) {
		cin >> arr[i];
	}
	countResult();
	cout << result << "\n";	
	return 0;
}
