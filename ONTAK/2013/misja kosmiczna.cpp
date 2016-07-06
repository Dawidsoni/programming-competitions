#include<stdio.h>
#include<set>
#include<vector>
using namespace std;

class Wierz {
public:
    int odl, czasRozp, suma, numer;
    vector<Wierz*>  lacznik;
    friend bool operator < (const Wierz & w1, const Wierz & w2) {
        if(w1.suma < w2.suma) return true;
        return false;
    }
};

const int ROZMIAR = 550000;
Wierz wierz[ROZMIAR];
bool czyByl[ROZMIAR];
int ile, wcz1, wcz2, wynik, czas;
multiset<Wierz> zbior;

void dfs(int numer, int odl) {
    czyByl[numer] = true;
    wierz[numer].odl = odl;
    for(int i = 0; i < wierz[numer].lacznik.size(); i++) {
        if(czyByl[wierz[numer].lacznik[i]->numer] == false) {
            dfs(wierz[numer].lacznik[i]->numer, odl + 1);
        }
    }
}

int main() {
    scanf("%d", &ile);
    czas = ile - 1;
    for(int i = 1; i <= ile; i++) {
        scanf("%d",&wcz1);
        wierz[i].czasRozp = wcz1;
        wierz[i].numer = i;
    }
    for(int i = 0; i + 1 < ile; i++) {
        scanf("%d%d", &wcz1, &wcz2);
        wierz[wcz1].lacznik.push_back(&wierz[wcz2]);
        wierz[wcz2].lacznik.push_back(&wierz[wcz1]);
    }
    dfs(1,0);
    for(int i = 1; i <= ile; i++) {
        wierz[i].suma = wierz[i].odl + wierz[i].czasRozp;
        czyByl[i] = false;
    }
    zbior.insert(wierz[1]);
    while(zbior.size() > 0) {
        Wierz nowy = *zbior.begin();
        zbior.erase(zbior.begin());
        czyByl[nowy.numer] = true;
        for(int i = 0; i < nowy.lacznik.size(); i++) {
            if(czyByl[nowy.lacznik[i]->numer] == false) {
                zbior.insert(*wierz[nowy.numer].lacznik[i]);
            }
        }
        wynik = max(wynik, nowy.suma + czas);
        czas--;
    }
    printf("%d",wynik);
    return 0;
}
