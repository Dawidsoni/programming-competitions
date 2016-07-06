#include<iostream>
#include<algorithm>

using namespace std;

class Stacja {
public:
    int odl, cena;
    Stacja() {}
    Stacja(int od, int ce) : odl(od), cena(ce) {}
};

const int MAX_SIZE = 1000100;

int maxPoj, ileStacji, maxOdl, wczOdl, wczCena, wynik, aktNumer, poczKolej, aktPoj;
Stacja stacja[MAX_SIZE];
Stacja aktStacja;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> maxPoj >> ileStacji;
    for(int i = 0; i < ileStacji; i++) {
        cin >> wczCena >> wczOdl;
        stacja[i] = Stacja(maxOdl, wczCena);
        maxOdl += wczOdl;
    }
    stacja[ileStacji++] = Stacja(maxOdl, 0);
    aktStacja = stacja[0];
    poczKolej = aktNumer = 1;
    aktPoj = maxPoj;
    while(aktStacja.odl < maxOdl) {
        while(aktNumer < ileStacji && stacja[aktNumer].odl <= aktStacja.odl + aktPoj) {
            if(stacja[aktNumer].cena <= aktStacja.cena) {
                wynik += aktStacja.cena * (stacja[aktNumer].odl - aktStacja.odl);
                aktStacja = stacja[aktNumer];
                poczKolej = aktNumer + 1;
                aktPoj = maxPoj;
            }
            aktNumer++;
        }
        if(aktStacja.odl >= maxOdl) break;
        Stacja nowaStacja = stacja[poczKolej];
        for(int i = poczKolej; i < aktNumer; i++) {
            if(stacja[i].cena <= nowaStacja.cena) {
                nowaStacja = stacja[i];
                poczKolej = i + 1;
            }
        }
        wynik += aktStacja.cena * aktPoj;
        int nowaOdl = aktStacja.odl + aktPoj;
        aktStacja = nowaStacja;
        aktPoj = maxPoj - (nowaOdl - aktStacja.odl);
        aktStacja.odl = nowaOdl;
    }
    cout << wynik << endl;
    return 0;
}
