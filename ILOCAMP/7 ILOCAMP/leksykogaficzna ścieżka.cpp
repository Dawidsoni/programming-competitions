#include<stdio.h>
#include<algorithm>
using namespace std;

class Liczba {
public:
    Liczba() {}
    Liczba(int px, int py, int licz) : pozX(px), pozY(py), liczba(licz) {}
    int pozX, pozY, liczba;
    friend bool operator < (const Liczba & licz1, const Liczba & licz2) {
        if(licz1.liczba < licz2.liczba) return true;
        else return false;
    }
};

const int ROZMIAR = 1100;
const int ILE_LICZB = ROZMIAR * ROZMIAR;
int ile, nSortTab, nWyn;
int tab[ROZMIAR][ROZMIAR];
bool czyZajety[ILE_LICZB];
Liczba sortTab[ILE_LICZB];
Liczba pomoc[ILE_LICZB];
int wynik[ILE_LICZB];

void zajmij(int pozX, int pozY) {
    int lewyX = pozX + 1, lewyY = pozY - 1;
    int prawyX = pozX - 1, prawyY = pozY + 1;
    while(lewyX < ile && czyZajety[tab[lewyX][lewyY]] == false) {
        int kopia = lewyY;
        while(lewyY >= 0 && czyZajety[tab[lewyX][lewyY]] == false) {
            czyZajety[tab[lewyX][lewyY]] = true;
            lewyY--;
        }
        lewyY = kopia;
        lewyX++;
    }
    while(prawyX >= 0 && czyZajety[tab[prawyX][prawyY]] == false) {
        int kopia = prawyY;
        while(prawyY < ile && czyZajety[tab[prawyX][prawyY]] == false) {
            czyZajety[tab[prawyX][prawyY]] = true;
            prawyY++;
        }
        prawyY = kopia;
        prawyX--;
    }
}

void sortuj() {
    for(int i = 0; i <= ile * ile; i++) pomoc[i] = Liczba(-1,-1,-1);
    for(int i = 0; i < nSortTab; i++)
    {
        pomoc[sortTab[i].liczba] = sortTab[i];
    }
    nSortTab = 0;
    for(int i = 0; i <= ile * ile; i++) {
        if(pomoc[i].liczba != -1) sortTab[nSortTab++] = pomoc[i];
    }
}

int main() {
    scanf("%d", &ile);
    nWyn = ile * 2 - 1;
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            scanf("%d", &tab[i][ii]);
            if((i == 0 && ii == 0) || (i + 1 == ile && ii + 1 == ile)) continue;
            sortTab[nSortTab++] = Liczba(i,ii,tab[i][ii]);
        }
    }
    sortuj();
    wynik[0] = tab[0][0];
    for(int i = 0; i < nSortTab; i++) {
        if(czyZajety[sortTab[i].liczba] == false) {
            wynik[sortTab[i].pozX + sortTab[i].pozY] = sortTab[i].liczba;
            zajmij(sortTab[i].pozX, sortTab[i].pozY);
        }
    }
    wynik[nWyn - 1] = tab[ile - 1][ile - 1];
    for(int i = 0; i < nWyn; i++) {
        printf("%d ", wynik[i]);
    }
    return 0;
}
