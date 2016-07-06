#include<iostream>
#include<vector>
using namespace std;

const int ROZMIAR = 10100;

int ile, kraw1, kraw2, wynik;
vector<int> graf[ROZMIAR];

int dlaPocz(int pocz) {
	int nKraw = 0, wynik = 0;
	for(int i = pocz + 1; i <= ile; i++) {
		for(int ii = 0; ii < (int)graf[i].size(); ii++) {
			if(graf[i][ii] < i && graf[i][ii] >= pocz) {
				nKraw++;
			}
		}
		if(nKraw + 1 == i - pocz + 1) wynik++;
	}
	return wynik;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> ile;
	for(int i = 0; i + 1 < ile; i++) {
		cin >> kraw1 >> kraw2;
		graf[kraw1].push_back(kraw2);
		graf[kraw2].push_back(kraw1);
	}
	wynik = ile;
	for(int i = 1; i <= ile; i++) wynik += dlaPocz(i);
	cout << wynik;
	return 0;
}
