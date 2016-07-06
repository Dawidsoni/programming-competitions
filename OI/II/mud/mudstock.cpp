#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Miasto {
public:
    int odl, nOsob;
    Miasto() {}
    Miasto(int od, int nO) : odl(od), nOsob(nO) {}
};

const int MAX_SIZE = 400;

int nKolej, nStolOsob, wczIle, wczOdl, wczNOsob, ileLudzi, aktWynik, wynik;
vector<Miasto> tab[MAX_SIZE];
int nOsob[MAX_SIZE], wklad[MAX_SIZE];
int wsp1, wsp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nKolej >> nStolOsob;
    ileLudzi += nStolOsob;
    for(int i = 0; i < nKolej; i++) {
        cin >> wczIle;
        for(int ii = 0; ii < wczIle; ii++) {
            cin >> wczOdl >> wczNOsob;
            tab[i].push_back(Miasto(wczOdl, wczNOsob));
        }
    }
    for(int i = 0; i < nKolej; i++) {
        int odl = 0;
        for(int ii = 0; ii < tab[i].size(); ii++) {
            odl += tab[i][ii].odl;
            wklad[i] += (tab[i][ii].nOsob  * odl);
            nOsob[i] += tab[i][ii].nOsob;
        }
        ileLudzi += nOsob[i];
        aktWynik += wklad[i];
    }
    wynik = aktWynik;
    for(int i = 0; i < nKolej; i++) {
        int ileOdjacLudzi = ileLudzi - nOsob[i];
        int aktWyn = aktWynik;
        for(int ii = 0; ii < tab[i].size(); ii++) {
            aktWyn += ileOdjacLudzi * tab[i][ii].odl;
            aktWyn -= (ileLudzi - ileOdjacLudzi) * tab[i][ii].odl;
            if(aktWyn < wynik) {
                wsp1 = i + 1;
                wsp2 = ii + 1;
                wynik = aktWyn;
            }
            ileOdjacLudzi += tab[i][ii].nOsob;
        }
    }
    cout << wynik << endl;
    cout << wsp1 << " " << wsp2 << endl;
    return 0;
}
