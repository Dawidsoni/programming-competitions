#include<stdio.h>
#include<climits>
#include<algorithm>
#include<functional>
using namespace std;

long long int ile_tax, do_tax, do_cel, wczytaj, konczaca_min,
konczaca = LONG_LONG_MAX, licznik = 0;
long long int tax[500000];

long long int generuj() {
    if(konczaca==LONG_LONG_MAX) {
        return 0;
    }
    for(int i=0;i+1<ile_tax;i++,licznik++) {
        if(konczaca>=do_cel+do_tax) {
            return licznik + 1;
        }
        if(tax[i]>=do_cel+do_tax) {
            return licznik + 1;
        }
        if(tax[i]>=do_tax*2) {
            return licznik + 2;
        }
        if(do_tax>=tax[i]) {
            return 0;
        }
        long long int o_ile_przes = tax[i] - do_tax;
        do_tax -= o_ile_przes;
        do_cel -= o_ile_przes;
    }
        if(do_cel<=0) {
            return licznik + 1;
        }
        if(do_tax<=0) {
            return licznik + 2;
        }
        return 0;
}

int main() {
    scanf("%lld",&do_cel);
    scanf("%lld",&do_tax);
    scanf("%lld",&ile_tax);
    konczaca_min = do_cel - do_tax;
    for(int i=0,licz = 0;licz<ile_tax;licz++) {
        scanf("%lld",&wczytaj);
        if(wczytaj>=konczaca_min&&wczytaj<konczaca) {
            if(konczaca!=LONG_LONG_MAX) {
                tax[i] = konczaca;
                i++;
            }
            konczaca = wczytaj;
        }else {
            tax[i] = wczytaj;
            i++;
        }
    }
    sort(tax,tax+ile_tax-1,greater<long long int>());
    printf("%lld",generuj());
    return 0;
}
