#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

int ile_miast;
int ile_kraw;
int ile_kasyn;
int wczytaj;
int k1, k2, odl;
int kasyno[10010];
typedef pair<int, int>  para;
vector<para> tab[10010];
bool czy_juz[10010];
set<para> kolej;
int wynik[10010];
int naj_zarobek;
// 1 = odleglosc
// 2 = wierz

int main() {
    scanf("%d %d %d", &ile_miast, &ile_kraw, &ile_kasyn);
    for(int i=0;i<ile_kasyn;i++) {
        scanf("%d", &wczytaj);
        kasyno[i + 1] = wczytaj;
    }
    for(int i=0; i<ile_kraw;i++) {
        scanf("%d %d %d", &k1, &k2, &odl);
        tab[k1].push_back(para(odl,k2));
        tab[k2].push_back(para(odl,k1));
    }
    int numer = 0;
while(true) {
    for(int i=0;i<ile_miast;i++) {
        czy_juz[i] = false;
    }
    czy_juz[numer] = true;
    for(int i=0;i<ile_miast;i++) {
        wynik[i] = 100000000;
    }
    wynik[numer] = 0;
    for(int i=0;i<tab[numer].size();i++) {
        kolej.insert(tab[numer][i]);
        wynik[tab[numer][i].second] = tab[numer][i].first;
    }
    while(!kolej.empty()) {
        while(czy_juz[kolej.begin()->second]) kolej.erase(kolej.begin());
        para najmniejsza = *kolej.begin();
        kolej.erase(kolej.begin());
        for(int i=0;i<tab[najmniejsza.second].size();i++) {
            int x = wynik[tab[najmniejsza.second][i].second];
            int y = wynik[najmniejsza.second] + tab[najmniejsza.second][i].first;
            if(x > y) {
                wynik[tab[najmniejsza.second][i].second] = y;
                kolej.insert(para(x,tab[najmniejsza.second][i].second));
            }
        }
    }
    int max = 0, indeks = 0;
    for(int i=0;i<ile_miast;i++) {
        if(kasyno[i] - wynik[i] > max) {
            max = kasyno[i] - wynik[i];
            indeks = i;
        }
    }
    if(max <= 0) break;
    kasyno[indeks] = 0;
    naj_zarobek += max;
    numer = indeks;
}
    printf("%d", naj_zarobek);
    //for(int i=0;i<ile_miast;i++) {
    //    printf("%d ", wynik[i]);
    //}

    return 0;
}
