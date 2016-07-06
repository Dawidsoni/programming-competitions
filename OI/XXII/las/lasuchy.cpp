#include<iostream>
using namespace std;

const int MAX_SIZE = 1100000;
int ile, nPrzedz;
int tab[MAX_SIZE], wynik[MAX_SIZE * 2], odkad[MAX_SIZE], dokad[MAX_SIZE];

void ustawObow() {
    for(int i = 0; i + 1 < ile; i++) {
        if(tab[i] * 2 <= tab[i + 1]) {
            wynik[i] = 1;
        }else if(tab[i] >= tab[i + 1] * 2) {
            wynik[i] = 0;
        }else {
            wynik[i] = -1;
        }
    }
    if(tab[ile - 1] * 2 <= tab[0]) {
        wynik[ile - 1] = 1;
    }else if(tab[ile - 1] >= tab[0] * 2) {
        wynik[ile - 1] = 0;
    }else {
        wynik[ile - 1] = -1;
    }
}

void robPrzedz() {
    for(int i = 0; i < ile; i++) {
        wynik[i + ile] = wynik[i];
    }
    bool czyPocz = wynik[0] == -1;
    int pocz = -1;
    wynik[ile * 2] = 0;
    for(int i = 1; i <= ile * 2; i++) {
        if(wynik[0] == -1 && i == ile && pocz == -1) {
            pocz = 0;
        }
        if(wynik[i] == -1 && czyPocz == false) {
            czyPocz = true;
            pocz = i;
        }else if(wynik[i] != -1 && czyPocz == true) {
            czyPocz = false;
            if(pocz != -1) {
                odkad[nPrzedz] = pocz;
                dokad[nPrzedz++] = (i - 1);
            }
        }
        if(i >= ile && czyPocz == false) break;
    }
}

void ustawPrzedz(int odkad, int dokad) {
    bool czyLewy = wynik[(odkad - 1) < 0 ? odkad - 1 + ile : odkad - 1] != 1;
    bool czyPrawy = wynik[(dokad + 1) % ile] != 0;
    bool czyRosnie = true;
    for(int i = odkad; i <= dokad; i++) {
        if(czyLewy == czyPrawy && czyLewy) { //1 to najw wartosc, a reszta w prawo
            if(tab[i % ile] <= tab[(i + 1) % ile]) czyRosnie = false;
            if(czyRosnie == false) {
                wynik[i % ile] = 1;
            }else {
                wynik[i % ile] = 0;
            }
        }else if(czyLewy == czyPrawy) { //dopoki ciag rosnie, to rob w prawo, potem w lewo
            if(tab[i % ile] >= tab[(i + 1) % ile]) {
                czyRosnie = false;
            }
            if(czyRosnie == false) {
                wynik[i % ile] = 0;
            }else {
                wynik[i % ile] = 1;
            }
        }else if(czyLewy) { //wszystkie w lewo
            wynik[i % ile] = 0;
        }else { //wszystkie w prawo
            wynik[i % ile] = 1;
        }
    }
}

void zmienWyn() {
    for(int i = 0; i < ile; i++) {
        wynik[i] = (i + 1 + wynik[i]);
        if(wynik[i] > ile) wynik[i] %= ile;
    }
}

void wypisz() {
    for(int i = 0; i < ile; i++) {
        cout << wynik[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
    }
    ustawObow();
    robPrzedz();
    for(int i = 0; i < nPrzedz; i++) {
        ustawPrzedz(odkad[i], dokad[i]);
    }
    zmienWyn();
    wypisz();
    return 0;
}
