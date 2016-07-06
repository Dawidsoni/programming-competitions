#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1000100;

class Para {
public:
	int wart, ind;
	Para() {}
	Para(int w, int i) : wart(w), ind(i) {} 
};


int ile, nPtakow, zasieg, tab[MAX_SIZE];

void wypisz(deque<Para> & kolej) {
	for(int i = 0; i < (int) kolej.size(); i++) {
		cout << "(" << kolej[i].wart << " " << kolej[i].ind << "), ";
	}
	cout << "\n";
}

Para szukajMaks(int odkad, int dokad) {
	int wynik = 0, wynInd = 0;
	for(int i = odkad; i <= dokad; i++) {
		if(wynik <= tab[i]) {
			wynik = tab[i];
			wynInd = i;
		}
	}
	return Para(wynik, wynInd);
}

int aktWyn() {
	//cout << "zasieg = " << zasieg << "\n";
	int wynik = 0;
	deque<Para> kolej;
	kolej.push_back(Para(tab[0], 0));
	for(int i = 1; i < ile; i++) {
		if(kolej.front().wart > tab[i]) {
			while(kolej.size() > 1 && kolej.back().wart <= tab[i]) {
				kolej.pop_back();
				//cout << "usuw";
			}
			kolej.push_back(Para(tab[i], i));
		}
		if(i + 1 == ile && kolej.front().wart <= tab[i]) {
			//cout << "zwiekszam dla " << i << "\n";
			wynik++;
			break;
		}
		if(kolej.front().ind + zasieg == i) {
			kolej.pop_front();
		}
		if(kolej.size() == 0) {
			//cout << "zwiekszam dla " << i << "\n";
			wynik++;
			kolej.push_back(szukajMaks(i - zasieg + 1, i));
			i = kolej.front().ind;
		}
		//wypisz(kolej);
	}
	return wynik;
}

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
	cin >> nPtakow;
	for(int i = 0; i < nPtakow; i++) {
		cin >> zasieg;
		cout << aktWyn() << "\n";
	}
}

int main() {
	wczytaj();
	return 0;
}