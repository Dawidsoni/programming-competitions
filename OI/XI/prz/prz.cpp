#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> Para;

int obcMost, ile, wczCzas, wczWaga, wyn = 200000000;
Para tab[20];

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> obcMost >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> wczCzas >> wczWaga;
		tab[i] = Para(wczCzas, wczWaga);
	}
}

void dlaTab() {
	int aktWaga = 0, aktMax = 0, aktWyn = 0; 
	for(int i = 0; i < ile; i++) {
		aktWaga += tab[i].second;
		if(aktWaga > obcMost) {
			aktWyn += aktMax;
			aktWaga = tab[i].second;
			aktMax = 0;
		}
		aktMax = max(aktMax, tab[i].first);
	}
	aktWyn += aktMax;
	wyn = min(wyn, aktWyn);
}

void liczWyn() {
	sort(tab, tab + ile);
	do {
		dlaTab();
	}while(next_permutation(tab, tab + ile));
}

int main() {
	wczytaj();
	liczWyn();
	cout << wyn;
	return 0;
}