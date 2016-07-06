#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;

const int TREE_SIZE = 1 << 19;
const int INF = 100000000;

int tab[TREE_SIZE];
int ile, nPyt, odkad, dokad;
vector<int> drzewo[TREE_SIZE * 2];
int drzewoInd[TREE_SIZE * 2];
vector<int> pozycje[TREE_SIZE];
int czyByl[TREE_SIZE];

inline int ileElem(int elem, int odkad, int dokad) {
    return upper_bound(pozycje[elem].begin(), pozycje[elem].end(), dokad) - lower_bound(pozycje[elem].begin(), pozycje[elem].end(), odkad);
}

inline bool czyLider(int elem, int odkad, int dokad) {
    return ileElem(elem, odkad, dokad) > (dokad - odkad + 1) / 2;
}

vector<int> scalaj(vector<int> wek1, vector<int> wek2) {
    wek1.push_back(INF);
    wek2.push_back(INF);
    int poz1 = 0, poz2 = 0;
    vector<int> wynik;
    for(int i = 0; i < wek1.size() + wek2.size() - 2; i++) {
        if(wek1[poz1] < wek2[poz2]) {
            wynik.push_back(wek1[poz1++]);
        }else {
            wynik.push_back(wek2[poz2++]);
        }
    }
    return wynik;
}

int liderPrzedz(vector<int> & wek) { //-1 - brak ponad polowy wystapien
    if(wek.size() == 0) return -1;
    int przewaga = 1, lider = wek[0];
    for(int i = 1; i < wek.size(); i++) {
        if(przewaga == 0) {
            lider = wek[i];
            przewaga++;
        }else {
            if(wek[i] == lider) przewaga++;
            else przewaga--;
        }
    }
    przewaga = 0;
    for(int i = 0; i < wek.size(); i++) {
        if(wek[i] == lider) przewaga++;
    }
    return przewaga > wek.size() / 2 ? lider : -1;
}

void budujDrzewo() {
    for(int i = 0; i < ile; i++) {
        drzewo[i + TREE_SIZE].push_back(tab[i]);
        drzewoInd[i + TREE_SIZE] = tab[i];
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        drzewo[i] = scalaj(drzewo[i * 2], drzewo[i * 2 + 1]);
        drzewoInd[i] = liderPrzedz(drzewo[i]);
    }
}

int znajdzLidera(int odkad, int dokad, int ktore) {
    int pocz = odkad, kon = dokad;
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    if(czyLider(drzewoInd[odkad], pocz, kon)) return drzewoInd[odkad];
    if(czyLider(drzewoInd[dokad], pocz, kon)) return drzewoInd[dokad];
    czyByl[drzewoInd[odkad]] = czyByl[drzewoInd[dokad]] = ktore;
    while(odkad / 2 < dokad / 2) {
        if((odkad & 1) == 0 && drzewoInd[odkad + 1] != -1 && czyByl[drzewoInd[odkad + 1]] != ktore) {
            if(czyLider(drzewoInd[odkad + 1], pocz, kon)) return drzewoInd[odkad + 1];
            czyByl[drzewoInd[odkad + 1]] = ktore;
        }
        if((dokad & 1) == 1 && drzewoInd[dokad - 1] != -1 && czyByl[drzewoInd[dokad - 1]] != ktore) {
            if(czyLider(drzewoInd[dokad - 1], pocz, kon)) return drzewoInd[dokad - 1];
            czyByl[drzewoInd[dokad - 1]] = ktore;
        }
        odkad /= 2;
        dokad /= 2;
    }
    return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
    vector<int> wek;
    cin >> ile >> nPyt;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
        pozycje[tab[i]].push_back(i);
    }
    budujDrzewo();
    for(int i = 0; i < nPyt; i++) {
        cin >> odkad >> dokad;
        odkad--;
        dokad--;
        cout << znajdzLidera(odkad, dokad, i + 1) << endl;
    }
    return 0;
}
