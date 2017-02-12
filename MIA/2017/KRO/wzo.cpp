#include<iostream>
using namespace std;

int ans(int num) {
	int parNum = num * 2 - 2;
	int resNum = parNum;
	int oneCount = 0;
	while(parNum > 0) {
		if(parNum % 2 == 1) {
			oneCount++;
		}
		parNum /= 2;
	}	
	if(oneCount % 2 == 0) {
		return resNum;
	}else {
		return resNum + 1;
	}
}

int main() {
	int n, k;
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0;i < n; i++) {
		cin >> k;
		cout << ans(k) << "\n";
	}	
	return 0;
}
