#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

typedef pair<int,int> para;

const int ROZMIAR = 1100000;
const int INF = ROZMIAR - 1;

int ile, wynik;
char wczyt;
int tab[ROZMIAR];
int doZasieg[ROZMIAR];
vector<int> odZasieg[ROZMIAR];
stack<para> stos; //first - numer, second - nadwyzka
multiset<int> indeksy;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> wczyt;
        if(wczyt == 'j') tab[i] = -1;
        else tab[i] = 1;
    }
    for(int i = 0; i < ile; i++) {
        if(tab[i] == 1) {
            stos.push(para(i, 1));
        }else { //-1
            doZasieg[i] = INF;
            if(stos.size() > 0) {
                stos.top().second--;
                while(stos.top().second < 0) {
                    doZasieg[stos.top().first] = i - 1;
                    stos.pop();
                    if(stos.size() > 0) stos.top().second--;
                    else break;
                }
            }
        }
    }
    while(stos.size() > 0) {
        doZasieg[stos.top().first] = ile - 1;
        stos.pop();
    }
    for(int i = ile - 1; i >= 0; i--) {
        if(tab[i] == 1) {
            stos.push(para(i, 1));
        }else { //-1
            odZasieg[INF].push_back(i);
            if(stos.size() > 0) {
                stos.top().second--;
                while(stos.top().second < 0) {
                    odZasieg[i + 1].push_back(stos.top().first);
                    stos.pop();
                    if(stos.size() > 0) stos.top().second--;
                    else break;
                }
            }
        }
    }
    while(stos.size() > 0) {
        odZasieg[0].push_back(stos.top().first);
        stos.pop();
    }
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < odZasieg[i].size(); ii++) {
            indeksy.insert(odZasieg[i][ii]);
        }
        if(tab[i] == 1) {
            multiset<int>::iterator wsk = upper_bound(indeksy.begin(), indeksy.end(), doZasieg[i]);
            if(wsk != indeksy.begin()) {
                wsk--;
                wynik = max(wynik, *wsk - i + 1);
            }
        }
    }
    cout << wynik;
    return 0;
}
