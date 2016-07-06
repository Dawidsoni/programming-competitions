#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

typedef pair<int,int> para;
const int ROZMIAR = 510000;
const int INF = 10000000;
int korzen, ile, wierz1, wierz2, nWyn;
vector<int> graf[ROZMIAR];
bool czyByl[ROZMIAR];
int odl[ROZMIAR];
int maksWierz[ROZMIAR];
para wynik[ROZMIAR]; //dlugosc, wierzcholek

bool cmp(const para & p1, const para & p2) {
    if(p1.first < p2.first) return false;
    if(p1.first > p2.first) return true;
    return p1.second < p2.second;
}


para dfs(int wierz) {
    czyByl[wierz] = true;
    int maksOdl = 1;
    bool czyLisc = true;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            para newOdl = dfs(graf[wierz][i]);
            newOdl.first++;
            if(newOdl.first > maksOdl) {
                maksOdl = newOdl.first;
                maksWierz[wierz] = newOdl.second;
            }
            if(newOdl.first == maksOdl) maksWierz[wierz] = min(maksWierz[wierz], newOdl.second);
            czyLisc = false;
        }
    }
    if(czyLisc) maksWierz[wierz] = wierz;
    odl[wierz] = maksOdl;
    return para(maksOdl, maksWierz[wierz]);
}

void odWierz(int wierz, int odleglosc) {
    int nastWierz = INF;
    czyByl[wierz] = true;
    bool czyLisc = true;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            if(odl[wierz] - 1 == odl[graf[wierz][i]] && (nastWierz == INF || maksWierz[graf[wierz][i]] < maksWierz[nastWierz])) {
                nastWierz = graf[wierz][i];
            }
            czyLisc = false;
        }
    }
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            if(nastWierz == graf[wierz][i]) odWierz(graf[wierz][i], odleglosc);
            else odWierz(graf[wierz][i], odl[graf[wierz][i]]);
        }
    }
    if(czyLisc) {
        wynik[nWyn++] = para(odleglosc, wierz);
    }
}

int main() {
    scanf("%d%d",&ile, &korzen);
    for(int i = 0; i + 1 < ile; i++) {
        scanf("%d%d",&wierz1, &wierz2);
        graf[wierz1].push_back(wierz2);
        graf[wierz2].push_back(wierz1);
    }
    dfs(korzen);
    for(int i = 1; i <= ile; i++) czyByl[i] = false;
    odWierz(korzen, odl[korzen]);
    sort(wynik, wynik + nWyn,cmp);
    printf("%d\n",nWyn);
    for(int i = 0; i < nWyn; i++) {
        printf("%d ",wynik[i].second);
    }
    return 0;
}
