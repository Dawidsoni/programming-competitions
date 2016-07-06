#include<stdio.h>
#include<vector>
using namespace std;

const int MAX_SIZE = 1000010;

int ile, nKolor, nDom1, nDom2, ostDom, tab[MAX_SIZE], dom1[MAX_SIZE], dom2[MAX_SIZE], aktInd[MAX_SIZE];
int ileJest1[MAX_SIZE], ileJest2[MAX_SIZE], nWsp, kopTab[MAX_SIZE];
vector<int> wyn1, wyn2, wyn;
vector<int> ind[MAX_SIZE];

void wczytaj() {
	scanf("%d%d", &ile, &nKolor);
	for(int i = 0; i < ile; i++) {
		scanf("%d", &tab[i]);
	}
		scanf("%d%d", &nDom1, &nDom2);
	for(int i = 0; i < nDom1; i++) {
		scanf("%d", &dom1[i]);
	}
	for(int i = 0; i < nDom2; i++) {
		scanf("%d", &dom2[i]);
	}
	ostDom = dom1[nDom1 - 1];
}

int maksInd, wart, nastWart;

bool przesun(int wart, int nastWart) {
	maksInd = ind[nastWart][aktInd[nastWart]];
	if(aktInd[wart] + 1 >= (int)ind[wart].size()) return false;
	if(ind[wart][aktInd[wart] + 1] > maksInd) return false;
	while(aktInd[wart] + 1 < (int)ind[wart].size() && ind[wart][aktInd[wart] + 1] < maksInd){
		aktInd[wart]++;
	}
	return true; 
}

void liczWyn(int tabDom[],int nDom, vector<int> & wyn) {
	for(int i = 0; i <= ile; i++) {
		aktInd[i] = -1;
	}
	for(int i = 0; i < ile; i++) {
		ind[tab[i]].push_back(i);
		if(tab[i] == ostDom) {
			aktInd[tabDom[nDom - 1]] = ind[tabDom[nDom - 1]].size() - 1;
			for(int j = nDom - 2; j >= 0; j--) {
				wart = tabDom[j];
				nastWart = tabDom[j + 1];
				maksInd = ind[nastWart][aktInd[nastWart]];
				if(aktInd[wart] + 1 >= (int)ind[wart].size()) break;
				if(ind[wart][aktInd[wart] + 1] > maksInd) break;
				while(true){
					if(ind[wart][aktInd[wart] + 1] >= maksInd || aktInd[wart] + 1 >= (int)ind[wart].size()) {
						break;
					}
					aktInd[wart]++;
				}
			}
			if(aktInd[tabDom[0]] == -1) {
				wyn.push_back(-1);
			}else {
				wyn.push_back(ind[tabDom[0]][aktInd[tabDom[0]]] - 1);
			}
		}
	}
}

void czysc() {
	for(int i = 0; i < ile; i++) {
		ind[i].clear();
	}
}

void odwrocTab() {
	for(int i = 0; i < ile; i++) {
		kopTab[i] = tab[i];
	}
	for(int i = 0; i < ile; i++) {
		tab[i] = kopTab[ile - 1 - i];
	}
}

void odwrocWyn2() {
	for(int i = 0; i < (int) wyn2.size(); i++) {
		wyn2[i] = ile - 1 - wyn2[i];
	}
}

int ost1, ost2;

void wypisz() {
	for(int i = 0; i < ile; i++) {
//			cout << ileJest1[i] << " ";
	}
//	cout << "\n";
	for(int i = 0; i < ile; i++) {
//		cout << ileJest2[i] << " ";
	}
//	cout << "\n\n\n";
}

void powieksz(int maxInd) { //pocz
	//cout << "powiekszam do " << maxInd << endl;
	for(;ost1 < maxInd;ost1++) {
		ileJest1[tab[ost1 + 1]]++;
		if(ileJest1[tab[ost1 + 1]] == 1 && ileJest2[tab[ost1 + 1]] > 0) nWsp++;
	}
}

void pomniejsz(int maxInd) { //kon
	//cout << "zmniejszam do " << maxInd << endl;
	for(;ost2 + 1 < maxInd; ost2++) {
		ileJest2[tab[ost2 + 1]]--;
		if(ileJest2[tab[ost2 + 1]] == 0 && ileJest1[tab[ost2 + 1]] > 0) nWsp--;
		/*if(ileJest2[tab[ost2 + 1]] == 0) {
			cout << "TOOOO: " << ileJest1[tab[ost2 + 1]] << "\n";
		}*/
	}
} 

void robWyn() { 
	int nJest = 0;
	for(int i = 0; i < ile; i++) {
		ileJest2[tab[i]]++;
	}
	ost1 = ost2 = -1;
	for(int i = 0; i < ile; i++) {
		if(tab[i] == ostDom) {
			pomniejsz(wyn2[wyn2.size() - 1 - nJest]);
			powieksz(wyn1[nJest]);
			nJest++;
			if(nWsp > 0) {
				wyn.push_back(i + 1);
			}
		}
	}
}

int main() {
	wczytaj();
	liczWyn(dom1, nDom1, wyn1);
	odwrocTab();
	czysc();
	liczWyn(dom2, nDom2, wyn2);
	odwrocWyn2();
	odwrocTab();
	robWyn();
	/*for(int i = 0; i < wyn1.size(); i++) {
		cout << wyn1[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < wyn2.size(); i++) {
		cout << wyn2[i] << " ";
	}
	cout << "\n";*/	
	printf("%d\n", wyn.size());
	for(int i = 0; i < (int) wyn.size(); i++) {
		printf("%d ", wyn[i]);
	}
	return 0;
}