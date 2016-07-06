#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 10100;

int nWierz, nKraw, kraw1, kraw2, aktWyn, wynik, wierz1, wierz2, minWierz;
vector<int> graf[MAX_SIZE];

int droga(int pocz1, int pocz2, int wierz1, int wierz2) {
    int wynik = 0;
    while(wierz1 < wierz2 && wierz1 < pocz2) {
        int pocz = wierz1;
        for(int i = 0; i < graf[pocz].size(); i++) {
            wierz1 = max(wierz1, graf[pocz][i]);
        }
        if(pocz == wierz1) wierz1++;
        if(pocz1 != wierz1) wynik++;
    }
    return wynik;
}

int liczWyn(int wierz1, int wierz2) {
    int num1 = 0, num2 = 0, odl1 = 0, odl2 = 0;
    for(int i = 0; i < graf[wierz1].size(); i++) {
        int aktOdl = wierz1 < graf[wierz1][i] ? (wierz1 + nWierz - graf[wierz1][i]) : wierz1 - graf[wierz1][i];
        if(aktOdl > odl1) {
            odl1 = aktOdl;
            num1 = graf[wierz1][i];
        }
    }
    for(int i = 0; i < graf[wierz2].size(); i++) {
        int aktOdl = graf[wierz2][i] < wierz2 ? (graf[wierz2][i] + nWierz - wierz2) : (graf[wierz2][i] - wierz2);
        if(aktOdl > odl2) {
            odl2 = aktOdl;
            num2 = graf[wierz2][i];
        }
    }
    if(nWierz < wierz2) {
        num1 += nWierz;
        num2 += nWierz;
    }
    if(num1 == wierz2 || num2 == wierz1) return (wierz2 - wierz1 + 1);
    //cout << "dla " << wierz1 << " " << wierz2 << " jest " << num1 << " " << num2 << " wyn = " << wynik << endl;
    return wierz2 - wierz1 + 2 + droga(wierz1, wierz2, min(num1, num2), max(num1, num2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz >> nKraw;
    for(int i = 0; i < nKraw; i++) {
        cin >> kraw1 >> kraw2;
        graf[kraw1].push_back(kraw2);
        graf[kraw1 + nWierz].push_back(kraw2);
        graf[kraw2].push_back(kraw1);
        graf[kraw2 + nWierz].push_back(kraw1);
    }
    for(int i = 1; i <= nWierz; i++) {
        if(graf[i].size() > 0) {
            if(wierz1 == 0) wierz1 = minWierz = i;
            else if(wierz2 == 0) wierz2 = i;
            else {
                wierz1 = wierz2;
                wierz2 = i;
            }
            if(wierz2 != 0) {
                wynik = max(wynik, liczWyn(wierz1, wierz2));
            }
        }

    }
    wynik = max(wynik, liczWyn(wierz2,minWierz + nWierz));
    cout << wynik;
    return 0;
}
