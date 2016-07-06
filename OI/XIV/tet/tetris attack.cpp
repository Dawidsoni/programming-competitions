#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

class Elem {
public:
	int pierEl, drugEl, wart;
	Elem() {}
	Elem(int pEl, int dEl, int war) : pierEl(pEl), drugEl(dEl), wart(war) {}

	friend bool operator < (const Elem & el1, const Elem & el2) {
		return (el1.drugEl - el1.pierEl) < (el2.drugEl - el1.pierEl);
	}
};


const int MAX_SIZE = 100100;
const int TREE_SIZE = 1 << 18;
int ile, tab[MAX_SIZE], wyn[MAX_SIZE * 10], nWyn;
Elem elem[MAX_SIZE];
set<int> usuniete;
int drzewo[TREE_SIZE * 2];

void powieksz(int numer, int oIle) {
    numer += TREE_SIZE;
    while(numer > 0) {
        drzewo[numer] += oIle;
        numer /= 2;
    }
}

int wezSume(int odkad, int dokad) {
    int wynik = 0;
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    wynik += drzewo[odkad];
    if(odkad != dokad) wynik += drzewo[dokad];
    while(odkad / 2 < dokad / 2) {
        if(odkad % 2 == 0) {
            wynik += drzewo[odkad + 1];
        }
        if(dokad % 2 == 1) {
            wynik += drzewo[dokad - 1];
        }
        odkad /= 2;
        dokad /= 2;
    }
    return wynik;
}

void wczytaj() {
	ios_base::sync_with_stdio(false);
	cin >> ile;
	ile *= 2;
	for(int i = 0; i < ile; i++) {
		cin >> tab[i];
		if(elem[tab[i]].wart == 0) {
			elem[tab[i]] = Elem(i + 1, 0, tab[i]);
		}else {
			elem[tab[i]].drugEl = i + 1;
		}
	}
	ile /= 2;
	sort(elem + 1, elem + ile + 1);
}

void liczWyn() {
	for(int i = 1; i <= ile; i++) {
        int num1 = elem[i].pierEl - wezSume(0, elem[i].pierEl);
        int num2 = elem[i].drugEl - wezSume(0, elem[i].drugEl);
        powieksz(elem[i].pierEl, 1);
        powieksz(elem[i].drugEl, 1);
        for(;num1 + 1 < num2; num1++) {
            wyn[nWyn++] = num1;
        }
	}
}

int main() {
	wczytaj();
	liczWyn();
	cout << nWyn << "\n";
	for(int i = 0; i < nWyn; i++) {
		cout << wyn[i] << "\n";
	}
	return 0;
}
