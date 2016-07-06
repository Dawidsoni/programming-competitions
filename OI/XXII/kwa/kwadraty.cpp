#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long int LType;
const LType INF = -1;
const LType MAX_SIZE = 50000;
const LType MAX_SUM = 1500000;

LType ile;
LType tab[MAX_SUM];
LType suma[MAX_SUM];
LType wynik[MAX_SIZE];
bool czyPrzer[MAX_SIZE];
LType nPrzer[MAX_SIZE];
LType nInf[150];

void wyznaczTab() {
    for(LType i = 0; i < MAX_SUM; i++) {
        tab[i] = i * i;
    }
}

void wyznaczSume() {
    for(LType i = 1; true; i++) {
        suma[i] = suma[i - 1] + tab[i];
        if(i >= 50 && suma[i] > ile) {
            break;
        }
    }
}

void liczWyn() {
    for(LType i = 1; i <= suma[50]; i++) {
        wynik[i] = INF;
        for(LType ii = 0; tab[ii] <= i; ii++) {
            if(tab[ii] == i || (wynik[i - tab[ii]] != INF && sqrt(tab[ii]) > wynik[i - tab[ii]])) {
                wynik[i] = sqrt(tab[ii]);
                break;
            }
        }
    }
}

void liczPrzer() {
    LType aktMin = suma[50], ileP = 0;
    for(LType i = suma[50]; i >= 1; i--) {
        if(wynik[i] == INF) {
            czyPrzer[i] = true;
            continue;
        }
        aktMin = min(aktMin, wynik[i]);
        if(wynik[i] > aktMin) czyPrzer[i] = true;
    }
    for(LType i = 1; i <= suma[50]; i++) {
        if(czyPrzer[i]) ileP++;
        nPrzer[i] = ileP;
    }
}

void wyznaczInf() {
    int akt = 0;
    for(int i = 1; i < 150; i++) {
        if(wynik[i] == INF) akt++;
        nInf[i] = akt;
    }
}

void wypiszMaly() {
    if(wynik[ile] == INF) {
        cout << "- " << nPrzer[ile];
    }else {
        cout << wynik[ile] << " " << nPrzer[ile];
    }
}

void wypiszDuzy() {
    LType aktInd = 0, wynPrzer = nPrzer[suma[50]];
    for(LType i = 1;; i++) {
        if(i > 50) {
            wynPrzer += 31;
        }
        if(suma[i + 1] >= ile) {
            aktInd = i + 1;
            break;
        }
    }
    if(suma[aktInd] - ile <= 150 && suma[aktInd] - ile - 1 >= 0) {
        wynPrzer += 31;
        wynPrzer -= nInf[suma[aktInd] - ile - 1];
    }
    if(suma[aktInd] - ile <= 150 && wynik[suma[aktInd] - ile] == INF) {
        cout << aktInd + 1 << " " << wynPrzer;
    }else {
        cout << aktInd << " " << wynPrzer;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    wyznaczTab();
    wyznaczSume();
    liczWyn();
    liczPrzer();
    wyznaczInf();
    if(ile <= suma[50]) wypiszMaly();
    else wypiszDuzy();
    return 0;
}
