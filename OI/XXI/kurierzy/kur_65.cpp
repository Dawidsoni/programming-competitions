#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

const int ROZMIAR = 510000;
const int ILE_LOS = 35;
int ile, nPyt, odkad, dokad;
int tab[ROZMIAR];
vector<int> pozycje[ROZMIAR];

int losuj(int odkad, int dokad) {
    return rand() % (dokad - odkad + 1) + odkad;
}

int ileElem(int elem, int odkad, int dokad) {
    return upper_bound(pozycje[elem].begin(), pozycje[elem].end(), dokad) - lower_bound(pozycje[elem].begin(), pozycje[elem].end(), odkad);
}


int main() {
    srand(time(0));
    cin >> ile >> nPyt;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
        pozycje[tab[i]].push_back(i);
    }
    for(int i = 0; i < nPyt; i++) {
        cin >> odkad >> dokad;
        odkad--;
        dokad--;
        int wynik = 0;
        for(int i = 0; i < ILE_LOS; i++) {
            int ind = losuj(odkad, dokad);
            if(ileElem(tab[ind], odkad, dokad) > (dokad - odkad + 1) / 2) {
                wynik = tab[ind];
                break;
            }
        }
        cout << wynik << endl;
    }
    return 0;
}
