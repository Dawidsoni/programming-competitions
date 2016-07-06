#include<iostream>
#include<algorithm>
using namespace std;

const int ILE_MAX = 1100000;
const int TREE_SIZE = 1 << 20;

class Wierz {
public:
    int wspX, wspY, nPas;
};

bool sortX(const Wierz & w1, const Wierz & w2) {
    if(w1.wspX == w2.wspX) return w1.wspY < w2.wspY;
    return w1.wspX < w2.wspX;
}

bool sortY(const Wierz & w1, const Wierz & w2) {
    return w1.wspY < w2.wspY;
}


Wierz wierz[ILE_MAX];
int dlug, szer, ile, wynik;
int drzewo[TREE_SIZE * 2];

int zwrocMax(int odkad, int dokad) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    int wyn = max(drzewo[odkad], drzewo[dokad]);
    while(odkad / 2 < dokad / 2) {
        if(odkad % 2 == 0) wyn = max(wyn, drzewo[odkad + 1]);
        if(dokad % 2 == 1) wyn = max(wyn, drzewo[dokad - 1]);
        odkad /= 2;
        dokad /= 2;
    }
    return wyn;
}

void ustaw(int poz, int naIle) {
    poz += TREE_SIZE;
    drzewo[poz] = naIle;
    poz /= 2;
    while(poz > 0) {
        drzewo[poz] = max(drzewo[poz * 2], drzewo[poz * 2 + 1]);
        poz /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> dlug >> szer >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> wierz[i].wspX >> wierz[i].wspY >> wierz[i].nPas;
    }
    sort(wierz, wierz + ile, sortY);
    for(int i = 1, war = 1; i <= ile; war++, i++) {
        while(i <= ile && wierz[i].wspY == wierz[i - 1].wspY) {
            wierz[i - 1].wspY = war;
            i++;
        }
        wierz[i - 1].wspY = war;
    }
    sort(wierz, wierz + ile, sortX);
    for(int i = 0; i < ile; i++) {
        int maks = zwrocMax(1, wierz[i].wspY);
        ustaw(wierz[i].wspY, maks + wierz[i].nPas);
        wynik = max(wynik, maks + wierz[i].nPas);
    }
    cout << wynik;
    return 0;
}
