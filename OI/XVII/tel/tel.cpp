#include<iostream>
#include<queue>
using namespace std;

typedef long long int LType;
typedef pair<int, int> Para;

const int INF = 1000000;
const int MAX_SIZE = 1000100;

LType nWierz, nKraw, w1, w2, wyn;
vector<int> graf[MAX_SIZE];
bool czyByl[MAX_SIZE];
LType suma[MAX_SIZE];
LType warstwa[MAX_SIZE];
LType ileWierz[10];

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> nWierz >> nKraw;
	for(int i = 0; i < nKraw; i++) {
		cin >> w1 >> w2;
		graf[w1].push_back(w2);
		graf[w2].push_back(w1);
	}
}

void robWarstwy(LType wierz) {
	queue<Para> kolej;
	kolej.push(Para(wierz, 0));
	czyByl[wierz] = true;
	while(kolej.size() > 0) {
		LType akt = kolej.front().first;
		LType odl = kolej.front().second;
		warstwa[akt] = odl;
		kolej.pop();
		for(int i = 0; i < (int) graf[akt].size(); i++) {
			if(czyByl[graf[akt][i]] == false) {
				czyByl[graf[akt][i]] = true;
				kolej.push(Para(graf[akt][i], odl + 1));
			}
		}		
	}
	for(int i = 1; i <= nWierz; i++) {
		if(czyByl[i] == false) {
			czyByl[i] = true;
			warstwa[i] = INF;
		}
	}
}

void wypisz() {
	for(int i = 0; i <= 5; i++) {
		cout << "dla " << i << ": ";
		for(int j = 1; j <= nWierz; j++) {
			if(warstwa[j] == i) {
				cout << j << " ";
			} 
		}
		cout << "\n";
	}
}

void robSumy() {
	LType akt = 0;
	for(int i = 2; i <= 50000; i++) { 
		akt += (i - 1);
		suma[i] = akt;
	}
}

bool czyDoWarstwy(LType wierz, LType war) {
	for(int i = 0; i < (int)graf[wierz].size(); i++) {
		if(warstwa[graf[wierz][i]] == war) {
			return true;
		}
	}
	return false;
}

void aktualizuj() {
	for(int i = 0; i <= 5; i++) {
		ileWierz[i] = 0;
	}
	for(int i = 1; i <= nWierz; i++) {
		ileWierz[warstwa[i]]++;
	}
}

void zmienWarstwy() {
	for(int i = 2; i <= nWierz; i++) {
		if(warstwa[i] > 4) {
			warstwa[i] = 4;
		}
	}
	warstwa[1] = 5;
	for(int i = 3; i <= nWierz; i++) {
		if(warstwa[i] == 4 && czyDoWarstwy(i, 5) == false) {
			warstwa[i] = 3;
		}
	}
	aktualizuj();
	if(ileWierz[1] > ileWierz[4]) {
		for(int i = 3; i <= nWierz; i++) {
			if(warstwa[i] == 3 && czyDoWarstwy(i, 4) == false) {
				warstwa[i] = 2;
			}
		}		
	}
}

void robWyn() {
	aktualizuj();
	for(int i = 1; i <= 4; i++) {
		wyn += suma[ileWierz[i]];
	}
	for(int i = 0; i <= 4; i++) {
		wyn += (ileWierz[i] * ileWierz[i + 1]);
	}
}

int main() {
	wczytaj();
	robSumy();
	robWarstwy(2);
	zmienWarstwy();
	//wypisz();
	robWyn();
	cout << wyn - nKraw;
	return 0;
}