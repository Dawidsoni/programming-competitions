#include<stdio.h>
using namespace std;

inline bool czy_pierwsza(int liczba) {
    for(int i=2;i<=liczba/2;i++) {
        if(liczba%i==0)
            return false;
    }
    if(liczba==1) return false;
    return true;
}


int main() {
    int ile, wczytaj;
    bool * wsk;
    scanf("%d",&ile);
    wsk = new bool[ile];
    for(int i=0;i<ile;i++) {
        scanf("%d",&wczytaj);
        wsk[i] = czy_pierwsza(wczytaj);
    }
    for(int i=0;i<ile;i++) {
        if(wsk[i]==true)
            printf("TAK\n");
        else
            printf("NIE\n");
    }

    return 0;
}
