#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<int, int> Para;

const int SIZE = 260000;
const int TREE_SIZE = 1 << 19;

int nKraw, nZap, wczA, wczB, licznik;
vector<Para> graf[SIZE];
vector<Para> zap[SIZE];
int wynik[SIZE];
bool czyByl[SIZE];
int czyZdarz[TREE_SIZE * 2];
char znak;

int wezSume(int odkad, int dokad) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    int suma = 0;
    suma += czyZdarz[odkad];
    if(odkad != dokad) suma += czyZdarz[dokad];
    while(odkad/2 < dokad/2) {
        if(odkad % 2 == 0) {
            suma += czyZdarz[odkad + 1];
        }
        if(dokad % 2 == 1) {
            suma += czyZdarz[dokad - 1];
        }
        odkad /= 2;
        dokad /= 2;
    }
    return suma;
}

void powieksz(int numer, int wart) {
    numer += TREE_SIZE;
    while(numer > 0) {
        czyZdarz[numer] += wart;
        numer /= 2;
    }
}


void wczytaj() {
    ios_base::sync_with_stdio(false);
    cin >> nKraw;
    for(int i = 0; i + 1 < nKraw; i++) {
        cin >> wczA >> wczB;
    }
    cin >> nZap;
    for(int i = 0; i < nKraw + nZap - 1; i++) {
        cin >> znak;
        if(znak == 'A') {
            cin >> wczA >> wczB;
            graf[wczA].push_back(Para(wczB, i));
        }else {
            cin >> wczA;
            zap[wczA].push_back(Para(i, licznik++));
        }
    }
}

void dfs(int wierz, int odl) {
    for(int i = 0; i < zap[wierz].size(); i++) {
        wynik[zap[wierz][i].second] = odl - wezSume(0, zap[wierz][i].first);
    }
    czyByl[wierz] = true;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i].first] == false) {
            powieksz(graf[wierz][i].second, 1);
            dfs(graf[wierz][i].first, odl + 1);
            powieksz(graf[wierz][i].second, -1);
        }
    }
}

int main() {
    wczytaj();
    dfs(1, 0);
    for(int i = 0; i < nZap; i++) {
        cout << wynik[i] << "\n";
    }
    return 0;
}
