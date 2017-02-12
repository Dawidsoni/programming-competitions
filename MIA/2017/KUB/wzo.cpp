#include<iostream>
using namespace std;

const int MAX_SIZE = 1100000;

int nCup, nMove, startCup;
bool isPossible[MAX_SIZE];
int fromInd, toInd;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nCup >> nMove >> startCup;
	isPossible[startCup] = true;
	for(int i = 0; i < nMove; i++) {
		cin >> fromInd >> toInd;
		if(isPossible[fromInd]) {
			isPossible[toInd] = true;
		}else if(isPossible[toInd]) {
			isPossible[fromInd] = true;
		}
	}
	for(int i = 1; i <= nCup; i++) {
		if(isPossible[i]) {
			cout << "TAK\n";
		}else {
			cout << "NIE\n";
		}
	}	
	return 0;
}
