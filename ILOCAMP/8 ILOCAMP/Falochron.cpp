#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int ROZMIAR = 1100000;

int ile, maxWyn;
int tab[ROZMIAR];
int wynik[ROZMIAR];

class Kolej {
public:
	stack<int> stos;
	
	int rozmiar() {
		return stos.size();
	}
	
	void dodaj(int licz) {
		while(stos.size() > 0 && licz > stos.top()) stos.pop();
		stos.push(licz);
	}
};

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
}

void dodajLewa() {
	Kolej kolej;
	for(int i = 0; i + 1 < ile; i++) {
		kolej.dodaj(tab[i]);
		wynik[i + 1] += kolej.rozmiar();		
	}
}

void dodajPrawa() {
	Kolej kolej;
	for(int i = ile - 1; i >= 1; i--) {
		kolej.dodaj(tab[i]);
		wynik[i - 1] += kolej.rozmiar();
	}
}

int main() {
	wczytaj();
	dodajLewa();
	dodajPrawa();
	for(int i = 0; i <= ile; i++) {
		maxWyn = max(maxWyn, wynik[i]);
	}
	cout << maxWyn;
	return 0;
}
