#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> Para;

const int MAX_SIZE = 10010;

int nWierz, nPunkt, wX[MAX_SIZE], wY[MAX_SIZE], pX[MAX_SIZE], pY[MAX_SIZE], pWart[MAX_SIZE];
int odc[610][610], wyn = -20000000, suma;

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> nWierz;
	for(int i = 0; i < nWierz; i++) {
		cin >> wX[i] >> wY[i];
	}
	cin >> nPunkt;
	for(int i = 0; i < nPunkt; i++) {
		cin >> pX[i] >> pY[i] >> pWart[i];
		suma += pWart[i];
	}
}

int mod(int nr) {
	if(nr >= nWierz) return nr % nWierz;
	 if(nr < 0) return nr + nWierz;
	 return nr;
}

bool wezKierunek(int x1, int y1, int x2, int y2, int pX, int pY) {
	x2 -= x1;
	y2 -= y1;
	pX -= x1;
	pY -= y1;
	return ((pX * y2 - x2 * pY) >= 0);
}

void ustawPunkt(vector<Para> & wek, int nr) {
	int pocz = 0, kon = wek.size(), wyn = wek.size();
	while(pocz < kon) {
		int sr = (pocz + kon) / 2;
		int num1 = wek[sr].first, num2 = wek[sr].second;
		if(wezKierunek(wX[num1], wY[num1], wX[num2], wY[num2], pX[nr], pY[nr]) == true) {//szukam pierwszego 0
			pocz = sr + 1;
		}else {
			kon = sr;
			wyn = sr;
		}
	}
	if(wyn != (int) wek.size()) {
		odc[wek[wyn].first][wek[wyn].second] += pWart[nr];
	}
}

void dlaWierz(int nr) {
	odc[nr][nr] = 0;
	odc[nr][mod(nr + 1)] = 0;
	odc[nr][mod(nr - 1)] = 0;
	vector<Para> wek;
	for(int i = 2; i + 1 < nWierz; i++) {
		wek.push_back(Para(nr, mod(nr + i)));
	}
	for(int i = 0; i < nPunkt; i++) {
		ustawPunkt(wek, i);
	}
	int suma = 0;
	for(int i = 0; i < (int) wek.size(); i++) { 
		suma += odc[wek[i].first][wek[i].second];
		odc[wek[i].first][wek[i].second] = suma;
	}
}

void dlaTroj(int nr1, int nr2, int nr3) {  // 1 -> 2 -> 3 -> 1
	//cout << "dla: " << nr1 << " " << nr2 << " " << nr3 << "\n";
	//cout << nr1 << " -> " << nr2 << ": " << odc[nr1][nr2] << "\n";
	//cout << nr2 << " -> " << nr3 << ": " << odc[nr2][nr3] << "\n";
	//cout << nr3 << " -> " << nr1 << ": " << odc[nr3][nr1] << "\n";
	wyn = max(wyn, (suma - odc[nr1][nr2] - odc[nr2][nr3] - odc[nr3][nr1]));
}

int main() {
	wczytaj();
	for(int i = 0; i < nWierz; i++) {
		dlaWierz(i);
	}
	for(int i = 0; i < nWierz; i++) {
		for(int j = i + 1; j < nWierz; j++) {
			for(int k = j + 1; k < nWierz; k++) {
				dlaTroj(i, j, k);
			} 
		}
	}
	cout << wyn;
	return 0;
}