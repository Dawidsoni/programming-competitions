#include <iostream>
#include <algorithm>
#include<set>

using namespace std;

class Butla {
public:
    int nTlen, nAzot, waga;
    Butla() {}
    Butla(int nT, int nA, int wa) : nTlen(nT), nAzot(nA), waga(wa) {}
};

const int MAX_BUTLI = 1100;
const int INF = 100000000;

int ileTlen, ileAzot, ileButli, aktButla, lTlen, lAzot;
Butla butla[MAX_BUTLI];
int wynik[30][90];
set<int> czyByl[30][90];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ileTlen >> ileAzot >> ileButli;
    for(int i = 0; i < ileButli; i++) {
        cin >> butla[i].nTlen >> butla[i].nAzot >> butla[i].waga;
    }
    for(int i = 0; i <= ileTlen; i++) {
        for(int ii = 0; ii <= ileAzot; ii++) {
            if(i == 0 && ii == 0) continue;
            wynik[i][ii] = INF;
            aktButla = -1;
            for(int j = 0; j < ileButli; j++) {
                lTlen = i - butla[j].nTlen >= 0 ? i - butla[j].nTlen : 0, lAzot = ii - butla[j].nAzot >= 0 ? ii - butla[j].nAzot : 0;
                if(wynik[i][ii] > butla[j].waga + wynik[lTlen][lAzot] && czyByl[lTlen][lAzot].count(j) == 0) {
                    wynik[i][ii] = butla[j].waga + wynik[lTlen][lAzot];
                    aktButla = j;
                }
            }
            if(aktButla != -1) {
                czyByl[i][ii] = czyByl[i - butla[aktButla].nTlen >= 0 ? i - butla[aktButla].nTlen : 0][ii - butla[aktButla].nAzot >= 0 ? ii - butla[aktButla].nAzot : 0];
                czyByl[i][ii].insert(aktButla);
            }
        }
    }
    cout << wynik[ileTlen][ileAzot];
    return 0;
}
