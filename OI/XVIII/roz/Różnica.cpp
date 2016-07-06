#include<iostream>
#include<vector>
#include<climits>
using namespace std;

const int ch_int = 97;
int ile_znakow;
string napis;
vector<int> pozycje[26];
int wynik, maks_wynik;
int tab[1000100];
int ile_tab;

int maks_podtab(int wiecej, int mniej) {
    int w_licz = 0, m_licz = 0, wynik = 0, maks_wynik = 0;
    int ile_tab = pozycje[wiecej].size() + pozycje[mniej].size() - 2;
    for(int i = 0; i < ile_tab; i++) {
        if(pozycje[wiecej][w_licz] < pozycje[mniej][m_licz]) {
            tab[i] = 1;
            w_licz++;
        }else {
            tab[i] = -1;
            m_licz++;
        }
    }
    bool czy_jest_ujemna = false;
    for(int i = 0; i < ile_tab; i++) {
        if(tab[i] == -1) czy_jest_ujemna = true;
        wynik += tab[i];
        if(wynik > maks_wynik && czy_jest_ujemna) maks_wynik = wynik;
        if(wynik > maks_wynik && i + 1 == ile_tab && czy_jest_ujemna == false) maks_wynik = wynik - 1;
        if(wynik < 0) {
            wynik = 0;
            czy_jest_ujemna = false;
        }
    }
    return maks_wynik;
}

int main() {
    cin >> ile_znakow >> napis;
    for(int i = 0; i < ile_znakow; i++) {
        pozycje[napis[i] - 97].push_back(i);
    }
    for(int i = 0; i < 26; i++) {
        pozycje[i].push_back(INT_MAX);
    }
    for(int i = 0; i < 26;i++) {
        for(int j = 0; j < 26; j++) {
            if(i != j && pozycje[i].size() > 1 && pozycje[j].size() > 1) {
                wynik = maks_podtab(i,j);
                if(wynik > maks_wynik) maks_wynik = wynik;
            }
        }
    }
    cout << maks_wynik;
    return 0;
}
