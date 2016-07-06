#include<bitset>
#include<iostream>
#include<queue>
using namespace std;

queue<bitset<40001> > kolejka;
bitset<40001> druzyna1, druzyna2;
int ile_zawod, ile_meczy, numer;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> ile_zawod >> ile_meczy;
    for(int i=0;i<ile_meczy;i++) {
        druzyna1.reset();//wszystkie bity na 0
        druzyna2.reset();//wszystkie bity na 0
        for(int ii=0;ii<ile_zawod/2;ii++) {//wczytuje 1 dru¿yne
            cin >> numer;
            druzyna1.set(numer,1);
        }
        for(int ii=0;ii<ile_zawod/2;ii++) {//wczytuje 2 dru¿yne
            cin >> numer;
            druzyna2.set(numer,1);
        }
        int rozmiar_kolejki = kolejka.size();//rozmiar siê zmienia podczas pêtli, dlatego zapamiêtujê
        for(int ii=0;ii<rozmiar_kolejki;ii++) {
            bitset<40001> wynik = kolejka.front();//zapamiêtujê 1 element z kolejki
            kolejka.pop();//zdejmujê 1 element z kolejki
            bitset<40001> w1 = wynik & druzyna1;
            bitset<40001> w2 = wynik & druzyna2;
            if(w1.count()>1) {
                kolejka.push(w1);
            }
            if(w2.count()>1) {
                kolejka.push(w2);
            }
        }
        if(i==0) {
            kolejka.push(druzyna1);
            kolejka.push(druzyna2);
            continue;
        }
    }
    if(kolejka.size()>0) cout << "NIE";
    else cout << "TAK";
    return 0;
}


