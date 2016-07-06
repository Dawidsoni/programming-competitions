#include<iostream>
#include<vector>
using namespace std;

const int ROZMIAR = 1100000;

vector<int> graf[ROZMIAR];
bool czyByl[ROZMIAR];
bool czyZal[ROZMIAR];
int nWierz, odkad, dokad, wyn;

bool dfs(int wierz) {
    czyByl[wierz] = true;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            if(dfs(graf[wierz][i]) == false && czyZal[wierz] == false) {
                wyn++;
                czyZal[graf[wierz][i]] = czyZal[wierz] = true;
            }
        }
    }
    return czyZal[wierz];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz;
    for(int i = 0; i + 1 < nWierz; i++) {
        cin >> odkad >> dokad;
        graf[odkad].push_back(dokad);
        graf[dokad].push_back(odkad);
    }
    dfs(1);
    cout << wyn;
    return 0;
}
