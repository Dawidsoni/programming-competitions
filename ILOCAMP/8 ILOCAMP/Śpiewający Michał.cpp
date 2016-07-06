#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> Para;

const int ROZMIAR = 55;

int nZest, ile, nCzas;
Para tonCzas[ROZMIAR];



int wynDla(int odkad, int dokad) {
	int wynik = tonCzas[dokad].first - tonCzas[odkad].first + tonCzas[odkad].second + tonCzas[dokad].second;
	if(odkad == dokad) wynik -= tonCzas[odkad].second;
	if(wynik > nCzas) return 0;
	if(odkad == dokad) return 1;
	int ileJest = 2, licz = 0;
	vector<int> wek;
	for(int i = odkad + 1; i <= dokad - 1; i++) {
		wek.push_back(tonCzas[i].second);
	}
	sort(wek.begin(), wek.end());
	while(licz < (int)wek.size() && wynik <= nCzas) {
		wynik += wek[licz++];
		if(wynik > nCzas) break;
		ileJest++;
	}
	//cout << "dla " << odkad << " " << dokad << " jest " << ileJest << endl;
	return ileJest;
}

int odp() {
	int wynik = 0;
	/*cout << endl << endl;
	for(int i = 0; i < ile; i++) {
		cout << tonCzas[i].first << " " << tonCzas[i].second << endl;
	}*/
	for(int i = 0; i < ile; i++) {
		for(int ii = i; ii < ile; ii++) {
			wynik = max(wynik, wynDla(i, ii));
		}
	}
	return wynik;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nZest;
	for(int i = 0; i < nZest; i++) {
		cin >> ile >> nCzas;
		for(int i = 0; i < ile; i++) {
			cin >> tonCzas[i].second >> tonCzas[i].first;
		}
		sort(tonCzas, tonCzas + ile);
		cout << odp() << endl;
	}
	return 0;
}
