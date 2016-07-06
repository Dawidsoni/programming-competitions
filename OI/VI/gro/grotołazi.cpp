#include<iostream>
#include<vector>
using namespace std;

class Krawedz {
public:
    int dokad, numer;
    Krawedz() {}
    Krawedz(int dok, int num) : dokad(dok), numer(num) {}
};

const int MAX_SIZE = 210, MAX_KRAW = 2100000;

int nWierz, wczIle, wczWierz, wynik, numKraw;
vector<int> graf[MAX_SIZE], grupa1, grupa2;
vector<Krawedz> para[MAX_SIZE];
bool czyWysoki[MAX_SIZE], czyNiski[MAX_SIZE], czyByl[MAX_SIZE], czyZajety[MAX_SIZE], czyKraw[MAX_KRAW];


void wczytaj() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz;
    for(int i = 1; i <= nWierz - 1; i++) {
        cin >> wczIle;
        for(int ii = 0; ii < wczIle; ii++) {
            cin >> wczWierz;
            graf[i].push_back(wczWierz);
            if(wczWierz == nWierz) {
                czyNiski[i] = true;
                grupa2.push_back(i);
            }
        }
    }
}

void dodajPary() {
    for(int i = 0; i < graf[1].size(); i++) {
        int wierz = graf[1][i];
        czyWysoki[wierz] = true;
        if(wierz == nWierz) {
            wynik++;
            continue;
        }
        for(int ii = 0; ii < graf[wierz].size(); ii++ ) {
            if(graf[wierz][ii] == nWierz) {
                wynik++;
                break;
            }else if(ii + 1 == graf[wierz].size()) {
                grupa1.push_back(wierz);
            }
        }
    }
}

void dfs(int pocz, int akt) {
    czyByl[akt] = true;
    if(czyNiski[akt] && akt != pocz && czyWysoki[akt] == false && akt != nWierz) {
        czyKraw[numKraw] = true;
        para[pocz].push_back(Krawedz(akt, numKraw));
        para[akt].push_back(Krawedz(pocz, numKraw++));
    }
    for(int i = 0; i < graf[akt].size(); i++) {
        if(czyByl[graf[akt][i]] == false) {
            dfs(pocz, graf[akt][i]);
        }
    }
}

void liczPary() {
    for(int i = 0; i < grupa1.size(); i++) {
        for(int ii = 1; ii <= nWierz; ii++) czyByl[ii] = false;
        dfs(grupa1[i], grupa1[i]);
    }
}

bool dfs(int wierz, bool czyWolna) {
    czyByl[wierz] = true;
    for(int i = 0; i < para[wierz].size(); i++) {
        if(czyByl[para[wierz][i].dokad] == false && czyWolna == czyKraw[para[wierz][i].numer]) {
            if(czyKraw[para[wierz][i].numer] && czyZajety[para[wierz][i].dokad] == false) {
                czyZajety[para[wierz][i].dokad] = true;
                czyKraw[para[wierz][i].numer] = false;
                return true;
            }else {
                bool wynik = dfs(para[wierz][i].dokad, !czyWolna);
                if(wynik == true) {
                    czyKraw[para[wierz][i].numer] = !czyKraw[para[wierz][i].numer];
                    return true;
                }
            }
        }
    }
    return false;
}

bool skojarzona(int wierz) {
    for(int i = 1; i <= nWierz; i++) czyByl[i] = false;
    int wynik = dfs(wierz, true);
    return wynik;
}

int main() {
    wczytaj();
    dodajPary();
    liczPary();
    for(int i = 0; i < grupa1.size(); i++) {
        if(skojarzona(grupa1[i])) wynik++;
    }
    cout << wynik;
    return 0;
}
