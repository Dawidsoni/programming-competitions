#include<stdio.h>
#include<algorithm>
using namespace std;

int tab[1010][1010];
int suma[1010];
int ile, maks;

bool czy_sie_da(int maks_wynik) {
    for(int i=0;i<ile;i++) {
        int ktorego_wywalic = tab[0][i];
        bool czy_mozna = true;
        for(int j=0;j + 1<ile;j++) {
            int ile_obnizyc = ktorego_wywalic + suma[j + 1] - maks_wynik;
            int * wsk = lower_bound(tab[j + 1], tab[j + 1] + ile, ile_obnizyc);
            if(wsk == tab[j + 1] + ile) {
                czy_mozna = false;
                break;
            }
            ktorego_wywalic = *wsk;
        }
        int ile_maks = maks_wynik - (suma[0] - tab[0][i]);
        if(ktorego_wywalic > ile_maks) {
            czy_mozna = false;
        }
        if(czy_mozna) return true;
    }
    return false;
}

int wynik;

int main() {
    scanf("%d", &ile);
    for(int i=0;i<ile;i++) {
        int su = 0;
        for(int j=0;j<ile;j++) {
            scanf("%d", &tab[i][j]);
            su += tab[i][j];
        }
        if(su > maks) maks = su;
        suma[i] = su;
        sort(tab[i], tab[i] + ile);
    }
    wynik = maks;
    for(int od_kad = 0, do_kad = maks;;) {
        int srodek = (od_kad + do_kad)/2;
        if(czy_sie_da(srodek)) {
            if(srodek < wynik)
                wynik = srodek;
            do_kad = srodek;
        }else {
            od_kad = srodek + 1;
        }
        if(od_kad == do_kad) {
            break;
    }
    }
    printf("%d %d",maks, wynik);
    return 0;
}
