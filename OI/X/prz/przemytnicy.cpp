#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef pair<int, int> para;

const int MAX_WIERZ = 5100;
const int INF = 1000000000;

int nWierz, nKraw, kraw1, kraw2, odl, wynik = INF;
int waga[MAX_WIERZ];
vector<para> grafPod[MAX_WIERZ], grafOdwr[MAX_WIERZ];
int wynDo[MAX_WIERZ], wynOd[MAX_WIERZ];

void dijkstra(vector<para> graf[], int wynik[]) {
    set<para> kolej; //first- odl, second - wierz
    bool czyByl[MAX_WIERZ];
    kolej.insert(para(0, 1));
    for(int i = 1; i <= nWierz; i++) czyByl[i] = false;
    for(int i = 2; i <= nWierz; i++) wynik[i] = INF;
    for(int i = 0; i < nWierz; i++) {
        while(kolej.size() > 0 && czyByl[kolej.begin()->second] == true) kolej.erase(kolej.begin());
        if(kolej.size() == 0) break;
        para wierz = *kolej.begin();
        kolej.erase(kolej.begin());
        wynik[wierz.second] = wierz.first;
        czyByl[wierz.second] = true;
        for(int i = 0; i < graf[wierz.second].size(); i++) {
            if(czyByl[graf[wierz.second][i].second] == false && wynik[wierz.second] + graf[wierz.second][i].first < wynik[graf[wierz.second][i].second]) {
                kolej.insert(para(wynik[wierz.second] + graf[wierz.second][i].first, graf[wierz.second][i].second));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nWierz;
    for(int i = 1; i <= nWierz; i++) cin >> waga[i];
    cin >> nKraw;
    for(int i = 0; i < nKraw; i++) {
        cin >> kraw1 >> kraw2 >> odl;
        grafPod[kraw1].push_back(para(odl, kraw2));
        grafOdwr[kraw2].push_back(para(odl, kraw1));
    }
    dijkstra(grafPod, wynOd);
    dijkstra(grafOdwr, wynDo);
    for(int i = 1; i <= nWierz; i++) wynik = min(wynik, wynDo[i] + wynOd[i] + (int)(0.5 * waga[i]));
    cout << wynik;
    return 0;
}
