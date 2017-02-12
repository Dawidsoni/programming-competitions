#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 17;
int count, elem;
vector<int> posVec;
int arr[MAX_SIZE];
bool isC[1 << MAX_SIZE];
int dp[1 << MAX_SIZE];
int iAns, jAns, kAns;

int asInt(vector<int>& posVec) {
	int result = 0;
	for(int i = 0; i < (int)posVec.size(); i++) {
		result *= 2;
		result += posVec[i];
	}
	return result;
}

vector<int> createVec(vector<int>& posVec, int iNum, int jNum, int kNum) {
	vector<int> result;
	result.reserve(count);
	for(int i = 0; i < (int)posVec.size(); i++) {
		if(iNum == i) {
			result.push_back(!posVec[i]);
		}else if(jNum == i && kNum == i) {
			result.push_back(posVec[i]);
		}else if(jNum == i || kNum == i) {
			result.push_back(!posVec[i]);			
		}else {
			result.push_back(posVec[i]);			
		}
	}	
	return result;
}

bool isWin(vector<int>& posVec);

bool getResult(vector<int>& posVec) {
	for(int i = 0; i < (int)posVec.size(); i++) {
		if(posVec[i] == 1) {
			for(int j = i + 1; j < (int)posVec.size(); j++) {
				for(int k = j; k < (int)posVec.size(); k++) {
					vector<int> childVec = createVec(posVec, i, j, k);
					if(!isWin(childVec)) {
						return true;						
					}
				}
			}
		}
	}	
	return false;
}

bool isWin(vector<int>& posVec) {
	int key = asInt(posVec);
	if(isC[key]) {
		return dp[key];
	}
	bool result = getResult(posVec);
	isC[key] = true;
	dp[key] = result;
	return result;
}

void findNum() {
	for(int i = 0; i < count; i++) {
		if(arr[i] == 0) {
			continue;
		}
		for(int j = i + 1; j < count; j++) {
			for(int k = j; k < count; k++) {
				vector<int> childVec = createVec(posVec, i, j, k);
				isWin(childVec);
				int key = asInt(childVec);
				if(dp[key] == 0) {
					iAns = i; 
					jAns = j;
					kAns = k;
					return;
				}
			}
		}			
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> count;
	for(int i = 0; i < count; i++) {
		cin >> elem;
		arr[i] = elem;
		posVec.push_back(elem % 2);
	}		
	if(isWin(posVec)) {
		cout << "YES\n";
		findNum();
		cout << iAns << " " << jAns << " " << kAns << "\n";
	}else {
		cout << "NO\n";
	}
	return 0;
}
