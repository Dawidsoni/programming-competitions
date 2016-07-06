#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<stdio.h>
using namespace std;

typedef pair<int, int> para;

const int ROZMIAR = 110000;
const int MAX_WYN = 5 * 1100000;
int nWierz, nKraw, wierz1, wierz2, numKraw;
bool wczJest, wczMaByc;
vector<para> graf[ROZMIAR];
bool czyByl[ROZMIAR];
bool czyPowt[ROZMIAR];
bool czyKraw[ROZMIAR * 10];
vector<int> wynik[MAX_WYN];
int nWyn;
vector<int> wyn;
int odkad[ROZMIAR];

vector<int> & euler(int wierz) {
    wyn.clear();
    stack<int> stos;
    int akt = wierz;
    stos.push(wierz);
    while(stos.size() > 0) {
        akt = stos.top();
        czyByl[akt] = true;
        while(odkad[akt] < graf[akt].size() && czyKraw[graf[akt][odkad[akt]].second]) odkad[akt]++;
        if(odkad[akt] < graf[akt].size()) {
            czyKraw[graf[akt][odkad[akt]].second] = true;
            stos.push(graf[akt][odkad[akt]].first);
        }else {
            stos.pop();
            wyn.push_back(akt);
        }
    }
    return wyn;
}

bool czyDaSie() {
    for(int i = 1; i <= nWierz; i++) {
        if(graf[i].size() % 2 == 1) return false;
    }
    return true;
}

void dodajWynik(vector<int> & wektor) {
    stack<int> stos;
    for(int i = 0; i < wektor.size(); i++) {
        stos.push(wektor[i]);
        if(czyPowt[wektor[i]]) {
            stos.pop();
            wynik[nWyn].push_back(wektor[i]);
            for(int akt = stos.top(); akt != wektor[i]; akt = stos.top()) {
                wynik[nWyn].push_back(akt);
                czyPowt[akt] = false;
                stos.pop();
            }
            wynik[nWyn].push_back(wektor[i]);
            nWyn++;
        }else {
            czyPowt[wektor[i]] = true;
        }
    }
}


int main() {
    cin >> nWierz >> nKraw;
    for(int i = 0; i < nKraw; i++)  {
        cin >> wierz1 >> wierz2 >> wczJest >> wczMaByc;
        if(wczJest != wczMaByc) {
            graf[wierz1].push_back(para(wierz2, numKraw));
            graf[wierz2].push_back(para(wierz1, numKraw++));
        }
    }
    if(czyDaSie() == false) { //KONIEC PROGRAMU
        printf("NIE");
        return 0;
    }
    for(int i = 1; i <= nWierz; i++) {
        if(czyByl[i] == false) {
            if(graf[i].size() == 0) continue;
            dodajWynik(euler(i));
        }
    }
    printf("%d\n",nWyn);
    for(int i = 0; i < nWyn; i++) {
        printf("%d ", wynik[i].size() - 1);
        for(int ii = 0; ii < wynik[i].size(); ii++) {
            printf("%d ", wynik[i][ii]);
        }
        printf("\n");
    }
    return 0;
}
