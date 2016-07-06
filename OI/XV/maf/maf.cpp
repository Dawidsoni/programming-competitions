#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1000001;

int nWierz, wcz, wynMin, wynMax;
vector<int> graf[MAX_SIZE];
int kiedyByl[MAX_SIZE];
vector<int> cykl;
bool czyMin[MAX_SIZE], czyMin2[MAX_SIZE], czyBylMin[MAX_SIZE];
bool czyMax[MAX_SIZE], czyBylMax[MAX_SIZE];
bool czyByl;
bool czyPoprz;
int ilePetli;

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> nWierz;
	for(int i = 1; i <= nWierz; i++) {
		cin >> wcz;
		graf[wcz].push_back(i);
	}
}

bool dfsCykl(int wierz, int kiedy) {
	kiedyByl[wierz] = kiedy;
	for(int i = 0; i < (int) graf[wierz].size(); i++) {
		if(kiedyByl[graf[wierz][i]] == 0) {
			if(dfsCykl(graf[wierz][i], kiedy) == true) {
				cykl.push_back(wierz);
				return true;
			}
		}else if(kiedyByl[graf[wierz][i]] == kiedy){
			cykl.push_back(wierz);
			return true;
		}
	}
	return false;
}

void dfsMin(int wierz, int nastZly) {
	czyBylMin[wierz] = true;
	for(int i = 0; i < (int) graf[wierz].size(); i++) { 
		if(czyBylMin[graf[wierz][i]] == false && nastZly != graf[wierz][i]) {
			dfsMin(graf[wierz][i], nastZly);
		}
	}
	for(int i = 0; i < (int) graf[wierz].size(); i++) { 
		if(czyMin[graf[wierz][i]] == false && nastZly != graf[wierz][i]) {
			wynMin++;
			czyMin[wierz] = true;
			czyMin2[wierz] = true;
			return;
		}
	}	
}

void dfsMax(int wierz, int nastZly) {
	czyBylMax[wierz] = true;
	bool czyDodac = false;
	for(int i = 0; i < (int) graf[wierz].size(); i++) {
		if(czyBylMax[graf[wierz][i]] == false && nastZly != graf[wierz][i]) {
			dfsMax(graf[wierz][i], nastZly);
			czyDodac = true;
		}
		if(wierz == graf[wierz][i]){
			czyDodac = true;
		}
	}
	if(czyDodac) {
		wynMax++;
		czyMax[wierz] = true;
	}
}

void dfsKolo(int num) {
	if(num < 0) {
		ilePetli++;
		num = cykl.size() - 1;
	}
	if(ilePetli >= 3) return;
	if(czyMin[cykl[num]] || ilePetli >= 1) czyByl = true;
	if(czyByl == true && czyPoprz == false && czyMin[cykl[num]] == false) {
		czyMin[cykl[num]] = true;
		wynMin++;
	}
	for(int i = 0; i < (int) graf[cykl[num]].size(); i++) {
		if(graf[cykl[num]][i] == cykl[num - 1 < 0 ? cykl.size() - 1 : num - 1]) {
			czyPoprz = czyMin[cykl[num]];
			dfsKolo(num - 1);
		}
	}	
}

void liczDlaCyklu() {
	bool czyMaxDrz = false;
	int nOdj = 0;
	for(int i = 0; i < (int) cykl.size(); i++) {
		dfsMin(cykl[i], i - 1 < 0 ? cykl[cykl.size() - 1] : cykl[i - 1]); 
		dfsMax(cykl[i], i - 1 < 0 ? cykl[cykl.size() - 1] : cykl[i - 1]); 
		if(czyMax[cykl[i]]) {
			czyMaxDrz = true;
			nOdj++;
		}
	}
	czyByl = false;
	czyPoprz = true;
	ilePetli = 0;
	dfsKolo(cykl.size() - 1);
	if(czyMaxDrz == true) {
		wynMax += cykl.size() - nOdj;
	}else {
		wynMax += cykl.size() - 1;	
	}
}

void liczCykl() {
	for(int i = 1; i <= nWierz; i++) {
		if(kiedyByl[i] == 0) {
			cykl.clear();
			dfsCykl(i, i);
			if(cykl.size() > 0) {
				liczDlaCyklu();
			}
		}
	}
}

int main() {
	wczytaj();
	liczCykl();
	cout << wynMin << " " << wynMax;
	return 0;
}