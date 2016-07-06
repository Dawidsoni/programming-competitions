#include<stdio.h>

typedef unsigned long long int typ_long;

typ_long nwd(typ_long a, typ_long b) {
    return b==0 ? a : nwd(b,a%b);
}

int main() {
    typ_long n, ile, wczytaj, wynik;
    scanf("%llu",&n);
    for(int i=0;i<n;i++) {
        scanf("%llu",&ile);
        wynik = 1;
        for(int ii=0;ii<ile;ii++) {
            scanf("%llu",&wczytaj);
            wynik = wynik/nwd(wynik,wczytaj)*wczytaj;
        }
        printf("%llu\n",wynik);
    }

    return 0;
}
