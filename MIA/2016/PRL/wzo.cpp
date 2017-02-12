#include<iostream>

using namespace std;

const int MAX_SIZE = 110;

int caseCount;
int perlCount;
int amountArray[MAX_SIZE];
int costArray[MAX_SIZE];
int currentSum;

void updatePerl(int num) {
	int minSum = currentSum;
	int minIndex = -1;
	for(int i = num + 1; i < perlCount; i++) {
		int newSum = currentSum;
		newSum -= (amountArray[num] + 10) * costArray[num];
		newSum += (amountArray[num] * costArray[i]);
		if(newSum < minSum) {
			minSum = newSum;
			minIndex = i;
		}
	}	
	if(minSum < currentSum) {
		amountArray[minIndex] += amountArray[num];
		amountArray[num] = costArray[num] = 0;
		currentSum = minSum;
	}
}

void countResult() {
	currentSum = 0;
	for(int i = 0; i < perlCount; i++) {
		currentSum += (amountArray[i] + 10) * costArray[i];
	}	
	for(int i = 0; i + 1 < perlCount; i++) {
		updatePerl(i);
	}
	cout << currentSum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> caseCount;
	for(int i = 0; i < caseCount; i++) {
		cin >> perlCount;
		for(int j = 0; j < perlCount; j++) {
			cin >> amountArray[j] >> costArray[j];
		}
		countResult();
	}	
	return 0;
}
