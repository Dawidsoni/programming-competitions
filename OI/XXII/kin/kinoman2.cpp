#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 1100000;
const int TREE_SIZE = 1 << 20;

LType ile, nWart, wynik, ileOdjac;
LType tab[MAX_SIZE], wart[MAX_SIZE], ileJest[MAX_SIZE];
LType drzewo[TREE_SIZE * 2], dMaks[TREE_SIZE * 2];
vector<LType> poz[MAX_SIZE];

void wczytaj() {
    ios_base::sync_with_stdio(false);
    cin >> ile >> nWart;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
    }
    for(int i = 1; i <= nWart; i++) {
        cin >> wart[i];
    }
}

void budujPoz() {
    for(int i = 0; i < ile; i++) {
        poz[tab[i]].push_back(i);
    }
}

void robDrzewo() {
    //cout << "drzewo: \n";
    LType aktWart = 0;
    for(int i = 0; i < ile; i++) {
        ileJest[tab[i]]++;
        if(ileJest[tab[i]] == 1) {
            aktWart += wart[tab[i]];
        }else if(ileJest[tab[i]] == 2) {
            aktWart -= wart[tab[i]];
        }
        drzewo[i] = aktWart;
        wynik = max(wynik, aktWart);
        //cout << drzewo[i] << " ";
    }
    //cout << endl << endl;
}


void budujDrzewo() {
    for(int i = 0; i < TREE_SIZE; i++) {
        drzewo[i + TREE_SIZE] = dMaks[i + TREE_SIZE] = drzewo[i];
        drzewo[i] = 0;
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        dMaks[i] = max(dMaks[i * 2], dMaks[i * 2 + 1]);
    }
}

LType wezMaks(LType odkad, LType dokad) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    LType lMax = 0, pMax = 0;
    while(odkad/2 < dokad/2) {
        lMax += drzewo[odkad];
        pMax += drzewo[dokad];
        if(odkad % 2 == 0) lMax = max(lMax, dMaks[odkad + 1]);
        if(dokad % 2 == 1) pMax = max(pMax, dMaks[dokad - 1]);
        odkad /= 2;
        dokad /= 2;
    }
    while(odkad > 0) {
        lMax += drzewo[odkad];
        pMax += drzewo[dokad];
        odkad /= 2;
        dokad /= 2;
    }
    return max(lMax, pMax);
}


void powieksz(LType odkad, LType dokad, LType war) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    LType odk = odkad/2, dok = dokad/2;
    drzewo[odkad] += war;
    if(odkad != dokad) drzewo[dokad] += war;
    dMaks[odkad] = drzewo[odkad];
    dMaks[dokad] = drzewo[dokad];
    while(odkad/2 < dokad/2) {
        if(odkad % 2 == 0) {
            drzewo[odkad + 1] += war;
            dMaks[odkad + 1] += war;
        }
        if(dokad % 2 == 1) {
            drzewo[dokad - 1] += war;
            dMaks[dokad - 1] += war;
        }
        odkad /= 2;
        dokad /= 2;
    }
    while(odk > 0) {
        dMaks[odk] = max(dMaks[odk * 2], dMaks[odk * 2 + 1]) + drzewo[odk];
        dMaks[dok] = max(dMaks[dok * 2], dMaks[dok * 2 + 1]) + drzewo[dok];
        odk /= 2;
        dok /= 2;
    }
}



void liczWyn() {
    for(int i = 1; i <= nWart; i++) {
        ileJest[i] = 0;
    }
    for(int i = 0; i + 1 < ile; i++) {
        //cout << "ind = " << i << endl;
        ileJest[tab[i]]++;
        LType ind = ileJest[tab[i]];
        LType poczUsuw = i + 1, konUsuw = (ind < poz[tab[i]].size()) ? poz[tab[i]][ind] - 1 : ile - 1;
        LType poczDod = (ind < poz[tab[i]].size()) ? poz[tab[i]][ind] : ile;
        LType konDod = (ind + 1 < poz[tab[i]].size()) ? poz[tab[i]][ind + 1] - 1 : ile - 1;
        //cout << "poczUsuw = " << poczUsuw << " konUsuw = " << konUsuw << " poczDod = " << poczDod << " konDod = " << konDod << endl;
        ileOdjac += wart[tab[i]];
        if(konDod < ile - 1) powieksz(konDod + 1, ile - 1, wart[tab[i]]);
        if(poczDod <= konDod) {
            powieksz(poczDod, konDod, wart[tab[i]] * 2);
            wynik = max(wynik, wezMaks(poczDod, konDod) - ileOdjac);
        }
        //cout << "ileOdjac = " << ileOdjac << endl;
        //cout << "aktWyn = " << wezMaks(i + 1, ile - 1) - ileOdjac << endl << endl << endl;
    }
}

int main() {
    wczytaj();
    budujPoz();
    robDrzewo();
    budujDrzewo();
    liczWyn();
    cout << wynik << "\n";
    return 0;
}
