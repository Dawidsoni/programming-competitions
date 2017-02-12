#include<iostream>
using namespace std;

typedef long long int LType;

const int MAX_SIZE = 1100;
const int MOD_NUM = 1000000007;

int nKebab, dreamInterval;
LType kebabSize[MAX_SIZE], numHappy[MAX_SIZE];
LType dp[260][260];
LType pref[260 * 1100];

void makeKebab(int num, int index) {	
	for(int i = 0; i < kebabSize[num]; i++) {
		dp[0][i] = pref[index - 1];
//		cout << dp[0][i] << " ";
	}
//	cout << "\n";
//	cout << dp[1][0] << " ";
	for(int i = 0; i < kebabSize[num]; i++) {
		if(i - dreamInterval - 1 >= 0) {
			dp[1][i] = dp[0][i - dreamInterval - 1] + dp[1][i - 1];
		}else if(index + i - dreamInterval - 1 >= 1) {
			dp[1][i] = pref[index + i - dreamInterval - 1] + dp[1][i - 1];
		}else {
			dp[1][i] = 1 + dp[1][i - 1];
		}
		if(dp[1][i] >= MOD_NUM) {
			dp[1][i] %= MOD_NUM;				
		}
	}
//	cout << "\n";
	for(int i = 2; i <= numHappy[num]; i++) {
		for(int j = 0; j < kebabSize[num]; j++) {
			if(j - dreamInterval - 1 < 0) {
				dp[i][j] = 0;					
			}else {
				dp[i][j] = dp[i - 1][j - dreamInterval - 1] + dp[i][j - 1];
				if(dp[i][j] >= MOD_NUM) {
					dp[i][j] %= MOD_NUM;					
				}
			}
		}		
	}
	for(int i = 0; i < kebabSize[num]; i++) {
		LType sum = 0;
		for(int j = 0; j <= numHappy[num]; j++) {
			sum += dp[j][i];
			if(sum >= MOD_NUM) {
				sum %= MOD_NUM;				
			}
		}
		pref[index + i] = sum;
//		cout << sum << " ";
	}
//	cout << "\n\n\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nKebab >> dreamInterval;
	for(int i = 0; i < nKebab; i++) {
		cin >> kebabSize[i] >> numHappy[i];
		numHappy[i] = kebabSize[i] - numHappy[i];
	}
	int totalSize = 1;
	pref[0] = 1;
	for(int i = 0; i < nKebab; i++) {
		makeKebab(i, totalSize);
		totalSize += kebabSize[i];
	}	
	cout << pref[totalSize - 1] << "\n";
	return 0;
}
