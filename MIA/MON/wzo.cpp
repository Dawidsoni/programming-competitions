#include<iostream>
using namespace std;

const int MAX_SIZE = 2100000;

int minPrefPlus[MAX_SIZE];
int minPrefMinus[MAX_SIZE];
int array[MAX_SIZE];
string str;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> str;
	for(int i = 0; i < (int)str.size(); i++) {
		if(str[i] == 'A') {
			array[i] = 1;
		}else {
			array[i] = -2;
		}
	}
	int sum = 0;
	for(int i = 0; i < (int)str.size(); i++) {
		sum += array[i];
		if(sum > 0 && minPrefPlus[sum] == 0) {
			minPrefPlus[sum] = i + 1;
		}else if(sum > 0) {
			result = max(result, i + 1 - minPrefPlus[sum]);
		}else if(sum < 0 && minPrefMinus[-sum] == 0) {
			minPrefMinus[-sum] = i + 1;
		}else if(sum < 0) {
			result = max(result, i + 1 - minPrefMinus[-sum]);			
		}else {
			result = max(result, i + 1);
		}
	}
	cout << result;
	return 0;
}
