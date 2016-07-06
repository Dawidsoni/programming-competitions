#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;

typedef long long int long_type;
long_type ile, wczytaj, tab_fib[90];

void rob_fib() {
    tab_fib[0] = 0;
    tab_fib[1] = 1;
    for(int i=2;i<90;i++) {
        tab_fib[i] = tab_fib[i-1] + tab_fib[i-2];
    }
}

void wypisz(long_type tab[], int ile) {
    for(int i=0;i<ile;i++) {
        cout << tab[i] << endl;
    }
}

long_type zwroc_wynik(long_type wczytana) {
    long_type bierzacy = 0, ile = 0;
    while(true) {
        ile++;
        long_type * wsk = lower_bound(tab_fib,&tab_fib[90],fabs(wczytana - bierzacy));
        long_type wieksze_od = *wsk, mniejsze_od = *(wsk - 1);
        if(bierzacy<wczytana) {
            if((bierzacy + wieksze_od - wczytana< -1*(bierzacy + mniejsze_od - wczytana) )) {
                bierzacy += wieksze_od;
            }else {
                bierzacy += mniejsze_od;
            }
        }else {
            if(-1*(bierzacy - wieksze_od - wczytana)<bierzacy - mniejsze_od - wczytana) {
                bierzacy -= wieksze_od;
            }else {
                bierzacy -= mniejsze_od;
            }
        }
        if(bierzacy==wczytana) return ile;
    }
}


int main() {
    rob_fib();
    cin >> ile;
    for(int i=0;i<ile;i++) {
        cin >> wczytaj;
        cout << zwroc_wynik(wczytaj) << endl;
    }
    return 0;
}
