#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long int LType;
const int ROZMIAR = 300000;
const LType TREE_SIZE = 1 << 18;
const LType INF = 1200000000;
LType ile, ileMin, ilePyt, odKad, doKad;
LType tab[ROZMIAR];
LType drzewoMin[ROZMIAR * 2][10];
LType drzewoMax[ROZMIAR * 2];

void inicMax() {
    for(int i = 0; i < ile; i++) {
        drzewoMax[i + TREE_SIZE] = tab[i];
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        drzewoMax[i] = max(drzewoMax[i*2], drzewoMax[i*2 + 1]);
    }
}

void laczZbiory(LType * wsk1, LType * wsk2, LType * wynik) {
    int nWsk1 = 0, nWsk2 = 0;
    for(int i = 0; i < 10; i++) {
        if(wsk1[nWsk1] < wsk2[nWsk2]) {
            wynik[i] = wsk1[nWsk1++];
        }else {
            wynik[i] = wsk2[nWsk2++];
        }
    }
}

void inicMin() {
    for(int i = 0; i < ile; i++) {
        drzewoMin[i + TREE_SIZE][0] = tab[i];
        for(int ii = 1; ii < 10; ii++) {
            drzewoMin[i + TREE_SIZE][ii] = INF;
        }
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        laczZbiory(drzewoMin[i*2],drzewoMin[i*2 + 1],drzewoMin[i]);
    }
}

LType pytMax(LType odKad, LType doKad) {
    odKad += TREE_SIZE;
    doKad += TREE_SIZE;
    LType wynik = max(drzewoMax[odKad], drzewoMax[doKad]);
    while(odKad / 2 < doKad / 2) {
        if(odKad % 2 == 0) {
            wynik = max(wynik, drzewoMax[odKad + 1]);
        }
        if(doKad % 2 == 1) {
            wynik = max(wynik, drzewoMax[doKad - 1]);
        }
        odKad /= 2;
        doKad /= 2;
    }
    return wynik;
}

void kopiaTab(LType * zKad, LType * doKad) {
    for(int i = 0; i < 10; i++) {
        doKad[i] = zKad[i];
    }
}

LType pytMin(LType odKad, LType doKad) {
    odKad += TREE_SIZE;
    doKad += TREE_SIZE;
    LType wynik[10], kopia[10];
    laczZbiory(drzewoMin[odKad], drzewoMin[doKad], wynik);
    while(odKad / 2 < doKad / 2) {
        if(odKad % 2 == 0) {
            kopiaTab(wynik,kopia);
            laczZbiory(kopia, drzewoMin[odKad + 1], wynik);
        }
        if(doKad % 2 == 1) {
            kopiaTab(wynik, kopia);
            laczZbiory(kopia, drzewoMin[doKad - 1], wynik);
        }
        odKad /= 2;
        doKad /= 2;
    }
    LType suma = 0;
    for(int i = 0; i < ileMin - 1; i++) {
        suma += wynik[i];
    }
    return suma;
}


int main() {
    scanf("%lld%lld", &ile, &ileMin);
    for(int i = 0; i < ile; i++) {
        scanf("%lld", &tab[i]);
    }
    inicMax();
    inicMin();
    scanf("%lld", &ilePyt);
    for(int i = 0; i < ilePyt; i++) {
        scanf("%lld%lld", &odKad, &doKad);
        odKad--;
        doKad--;
        if(doKad - odKad + 1 < ileMin) printf("TAK\n");
        else if(pytMin(odKad,doKad) > pytMax(odKad, doKad)) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}
