#include<iostream>
#include<vector>
using namespace std;

const int MAX_WIERZ = 1200000;

int ile, nWierz, wczKan1, wczStan1, wczKan2, wczStan2, postLicz, nSilnych, ileWyn;
vector<int> graf[MAX_WIERZ];
vector<int> odwrGraf[MAX_WIERZ];
vector<int> silna[MAX_WIERZ];
int postOrder[MAX_WIERZ], wynik[MAX_WIERZ];
bool czyZal[MAX_WIERZ];

int odwrWierz(int wierz) {
	return (wierz % 2 == 0) ? wierz - 1 : wierz + 1;
}

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile >> nWierz;
	nWierz *= 2;
	for(int i = 0; i < ile; i++) {
		cin >> wczKan1 >> wczStan1 >> wczKan2 >> wczStan2;
		int wierz1 = wczKan1 * 2 - (wczStan1 == 1 ? 1 : 0);
		int wierz2 = wczKan2 * 2 - (wczStan2 == 1 ? 1 : 0);
		graf[odwrWierz(wierz1)].push_back(wierz2);
		graf[odwrWierz(wierz2)].push_back(wierz1);
	}
	/*for(int i = 1; i <= nWierz; i++) {
		cout << "dla wierz = " << i << ": ";
		for(int ii = 0; ii < (int) graf[i].size(); ii++) {
			cout << graf[i][ii] << " ";
		}
		cout << endl;
	}*/
}

void dfs(int wierz) {
	czyZal[wierz] = true;
	for(int i = 0; i < (int) graf[wierz].size(); i++) {
		if(czyZal[graf[wierz][i]] == false) {
			dfs(graf[wierz][i]);
		}
	}
	postOrder[postLicz++] = wierz;
}

void odwroc() {
	for(int i = 1; i <= nWierz; i++) {
		for(int ii = 0; ii < (int) graf[i].size(); ii++) {
			odwrGraf[graf[i][ii]].push_back(i);
		}
	}
}

void odwrDfs(int wierz) {
	silna[nSilnych].push_back(wierz);
	czyZal[wierz] = true;
	for(int i = 0; i < (int) odwrGraf[wierz].size(); i++) {
		if(czyZal[odwrGraf[wierz][i]] == false) {
			odwrDfs(odwrGraf[wierz][i]);
		}
	}
}

void silneSpojne() {
	for(int i = 1; i <= nWierz; i++) {
		if(czyZal[i] == false) dfs(i);
	}
	odwroc();
	for(int i = 1; i <= nWierz; i++) czyZal[i] = false;

	for(int i = nWierz - 1; i >= 0; i--) {
		if(czyZal[postOrder[i]] == false) {
			odwrDfs(postOrder[i]);
			nSilnych++;
		}
	}
	/*cout << nSilnych << endl;
	for(int i = 0; i < nSilnych; i++) {
		cout << "silna " << i << ": ";
		for(int ii = 0; ii < (int) silna[i].size(); ii++) {
			cout << silna[i][ii] << " ";
		}
		cout << endl;
	}*/
}

bool liczWyn() {
	for(int i = nSilnych - 1; i >= 0; i--) {
		for(int ii = 0; ii < (int) silna[i].size(); ii++) {
			if(wynik[silna[i][ii]] == -1) {
				wynik[silna[i][ii]] = 1;
				wynik[odwrWierz(silna[i][ii])] = 0;
				for(int j = 0; j < (int) graf[silna[i][ii]].size(); j++) {
					if(wynik[graf[silna[i][ii]][j]] == 0) return false;
				}
				ileWyn++;
				if(ileWyn >= nWierz / 2) return true;
			}
		}
	}
	return false;
}

void zrobWyn() {
	if(liczWyn() == false) {
		cout << "IMPOSSIBLE";
		return;
	}
	for(int i = 1; i <= nWierz; i++) {
		if(wynik[i] && i % 2 == 0) {
			cout << "0" << endl;
		}else if(wynik[i] && i % 2 == 1) {
			cout << "1" << endl;
			i++;
		}
	}
}


int main() {
	wczytaj();
	silneSpojne();
	for(int i = 1; i <= nWierz; i++) wynik[i] = -1;
	zrobWyn();
	return 0;
}
