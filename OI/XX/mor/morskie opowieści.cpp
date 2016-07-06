#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> para;

const int ROZMIAR = 5100;
const int INF = 30000;

int nWierz, nKraw, nPyt, wierz1, wierz2, pyt;
vector<int> graf[ROZMIAR];
short int odl1[ROZMIAR][ROZMIAR];
short int odl2[ROZMIAR][ROZMIAR];
bool czyByl1[ROZMIAR];
bool czyByl2[ROZMIAR];

void dlaWierz(int wierz) {
    for(int i = 1; i <= nWierz; i++) {
        czyByl1[i] = czyByl2[i] = false;
        odl1[wierz][i] = odl2[wierz][i] = INF;
    }
    if(graf[wierz].size() == 0) odl1[wierz][wierz] = INF;
    else odl1[wierz][wierz] = 0;
    czyByl1[wierz] = true;
    queue<para> kolej1, kolej2; //first - wierz, second - odl
    for(int i = 0; i < graf[wierz].size(); i++) {
        czyByl1[graf[wierz][i]] = true;
        kolej1.push(para(graf[wierz][i], 1));
    }
    for(int i = 1; kolej1.size() > 0 || kolej2.size() > 0; i++) {
        while(kolej1.size() > 0 && kolej1.front().second == i) {
            para elem = kolej1.front();
            odl1[wierz][elem.first] = i;
            for(int ii = 0; ii < graf[elem.first].size(); ii++) {
                if(czyByl1[graf[elem.first][ii]] == false) {
                    czyByl1[graf[elem.first][ii]] = true;
                    kolej1.push(para(graf[elem.first][ii], i + 1));
                }else {
                    if(odl1[wierz][graf[elem.first][ii]] == i) {
                        //cout << "dla \"" << i + 1 << "\"" << endl;
                        if(czyByl2[elem.first] == false) {
                            kolej2.push(para(elem.first, i + 1));
                            czyByl2[elem.first] = true;
                        }
                        if(czyByl2[graf[elem.first][ii]] == false) {
                            kolej2.push(para(graf[elem.first][ii], i + 1));
                            czyByl2[graf[elem.first][ii]] = true;
                        }
                    }
                }
            }
            kolej1.pop();
        }
        while(kolej2.size() > 0 && kolej2.front().second == i) {
            para elem = kolej2.front();
            odl2[wierz][elem.first] = i;
            for(int ii = 0; ii < graf[elem.first].size(); ii++) {
                if(czyByl2[graf[elem.first][ii]] == false) {
                    czyByl2[graf[elem.first][ii]] = true;
                    kolej2.push(para(graf[elem.first][ii], i + 1));
                }
            }
            kolej2.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz >> nKraw >> nPyt;
    for(int i = 0; i < nKraw; i++) {
        cin >> wierz1 >> wierz2;
        graf[wierz1].push_back(wierz2);
        graf[wierz2].push_back(wierz1);
    }
    for(int i = 1; i <= nWierz; i++) {
        dlaWierz(i);
    }
    for(int i = 0; i < nPyt; i++) {
        cin >> wierz1 >> wierz2 >> pyt;
        int reszta = pyt % 2;
        if(odl1[wierz1][wierz2] != INF && odl1[wierz1][wierz2] % 2 == reszta && odl1[wierz1][wierz2] <= pyt) cout << "TAK\n";
        else if(odl2[wierz1][wierz2] != INF && odl2[wierz1][wierz2] % 2 == reszta && odl2[wierz1][wierz2] <= pyt) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}
