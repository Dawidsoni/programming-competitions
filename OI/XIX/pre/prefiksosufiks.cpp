#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long LType;

const int ROZMIAR = 1100000;
const unsigned stP = 1000000033;
const unsigned stQ = 1000000087;

int ile, wyn;
string napis;
unsigned potTab[ROZMIAR];
unsigned hashTab[ROZMIAR];
bool czyPref[ROZMIAR];

void zmienNapis() {
    if(napis.size() % 2 == 0) {
        napis.resize(napis.size() + 1);
        ile++;
        for(int i = ile - 2; i >= ile/2; i--) napis[i + 1] = napis[i];
    }
    napis[ile / 2] = '#';
}

void wyznaczPot() {
    potTab[0] = 1;
    for(int i = 1; i <= ile; i++) potTab[i] = ((LType)potTab[i - 1] * stP) % stQ;
}

void wyznaczHash() {
    hashTab[0] = napis[0];
    for(int i = 1; i < ile; i++) hashTab[i] = (hashTab[i - 1] + ((LType)napis[i] * potTab[i])) % stQ;
}

unsigned zwrocHash(int odkad, int dokad) {
    unsigned aktHash = hashTab[dokad] - (odkad == 0 ? 0 : hashTab[odkad - 1]);
    aktHash += stQ;
    aktHash = ((LType)aktHash * potTab[ile - odkad]) % stQ;
    return aktHash;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    cin >> napis;
    zmienNapis();
    wyznaczPot();
    wyznaczHash();
    czyPref[0] = true;
    for(int i = 0; i < ile/2; i++) {
        if(zwrocHash(0, i) == zwrocHash(ile - 1 - i, ile - 1)) czyPref[i + 1] = true;
    }
    int odl = 0;
    for(int i = ile / 2 - 1, j = ile / 2 + 1; i >= 0; i--, j++) {
        odl += 2;
        while(zwrocHash(i, i + odl) != zwrocHash(j - odl, j) || i + odl >= ile / 2) {
            odl--;
        }
        if(czyPref[i]) wyn = max(wyn, i + odl + 1);
    }
    cout << wyn;
    return 0;
}
