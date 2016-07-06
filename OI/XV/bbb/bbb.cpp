#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1000010;

int ile, saldPocz, saldKon, kosztZam, kosztPrzes, nZam, nPrzes, minSuma, suma, wynik = 2000000000;
string tab;


void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile >> saldPocz >> saldKon >> kosztZam >> kosztPrzes;
	cin >> tab;
}

void liczSume() {
	for(int i = 0; i < (int) tab.size(); i++) {
		if(tab[i] == '+') {
			suma++;
		}else {
			suma--;
		}
		minSuma = min(minSuma, suma);
	}
	minSuma = saldPocz + minSuma;
	suma = saldPocz + suma;
}

int wynDla(int nZam, int nPrzes) {
	//cout << nZam << " " << nPrzes << "\n";
	return (nZam * kosztZam) + (nPrzes * kosztPrzes);	
}

void liczMinus() { // + na -
	nZam = (suma - saldKon) / 2;
	if(minSuma >= 0) {
		wynik = min(wynik, wynDla(nZam, 0));		
		return;
	}
	int ileDodac = -minSuma, aktDodac = -minSuma;
	int ileZm = (ileDodac % 2 == 0) ? ileDodac : ileDodac + 1;
	wynik = min(wynik, wynDla(nZam + ileZm, 0));
	for(int licz = 1, i = tab.size() - 1; licz <= (int) tab.size(); licz++, i--) {
		if(tab[i] == '-') {
			aktDodac++;
		}else {
			aktDodac--;
		}
		ileZm = (aktDodac % 2 == 0) ? aktDodac : aktDodac + 1;
		if(aktDodac >= 0) {
			wynik = min(wynik, wynDla(nZam + ileZm, licz));
		}
	}
}

void liczPlus() {
	nZam = (saldKon - suma) / 2;
	//cout << nZam << "\n";
	//cout << "minSuma: " << minSuma << "\n";
	minSuma = minSuma + nZam * 2;
	int ileDodac = -minSuma, aktDodac = -minSuma;
	if(minSuma >= 0) {
		wynik = min(wynik, wynDla(nZam, 0));
		return;
	}	
	int ileZm = (ileDodac % 2 == 0) ? ileDodac : ileDodac + 1;
	wynik = min(wynik, wynDla(nZam + ileZm, 0));	
	for(int licz = 1, i = tab.size() - 1; licz <= (int) tab.size(); licz++, i--) {
		if(tab[i] == '-') {
			aktDodac++;
		}else {
			aktDodac--;
		}
		ileZm = (aktDodac % 2 == 0) ? aktDodac : aktDodac + 1;
		if(aktDodac >= 0) {
			wynik = min(wynik, wynDla(nZam + ileZm, licz));
		}
	}
}

int main() {
	wczytaj();
	liczSume();
	if(suma > saldKon) {
		liczMinus();
	}else {
		liczPlus();
	}	
	cout << wynik << "\n";
	return 0;
}