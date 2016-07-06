#include<iostream>
#include<vector>
using namespace std;

typedef unsigned int UInt;
typedef long long int LType;

LType INF = 1100000000 * (LType)1100000000;
const UInt ST_P = 1000000033;

LType ile, dlWyr, wyn;
string tab[205];
UInt potTab[100010];
vector<LType> tabHash[205];
LType graf[205][205];
LType aktWyn[100][205][205];

void robPot() {
	potTab[0] = 1;
	for(int i = 1;i < 100010; i++) {
		potTab[i] = (LType)potTab[i - 1] * ST_P;
	}
}

void robHash() {
	for(int i = 0; i < ile; i++) {
		tabHash[i].push_back(tab[i][0]);
	}
	for(int i = 0; i < ile; i++) {
		for(int j = 1; j < (int) tab[i].size(); j++) {
			tabHash[i].push_back(tabHash[i][tabHash[i].size() - 1] + (LType)potTab[j] * tab[i][j]);
		}
	}
}

UInt zwrocHash(int nr, int odkad, int dokad) {
	UInt aktHash = (odkad <= 0) ? (tabHash[nr][dokad]) : (tabHash[nr][dokad] - tabHash[nr][odkad - 1]);
	aktHash *= potTab[100010 - 1 - odkad];
	return aktHash;
}

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile >> dlWyr;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
}

void robKraw(LType w1, LType w2) {
	LType nWsp = 0;
	for(int i = tab[w1].size() - 1, j = 0; i >= 0 && j + 1 < (int) tab[w2].size(); i--, j++) {
		if(zwrocHash(w1, i, tab[w1].size() - 1) == zwrocHash(w2, 0, j)) {
			nWsp = j + 1;
		}
	}
	nWsp = tab[w2].size() - nWsp;
	graf[w1][w2] = nWsp;
	//cout << "dla " << w1 << ", " << w2 << " jest " << nWsp << "\n";
}

void robGraf() {
	for(int i = 0; i < ile; i++) {
		for(int j = 0; j < ile; j++) {
			robKraw(i, j);
		}
	}
}

void liczMac(LType akt, LType pow, LType aktInd, LType powInd) {
	//cout << akt << "\n";
	//cout << "akt = "  << akt << " ind = " << aktInd << " pow = " << pow << " ind = " << powInd << "\n";
	for(int i = 0; i < ile; i++) {
		for(int j = 0; j < ile; j++) {
			aktWyn[aktInd][i][j] = INF;
		}
	}
	for(int k = 0; k < ile; k++) {
		for(int i = 0; i < ile; i++) {
			for(int j = 0; j < ile; j++) {
				aktWyn[aktInd][i][j] = min(aktWyn[aktInd][i][j], aktWyn[aktInd - 1][i][k] + aktWyn[powInd][k][j]);
			}
		}
	}
}

void robWyn() {
	for(int i = 0; i < ile; i++) {
		for(int j = 0; j < ile; j++) {
			if(i == j) {
				aktWyn[0][i][j] = 0;
			}else {
				aktWyn[0][i][j] = INF;
			}
			aktWyn[1][i][j] = graf[i][j];
		}
	}
	LType aktDl = 1, ileDodac, ind = 1, wInd = 1;
	while(aktDl * 2 < dlWyr) {
		liczMac(aktDl, aktDl, ind + 1, ind);
		ind++;
		aktDl *= 2;
	}
	ileDodac = aktDl;
	wInd = ind;
	wInd++;
	while(ileDodac > 0) {
		if(aktDl + ileDodac >= dlWyr) {
			ileDodac /= 2;
			ind--;
			continue;
		}
		liczMac(aktDl, ileDodac, wInd, ind);
		wInd++;
		aktDl += ileDodac;
	}
	wyn = INF;
	for(int i = 0; i < ile; i++) {
		for(int j = 0; j < ile; j++) {
			wyn = min(wyn, ((LType)tab[i].size() + aktWyn[wInd - 1][i][j]));
		}
	}	
}

int main() {
	wczytaj();
	robPot();
	robHash();
	robGraf();
	if(dlWyr == 1) {
		wyn = INF;
		for(int i = 0; i < ile; i++) {
			wyn = min(wyn, (LType)tab[i].size());
		}
	}else {
		robWyn();
	}
	/*for(int k = 0; k < 4; k++) {
		for(int i = 0; i < ile; i++) {
			for(int j = 0; j < ile; j++) {
				cout << "(" << k << ")dla " << i << " i " << j << " jest " << aktWyn[k][i][j] << "\n";
			}
			cout << "\n";
		}
		cout << "\n\n\n";
	}*/
	cout << wyn;
	return 0;
}