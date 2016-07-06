#include<stdio.h>
using namespace std;

typedef long long int long_type;


bool czy_palindron(long_type liczba) {
    long_type tab[10000];
    long_type ile_cyfr = 0;
    for(long_type podziel_przez = 1 ; liczba != 0 ; podziel_przez *= 10, ile_cyfr++) {
        long_type licz = liczba%(podziel_przez * 10);
        liczba -= licz;
        licz /= podziel_przez;
        tab[ile_cyfr] = licz;
    }
    for(long_type i=0, j = ile_cyfr - 1; i < j; i++, j--) {
        if(tab[i]!=tab[j]) return false;
    }
    return true;
}

long_type dziwnie_dodaj(long_type liczba) {
    long_type tab[10000];
    long_type ile_cyfr = 0;
    long_type podziel_przez = 1;
    for(; liczba != 0 ; podziel_przez *= 10, ile_cyfr++) {
        long_type licz = liczba%(podziel_przez * 10);
        liczba -= licz;
        licz /= podziel_przez;
        tab[ile_cyfr] = licz;
    }
    podziel_przez /= 10;
    long_type wynik = 0;
    for(long_type i = 0, j = ile_cyfr - 1; i<ile_cyfr; i++, j--, podziel_przez /= 10) {
        wynik += tab[i] * podziel_przez;
        wynik += tab[j] * podziel_przez;
    }
    return wynik;
}

long_type ile, liczba, n_dodawan;

int main() {
    scanf("%dll", &ile);
    for(int i=0;i<ile;i++) {
        scanf("%lld",&liczba);
        n_dodawan = 0;
        while(!czy_palindron(liczba)) {
            liczba = dziwnie_dodaj(liczba);
            n_dodawan++;
        }
        printf("%lld %lld \n",liczba, n_dodawan);
    }
    return 0;
}
