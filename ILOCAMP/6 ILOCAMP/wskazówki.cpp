#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;


int ile_wsk, ile_zeg, wielkosc_podz;

class wskazowki {
public:
    int wsk[1010];
    friend bool operator < (const wskazowki & wsk1, const wskazowki & wsk2) {
        for(int i=0; i < ile_wsk;i++) {
            if(wsk1.wsk[i] < wsk2.wsk[i]) return true;
            if(wsk2.wsk[i] > wsk1.wsk[i]) return false;
        }
        return false;
    }
/*   friend ostream & operator <
 < (ostream & strum, wskazowki & wsk1) {
        for(int i=0;i<ile_wsk;i++) {

        }
        return strum;
    }*/
};

int wczytaj, ile_odjac, poprz_wcz;
int wynik;
int tab[1010];
bool czy_sortowac;
wskazowki nowa;
multiset<wskazowki> wskazy;
typedef multiset<wskazowki>::iterator it_type;
int main() {
    scanf("%d %d %d", &ile_zeg, &ile_wsk, &wielkosc_podz);
    for(int i=0;i<ile_zeg;i++) {
        czy_sortowac = false;
        int min = 2000000000;
        for(int j=0;j<ile_wsk;j++) {
            scanf("%d", &wczytaj);
            if(wczytaj < min ) min = wczytaj;
            nowa.wsk[j] = wczytaj;
        }
        for(int i=0;i<ile_wsk;i++) {
            nowa.wsk[i] -= (min - 1);
        }
        sort(nowa.wsk, nowa.wsk + ile_wsk);
        it_type it = wskazy.find(nowa);
        wskazy.insert(nowa);
        if(it != wskazy.end()) wynik = wynik + wskazy.count(nowa) - 1;
    }
    printf("%d", wynik);
    return 0;
}
