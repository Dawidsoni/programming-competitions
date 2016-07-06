//Dawid Wegner
//279743
//KLO

#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 1100000;

int nNumber, nQuery;
int numList[MAX_SIZE];

int answer(int query) {
	return (&numList[nNumber] - lower_bound(&numList[0], &numList[nNumber], query));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nNumber;
	for(int i = 0; i < nNumber; i++) {
		cin >> numList[i];
	}
	cin >> nQuery;
	for(int i = 0; i < nQuery; i++) {
		int query;
		cin >> query;
		cout << answer(query) << " ";
	}	
	return 0;
}
