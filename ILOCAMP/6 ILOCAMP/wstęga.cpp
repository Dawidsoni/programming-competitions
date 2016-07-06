#include<stdio.h>

int ile_pocz, ile_kon;
int tab[300010];
int maks_prawa, maks_lewa, min_prawa, min_lewa;
int wczytaj;

int wart_bez(int a) {
    if(a < 0) return -a;
    else return a;
}
int main() {
    scanf("%d %d", &ile_pocz, &ile_kon);
    for(int i=0;i<ile_pocz; i++) {
        scanf("%d", &tab[i]);
    }
    min_lewa = tab[0];
    min_prawa = tab[ile_pocz - 1];
    for(int i=0;i + 1<ile_pocz;i++) {
        if(tab[i] > maks_lewa) maks_lewa = tab[i];
    }
    for(int i=ile_pocz - 1; i >= 1; i--) {
        if(tab[i] > maks_prawa) maks_prawa = tab[i];
    }
    int ostatni = tab[ile_pocz - 1];
    for(int i=0;i<ile_kon;i++) {
        scanf("%d", &wczytaj);
        if(ostatni > maks_lewa) maks_lewa = ostatni;
        min_prawa = wczytaj;
        if(wczytaj > maks_prawa) maks_prawa = wczytaj;
        //printf("%d %d %d %d\n", maks_lewa,min_lewa,maks_prawa,min_prawa);
        int wyn1 = wart_bez(maks_lewa - min_prawa);
        int wyn2 = wart_bez(maks_prawa - min_lewa);
        if(wyn1 > wyn2) printf("%d ", wyn1);
        else printf("%d ", wyn2);
        ostatni = wczytaj;
    }

    return 0;
}
