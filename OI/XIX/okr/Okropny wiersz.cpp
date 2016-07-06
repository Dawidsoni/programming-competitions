#include<stdio.h>
#include<vector>
#include<iostream>>
#include<algorithm>
using namespace std;

class Lacznik {
public:
    int pier, drug, num;
    Lacznik();
    Lacznik(int pi, int dr, int nu) : pier(pi), drug(dr), num(nu) {}
    friend bool operator < (const Lacznik & lacz1, const Lacznik & lacz2) {
        if(lacz1.pier == lacz2.pier) return lacz1.drug < lacz2.drug;
        return lacz1.pier < lacz2.pier;
    }
};

const int ROZMIAR = 510000;

int ile, nPyt, odkad, dokad;
char str[ROZMIAR];
vector<int> dzielniki[ROZMIAR];
int kmr[ROZMIAR][20];

void liczDziel() {
    int maks = 0;
    for(int i = 1; i <= ile; i++) {
        for(int ii = i; ii <= ile; ii += i) {
            dzielniki[ii].push_back(i);
        }
    }
}

bool czyRowne(int odkad1, int odkad2, int dlugosc) {
    int pot = 1, i = 0;
    for(; pot <= dlugosc; i++, pot *= 2) {}
    pot /= 2;
    i--;
    if(kmr[odkad1][i] == kmr[odkad2][i] && kmr[odkad1 + (dlugosc - pot)][i] == kmr[odkad2 + (dlugosc - pot)][i]) return true;
    return false;
}

bool czyZgadza(int dlugosc) {
    return czyRowne(odkad, odkad + dlugosc, dokad - odkad + 1 - dlugosc);
}

void robKMR() {
    for(int i = 0; i < ile; i++) {
        kmr[i][0] = str[i] - 'a';
    }
    for(int i = 1, pot = 1; pot * 2 <= ile; i++, pot *= 2) {
        vector<Lacznik> wek;
        for(int ii = 0; ii < ile; ii++) {
            if(ii + (pot * 2) > ile) break;
            wek.push_back(Lacznik(kmr[ii][i - 1], kmr[ii + pot][i - 1], ii));
        }
        sort(wek.begin(), wek.end());
        kmr[wek[0].num][i] = 0;
        for(int ii = 1, num = 0; ii < wek.size(); ii++) {
            if(wek[ii].pier != wek[ii - 1].pier || wek[ii].drug != wek[ii - 1].drug) num++;
            kmr[wek[ii].num][i] = num;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d", &ile);
    scanf("%s", str);
    scanf("%d", &nPyt);
    liczDziel();
    robKMR();
    for(int i = 0;i < nPyt; i++) {
        scanf("%d%d",&odkad, &dokad);
        odkad--;
        dokad--;
        int dlug = (dokad - odkad + 1);
        for(int ii = 0; ii < dzielniki[dlug].size(); ii++) {
            if(czyZgadza(dzielniki[dlug][ii])) {
                printf("%d\n", dzielniki[dlug][ii]);
                break;
            }
        }
    }
    return 0;
}
