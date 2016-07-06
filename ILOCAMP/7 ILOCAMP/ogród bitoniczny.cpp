#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> para; //first - dlugosc, second - numer
const int ROZMIAR = 310000;
int nWierz, nKraw, wierz1, wierz2, dlug, liczKraw, wynik;
vector<para> graf[ROZMIAR];

int dlaWierz(int numer, int dlugosc, int sciezka) {
    int aktSciezka = sciezka;
    for(int i = 0; i < graf[numer].size(); i++) {
        if(graf[numer][i].first > dlugosc) {
            sciezka = max(sciezka, dlaWierz(graf[numer][i].second, graf[numer][i].first, aktSciezka));
        }
    }
    return sciezka + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz >> nKraw;
    for(int i = 0; i < nKraw; i++) {
        cin >> wierz1 >> wierz2 >> dlug;
        graf[wierz1].push_back(para(dlug,wierz2));
        graf[wierz2].push_back(para(dlug, wierz1));
    }
    for(int i = 1; i <= nWierz; i++) {
        wynik = max(wynik, dlaWierz(i, 0, 0));
    }
    cout << wynik - 1;
    return 0;
}
