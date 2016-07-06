#include<stdio.h>

int tab[500][500];

void wypisz(int wier, int kol) {
    for(int i=0;i<wier;i++) {
    for(int ii=0;ii<kol;ii++) {
        printf("%d ",tab[i][ii]);
    }
    printf("\n");
    }
}

void rob_tabele(int wier, int kol) {
    for(int i=0;i<wier;i++) {
    for(int ii=0;ii<kol;ii++) {
    scanf("%d",&tab[i][ii]);
    }
    }
    int kopia = tab[wier-1][0],  kopia2 = tab[wier-1][kol-1];
    for(int i=wier-1;i>0;i--) {
        tab[i][0] = tab[i-1][0];
    }
    for(int i=kol-1;i>1;i--) {
        tab[wier-1][i] = tab[wier-1][i-1];
    }
    tab[wier-1][1] = kopia;
    kopia = tab[0][kol-1];
    for(int i=0;i+2<wier;i++) {
        tab[i][kol-1] = tab[i+1][kol-1];
    }
    tab[wier-2][kol-1] = kopia2;
    for(int i=0;i+2<kol;i++) {
        tab[0][i] = tab[0][i+1];
    }
    tab[0][kol - 2] = kopia;
    wypisz(wier,kol);
}


int main() {
    int n, wier, kol;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
    scanf("%d",&wier);
    scanf("%d",&kol);
    rob_tabele(wier,kol);
    }

    return 0;
}
