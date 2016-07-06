#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int ROZMIAR = 510000;

int ile, odl, wynik;
int tab[ROZMIAR];
multiset<int, greater<int> > zbior;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> ile >> odl;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
	for(int i = 0; i < ile; i++) {
		if(i <= odl) {
			zbior.insert(tab[i]);			
		}else {
			zbior.erase(tab[i - odl - 1]);
			zbior.insert(tab[i]);
			multiset<int>::iterator iter = zbior.begin();
			iter++;
			wynik = max(wynik, *zbior.begin() + *iter);
		}
		if(i >= 1) {
			multiset<int>::iterator iter = zbior.begin();
			iter++;
			wynik = max(wynik, *zbior.begin() + *iter);
		}
	}
	cout << wynik;
	return 0;
}
