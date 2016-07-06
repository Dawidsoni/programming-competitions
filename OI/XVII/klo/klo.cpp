#include<iostream>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 1000010;

LType ile, nPyt, aktWys, aktSuma, wynik;
LType wczTab[MAX_SIZE], tab[MAX_SIZE], sumPref[MAX_SIZE], maxPref[MAX_SIZE], nPref, aktWyn[MAX_SIZE], nWyn;

void zmienTab() {
	for(int i = 0; i < ile; i++) {
		tab[i] = wczTab[i] - aktWys;
	}
}

void liczSumPref() {
	sumPref[0] = tab[0];
	for(int i = 1; i < ile; i++) {
		sumPref[i] = sumPref[i - 1] + tab[i];
	}
}

void liczMaxPref() {
	nPref = 0;
	nWyn = 0;
	LType maxInd = ile - 1, maxSum = sumPref[ile - 1];
	aktWyn[nWyn++] = ile - 1;
	for(int i = ile - 2; i >= 0; i--) {
		if(sumPref[i] > maxSum) {
			maxSum = sumPref[i];
			maxInd = i;
			aktWyn[nWyn++] = maxInd;
		}
	}
	for(int i = nWyn - 1; i >= 0; i--) {
		maxPref[nPref++] = aktWyn[i];
	}
}

inline LType suma(LType odkad, LType dokad) {
	return sumPref[dokad] - (odkad - 1 < 0 ? 0 : sumPref[odkad - 1]);
}

void liczWyn() {
	wynik = 0;
	liczSumPref();
	liczMaxPref();
	LType aktMax = 0;
	for(int i = 0; i < ile; i++) {
		while(suma(i, maxPref[aktMax + 1]) >= 0 && aktMax + 1 < (int) nPref) {
			aktMax++;
		}
		if(maxPref[aktMax] - i + 1 > wynik && suma(i, maxPref[aktMax]) >= 0) {
			wynik = max(wynik, maxPref[aktMax] - i + 1);
		}
		if(maxPref[aktMax] == i) {
			aktMax++;
		}
	}
	cout << wynik << " ";
}

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile >> nPyt;
	for(int i = 0; i < ile; i++) {
		cin >> wczTab[i];
	}
	for(int i = 0; i < nPyt; i++) {
		cin >> aktWys;
		zmienTab();
		liczWyn();
	}
}

int main() {
	wczytaj();
	return 0;
}