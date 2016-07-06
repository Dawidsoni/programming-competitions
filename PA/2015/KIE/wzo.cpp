#include<iostream>
using namespace std;

const int MAX_ODD = 1100000000;
int length, number, minOdd = MAX_ODD, sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> length;
	for(int i = 0; i < length; i++) {
		cin >> number;
		if(number % 2 == 1 && number < minOdd) {
			minOdd = number;
		}
		sum += number;
	}
	if(sum % 2 == 0) {
		cout << sum;
	}else if(minOdd != MAX_ODD && minOdd != sum) {
		cout << (sum - minOdd);
	}else {
		cout << "NIESTETY";
	}	
	return 0;
}
