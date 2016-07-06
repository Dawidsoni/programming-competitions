#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<int, int> Para;

const int MAX_SIZE = 1000010;

int nWierz, w1, w2, nLini, korzen, wyn;
int wynik[MAX_SIZE];
vector<int> graf[MAX_SIZE];
bool czyByl[MAX_SIZE];
int maxWierz[MAX_SIZE];

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> nWierz >> nLini;
	for(int i = 0; i + 1 < nWierz; i++) {
		cin >> w1 >> w2;
		graf[w1].push_back(w2);
		graf[w2].push_back(w1);
	}
}

int dfsSzuk(int wierz) {
	czyByl[wierz] = true;
	multiset<int, greater<int> > wyn;
	for(int i = 0; i < (int)graf[wierz].size(); i++) {
		if(czyByl[graf[wierz][i]] == false) {
			wyn.insert(dfsSzuk(graf[wierz][i]));
		}
	}
	if(wyn.size() == 0) {
		wynik[wierz] = 1;
		return 1;
	}else if(wyn.size() == 1) {
		wynik[wierz] = *wyn.begin() + 1;
	}else {
		set<int>::iterator iter = wyn.begin();
		iter++;
		wynik[wierz] = 1 + *wyn.begin() + *iter;
	}
	return *wyn.begin() + 1;
} 

void szukajKorz() {
	dfsSzuk(1);
	int maxWart = 0;
	for(int i = 1; i <= nWierz; i++) {
		if(maxWart < wynik[i]) {
			maxWart = wynik[i];
			korzen = i;
		}
	}
}

int dfsWierz(int wierz) {
	czyByl[wierz] = true;
	int wyn = 0;
	for(int i = 0; i < (int) graf[wierz].size(); i++) {
		if(czyByl[graf[wierz][i]] == false) {
			wyn = max(wyn, dfsWierz(graf[wierz][i]));
		}
	}
	maxWierz[wierz] = wyn + 1;
	return wyn + 1;
}

void liczMaxWierz() {
	for(int i = 1; i <= nWierz; i++) {
		czyByl[i] = false;
	}
	dfsWierz(korzen);
}

multiset<Para, greater<Para> > aktWyn;

void dfsLicz(int wierz) {
	if(nLini == 0) {
		return;
	}
	if(czyByl[wierz] == false) {
		czyByl[wierz] = true;
		wyn++;
		//cout << wierz << endl;
	}
	int numWierz = 0, maxWart = 0;
	for(int i = 0; i < (int) graf[wierz].size(); i++) {
		if(czyByl[graf[wierz][i]] == false && maxWart < maxWierz[graf[wierz][i]]) {
			maxWart = maxWierz[graf[wierz][i]];
			numWierz = graf[wierz][i];
		}
	}
	if(numWierz != 0) {
		dfsLicz(numWierz);
	}
	for(int i = 0; i < (int) graf[wierz].size(); i++) {
		if(czyByl[graf[wierz][i]] == false) {
			aktWyn.insert(Para(maxWierz[graf[wierz][i]],graf[wierz][i]));
			//cout << "dodaje " << graf[wierz][i] << "\n";
		}
	}
}

void robWyn() {
	for(int i = 1; i <= nWierz; i++) {
		czyByl[i] = false;
	}
	if(graf[korzen].size() == 1) {
		dfsLicz(korzen);
	}else {
		for(int i = 0; i < (int) graf[korzen].size(); i++) {
			aktWyn.insert(Para(maxWierz[graf[korzen][i]], graf[korzen][i]));
		}
		czyByl[korzen] = true;
		wyn++;
		int wierz1 = aktWyn.begin()->second;
		aktWyn.erase(aktWyn.begin());
		int wierz2 = aktWyn.begin()->second;
		aktWyn.erase(aktWyn.begin());
		dfsLicz(wierz1);
		dfsLicz(wierz2);
	}
	//cout << "to: " << wyn << "\n";
	for(int i = 0; i + 1 < nLini; i++) {
		//cout << i << "\n";
		if(aktWyn.size() == 0) break;
		int wierz1 = aktWyn.begin()->second;
		//cout << "w1: " << wierz1 << "\n";
		aktWyn.erase(aktWyn.begin());
		dfsLicz(wierz1);
		if(aktWyn.size() == 0) break;
		int wierz2 = aktWyn.begin()->second;
		//cout << "w2: " << wierz2 << "\n";
		aktWyn.erase(aktWyn.begin());
		if(wyn == nWierz) break;
		dfsLicz(wierz2);
		if(wyn == nWierz) break;
	}
}

int main() {
	wczytaj();
	szukajKorz();
	liczMaxWierz();
	robWyn();
	cout << wyn;
	return 0;
}