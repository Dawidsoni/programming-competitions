#include<iostream>
#include<vector>
using namespace std;

const int MAX_SIZE = 610;

int ile, nKon;
int tab[MAX_SIZE][MAX_SIZE];
int sumPref[MAX_SIZE][MAX_SIZE];
int dyn[MAX_SIZE][MAX_SIZE];
vector<int> poprz[60][MAX_SIZE];

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile >> nKon;
	for(int i = 0; i + 1 < ile; i++) {
		for(int j = i + 1; j < ile; j++) {
			cin >> tab[i][j];
		}
	}
}

void zrobSume() {
	for(int i = 0; i < ile; i++) {
		int suma = 0;
		for(int j = 0; j < ile; j++) {
			suma += tab[i][j];
			sumPref[i][j] = suma + (i - 1 < 0 ? 0 : sumPref[i - 1][j]);
		}
	}
}

int wezSume(int x1, int x2, int y1, int y2) {
	int suma = sumPref[x2][y2] - (y1 - 1 < 0 ? 0 : sumPref[x2][y1 - 1]) - (x1 - 1 < 0 ? 0 : sumPref[x1 - 1][y2]);
	suma += ((x1 - 1 < 0 || y1 - 1 < 0) ? 0 : sumPref[x1 - 1][y1 - 1]);	
	return suma;
}

void robWyn() {
	for(int i = 1; i < ile; i++) {
		dyn[1][i] = wezSume(0, i - 1, i, ile - 1);
		poprz[1][i].push_back(i);
	}
	/*for(int i = 1; i < ile; i++) {
		cout << dyn[1][i] << " ";
	}*/
	for(int k = 2; k <= nKon; k++) {
		for(int i = k; i < ile; i++) {
			int nastElem = 0;
			for(int j = 1; j < i; j++) {
				if(dyn[k - 1][j] + wezSume(j, i - 1, i, ile - 1) > dyn[k][i]) {
					dyn[k][i] = dyn[k - 1][j] + wezSume(j, i - 1, i, ile - 1);
					nastElem = j;
				}
				//cout << "suma: " << wezSume(j, i - 1, i, ile - 1) +  dyn[k - 1][j] << "  ";
			}
			poprz[k][i] = poprz[k - 1][nastElem];
			poprz[k][i].push_back(i);			
			//cout << "(" << dyn[k][i] << ")\n";
		}
	}
}

int main() {
	wczytaj();
	zrobSume();
	robWyn();
	int maks = 0, maksInd = 0;
	for(int i = 1; i < ile; i++) {
		if(dyn[nKon][i] > maks) {
			maks = dyn[nKon][i];
			maksInd = i;
		}
	}
	for(int i = 0; i < (int)poprz[nKon][maksInd].size(); i++) {
		cout << poprz[nKon][maksInd][i] << " ";
	}
	return 0;
}