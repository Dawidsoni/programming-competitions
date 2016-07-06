#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int LType;
typedef pair<LType, LType> Para;

const int ROZMIAR = 110000;

LType nTest, ile;
LType tab[ROZMIAR];

LType nwd(LType licz1, LType licz2) {
	while(licz1 != 0 && licz2 != 0) {
		if(licz1 >= licz2) licz1 %= licz2;
		else licz2 %= licz1;
	}
	return licz1 == 0 ? licz2 : licz1;
}

LType odp() {
	LType wynik = 0;
	vector<Para> kolej;
	for(int i = 0; i < ile; i++) {
		kolej.push_back(Para(tab[i], 0));
		for(int ii = 0; ii < (int)kolej.size(); ii++) {
			kolej[ii].first = nwd(kolej[ii].first, tab[i]);
			kolej[ii].second++;
			wynik = max(wynik, kolej[ii].first * kolej[ii].second);
		}
		for(int ii = kolej.size() - 1; ii >= 1; ii--) {
			if(kolej[ii].first == kolej[ii - 1].first && kolej[ii].second <= kolej[ii - 1].second) {
				kolej.pop_back();
			}else break;
		}
	}
	return wynik;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> ile;
		for(int ii = 0; ii < ile; ii++) {
			cin >> tab[ii];
		}
		cout << odp() << endl;
	}
	return 0;
}
