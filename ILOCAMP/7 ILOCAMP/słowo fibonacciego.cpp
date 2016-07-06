#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

unsigned stP = 1000000033;
//unsigned stM = 1000000087;

typedef unsigned long long LType;
const int ROZMIAR = 110000;
int ile, wynik;
string napis;
unsigned hashTab[ROZMIAR];
unsigned potTab[ROZMIAR];

void wyznaczPot() {
    potTab[0] = 1;
    for(int i = 1; i <= ile; i++) potTab[i] = ((LType)potTab[i - 1] * stP);
}

void wyznaczHash() {
    hashTab[0] = napis[0];
    for(int i = 1; i < ile; i++) {
        hashTab[i] = (hashTab[i - 1] + (LType)napis[i] * potTab[i]);
    }
}

unsigned zwrocHash(int odkad, int dokad) {
    unsigned int aktHash = hashTab[dokad] - (odkad == 0 ? 0 : hashTab[odkad - 1]);
    aktHash = ((LType)aktHash * potTab[ile - odkad]);
    return aktHash;
}

unsigned laczHashe(int dlugosc1, unsigned hash1, unsigned hash2) {
    return (hash1 + (LType)hash2 * potTab[dlugosc1]);
}

void zmienWyn(int odkad) {
    unsigned hash1 = zwrocHash(odkad, odkad + 1);
    int dlug1 = 2;
    unsigned hash2 = zwrocHash(odkad, odkad);
    int dlug2 = 1;
    while(hash1 == zwrocHash(odkad, odkad + dlug1 - 1)) {
        wynik = max(wynik,dlug1);
        int hashKopia = hash1;
        hash1 = laczHashe(dlug1, hash1, hash2);
        hash2 = hashKopia;
        int kopia = dlug1;
        dlug1 += dlug2;
        dlug2 = kopia;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    cin >> napis;
    wyznaczPot();
    wyznaczHash();
    cout << wezHash(1, 2) << endl << wezHash(2, 3) << endl;

    /*cout << zwrocHash(0, 1) << endl << zwrocHash(2, 3) <<  endl << zwrocHash(ile - 2, ile - 1) << endl;
    for(int i = 0; i + 1 < ile; i++) zmienWyn(i);
    cout << wynik;*/
    return 0;
}
