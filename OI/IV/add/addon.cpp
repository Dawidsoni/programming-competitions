#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 10010;

int maks[MAX_SIZE];
bool czyJest[MAX_SIZE];
bool czyUzyc[MAX_SIZE];
int ile, tab[MAX_SIZE], ileMaks, wynik;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
        czyJest[tab[i]] = true;
    }
    ileMaks = tab[ile - 1];
    for(int i = 1; i <= ileMaks; i++) {
        for(int ii = 0; ii < ile; ii++) {
            if(tab[ii] < i) {
                maks[i] = max(maks[i], tab[ii] + maks[i - tab[ii]]);
            }else break;
        }
        if(czyJest[i] && i != maks[i]) {
            czyUzyc[i] = true;
            maks[i] = i;
        }
        if(czyJest[i]) wynik = i;
        if(i == ileMaks || (czyJest[maks[i]] == false && maks[i] != 0)) {
            break;
        }
    }
    cout << wynik << endl;
    for(int i = 1; i <= wynik; i++) {
        if(czyUzyc[i]) cout << i << endl;
    }
    return 0;
}
