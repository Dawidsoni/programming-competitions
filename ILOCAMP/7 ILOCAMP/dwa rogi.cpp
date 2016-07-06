#include<stdio.h>
#include<algorithm>
using namespace std;

const int ROZMIAR = 2100;
int ile;
int tab[ROZMIAR][ROZMIAR];
int minKol[ROZMIAR];
int maxKol[ROZMIAR];
int wynik;

void kolumny(int kol1, int kol2) {
    if(minKol[kol1] == -1 || minKol[kol2] == -1) return ;
    wynik = max(wynik, (kol2 - kol1 + 1) *  (maxKol[kol2] - minKol[kol1] + 1));
}

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        minKol[i] = maxKol[i] = -1;
    }
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            scanf("%d", &tab[i][ii]);
            if(tab[i][ii] == 1) {
                if(minKol[ii] == -1) minKol[ii] = maxKol[ii] = i;
                else maxKol[ii] = i;
            }
        }
    }
    for(int i = 0; i < ile; i++) {
        for(int ii = i; ii < ile; ii++) {
            kolumny(i,ii);
        }
    }
    printf("%d",wynik);
    return 0;
}
