#include<stdio.h>
#include<set>
using namespace std;

struct Para {
    Para() {}
    Para(int wOrg, int wWyn) : wierzOrg(wOrg), wierzWyn(wWyn) {}
    int wierzOrg, wierzWyn;
    friend bool operator < (const Para & p1, const Para & p2) {
        return p1.wierzOrg < p2.wierzOrg;
    }
    friend bool operator == (const Para & p1, const Para & p2) {
        return p1.wierzOrg == p2.wierzOrg;
    }
};

const int ROZMIAR = 400000;
int ile, wynik;
int tab[ROZMIAR];
int tabWyn[ROZMIAR];
int ciag1[ROZMIAR];
int ciag2[ROZMIAR];
int ciag2Pet[ROZMIAR];

void wyznaczWyn() {
    set<Para> zbior; //first - numer, second - numer w tabWyn
    for(int i = 0; i < ile; i++) {
        set<Para>::iterator iter = zbior.find(Para(tab[i],0));
        if(iter == zbior.end()) { //jeœli jeszcze nie ma
            zbior.insert(Para(tab[i], i + 1));
            tabWyn[i] = i + 1;
        }else {
            tabWyn[i] = iter->wierzWyn;
        }
    }
}

void wypisz() {
    for(int i = 0; i < ile; i++) {
        printf("%d ",ciag1[i]);
    }
    printf("\n");
    for(int i = 0; i < ile; i++) {
        printf("%d ",ciag2[i]);
    }
    printf("\n\n");
}

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d", &tab[i]);
    }
    wyznaczWyn();
    for(int i = 0; i < ile; i++) {
        ciag1[tabWyn[i]]++;
        ciag2[tabWyn[i]]++;
    }
    int ileRoznic = 0;
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) ciag2Pet[ii] = ciag2[ii];
        int kopiaRoznic = ileRoznic;
        for(int ii = ile - 1; ii >= 0; ii--) {
            ciag2Pet[tabWyn[ii]]--;
            if(ciag2Pet[tabWyn[ii]] == 0 && ciag1[tabWyn[ii]] == 0) ileRoznic--;
            if(ciag2Pet[tabWyn[ii]] == 0 && ciag1[tabWyn[ii]] > 0) ileRoznic++;
            if(ileRoznic == 0) wynik++;
        }
        ileRoznic = kopiaRoznic;
        ciag1[tabWyn[i]]--;
        if(ciag1[tabWyn[i]] == 0 && ciag2[tabWyn[i]] == 0) ileRoznic--;
        if(ciag1[tabWyn[i]] == 0 && ciag2[tabWyn[i]] > 0) ileRoznic++;
        if(ileRoznic == 0) wynik++;
       // wypisz();
       // printf("ileRoznic: %d\n",ileRoznic);
    }
    printf("%d",wynik + 1);
    return 0;
}
