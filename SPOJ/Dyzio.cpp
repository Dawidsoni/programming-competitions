#include<stdio.h>
#include<algorithm>
using namespace std;

const int rozmiar = 1 << 21;

int drzewo[2 * rozmiar + 1];
int ile;

void buduj_drzewo() {
    for(int i = 0; i < rozmiar; i++) {
        drzewo[i + rozmiar] = drzewo[i];
        drzewo[i] = 0;
    }
    for(int od_kad = rozmiar - 1; od_kad >= 1; od_kad -- ) {
        drzewo[od_kad] = drzewo[od_kad * 2] + drzewo[od_kad * 2 + 1];
    }
}

int suma(int od_k, int do_k) {
    od_k += rozmiar;
    do_k += rozmiar;
    int wynik = drzewo[od_k];
    if(od_k != do_k) wynik += drzewo[do_k];
    while(od_k/2 != do_k/2) {
        if(od_k % 2 == 0) wynik += drzewo[od_k + 1];
        if(do_k % 2 == 1) wynik += drzewo[do_k - 1];
        od_k /= 2;
        do_k /= 2;
    }
    return wynik;
}


int od_k, do_k;

int main() {
    scanf("%d", &ile);
    for(int i=0;i < 2 * rozmiar; i++) {
        drzewo[i] = 1;
    }
    for(int i = 2; i*i <= rozmiar; i++) {
        if(drzewo[i] == 0) continue;
        for(int ii = 2*i; ii <=rozmiar; ii += i) {
            drzewo[ii] = 0;
        }
    }
    drzewo[0] = drzewo[1] = 0;
    buduj_drzewo();
    for(int i=0;i<ile;i++) {
        scanf("%d%d",&od_k,&do_k);
        printf("%d\n",suma(od_k,do_k));
    }
    return 0;
}
