#include<iostream> //stringi
using namespace std;

const int na_liczbe = 48;

class liczba {
    char cyfra[10000];
    int ile_znakow;
public:
    liczba() : ile_znakow(0) {}
    liczba(char tab[], int ile) {
        cyfra[ile] = NULL;
        for(int i=0;;i++) {
            if(tab[i]==NULL) {
                cyfra[i] = NULL;
                ile_znakow = i;
                break;
            }
        }
        for(int i=0;i<ile_znakow;i++) {
            cyfra[ile_znakow - 1 - i] = tab[i];
        }
    }
    friend ostream & operator << (ostream & strum, const liczba & licz) {
        for(int i=licz.ile_znakow - 1;i>=0;i--) {
            strum << licz.cyfra[i];
        }
        return strum;
    }
    friend istream & operator >> (istream & strum, liczba & licz) {
        char tab[10000];
        strum >> tab;
        for(int i=0;;i++) {
            if(tab[i]==NULL) {
                licz.cyfra[i] = NULL;
                licz.ile_znakow = i;
                break;
            }
        }
        for(int i=0;i<licz.ile_znakow;i++) {
            licz.cyfra[licz.ile_znakow - 1 - i] = tab[i];
        }
        return strum;
    }
    friend liczba operator + (const liczba & licz1, const liczba & licz2) {
        liczba wynik;
        int ile_dodac = 0, cyfra1, cyfra2;
        for(int i=0;;i++) {
            if(licz1.ile_znakow <= i && licz2.ile_znakow <= i && ile_dodac == 0){
                wynik.ile_znakow = i;
                wynik.cyfra[i] = NULL;
                break;
            }
            if(licz1.ile_znakow <= i) cyfra1 = na_liczbe;
            else cyfra1 = licz1.cyfra[i];
            if(licz2.ile_znakow <= i) cyfra2 = na_liczbe;
            else cyfra2 = licz2.cyfra[i];
            int wartosc = ile_dodac + cyfra1 + cyfra2 - 2*na_liczbe;
            ile_dodac = wartosc/10;
            wartosc %= 10;
            wynik.cyfra[i] = wartosc + na_liczbe;
        }

        return wynik;
    }
    friend liczba operator * (const liczba & licz1, const liczba & licz2) {
        liczba wynik;
        for(int i=0; i < licz1.ile_znakow;i++) {
            int ile_dodac = 0;
            liczba mnozenie;
            for(int j=0;j<i;j++) {
                mnozenie.cyfra[j] = na_liczbe;
            }
            int pomnoz_przez = licz1.cyfra[i] - na_liczbe, cyfra;
            for(int ii=0;;ii++) {
                if(ii + 1 > licz2.ile_znakow) cyfra = na_liczbe;
                else cyfra = licz2.cyfra[ii];
                int wartosc = ((cyfra - na_liczbe)*pomnoz_przez) + ile_dodac;
                ile_dodac = wartosc / 10;
                wartosc %= 10;
                mnozenie.cyfra[ii + i] = wartosc + na_liczbe;
                if(ii + 1 >= licz2.ile_znakow && ile_dodac == 0) {
                    mnozenie.ile_znakow = ii + 1 + i;
                    mnozenie.cyfra[ii + 1 + i] = NULL;
                    break;
                }
            }
            wynik = wynik + mnozenie;
        }
        return wynik;
    }
};

int do_ktorej_potegi;

int main() {
    liczba licz, wynik("1",1);
    cin >> licz >> do_ktorej_potegi;
        for(int i=do_ktorej_potegi;i>1;i/=2) {
            if(i%2==1)
                wynik = wynik * licz;
            licz = licz * licz;
            if(i/2 <= 1) {
                wynik = wynik * licz;
            }
        }
        if(do_ktorej_potegi==1) cout << licz;
        else cout << wynik;
    return 0;
}
