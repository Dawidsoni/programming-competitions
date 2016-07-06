#include<iostream>
using namespace std;


const int ROZMIAR = 1100000;
string napis;
int ile, odkad, wynik;
int wynPref[ROZMIAR];
bool czyJest[ROZMIAR];
int naJest[ROZMIAR];

void pref() {
    for(int i = 1;i < napis.size();i++) {
        while(odkad > 0 && napis[odkad] != napis[i]) {
            odkad = wynPref[odkad - 1];
        }
        if(napis[odkad] == napis[i]) odkad++;
        wynPref[i] = odkad;
    }
}

int main() {
    cin >> ile;
    cin >> napis;
    pref();
    /*for(int i = 0; i < ile; i++) {
        cout << wynPref[i] << " ";
    }*/
    //cout << endl;
    for(int i = 0; i < ile - wynPref[ile - 1]; i++) {
        czyJest[wynPref[i]] = true;
        naJest[wynPref[i]] = i;
    }
    if(wynPref[ile - 1] * 2 > ile) { //ma okres
        wynik = (ile / 3) - ((ile / 3) % (ile - wynPref[ile - 1]));
    }else if(wynPref[ile - 1] * 3 > ile) {
        wynik = 0;
    }else {
        int suf = wynPref[ile - 1];
        while(suf > 0) {
            if(czyJest[suf] == true && naJest[suf] - suf * 2 + 1 >= 0) {
                wynik = suf;
                break;
            }
            suf = wynPref[suf - 1];
        }
    }
    cout << wynik << endl;
    return 0;
}
