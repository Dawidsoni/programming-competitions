#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 510000;

int length, result;
int array[MAX_SIZE];
int tmpArray[MAX_SIZE];
int tmpArrayCounter;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> length;
	for(int i = 0; i < length; i++) {
		cin >> array[i];
	}
	sort(&array[0], &array[length]);
	for(int i = 0; i < length; i++) {
		tmpArray[i] = array[i];
	}
	for(int i = 0; i < length; i++) {
		while(tmpArrayCounter < length && tmpArray[tmpArrayCounter] <= array[i]) {
			tmpArrayCounter++;
		}
		if(tmpArrayCounter == length) {
			result++;
		}else {
			tmpArrayCounter++;
		}
	}
	
	cout << result;
	return 0;
}
