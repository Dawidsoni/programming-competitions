#include<set>
#include<stdio.h>
#include<climits>
using namespace std;

class kopiec {
public:
    set<kopiec*> polacz;
    bool czy_jest;
    int numer;
    static int licznik;
    kopiec() : czy_jest(true) {numer = licznik++;}
    operator int() {
        return numer;
    }
    void dodaj_polaczenie(kopiec * ktory) {
        polacz.insert(ktory);
    }
};

int kopiec::licznik = 1;

int n_miast, n_kolei, miasto_pocz, kosz_kolej, koszt_samol, wcz1, wcz2;
kopiec graf[100000];
int wynik[100000];
kopiec * aktualny, * nastepny;

class obj_fun {
public:
    bool operator ()(kopiec * const & a,kopiec * const & b) {
        if(wynik[a->numer - 1]<wynik[b->numer - 1]) return true;
        return false;
    }
};
multiset<kopiec*,obj_fun> kol_pior;


int main() {
    scanf("%d%d%d%d%d",&n_miast,&n_kolei,&miasto_pocz,&kosz_kolej,&koszt_samol);
    for(int i=0;i<n_kolei;i++) {
        scanf("%d%d",&wcz1,&wcz2);
        graf[wcz1 - 1].dodaj_polaczenie(&graf[wcz2 - 1]);
        graf[wcz2 - 1].dodaj_polaczenie(&graf[wcz1 - 1]);
    }
    for(int i=0;i<n_miast;i++) {
        wynik[i] = INT_MAX;
    }
    wynik[miasto_pocz - 1] = 0;
    aktualny = &graf[miasto_pocz - 1];
    for(int i=0;;i++) {
        for(set<kopiec*>::iterator it_s = aktualny->polacz.begin();it_s!=aktualny->polacz.end();it_s++) {
            for(set<kopiec*>::iterator it_s2 = (*it_s)->polacz.begin();it_s2!=(*it_s)->polacz.end();it_s2++) {
                if((*it_s2)->czy_jest==false) continue;
                if((aktualny->polacz.find(*it_s2)==aktualny->polacz.end())&&(aktualny!=*it_s2)) {
                    if(wynik[*aktualny - 1] + koszt_samol<wynik[*(*it_s2) - 1]) {
                        wynik[*(*it_s2) - 1] = wynik[*aktualny - 1] + koszt_samol;
                        kol_pior.insert(*it_s2);
                    }
                }
            }
            if((*it_s)->czy_jest==false) continue;
            if(wynik[*aktualny - 1] + kosz_kolej<wynik[*(*it_s) - 1]) {
                wynik[*(*it_s) - 1] = wynik[*aktualny - 1] + kosz_kolej;
                kol_pior.insert(*it_s);
            }
        }
        aktualny->czy_jest = false;
        if(i+1==n_miast) break;
        for(set<kopiec*>::iterator it = kol_pior.begin();;it++) {
            if((*it)->czy_jest==false) continue;
            aktualny = *it;
            it++;
            kol_pior.erase(kol_pior.begin(),it);
            break;
        }
    }

    for(int i=0;i<n_miast;i++) {
        printf("%d\n",wynik[i]);
    }
    return 0;
}
