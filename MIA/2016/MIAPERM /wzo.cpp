#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

typedef long long int LType;

int permCount, strLength;
string strList[20];
int indexList[20];
LType result = ((LType)1000000000) * ((LType)1000000000);

inline LType toNumber(string & str) {
	LType result = 0;
	for(int i = 0; i < (int)str.size(); i++) {
		result += ((str[i] - '0') * pow(10, str.size() - i - 1));
	}	
	return result;
}

LType curMin, curMax, num;
LType powList[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> permCount >> strLength;
	for(int i = 0; i < permCount; i++) {
		cin >> strList[i];
	}
	for(int i = 0; i < strLength; i++) {
		indexList[i] = i;
	}
	powList[0] = 1;
	for(int i = 1; i < 12; i++) {
		powList[i] = powList[i - 1] * 10;
	}	
	do {
		curMin = ((LType)1000000000) * ((LType)1000000000);
		curMax = 0;
		for(int i = 0; i < permCount; i++) {
			num = 0;
			for(int j = 0; j < strLength; j++) {
				num += ((strList[i][indexList[j]] - '0') * powList[strLength - j - 1]);
			}	
			curMin = min(curMin, num);
			curMax = max(curMax, num);
		}
		result = min(result, curMax - curMin);
	}while(next_permutation(indexList, indexList + strLength));
	cout << result << "\n";
	return 0;
}
