#include<iostream>
#include<algorithm>

using namespace std;

const int ROZMIAR = 1100000;
int tab[ROZMIAR];
int ile, wynik;
string str;

int dlaCiagu(int odkad, int dokad) {
    int sumaLewa = 0, sumaPrawa = 0;
    for(int i = odkad; i <= dokad; i++) {
        sumaLewa += tab[i];
        if(sumaLewa < 0) return 0;
    }
    for(int i = dokad; i >= odkad; i--) {
        sumaPrawa += tab[i];
        if(sumaPrawa < 0) return 0;
    }
    return dokad - odkad + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    cin >> str;
    for(int i = 0; i < ile; i++) {
        if(str[i] == 'j') tab[i] = -1;
        else tab[i] = 1;
    }
    for(int i = 0; i < ile; i++) {
        for(int ii = i; ii < ile; ii++) {
            wynik = max(wynik, dlaCiagu(i,ii));
        }
    }
    cout << wynik;
    return 0;
}
