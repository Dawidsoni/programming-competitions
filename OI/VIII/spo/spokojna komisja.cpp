#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int ROZMIAR = 20100;

int nWierz, nKraw, postLicz, nSilnych, wcz1, wcz2, ileRazy;
vector<int> graf[ROZMIAR];
vector<int> odwrGraf[ROZMIAR];
vector<int> silna[ROZMIAR];
bool czyByl[ROZMIAR];
int postOrder[ROZMIAR]; //numery wierz po kolei dla postOrder[i]
int numSilnej[ROZMIAR];
int wynik[ROZMIAR];

void dfs(int wierz) {
    czyByl[wierz] = true;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            dfs(graf[wierz][i]);
        }
    }
    postOrder[postLicz++] = wierz;
}

void odwrocGraf() {
    for(int i = 1; i <= nWierz; i++) {
        for(int ii = 0; ii < graf[i].size(); ii++) {
            odwrGraf[graf[i][ii]].push_back(i);
        }
    }
}

void odwrDfs(int wierz) {
    czyByl[wierz] = true;
    for(int i = 0; i < odwrGraf[wierz].size(); i++) {
        if(czyByl[odwrGraf[wierz][i]] == false) {
            odwrDfs(odwrGraf[wierz][i]);
        }
    }
    silna[nSilnych].push_back(wierz);
}

void sss() {
    for(int i = 1; i <= nWierz; i++) {
        if(czyByl[i] == false) dfs(i);
    }
    odwrocGraf();
    for(int i = 1; i <= nWierz; i++) czyByl[i] = false;
    for(int i = nWierz - 1; i >= 0; i--) {
        if(czyByl[postOrder[i]] == false) {
            odwrDfs(postOrder[i]);
            nSilnych++;
        }
    }
}

int negacja(int licz) {
    return licz % 2 == 0 ? licz - 1 : licz + 1;
}

bool liczWynik() {
    for(int i = nSilnych - 1; i >= 0; i--) {
        for(int ii = 0; ii < silna[i].size(); ii++) {
            if(wynik[silna[i][ii]] == -1) {
                wynik[silna[i][ii]] = 1;
                wynik[negacja(silna[i][ii])] = 0;
                for(int iii = 0; iii < graf[silna[i][ii]].size(); iii++) {
                    if(wynik[graf[silna[i][ii]][iii]] == 0) return false;
                }
                ileRazy++;
            }
        }
    }
    return (ileRazy >= nWierz / 2);
}

void wypiszWynik() {
    for(int i = 1; i <= nWierz; i++) {
        if(wynik[i]) cout << i << endl;
        if(wynik[i] && i % 2 == 1) i++;
    }
}

void robWynik() {
    if(liczWynik()) wypiszWynik();
    else cout << "NIE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz >> nKraw;
    nWierz *= 2;
    for(int i = 0; i < nKraw; i++) {
        cin >> wcz1 >> wcz2;
        graf[negacja(wcz1)].push_back(wcz2);
    }
    sss();
    for(int i = 1; i <= nWierz; i++) wynik[i] = -1;
    /*cout << "SILNE: " << endl;
    for(int i = 0; i < nSilnych; i++) {
        for(int ii = 0; ii < silna[i].size(); ii++) {
            cout << silna[i][ii] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;*/
    robWynik();
    return 0;
}
