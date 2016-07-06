#include<iostream>
#include<vector>
using namespace std;

const int MAX_SIZE = 1000010;

int tab1[MAX_SIZE], tab2[MAX_SIZE], ile1, ile2;
vector<int> wynik;

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile1;
	for(int i = 0; i < ile1; i++) {
		cin >> tab1[i];
	}
	cin >> ile2;
	for(int i = 0; i < ile2; i++) {
		cin >> tab2[i];
	}
}

void robSume() {
	for(int i = 0, j = 0; i < ile1 || j < ile2; i++, j++) {
		int akt = 0;
		if(i < ile1) {
			akt += tab1[i];
		}
		if(j < ile2) {
			akt += tab2[j];			
		}
		wynik.push_back(akt);
	}
}

void zwieksz(int poz, int oIle) {
	if(poz < 0) {
		wynik[0] += oIle;
	}else if(poz < (int) wynik.size()) {
		wynik[poz] += oIle;
	}else {
		wynik.push_back(oIle);
	}
}

void usunDwojki() {
	for(int i = wynik.size() - 1; i >= 0; i--) {
		if(i > 0 && ((wynik[i] >= 1 && wynik[i - 1] > 1) || (wynik[i] > 1 && wynik[i - 1] >= 1))) {
			wynik[i]--;
			wynik[i - 1]--;
			zwieksz(i + 1, 1);
		}else if(wynik[i] >= 2) {
			wynik[i] -= 2;
			zwieksz(i + 1, 1);
			if(i > 0) {
				zwieksz(i - 2, 1);
			}
		}
	}
}

void zamieniajOd(int i) {
	if(i < (int) wynik.size() && i > 0 && wynik[i] == 1 && wynik[i - 1] == 1) {
		wynik[i] = wynik[i - 1] = 0;
		zwieksz(i + 1, 1);
		zamieniajOd(i + 2);
	}
}

void usunJedynki() {
	for(int i = wynik.size() - 1; i >= 1; i--) {
		if(wynik[i] == 1 && wynik[i - 1] == 1) {
			zamieniajOd(i);
		}
	}
}

int main() {
	wczytaj();
	robSume();
	usunDwojki();	
	usunJedynki();
	cout << (int)wynik.size() << ' ';
	for(int i = 0; i < (int) wynik.size(); i++) {
		cout << wynik[i];
		if(i + 1 != (int)wynik.size()) cout << ' ';
	}
	cout << endl;
	return 0;
}