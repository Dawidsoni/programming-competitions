#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>

using namespace std;

class Zmienna {
public:
    short int indI, indJ, aktPoz, numRow;
    Zmienna() {}
    Zmienna(int iI, int iJ, int aktP, int nR) : indI(iI), indJ(iJ), aktPoz(aktP), numRow(nR) {}
};

const int MAX_LITER = 27, MAX_ROZM = 10000;

int nTest, nZmiennych, wynik, nWyst1, nWyst2, ilePoz1, ilePoz2;
short int dlugZmiennej[MAX_ROZM];
vector<short int> wyst1[MAX_LITER][MAX_ROZM], wyst2[MAX_LITER][MAX_ROZM];
string str1, str2;
short int indI1[MAX_ROZM], indJ1[MAX_ROZM], indI2[MAX_ROZM], indJ2[MAX_ROZM];
bool czyByl1[MAX_ROZM], czyByl2[MAX_ROZM];
bool czyKolej1[MAX_ROZM], czyKolej2[MAX_ROZM];

void czysc(vector<short int> wyst[MAX_LITER][MAX_ROZM], bool czyByl[MAX_ROZM], bool czyKolej[MAX_ROZM], int ilePoz) {
    for(int i = 0; i < MAX_LITER; i++) {
        for(int ii = 0; wyst[i][ii].size(); ii++) wyst[i][ii].clear();
    }
    for(int i = 0; i < ilePoz; i++) czyByl[i] = czyKolej[i] = false;
}

int dodaj(string str, int nWyst, vector<short int> wyst[MAX_LITER][MAX_ROZM], short int indI[MAX_ROZM], short int indJ[MAX_ROZM]) {
    int aktPoz = 0;
    for(int i = 0; i < nWyst; i++) {
        if(str[i] != '1' && str[i] != '0') {
            int numLit = str[i] - 'a';
            for(int ii = 0; ii < dlugZmiennej[numLit]; ii++) {
                indI[aktPoz] = numLit;
                indJ[aktPoz] = ii;
                wyst[numLit][ii].push_back(aktPoz++);
            }
        }else if(str[i] == '1') {
            indI[aktPoz] = indJ[aktPoz] = -1;
            aktPoz++;
        }else {
            indI[aktPoz] = indJ[aktPoz] = -2;
            aktPoz++;
        }
    }
    return aktPoz;
}

void liczWyn() {
    wynik = 0;
    czysc(wyst1, czyByl1, czyKolej1, ilePoz1);
    czysc(wyst2, czyByl2, czyKolej2, ilePoz2);
    ilePoz1 = dodaj(str1, nWyst1, wyst1, indI1, indJ1);
    ilePoz2 = dodaj(str2, nWyst2, wyst2, indI2, indJ2);
    if(ilePoz1 != ilePoz2) {
        wynik = -1;
        return;
    }
    queue<Zmienna> kolej;
    for(int i = 0; i < ilePoz1; i++) {
        if(czyByl1[i]) continue;
        kolej.push(Zmienna(indI1[i], indJ1[i], i, 1));
        int czyStala = 0;
        while(kolej.empty() == false) {
            Zmienna zmienna = kolej.front();
            kolej.pop();
            if(zmienna.indI < 0 && czyStala < 0 && zmienna.indI != czyStala) {
                wynik = -1;
                return;
            }else if(zmienna.indI < 0) {
                czyStala = zmienna.indI;
                continue;
            }
            else if(zmienna.numRow == 1) {
                if(czyByl1[zmienna.aktPoz]) continue;
                czyByl1[zmienna.aktPoz] = czyKolej1[zmienna.aktPoz] = true;
                if(czyByl2[zmienna.aktPoz] == false) {
                    kolej.push(Zmienna(indI2[zmienna.aktPoz], indJ2[zmienna.aktPoz], zmienna.aktPoz, 2));
                }
            }else {
                if(czyByl2[zmienna.aktPoz]) continue;
                czyByl2[zmienna.aktPoz] = czyKolej2[zmienna.aktPoz] = true;
                if(czyByl1[zmienna.aktPoz] == false) {
                    kolej.push(Zmienna(indI1[zmienna.aktPoz], indJ1[zmienna.aktPoz], zmienna.aktPoz, 1));
                }
            }
            for(int i = 0; i < wyst1[zmienna.indI][zmienna.indJ].size(); i++) {
                if(czyKolej1[wyst1[zmienna.indI][zmienna.indJ][i]] == false) {
                    kolej.push(Zmienna(zmienna.indI, zmienna.indJ, wyst1[zmienna.indI][zmienna.indJ][i], 1));
                    czyKolej1[wyst1[zmienna.indI][zmienna.indJ][i]] = true;
                }
            }
            for(int i = 0; i < wyst2[zmienna.indI][zmienna.indJ].size(); i++) {
                if(czyKolej2[wyst2[zmienna.indI][zmienna.indJ][i]] == false) {
                    kolej.push(Zmienna(zmienna.indI, zmienna.indJ, wyst2[zmienna.indI][zmienna.indJ][i], 2));
                    czyKolej2[wyst2[zmienna.indI][zmienna.indJ][i]] = true;
                }
            }
        }
        if(czyStala == 0) wynik++;
    }
}

void mnoz(string & str) {
   string wynik;
   int ileDodac = 0;
   for(int i = str.size() - 1; i >= 0; i--) {
        int licz = (str[i] - '0') * 2;
        licz += ileDodac;
        if(licz >= 10) {
            licz -= 10;
            ileDodac = 1;
        }else {
            ileDodac = 0;
        }
        wynik += ((char)(licz + '0'));
   }
   if(ileDodac) wynik += '1';
   str.resize(wynik.size());
   for(int i = 0; i < wynik.size(); i++) {
        str[i] = wynik[wynik.size() - 1 - i];
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nTest;
    for(int i = 0; i < nTest; i++) {
        cin >> nZmiennych;
        for(int ii = 0; ii < nZmiennych; ii++) {
            cin >> dlugZmiennej[ii];
        }
        cin >> nWyst1 >> str1 >> nWyst2 >> str2;
        liczWyn();
        if(wynik == -1) cout << "0" << endl;
        else {
            string wyn = "1";
            for(int i = 1; i <= wynik; i++) {
                mnoz(wyn);
            }
            cout << wyn << endl;
        }
    }
    return 0;
}
