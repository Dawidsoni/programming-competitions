#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 2000000000;
const int MAX_SIZE = 32;

int aBits, bBits, cBits, kNum;
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE][2];
bool isC[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE][2];

int countBits(int num) {
	int result = 0;
	int nBits = 0;
	while(num > 0) {
		if(num % 2 == 1) {
			result++;
		}
		num /= 2;
		nBits++;
	}
	kNum = max(kNum, nBits);
	return result;
}

int countResult(int kNum, int aNum, int bNum, int cNum, int carry) {
//	cout << kNum << " " << aNum << " " << bNum << " " << cNum << "\n";
	if(kNum < 0 || aNum < 0 || bNum < 0 || cNum < 0) {
		return -1;
	}
	if(aNum == 0 && bNum == 0 && cNum == 0 && carry == 1) {
		return -1;
	}
	if(aNum == 0 && bNum == 0 && cNum == 0 && carry == 0) {
		return 0;
	}	
	if(isC[kNum][aNum][bNum][cNum][carry]) {
		return dp[kNum][aNum][bNum][cNum][carry];
	} 	
	int result = INF;
	int r1 = countResult(kNum - 1, aNum, bNum, cNum - carry, 0);
	if(r1 != -1) {
		result = min(result, r1 * 2 + carry);
	}		
	int r2 = countResult(kNum - 1, aNum - 1, bNum, cNum - !carry, carry);
	if(r2 != -1) {
		result = min(result, r2 * 2 + !carry);
	}		
	int r3 = countResult(kNum - 1, aNum, bNum - 1, cNum - !carry, carry);
	if(r3 != -1) {
		result = min(result, r3 * 2 + !carry);
	}		
	int r4 = countResult(kNum - 1, aNum - 1, bNum - 1, cNum - carry, 1);
	if(r4 != -1) {
		result = min(result, r4 * 2 + carry);
	}		
	if(result == INF) {
		result = -1;
	}
	dp[kNum][aNum][bNum][cNum][carry] = result;
	isC[kNum][aNum][bNum][cNum][carry] = true;
	return result;	
}

int main() {
	int aNum, bNum, cNum;	
	cin >> aNum >> bNum >> cNum;
	aBits = countBits(aNum);
	bBits = countBits(bNum);
	cBits = countBits(cNum);
	cout << countResult(kNum, aBits, bBits, cBits, 0) << "\n";
	return 0;
}
