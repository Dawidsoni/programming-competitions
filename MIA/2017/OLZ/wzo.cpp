#include<iostream>
using namespace std;

typedef long long int LType;

const int MAX_SIZE = 110000;

LType k, q, arr[MAX_SIZE], l, r, pref[MAX_SIZE];

void createPref() {
	arr[k] = arr[0];
	for(int i = 1; i < k; i++) {
		arr[k] = arr[k] ^ arr[i];
	}
	k++;	
	pref[0] = arr[0];
	for(int i = 1; i < k; i++) {
		pref[i] = pref[i - 1] ^ arr[i];
	}
}

LType ans() {
	l--;
	r--;
	l = l % k;
	r = r % k;
	if(l == 0) {
		l = k;
	}	
	return pref[r] ^ pref[l - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	createPref();
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> l >> r;
		cout << ans() << "\n";		
	}	
	return 0;
}
