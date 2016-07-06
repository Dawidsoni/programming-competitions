#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;

class Mrowka {
public:
    int num, poz, nZabitych;
    Mrowka() : num(0), poz(0), nZabitych(0) {}
    Mrowka(int n, int p, int z = 0) : num(n), poz(p), nZabitych(z) {}
    friend bool operator < (const Mrowka & mr1, const Mrowka & mr2) {
        return mr1.poz < mr2.poz;
    }
    friend bool operator == (const Mrowka & mr1, const Mrowka & mr2) {
        return mr1.poz == mr2.poz;
    }
};

const int MAX_WIERZ = 5100;
const int INF = 10000000;

int nWierz, wierz1, wierz2, nMrowek, wczMrow, nBied, numBied, nSciezek, nWyn, nAkt;
vector<int> graf[MAX_WIERZ];
bool czyByl[MAX_WIERZ];
multiset<Mrowka> mrowka;
int wynPoz[MAX_WIERZ];
int wynZab[MAX_WIERZ];
int wysWierz[MAX_WIERZ];
int aktWierzch[MAX_WIERZ];
Mrowka wynik[MAX_WIERZ];

void dfs(int wierz, int wys) {
    czyByl[wierz] = true;
    wysWierz[wierz] = wys;
    set<Mrowka>::iterator iter = mrowka.find(Mrowka(0, wierz));
    if(iter != mrowka.end()) {
        wynik[nWyn++] = (*iter);
        mrowka.erase(iter);
        return ;
    }
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            dfs(graf[wierz][i], wys + 1);
        }
    }
}

void dfsDol(int wierz) {
    czyByl[wierz] = true;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false && wysWierz[wierz] < wysWierz[graf[wierz][i]]) {
            dfsDol(graf[wierz][i]);
        }
    }
}

bool numSort(const Mrowka & mr1,const Mrowka & mr2) {
    return mr1.num < mr2.num;
}

void aktWyn(int numBied) {
    nWyn = 0;
    bool czyKoniec = false, czyOst = false;
    for(int i = 1; i <= nWierz; i++) {
        czyByl[i] = false;
        wysWierz[i] = INF;
    }
    dfs(numBied, 0);
    sort(wynik, wynik + nWyn, numSort);
    for(int i = 1; i <= nWierz; i++) czyByl[i] = false;
    for(int i = 0; i < nWyn; i++) {
        if(wynik[i].poz == numBied) {
            czyOst = true;
            wynik[i] = Mrowka(wynik[i].num, wynik[i].poz, wynik[i].nZabitych + 1);
            break;
        }
    }
    while(czyKoniec == false && czyOst == false) {
        czyKoniec = true;
        nAkt = 0;
        for(int i = 0; i < nWyn; i++) {
            int ojciec = INF, wierz = wynik[i].poz;
            czyByl[wierz] = true;
            for(int i = 0; i < graf[wierz].size(); i++) {
                if(czyByl[graf[wierz][i]] == false && wysWierz[wierz] > wysWierz[graf[wierz][i]]) {
                    ojciec = graf[wierz][i];
                    break;
                }
            }
            if(ojciec != INF) {
                czyKoniec = false;
                if(ojciec == numBied) {
                    wynik[i] = Mrowka(wynik[i].num, ojciec, wynik[i].nZabitych + 1);
                    czyOst = true;
                }else {
                    wynik[i] = Mrowka(wynik[i].num, ojciec, wynik[i].nZabitych);
                }
                czyByl[ojciec] = true;
                aktWierzch[nAkt++] = ojciec;
            }
        }
        for(int i = 0; i < nAkt; i++) {
            dfsDol(aktWierzch[i]);
        }
    }
    for(int i = 0; i < nWyn; i++) {
        mrowka.insert(wynik[i]);
    }
}

int main() {
    scanf("%d", &nWierz);
    for(int i = 0; i + 1 < nWierz; i++) {
        scanf("%d %d", &wierz1, &wierz2);
        graf[wierz1].push_back(wierz2);
        graf[wierz2].push_back(wierz1);
    }
    scanf("%d", &nMrowek);
    for(int i = 0; i < nMrowek; i++) {
        scanf("%d", &wczMrow);
        mrowka.insert(Mrowka(i, wczMrow));
    }
    scanf("%d", &nBied);
    for(int i = 0; i < nBied; i++) {
        scanf("%d", &numBied);
        aktWyn(numBied);
    }
    for(set<Mrowka>::iterator iter = mrowka.begin(); iter != mrowka.end(); iter++) {
        wynPoz[iter->num] = iter->poz;
        wynZab[iter->num] = iter->nZabitych;
    }
    for(int i = 0; i < nMrowek; i++) {
        printf("%d %d\n", wynPoz[i], wynZab[i]);
    }
    return 0;
}
