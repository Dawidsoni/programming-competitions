#include<iostream>

using namespace std;

const int ROZMIAR = 510000;
int ile, nPyt, wczP, wczK;
int tab[ROZMIAR];
int dlaZap[ROZMIAR];
int ileJest[ROZMIAR];

int main() {
    cin >> ile >> nPyt;
    for(int i = 0; i < ile; i++) cin >> tab[i];
    for(int i = 0; i < nPyt; i++) {
        cin >> wczP >> wczK;
        wczP--;
        wczK--;
        for(int ii = wczP; ii <= wczK; ii++) {
            if(dlaZap[tab[ii]] != i) {
                dlaZap[tab[ii]] = i;
                ileJest[tab[ii]] = 0;
            }
            ileJest[tab[ii]]++;
            if(ileJest[tab[ii]] > (wczK - wczP + 1)/2) {
                cout << tab[ii] << endl;
                break;
            }
            if(ii == wczK) cout << "0" << endl;
        }
    }
    return 0;
}
