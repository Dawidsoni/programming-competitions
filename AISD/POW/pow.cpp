//Dawid Wegner
//279743
//KLO

#include<iostream>

using namespace std;

int a,b;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	if(a % 2 == 0) {
		a++;
	}
	while(a <= b) {
		cout << a << " ";
		a += 2;
	}
	
	return 0;
}
