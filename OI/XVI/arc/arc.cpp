#include<iostream>
#include<list>
#include "carclib.h"

using namespace std;

int nProj, liczba;
list<int> wynik;
list<int>::iterator iter;

/*int tab[1100];
int ile, nWczyt;

int inicjuj() {
	cin >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
	cin >> nProj;
	return nProj;
}

int wczytaj() {
	if(nWczyt == ile) return 0;
	return tab[nWczyt++];
}

void wypisz(int licz) {
	cout << licz << " ";
}*/

void usun() {
	if(iter == wynik.begin()) {
		wynik.erase(iter);
		iter = wynik.begin();
	}else {
		list<int>::iterator kopia = iter;
		iter--;
		wynik.erase(kopia);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	nProj = inicjuj();
	for(int i = 0; true; i++) {
		liczba = wczytaj();
		if(liczba == 0) {
			break;
		}
		if(i == 0) {
			wynik.push_back(liczba);
			iter = wynik.begin();
		}else if(i < nProj) {
			wynik.push_back(liczba);			
		}else {
			wynik.push_back(liczba);
			list<int>::iterator wIter = iter;
			wIter++;
			while(wIter != wynik.end() && *iter >= *wIter) {
				iter++;
				wIter++;
			}
			usun();
		}
	}
	for(list<int>::iterator it = wynik.begin(); it != wynik.end(); it++) {
		wypisz(*it);
	}
	
	return 0;
}