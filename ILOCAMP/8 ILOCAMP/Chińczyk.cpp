#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Para;

const int ROZMIAR = 2100000;

int nWierz, kraw1, kraw2;
bool czyChin[ROZMIAR];
vector<int> graf[ROZMIAR];

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> nWierz;
	for(int i = 1; i <= nWierz; i++) {
		cin >> czyChin[i];
	}
	for(int i = 0; i + 1 < nWierz; i++) {
		cin >> kraw1 >> kraw2;
		graf[kraw1].push_back(kraw2);
		graf[kraw2].push_back(kraw1);
	}
}

Para szukajNajdal(int wierz) {
	queue<Para> kolej; //first - wierz, second - odleglosc
	bool czyByl[ROZMIAR];
	int maxOdl = 0, wynWierz = 0;
	for(int i = 1; i <= nWierz; i++) czyByl[i] = false;
	kolej.push(Para(wierz, 0));
	while(kolej.empty() == false) {
		int aktWierz = kolej.front().first, odl = kolej.front().second;
		kolej.pop();
		czyByl[aktWierz] = true;
		for(int i = 0; i < (int)graf[aktWierz].size(); i++) {
			if(czyByl[graf[aktWierz][i]] == false) {
				kolej.push(Para(graf[aktWierz][i], odl + 1));
			}
		}
		if(czyChin[aktWierz] && odl > maxOdl) {
			maxOdl = odl;
			wynWierz = aktWierz;
		}
	}
	return Para(wynWierz, maxOdl);
}

int main() {
	wczytaj();
	int srednica = szukajNajdal(szukajNajdal(1).first).second;
	if(srednica % 2 == 0) cout << srednica / 2;
	else cout << srednica / 2 + 1;
	return 0;
}
