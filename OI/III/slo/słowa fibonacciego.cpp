#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int LType;
const int MAX_DLUG = 120, MAX_WYN = 210;

string wzor, fib[MAX_WYN], tab[MAX_WYN];
LType ile, wynik;

int ileJest(string wzor, string wyraz) {
    if(wzor.size() > wyraz.size()) return 0;
    int wynik = 0;
    for(int i = 0; i < wyraz.size() - wzor.size() + 1; i++) {
        for(int ii = 0; ii < wzor.size(); ii++) {
            if(wzor[ii] != wyraz[i + ii]) break;
            if(ii + 1 == wzor.size()) wynik++;
        }
    }
    return wynik;
}

string dodaj(string licz1, string licz2) {
    string wynik = "";
    int ileDodac = 0;
    for(int i = licz1.size() - 1, j = licz2.size() - 1, licz = 0; i >= 0 || j >= 0; i--, j--, licz++) {
        int cyfr1 = i < 0 ? 0 : (licz1[i] - '0');
        int cyfr2 = j < 0 ? 0 : (licz2[j] - '0');
        int wyn = cyfr1 + cyfr2 + ileDodac;
        if(wyn >= 10) {
            wyn -= 10;
            ileDodac = 1;
        }else {
            ileDodac = 0;
        }
        wynik += (wyn + '0');
    }
    if(ileDodac) wynik += "1";
    string odwrWynik = "";
    for(int i = wynik.size() - 1; i >= 0; i--) {
        odwrWynik += wynik[i];
    }
    return odwrWynik == "" ? "0" : odwrWynik;
}

string int_to_string(int licz) {
    string wynik = "";
    for(int i = 10; licz != 0; i *= 10) {
        int akt = ((licz % i) / (i / 10));
        wynik += (akt + '0');
        licz -= (akt * i / 10);
    }
    string odwrWynik = "";
    for(int i = wynik.size() - 1; i >= 0; i--) {
        odwrWynik += wynik[i];
    }
    return odwrWynik == "" ? "0" : odwrWynik;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> wzor >> ile;
    fib[1] = "b";
    fib[2] = "a";
    tab[1] = (wzor == fib[1]) ? "1" : "0";
    tab[2] = (wzor == fib[2]) ? "1" : "0";
    for(int i = 3; i <= ile; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i].size() >= MAX_DLUG) {
            string wynik = "", napis = "";
            for(int ii = 0; ii < 30; ii++) {
                wynik += fib[i][ii];
            }
            for(int ii = fib[i].size() - 30; ii < fib[i].size(); ii++) {
                wynik += fib[i][ii];
            }
            fib[i] = wynik;
            for(int ii = fib[i - 1].size() - (wzor.size() - 1); ii < fib[i - 1].size(); ii++) {
                napis += fib[i - 1][ii];
            }
            for(int ii = 0; ii < (wzor.size() - 1); ii++) {
                napis += fib[i - 2][ii];
            }
            tab[i] = dodaj(dodaj(tab[i - 1], tab[i - 2]), int_to_string(ileJest(wzor, napis)));
        }else {
            fib[i] = fib[i - 1] + fib[i - 2];
            tab[i] = int_to_string(ileJest(wzor, fib[i]));
        }
    }
    cout << tab[ile];
    return 0;
}
