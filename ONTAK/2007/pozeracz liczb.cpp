#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

const int SIZE = 510;

class Danie {
public:
	int wartosc;
	mutable int ileDan;
	Danie() {}
	Danie(int war, int nDan) : wartosc(war), ileDan(nDan) {}
	friend bool operator < (const Danie & dan1, const Danie & dan2) {
		return dan1.wartosc < dan2.wartosc;
	}
	friend bool operator == (const Danie & dan1, const Danie & dan2) {
		return dan1.wartosc == dan2.wartosc;
	}
};

int ile, nDan;
int tab[SIZE];
set<pair<unsigned, unsigned> > wynik;
vector<int> dania[SIZE];

typedef unsigned long long int LType;
const unsigned ST_P = 1000000033;
const unsigned ST_P2 = 1000000007;
unsigned potTab[SIZE * SIZE];
unsigned hashTab[SIZE * SIZE];
unsigned potTab2[SIZE * SIZE];
unsigned hashTab2[SIZE * SIZE];


void wyznaczPot() {
	potTab[0] = potTab2[0] = 1;
	for(int i = 1; i <= SIZE; i++) {
		potTab[i] = ((LType)potTab[i - 1] * ST_P);
		potTab2[i] = ((LType)potTab2[i - 1] * ST_P2);
	}
}

pair<int, int> wyznaczHash(vector<int> & wek) {
	unsigned aktHash = wek[0], aktHash2 = wek[0];
	for(int i = 1; i < (int) wek.size(); i++) {
		aktHash = ((LType)aktHash + ((LType)wek[i] * potTab[i]));
		aktHash2 = ((LType)aktHash2 + ((LType)wek[i] * potTab2[i]));
	}
	return pair<unsigned, unsigned>(aktHash, aktHash2);
}

void dodajDanie(set<Danie> & danie, vector<int> dania[]) {
	dania[nDan].clear();
	for(set<Danie>::iterator iter = danie.begin(); iter != danie.end(); iter++) {
		dania[nDan].push_back(iter->wartosc);
	}
	nDan++;
}


void dodajNowe(int dlugosc) {
	set<Danie> aktDania;
	nDan = 0;
	for(int i = 0; i < dlugosc; i++) {
		set<Danie>::iterator iter = aktDania.find(Danie(tab[i], 0));
		if(iter == aktDania.end()) aktDania.insert(Danie(tab[i], 1));
		else iter->ileDan++;
	}
	dodajDanie(aktDania, dania);
	for(int i = dlugosc; i < ile; i++) {
		set<Danie>::iterator iter = aktDania.find(Danie(tab[i], 0));
		if(iter == aktDania.end()) aktDania.insert(Danie(tab[i], 1));
		else iter->ileDan++;
		set<Danie>::iterator stary = aktDania.find(Danie(tab[i - dlugosc], 0));
		stary->ileDan--;
		if(stary->ileDan == 0) aktDania.erase(stary);
		dodajDanie(aktDania, dania);
	}
	for(int i = 0; i < nDan; i++) {
		pair<unsigned, unsigned> aktHash = wyznaczHash(dania[i]);
		wynik.insert(aktHash);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	wyznaczPot();
	cin >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
	for(int i = 1; i <= ile; i++) dodajNowe(i);
	cout << wynik.size();
	return 0;
}
