#include<iostream>
#include<vector>
using namespace std;

const int MAX_SIZE = 1010;
const int TREE_SIZE = 1 << 10;
const int INF = 110000000;

int nPas, nSit, nDiv, readPas;
vector<int> pasArr[MAX_SIZE];
int pasRange[MAX_SIZE][MAX_SIZE];
int sumTree[TREE_SIZE * 2];
int divArr[55][MAX_SIZE];

void initTree() {
	for(int i = 0; i < TREE_SIZE * 2; i++) {
		sumTree[i] = 0;
	}	
}

int getSum(int fromInd, int toInd) {
	fromInd += TREE_SIZE;
	toInd += TREE_SIZE;
	int result = sumTree[fromInd];
	if(fromInd != toInd) {
		result += sumTree[toInd];
	}
	while(fromInd / 2 < toInd / 2) {
		if(fromInd % 2 == 0) {
			result += sumTree[fromInd + 1];
		}
		if(toInd % 2 == 1) {
			result += sumTree[toInd - 1];
		}		
		fromInd /= 2;
		toInd /= 2;
	}
	return result;
}

void updateSum(int ind, int amount) {
	ind += TREE_SIZE;
	while(ind > 0) {
		sumTree[ind] += amount;
		ind /= 2;
	}	
}

void fillRange(int stInd) {
	int errSum = 0;
	for(int i = stInd; i <= nSit; i++) {
		for(int j = 0; j < (int)pasArr[i].size(); j++) {
			errSum += getSum(0, pasArr[i][j]);
		}
		pasRange[stInd][i] = errSum;
		//cout << stInd << ", " << i << ": " << errSum << "\n";
		for(int j = 0; j < (int)pasArr[i].size(); j++) {
			updateSum(pasArr[i][j], 1);
		}
	}
}

void findDiv(int nDiv, int prefInd) {
	for(int i = nDiv; i <= prefInd; i++) {
		int val = divArr[nDiv - 1][i - 1] + pasRange[i][prefInd];
		//scout << "(" << i << ", " << val << "), ";
		divArr[nDiv][prefInd] = min(divArr[nDiv][prefInd], val);
	}
}

void findDiv() {
	for(int i = 1; i <= nSit; i++) {
		divArr[0][i] = pasRange[1][i];
		//cout << "0, " << i << ": " << divArr[0][i] << "\n";
	}	
	for(int i = 1; i < nDiv; i++) {
		for(int j = 1; j <= nSit; j++) {
			divArr[i][j] = INF;
			findDiv(i, j);
			//cout << i << ", " << j << ": " << divArr[i][j] << "\n";
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nPas >> nSit >> nDiv;
	for(int i = 0; i < nPas; i++) {
		cin >> readPas;
		pasArr[readPas].push_back(i);
	}
	for(int i = 1; i <= nSit; i++) {
		initTree();
		fillRange(i);
	}
	//cout << "\n\n\n";
	findDiv();
	cout << divArr[nDiv - 1][nSit];
	return 0;
}
