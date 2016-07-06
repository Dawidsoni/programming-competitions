#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 200;
const int INF = 1000000001;

string tab[MAX_SIZE];
int najbWier[MAX_SIZE][MAX_SIZE];
int wynik[MAX_SIZE][MAX_SIZE];
int nWier, nKol;

void liczNajb() {
    for(int i = 0; i < nWier; i++) {
        int minOdl = INF;
        for(int ii = 0; ii < nKol; ii++) {
            if(tab[i][ii] == '1') minOdl = 0;
            else minOdl++;
            najbWier[i][ii] = minOdl;
        }
    }
    for(int i = 0; i < nWier; i++) {
        int minOdl = INF;
        for(int ii = nKol - 1; ii >= 0; ii--) {
            if(tab[i][ii] == '1') minOdl = 0;
            else minOdl++;
            najbWier[i][ii] = min(minOdl, najbWier[i][ii]);
        }
    }
}

int wartBezwgl(int x) {
    return x >= 0 ? x : -x;
}

void ustawWynik() {
    for(int i = 0; i < nWier; i++) {
        for(int ii = nKol - 1; ii >= 0; ii--) {
            wynik[i][ii] = INF;
        }
    }
}

void wypisz(){
    for(int i = 0; i < nWier; i++) {
        for(int ii = 0; ii < nKol; ii++) {
            cout << wynik[i][ii] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWier >> nKol;
    for(int i = 0; i < nWier; i++) {
        cin >> tab[i];
    }
    liczNajb();
    ustawWynik();
    for(int i = 0; i < nWier; i++) {
        for(int ii = 0; ii < nKol; ii++) {
            for(int iii = 0; iii < nWier; iii++) {
                wynik[i][ii] = min(wynik[i][ii], wartBezwgl(iii - i) + najbWier[iii][ii]);
            }
        }
    }
    wypisz();
    return 0;
}
