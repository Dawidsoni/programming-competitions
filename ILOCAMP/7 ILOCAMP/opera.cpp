#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

typedef unsigned long long LType;
const int ROZMIAR = 1100;
int ile, ileKat, ileK, wynik;
int ileJest[ROZMIAR * ROZMIAR];
unsigned potTab[ROZMIAR * 2];
unsigned stP = 1000000033;
unsigned stM = 1000000087;

void wyznaczPot() {
    potTab[0] = 1;
    for(int i = 1; i < ROZMIAR * 2; i++) potTab[i] = ((LType)potTab[i - 1] * stP) % stM;
}

multiset<unsigned> hashe;

class Ciag {
public:
    int tab[ROZMIAR * 2];
    unsigned wyznaczHash() {
        unsigned hash = (tab[0]);
        for(int i = 1; i < ile; i++) {
            hash = ((LType)hash + (LType)(tab[i]) * stP) % stM;
        }
        return hash;
    }

    void posortuj() {
        sort(tab, tab + ile);
    }
};

Ciag ciag[ROZMIAR];
Ciag sumaElem;

void wyznaczTab() {
    int licz = 0;
    for(int i = 1; i <= ileKat; i++) {
        for(int ii = 1; ii <= ileJest[i] - ileK; ii++) {
            sumaElem.tab[licz++] = i;
        }
    }
}

Ciag odejmijCiagi(Ciag & ciag1, Ciag & ciag2) {
    Ciag wynik;
    int licz = 0;
    int i1 = 0, i2 = 0;
    while(true) {
        int pocz1 = i1, pocz2 = i2;
        while(ciag1.tab[i1] == ciag1.tab[i1 + 1] && i1 < ile * 2) {
            i1++;
        }
        while(ciag2.tab[i2] == ciag2.tab[i2 + 1] && ciag2.tab[i2] == ciag1.tab[i1] && i2 < ile ) {
            i2++;
        }
        if(i2 == ile) i2--;
        for(int i = 0; i < (i1 - pocz1) - (i2 - pocz2); i++) {
            wynik.tab[licz++] = ciag1.tab[i1];
        }
        i1++;
        i2++;
        if(i1 == ile*2) break;
    }
    return wynik;
}

int main() {
    scanf("%d%d", &ile, &ileKat);
    wyznaczPot();
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            scanf("%d", &ciag[i].tab[ii]);
            ileJest[ciag[i].tab[ii]]++;
        }
        ciag[i].posortuj();
        hashe.insert(ciag[i].wyznaczHash());
    }
    int suma = 0;
    for(int i = 1; i <= ileKat; i++) {
        suma += (ileJest[i] - ileKat);
    }
    ileK = ileKat + (suma - ile * 2) / ileKat;
    if((suma - ile * 2) % ileKat != 0 || suma < 0) {
        printf("0");
        return 0;
    }
    for(int i = 1; i <= ileKat; i++) {
        if(ileJest[i] < ileK) {
            printf("0");
            return 0;
        }
    }
    wyznaczTab();
    for(int i = 0; i < ile; i++) {
        Ciag wynCiag = odejmijCiagi(sumaElem, ciag[i]);
        wynCiag.posortuj();
        unsigned hash = wynCiag.wyznaczHash();
        wynik += hashe.count(hash);
        if(hash == ciag[i].wyznaczHash()) wynik--;
    }
    printf("%d",wynik/2);
    return 0;
}
