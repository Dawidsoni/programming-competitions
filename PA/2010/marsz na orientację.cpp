#include<iostream>
using namespace std;

const int SIZE = 210000;

int ile, tab[SIZE];

bool liczWyn() {
	int ileRzad = 1;
	for(int i = 1; i < ile; i++) {
		if(tab[i - 1] >= tab[i]) ileRzad++;
		else ileRzad = 1;
		if(ileRzad == ile / 2) return true;
	}
	ileRzad = 1;
	for(int i = 1; i < ile; i++) {
		if(tab[i - 1] <= tab[i]) ileRzad++;
		else ileRzad = 1;
		if(ileRzad == ile / 2) return true;
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> ile;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
		tab[i + ile] = tab[i];
	}
	ile *= 2;
	if(liczWyn()) cout << "TAK";
	else cout << "NIE";
	return 0;
}
