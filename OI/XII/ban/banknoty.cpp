#include<iostream>
using namespace std;

const int INF = 1000000000;

int ile, maxWyn;
int nBankt[210], wartBankt[210];
int wynik[20100][210];
int ileWyn[20100];

void wczytaj() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> wartBankt[i];
    }
    for(int i = 0; i < ile; i++) {
        cin >> nBankt[i];
    }
    cin >> maxWyn;
}

int main() {
    wczytaj();
    for(int i = 1; i <= maxWyn; i++) {
        int minWyn = INF, ind = INF;
        for(int j = 0; j < ile; j++) {
            if(i - wartBankt[j] >= 0 && ileWyn[i - wartBankt[j]] + 1 < minWyn && wynik[i - wartBankt[j]][j] < nBankt[j]) {
                minWyn = ileWyn[i - wartBankt[j]] + 1;
                ind = j;
            }
        }
        if(minWyn != INF) {
            for(int j = 0; j < ile; j++) {
                wynik[i][j] = wynik[i - wartBankt[ind]][j];
            }
            wynik[i][ind]++;
        }
        ileWyn[i] = minWyn;
    }
    cout << ileWyn[maxWyn] << endl;
    for(int i = 0; i < ile; i++) {
        cout << wynik[maxWyn][i] << " ";
    }
    return 0;
}
