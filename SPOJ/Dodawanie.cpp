#include<iostream> //stringi
using namespace std;

const int na_liczbe = 48;

class liczba {
    char cyfra[10000];
    int ile_znakow;
public:
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
    friend liczba & operator + (const liczba & licz1, const liczba & licz2) {
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

};

int ile;

int main() {
    cin >> ile;
    liczba licz1, licz2;
    for(int i=0;i<ile;i++) {
        cin >> licz1;
        cin >> licz2;
        cout << (licz1 + licz2) << endl;
    }
    return 0;
}
