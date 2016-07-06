#include<iostream>
#include<algorithm>
using namespace std;

const int ROZMIAR = 510000;
typedef pair<int,int> para; //first - liczba, second - indeks
string wzorzec;
string wynik;
int dlCiagu, ileTest, maxWz, dlWz;
para ciag[ROZMIAR];
int tabZmian[30];
int wzPref[ROZMIAR];

void funkPref(string napis) {
    int odkad = 0;
    for(int i = 1; i < napis.size(); i++) {
        while(odkad > 0 && napis[i] != napis[odkad]) {
            odkad = wzPref[odkad - 1];
        }
        if(napis[i] == napis[odkad]) odkad++;
        wzPref[i] = odkad;
    }
}

int kmp(string wzorzec, string napis) {
    funkPref(napis);
    int odkad = 0, wynik = 0;
    for(int i = 0; i < wzorzec.size(); i++) {
        while(odkad > 0 && wzorzec[i] != napis[odkad]) {
            odkad = wzPref[odkad - 1];
        }
        if(wzorzec[i] == napis[odkad]) odkad++;
        if(odkad == napis.size()) {
            wynik++;
            odkad = wzPref[odkad - 1];
        }

    }
    return wynik;
}


int liczWyn() {
    int ind = 0;
    for(int i = 0; i < dlCiagu; i++) {
        while(ciag[i].first > tabZmian[ind]) {
            ind++;
        }
        wynik[ciag[i].second] = 'a' + ind;
    }
    return kmp(wzorzec, wynik);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> dlCiagu >> maxWz >> ileTest >> dlWz;
    wynik.resize(dlCiagu);
    cin >> wzorzec;
    for(int i = 0; i < dlCiagu; i++) {
        cin >> ciag[i].first;
        ciag[i].second = i;
    }
    sort(ciag, ciag + dlCiagu);
    for(int i = 0; i < ileTest; i++) {
        for(int ii = 0; ii < 25; ii++) {
            cin >> tabZmian[ii];
        }
        cout << liczWyn() << endl;
    }
    return 0;
}
