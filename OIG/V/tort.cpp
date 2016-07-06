#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int LType;

const int SIZE = 210000;

LType maxDlug, maxSzer, nDziel, ileMn, wczytaj;
LType dlug[SIZE];
LType szer[SIZE];

LType ileNieMn(LType maxPole) {
    LType wynik = 0;
    int wskDlug = nDziel - 1;
    for(int i = 0; i < nDziel; i++) {
        while(wskDlug >= 0 && dlug[wskDlug] * szer[i] >= maxPole) wskDlug--;
        wynik += (nDziel - 1 - wskDlug);
    }
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> maxDlug >> maxSzer >> nDziel >> ileMn;
    for(int i = 0; i < nDziel; i++) {
        LType ost = wczytaj;
        cin >> wczytaj;
        dlug[i] = wczytaj - ost;
    }
    dlug[nDziel] = maxDlug - wczytaj;
    wczytaj = 0;
    for(int i = 0; i < nDziel; i++) {
        LType ost = wczytaj;
        cin >> wczytaj;
        szer[i] = wczytaj - ost;
    }
    szer[nDziel] = maxSzer - wczytaj;
    nDziel++;
    sort(dlug, dlug + nDziel);
    sort(szer, szer + nDziel);
    LType odkad = 1, dokad = maxDlug * maxSzer;
    while(odkad < dokad) {
        LType srednia = (odkad + dokad + 1) / 2;
        LType ileW = ileNieMn(srednia);
        if(ileW >= ileMn) {
            odkad = srednia;
        }else {
            dokad = srednia - 1;
        }
    }
    cout << odkad << endl;
    return 0;
}
