#include<stdio.h>

int tab[20];

void wypisz(int * wsk, int ile) {
    for(int i=0;i<ile;i++)
        printf("%d ",wsk[i]);
    printf("\n");
}

void zrob_tab(int liczba) {
int ile_liczb = liczba;
    for(int i=0;i<liczba;i++) {
    for(int ii=0;ii+1<ile_liczb;ii++) {
        tab[ii] = 1;
    }
    tab[ile_liczb - 1] = liczba - ile_liczb + 1;
    wypisz(tab,ile_liczb);

    ile_liczb--;
    }
}

int main() {
    int n, wczytaj;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&wczytaj);
    zrob_tab(wczytaj);
    }
    return 0;
}
