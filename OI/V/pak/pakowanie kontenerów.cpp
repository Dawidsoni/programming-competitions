#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

class Pudelko {
public:
    int rozmiar, waga;
    Pudelko() {}
    Pudelko(int rozm, int wa) : rozmiar(rozm), waga(wa) {}
    friend bool operator < (const Pudelko & pud1, const Pudelko & pud2) {
        if(pud1.rozmiar == pud2.rozmiar) return pud1.waga < pud2.waga;
        return pud1.rozmiar < pud2.rozmiar;
    }
};

class Kontener {
public:
    int rozmiar, ile;
    Kontener() {}
    Kontener(int rozm, int il) : rozmiar(rozm), ile(il) {}
    friend bool operator < (const Kontener & kont1, const Kontener & kont2) {
        return kont1.rozmiar < kont2.rozmiar;
    }
};

const int MAX_KONT = 5100;

int nPudel, nKonter, wczRoz, wczWaga, wczIle, wynik, ktoryKonter;
multiset<Pudelko> pudelko;
multiset<Pudelko>::iterator iter;
Kontener konter[MAX_KONT];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nPudel;
    for(int i = 0; i < nPudel; i++) {
        cin >> wczRoz >> wczWaga;
        pudelko.insert(Pudelko(wczRoz, wczWaga));
    }
    cin >> nKonter;
    for(int i = 0; i < nKonter; i++) {
        cin >> wczRoz >> wczIle;
        konter[i] = Kontener(wczRoz, wczIle);
    }
    sort(konter, konter + nKonter);
    iter = pudelko.begin();
    while(konter[nKonter - 1].ile > 0 && iter != pudelko.end()) {
        if(iter->rozmiar == konter[ktoryKonter].rozmiar) {
            wynik += iter->waga;
            iter++;
            konter[ktoryKonter].ile--;
            if(konter[ktoryKonter].ile == 0) ktoryKonter++;
        }else if(iter->rozmiar > konter[ktoryKonter].rozmiar) {
            break;
        }else {
            multiset<Pudelko>::iterator lacz1 = iter++;
            if(iter != pudelko.end() && lacz1->rozmiar == iter->rozmiar) {
                multiset<Pudelko>::iterator lacz2 = iter++;
                pudelko.insert(Pudelko(lacz1->rozmiar + 1, lacz1->waga + lacz2->waga));
                iter--;
                if(iter == lacz2) iter++;
            }
        }
    }
    if(konter[nKonter - 1].ile > 0) cout << "NIE";
    else cout << wynik;
    return 0;
}
