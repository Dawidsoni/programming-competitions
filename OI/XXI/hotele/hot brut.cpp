#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int LType;
const int ROZMIAR = 5100;
int ile, odkad, dokad;
LType wynik;
vector<int> graf[ROZMIAR];
bool czyByl[ROZMIAR];

int dfs(int odWierz, int doWierz, int odl) {
    czyByl[odWierz] = true;
    if(odWierz == doWierz) return odl;
    int wynik = 0;
    for(int i = 0; i < graf[odWierz].size(); i++) {
        if(czyByl[graf[odWierz][i]] == false) {
            wynik = max(wynik, dfs(graf[odWierz][i], doWierz, odl + 1));
        }
    }
    return wynik;
}

int odl(int w1, int w2) {
    for(int i = 1; i <= ile; i++) czyByl[i] = false;
    return dfs(w1, w2, 0);
}

bool bezLiczby(int licz, int i, int ii, int iii) {
    if(i == licz || ii == licz || iii == licz) return false;
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i + 1 < ile; i++) {
        cin >> odkad >> dokad;
        graf[odkad].push_back(dokad);
        graf[dokad].push_back(odkad);
    }
    cout << endl << endl;
    for(int i = 1; i <= ile; i++) {
        for(int ii = i + 1; ii <= ile; ii++) {
            for(int iii = ii + 1; iii <= ile; iii++) {
                if(odl(i,ii) == odl(i,iii) && odl(i,ii) == odl(ii,iii)) {
                    wynik++;
                    cout << i << " " << ii << " " << iii << endl;
                }
            }
        }
    }
    cout << wynik;
    return 0;
}
