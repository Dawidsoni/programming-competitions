#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int LType;

const int ROZMIAR = 1010;

LType ileN, ileM, nWierz, maxWyn;
LType tab[ROZMIAR * ROZMIAR];
LType wynik[ROZMIAR * ROZMIAR];
bool czyByl[ROZMIAR * ROZMIAR];

void wczytaj() {
	cin >> ileN >> ileM;
	nWierz = ileN * ileM;
	for(int i = 1; i <= ileN; i++) {
		for(int ii = 1; ii <= ileM; ii++) {
			cin >> tab[(i - 1) * ileM + ii];
		}
	}
}

LType dfs(int numer);

void dlaSasiada(int numer, int sasiad) {
	if(czyByl[sasiad]) {
		wynik[numer] = max(wynik[numer], wynik[sasiad] + tab[numer]);
	}else {
		wynik[numer] = max(wynik[numer], dfs(sasiad) + tab[numer]);
	}
}

LType dfs(int numer) {
	czyByl[numer] = true;
	wynik[numer] = tab[numer];
	if(tab[numer - 1] > tab[numer] && numer % ileM != 1) dlaSasiada(numer, numer - 1);
	if(tab[numer + 1] > tab[numer] && numer % ileM != 0) dlaSasiada(numer, numer + 1);
	if(tab[numer - ileM] > tab[numer]) dlaSasiada(numer, numer - ileM);
	if(tab[numer + ileM] > tab[numer]) dlaSasiada(numer, numer + ileM);
	return wynik[numer];
}

int main() {
	wczytaj();
	for(int i = 1; i <= nWierz; i++) {
		if(czyByl[i] == false) {
			maxWyn = max(maxWyn, dfs(i));
		}
	}
	cout << maxWyn;
	return 0;
}
