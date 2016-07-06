#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long int LType;
typedef pair<int,int> para;

const int ROZMIAR = 5100;

LType wynik;
bool czyByl[ROZMIAR][ROZMIAR];
vector<int> graf[ROZMIAR];
int ile, odkad, dokad;
LType tab[ROZMIAR];
queue<para> kolej[ROZMIAR];



void dodajDoWyn(int srodek) {
    czyByl[srodek][srodek] = true;
    if(graf[srodek].size() < 3) return ; //trojek z tego nie zrobimy
    for(int i = 0; i < graf[srodek].size(); i++) {
        kolej[i].push(para(graf[srodek][i], 1));
        czyByl[srodek][graf[srodek][i]] = true;
    }
    for(int odl = 1;; odl++) {
        LType nTab = 0;
        for(int i = 0; i < graf[srodek].size(); i++) {
            int ileJest = 0;
            while(kolej[i].size() > 0 && kolej[i].front().second == odl) {
                int wierz = kolej[i].front().first;
                czyByl[srodek][wierz] = true;
                kolej[i].pop();
                for(int ii = 0; ii < graf[wierz].size(); ii++) {
                    if(czyByl[srodek][graf[wierz][ii]] == false) kolej[i].push(para(graf[wierz][ii], odl + 1));
                }
                ileJest++;
            }
            if(ileJest != 0) tab[nTab++] = ileJest;
        }
        if(nTab >= 3) {
            LType ileMoz = 1, ilePar = 0, ileJest = 0;
            for(int i = 0; i < nTab; i++) {
                if(i <=  2) {
                    ileMoz *= tab[i];
                }else {
                    ileMoz += ilePar * tab[i];
                }
                if(i >= 1) ilePar += tab[i] * ileJest;
                ileJest += tab[i];
            }
            wynik += ileMoz;
        }
        if(nTab == 0) break; //czekam do 0, zeby wyczyscic kolejki
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i + 1 < ile; i++) {
        cin >> odkad >> dokad;
        graf[odkad].push_back(dokad);
        graf[dokad].push_back(odkad);
    }
    for(int i = 1; i <= ile; i++) dodajDoWyn(i);
    cout << wynik;
    return 0;
}
