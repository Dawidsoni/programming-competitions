#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_WIERZ = 1010;
const int MAX_POLAN = 2010;

class Krawedz {
public:
    int dokad;
    int waga;
    Krawedz() {}
    Krawedz(int dok, int wag) : dokad(dok), waga(wag) {}
};


int nWierz, nPolan, nKraw, kraw1, kraw2, waga, nWyciagow, polStart, maxWyn, wynik;
vector<Krawedz> graf[MAX_WIERZ];
bool czyByl[MAX_WIERZ * MAX_POLAN];

void wczytaj() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz >> nPolan >> nKraw;
    for(int i = 0; i < nKraw; i++) {
        cin >> kraw1 >> kraw2;
        graf[kraw1].push_back(Krawedz(kraw2, 0));
    }
    cin >> nWyciagow;
    for(int i = 0; i < nWyciagow; i++) {
        cin >> kraw1 >> kraw2 >> waga;
        graf[kraw1].push_back(Krawedz(kraw2, waga));
    }
    cin >> polStart >> maxWyn;
}

int numer(int wyn, int wierz) {
    return wyn * nWierz + wierz;
}

vector<Krawedz> robKraw(int num) {
    int wyn = num / nWierz;
    int wierz = num % nWierz;
    if(wierz == 0) {
        wyn--;
        wierz += nWierz;
    }
    vector<Krawedz> wynik;
    for(int i = 0; i < graf[wierz].size(); i++) {
        int sasWyn = wyn - graf[wierz][i].waga;
        if(sasWyn >= 0) {
            int sasNum = numer(sasWyn, graf[wierz][i].dokad);
            wynik.push_back(Krawedz(sasNum, graf[wierz][i].waga));
        }
    }
    return wynik;
}

void dfs(int wierz, int odl) {
    czyByl[wierz] = true;
    if(wierz % nWierz <= nPolan && wierz % nWierz != 0) wynik = max(wynik, odl);
    vector<Krawedz> przestrzen = robKraw(wierz);
    for(int i = 0; i < przestrzen.size(); i++) {
        if(czyByl[przestrzen[i].dokad] == false && odl +  przestrzen[i].waga <= maxWyn) {
            dfs(przestrzen[i].dokad, odl +  przestrzen[i].waga);
        }
    }
}

int main() {
    wczytaj();
    dfs(numer(maxWyn, polStart), 0);
    cout << maxWyn - wynik;
    return 0;
}
