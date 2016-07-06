#include<iostream>
#include<vector>
#include <stdlib.h> 

using namespace std;

typedef long long int LType;

const int MAX_SIZE = 210000;
const int MOD_P = 9999991;

int keyCount;
int keyList[MAX_SIZE];
vector<int> hashList[MAX_SIZE];
int colMultList[MAX_SIZE];
int multiplier;

int randomInt(int fromInd, int toInd) {
	return (rand() % (toInd - fromInd + 1)) + fromInd; 		
}

int getHash(int key, int keyCount, int multiplier) {
	return ((((LType)multiplier) * key) % MOD_P) % keyCount;
}

void randomMultiplier() {
	multiplier = randomInt(1, MOD_P - 1);
	for(int i = 0; i < keyCount; i++) {
		hashList[i].clear();
	}
	for(int i = 0; i < keyCount; i++) {
		int hash = getHash(keyList[i], keyCount, multiplier);
		hashList[hash].push_back(keyList[i]);
	}	
}

bool randomColumn(int num) {
	colMultList[num] = randomInt(1, MOD_P - 1);
	int colSize = hashList[num].size() * hashList[num].size();
	bool* isHash = new bool[colSize];	
	for(int i = 0; i < colSize; i++) {
		isHash[i] = false;
	}
	for(int i = 0; i < (int)hashList[num].size(); i++) {
		int hash = getHash(hashList[num][i], colSize, colMultList[num]);
		if(isHash[hash]) {
			return false;
		}
		isHash[hash] = true;
	}
	return true;
}

void randomColumns() {
	for(int i = 0; i < keyCount; i++) {
		if(hashList[i].size() > 1) {
			while(randomColumn(i) == false) {}
		}
	}
}

int keysSum() {
	int result = 0;
	for(int i = 0; i < keyCount; i++) {
		int colSize = hashList[i].size() * hashList[i].size();
		result += max(1, colSize);
	}
	return result;
}

int main() {
	srand (time(NULL));
	ios_base::sync_with_stdio(false);
	cin >> keyCount;
	for(int i = 0; i < keyCount; i++) {
		cin >> keyList[i];
	}	
	while(true) {
		randomMultiplier();
		if(keysSum() <= 3 * keyCount) {
			break;
		}
	}
	randomColumns();
	cout << keyCount << "\n";
	for(int i = 0; i < keyCount; i++) {
		int colSize = hashList[i].size() * hashList[i].size();
		cout << max(1, colSize) << " ";
	}
	cout << "\n" << multiplier << "\n";
	for(int i = 0; i < keyCount; i++) {
		cout << colMultList[i] << " ";
	}
	cout << "\n";
	return 0;
}
