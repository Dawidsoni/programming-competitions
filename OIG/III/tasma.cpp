#include<iostream>
#include<algorithm>
using namespace std;

const int SIZE = 110000;

int nTest, ile;
int tab[SIZE];

void wypisz() {
	int odl = -1;
	for(int i = 1; i < ile; i++) {
		if(tab[0] != tab[i]) odl = i;
	}
	for(int i = ile - 2; i >= 0; i--) {
		if(tab[ile - 1] != tab[i]) odl = max(odl, ile - 1 - i);
	}
	if(odl == -1) cout << "BRAK" << endl;
	else cout << odl << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> ile;
		for(int ii = 0; ii < ile; ii++) {
			cin >> tab[ii];
		}
		wypisz();
	}
	return 0;
}
