#include<iostream>
#include<vector>
using namespace std;

const int ROZMIAR = 1100000;
int pierElem, ostElem, ile, maks, maksNiz, poprz;
int tabWyn[ROZMIAR];
int nWyn, suma, wczyt;
vector<int> ileJest[ROZMIAR];

void dodajElem(int ktory, int war) {
    if(ileJest[ktory].size() > 0 && ileJest[ktory].back() == ostElem) {
            ileJest[ktory].pop_back();
            ileJest[ktory].push_back(war);
            ileJest[ktory].push_back(ostElem);
        }
        else ileJest[ktory].push_back(war);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile >> pierElem >> ostElem;
    for(int i = 0; i < ile; i++) {
        cin >> wczyt;
        suma += wczyt;
        if(pierElem == i + 1) wczyt--;
        if(ostElem == i + 1) wczyt--;
        if(wczyt < 0 && ile != 1) {
            cout << "0";
            return 0;
        }
        dodajElem(wczyt, i + 1);
        maks = max(maks, wczyt);
    }
    if(ile == 1 && suma == 1) {
        cout << wczyt + 2;
        return 0;
    }
    if(ile == 1) {
        cout << "0";
        return 0;
    }
    tabWyn[nWyn++] = pierElem;
    poprz = pierElem;
    maksNiz = maks;
    while(maks != 0) {
        if(ileJest[maks].back() == poprz) {
            if(ileJest[maks].size() > 1) {
                swap(ileJest[maks][ileJest[maks].size() - 1], ileJest[maks][ileJest[maks].size() - 2]);
                tabWyn[nWyn++] = ileJest[maks].back();
                dodajElem(maks - 1, ileJest[maks].back());
                poprz = ileJest[maks].back();
                ileJest[maks].pop_back();
            }else {
                while(ileJest[maksNiz].size() == 0 || ileJest[maksNiz].back() == poprz) maksNiz--;
                if(maksNiz <= 0) break;
                tabWyn[nWyn++] = ileJest[maksNiz].back();
                dodajElem(maksNiz - 1, ileJest[maksNiz].back());
                poprz = ileJest[maksNiz].back();
                ileJest[maksNiz].pop_back();
            }
        }else {
            tabWyn[nWyn++] = ileJest[maks].back();
            dodajElem(maks - 1, ileJest[maks].back());
            poprz = ileJest[maks].back();
            ileJest[maks].pop_back();
        }
        while(ileJest[maks].size() == 0) maks--;
    }
    tabWyn[nWyn++] = ostElem;
    if(suma != nWyn) {
        cout << "0";
        return 0;
    }
    for(int i = 1; i < nWyn; i++) {
        if(tabWyn[i] == tabWyn[i - 1]) {
            cout << "0";
            return 0;
        }
    }
    for(int i = 0; i < nWyn; i++) cout << tabWyn[i] << " ";
    return 0;
}
