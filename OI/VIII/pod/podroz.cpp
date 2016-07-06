#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<int, int> Para;

const int MAX_SIZE = 2100;
const int INF = 1100000000;

class Linia {
public:
    int ilePrzyst, czestotl;
    vector<int> przyst;
    vector<int> odl;
};

class Krawedz {
public:
    int dokad, waga, minRozp;
    Krawedz() {}
    Krawedz(int dok, int wa, int minR) : dokad(dok), waga(wa), minRozp(minR) {}
};

Linia linia[MAX_SIZE * 2];
int nWierz, nLinii, pocz, kon, godzPocz, minPocz, wczLinia;
vector<Krawedz> graf[MAX_SIZE];
int minOdl[MAX_SIZE];
bool czyByl[MAX_SIZE];

void wczytaj() {
    cin >> nWierz >> nLinii >> pocz >> kon >> godzPocz >> minPocz;
    for(int i = 0; i < nLinii; i++) {
        cin >> linia[i].ilePrzyst >> linia[i].czestotl;
        for(int ii = 0; ii < linia[i].ilePrzyst; ii++) {
            cin >> wczLinia;
            linia[i].przyst.push_back(wczLinia);
        }
        for(int ii = 0; ii + 1 < linia[i].ilePrzyst; ii++) {
            cin >> wczLinia;
            linia[i].odl.push_back(wczLinia);
        }
    }
}

void odwrocLinie() {
    for(int i = 0; i < nLinii; i++) {
        linia[i + nLinii].czestotl = linia[i].czestotl;
        linia[i + nLinii].ilePrzyst = linia[i].ilePrzyst;
        for(int ii = linia[i].przyst.size() - 1; ii >= 0; ii--) {
            linia[i + nLinii].przyst.push_back(linia[i].przyst[ii]);
        }
        for(int ii = linia[i].odl.size() - 1; ii >= 0; ii--) {
            linia[i + nLinii].odl.push_back(linia[i].odl[ii]);
        }
    }
    nLinii *= 2;
}

void dlaLinii(Linia & linia) {
    for(int pocz = 0; pocz < 60; pocz += linia.czestotl) {
        int akt = pocz;
        for(int i = 0; i < linia.odl.size(); i++) {
            graf[linia.przyst[i]].push_back(Krawedz(linia.przyst[i + 1], linia.odl[i], akt));
            akt += linia.odl[i];
            akt %= 60;
        }
    }
}

void robGraf() {
    for(int i = 0; i < nLinii; i++) {
        dlaLinii(linia[i]);
    }
}

void wypiszLinie() {
    for(int i = 0; i < nLinii; i++) {
        cout << linia[i].ilePrzyst << " " << linia[i].czestotl << endl;
        for(int ii = 0; ii < linia[i].przyst.size(); ii++) {
            cout << linia[i].przyst[ii] << " ";
        }
        cout << endl;
        for(int ii = 0; ii < linia[i].odl.size(); ii++) {
            cout << linia[i].odl[ii] << " ";
        }
        cout << endl << endl;
    }
}

void wypiszGraf() {
    for(int i = 1; i <= nWierz; i++) {
        cout << "dla " << i << ": ";
        for(int ii = 0; ii < graf[i].size(); ii++) {
            cout << "{dokad: " << graf[i][ii].dokad << ", waga: " << graf[i][ii].waga << ", minuta: " << graf[i][ii].minRozp << "}, " << endl;
        }
        cout << endl;
    }
}

void dijkstry() {
    for(int i = 1; i <= nWierz; i++) {
        minOdl[i] = INF;
    }
    minOdl[pocz] = minPocz;
    set<Para> kolej;
    kolej.insert(Para(0, pocz));
    for(int i = 1; i <= nWierz; i++) {
        while(czyByl[kolej.begin()->second] == true) {
            kolej.erase(kolej.begin());
        }
        Para akt = *kolej.begin();
        kolej.erase(kolej.begin());
        int wierz = akt.second;
        czyByl[wierz] = true;
        if(wierz == kon) break;
        for(int i = 0; i < graf[wierz].size(); i++) {
            int czasCzekania = graf[wierz][i].minRozp - (minOdl[wierz] % 60);
            if(czasCzekania < 0) czasCzekania += 60;
            if(minOdl[graf[wierz][i].dokad] > minOdl[wierz] + czasCzekania + graf[wierz][i].waga) {
                minOdl[graf[wierz][i].dokad] = minOdl[wierz] + czasCzekania + graf[wierz][i].waga;
                kolej.insert(Para(minOdl[graf[wierz][i].dokad], graf[wierz][i].dokad));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    wczytaj();
    odwrocLinie();
    robGraf();
    //wypiszGraf();
    dijkstry();
    int ileMin = minOdl[kon];
    int ileGodz = godzPocz + ileMin / 60;
    ileMin %= 60;
    ileGodz %= 24;
    cout << ileGodz << " " << ileMin;
    return 0;
}
