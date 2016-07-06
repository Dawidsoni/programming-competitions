#include<iostream> //stringi
#include<string>
using namespace std;

int ile;
int wynik;
string napis;

bool czy_palindron(int poz_od, int poz_do, int bez_litery) {
    wynik = poz_do - poz_od + 1;
    for(;poz_do != poz_od; poz_do--, poz_od++) {
        if(poz_od == bez_litery) poz_od++;
        else if(poz_do == bez_litery) poz_do--;
        if(napis[poz_do] != napis[poz_od]) return false;
    }
    return true;
}


int main() {
    int ile;
    cin >> ile;
    getline(cin,napis);
    getline(cin, napis);
    for(int dlugosc = ile; dlugosc >= 0; dlugosc--) {
        for(int i = 0; i + dlugosc <= ile; i++) {
            for(int j = i ; j <= i + dlugosc;j++) {
              // cout << i << " " << j << " " << dlugosc <<  endl;
               // if(dlugosc == 6) cout << i + dlugosc << " ";
                if(czy_palindron(i, i + dlugosc -  1, j)) {
                        cout << wynik;
                        return 0;
                }
            }
        }
    }

    return 0;
}
