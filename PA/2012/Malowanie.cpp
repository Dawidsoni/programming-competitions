#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int LType;

const int ROZMIAR = 510000;
const LType INF = 100000000L * 100000000L;

class Prostokat {
public:
	LType x1, x2, y1, y2;

	Prostokat(LType x1_ = 0, LType y1_ = 0, LType x2_ = INF, LType y2_ = INF) {
		x1 = x1_;
		y1 = y1_;
		x2 = x2_;
		y2 = y2_;
	}

	friend Prostokat operator && (Prostokat pros1, Prostokat pros2) {
		if(pros1.x1 > pros2.x1) swap(pros1, pros2);
		if(pros1.x2 <= pros2.x1) return Prostokat(0, 0, 0, 0);
		LType x1 = pros2.x1, x2 = min(pros1.x2, pros2.x2);
		if(pros1.y1 > pros2.y1) swap(pros1, pros2);
		if(pros1.y2 <= pros2.y1) return Prostokat(0, 0, 0, 0);
		return Prostokat(x1, pros2.y1, x2, min(pros1.y2, pros2.y2));
	}

	LType pole() {
		return (x2 - x1) * (y2 - y1);
	}

	friend istream & operator >> (istream & strum, Prostokat & pros) {
		return strum >> pros.x1 >> pros.y1 >> pros.x2 >> pros.y2;
	}

};

LType ile, wynik;
Prostokat tab[ROZMIAR];
Prostokat pref[ROZMIAR];
Prostokat suf[ROZMIAR];
Prostokat iloczyn;

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
	}
}

void ustawPref() {
	Prostokat akt = pref[0] = tab[0];
	for(int i = 1; i < ile; i++) {
		pref[i] = akt = akt && tab[i];
	}
}

void ustawSuf() {
	Prostokat akt = suf[ile - 1] = tab[ile - 1];
	for(int i = ile - 2; i >= 0; i--) {
		suf[i] = akt = akt && tab[i];
	}
}

int main() {
	wczytaj();
	ustawPref();
	ustawSuf();
	iloczyn = pref[ile - 1];
	for(int i = 0; i < ile; i++) {
		wynik += (pref[i - 1] && suf[i + 1]).pole() - iloczyn.pole();
	}
	wynik += iloczyn.pole();
	cout << wynik;
	return 0;
}
