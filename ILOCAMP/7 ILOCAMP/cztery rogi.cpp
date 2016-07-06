#include<stdio.h>
#include<algorithm>
using namespace std;

const int ROZMIAR = 2100;
int ile, wynik;
int tab[ROZMIAR][ROZMIAR];

bool przedzKol(int kol1, int kol2) {
    int minEl = -1, maxEl = -1;
    for(int i = 0; i < ile; i++) {
        if(tab[kol1][i] == 1 && tab[kol2][i] == 1) {
            if(minEl == -1) minEl = maxEl = i;
            else maxEl = i;
        }
    }
    if(minEl == -1) return false;
    wynik = max(wynik, (kol2 - kol1 + 1) * (maxEl - minEl + 1));
    return true;
}

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            scanf("%d", &tab[i][ii]);
        }
    }
    for(int i = 0; i < ile; i++) {
        if((ile - i + 1) * ile < wynik) break;
        for(int ii = ile - 1; ii >= i; ii--) {
            przedzKol(i,ii);
            if((ii - i + 1) * ile < wynik) break;
        }
    }
    printf("%d",wynik);
    return 0;
}
