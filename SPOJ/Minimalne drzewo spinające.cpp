#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> para;
vector<para> wierz[10000100]; //FIRST = ODLEGLOSC, SECOND = NUMER
int n_wierz, n_kraw;
int ile_t, wierz1, wierz2, odl;
bool czy_byl[10001000];

void min_spin() {
    int wynik = 0;
    priority_queue<para, vector<para>, greater<para> > kolej; //FIRST = ODLEGLOSC, SECOND = DO_WIERZ
    for(int i = 0; i < n_wierz; i++) {
        czy_byl[i] = false;
    }
    czy_byl[0] = true;
    for(int i = 0; i < wierz[0].size(); i++) {
        kolej.push(wierz[0][i]);
    }
    while(!kolej.empty()) {
        para w_akt;
        while(!kolej.empty()) {
            w_akt = kolej.top();
            if(czy_byl[w_akt.second] == false) break;
            kolej.pop();
        }
        if(kolej.empty()) break;
        kolej.pop();
        czy_byl[w_akt.second] = true;
        wynik += w_akt.first;
        for(int i = 0; i < wierz[w_akt.second].size(); i++) {
            kolej.push(wierz[w_akt.second][i]);
        }
    }
    printf("%d\n",wynik);
}

int main() {
    scanf("%d",&ile_t);
    for(int i = 0; i < ile_t; i++) {
        getchar();
        scanf("n=%d,m=%d",&n_wierz,&n_kraw);
        for(int i = 0; i < n_wierz; i++) {
            wierz[i].clear();
        }
        for(int i=0;i<n_kraw;++i) {
            getchar();
            scanf("{%d,%d}%d",&wierz1,&wierz2,&odl);
            wierz[wierz1].push_back(para(odl,wierz2));
            wierz[wierz2].push_back(para(odl,wierz1));
        }
        min_spin();
    }
    return 0;
}

