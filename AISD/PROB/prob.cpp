#include<iostream>
#include<algorithm>

using namespace std;

int a,b;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	for(int i = min(a, b); i <= max(a, b); i++) {
		cout << i << "\n";
	}	
	return 0;
}
