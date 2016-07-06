#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Pole {
public:
    int poczKol, wys;
    Pole() {}
    Pole(int pKol, int wy) : poczKol(pKol), wys(wy) {}
};

const int MAX_SIZE = 2100;
int ile, wczyt, wynik, wys[MAX_SIZE];

void rozw() {
    stack<Pole> stos;
    for(int i = 0; i < ile; i++) {
        int minKol = i;
        while(stos.empty() == false && stos.top().wys > wys[i]) {
            wynik = max(wynik, (i - stos.top().poczKol) * stos.top().wys);
            minKol = stos.top().poczKol;
            stos.pop();
        }
        stos.push(Pole(minKol, wys[i]));
    }
    while(stos.empty() == false) {
        wynik = max(wynik, (ile - stos.top().poczKol) * stos.top().wys);
        stos.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            cin >> wczyt;
            if(wczyt == 0) wys[ii]++;
            else wys[ii] = 0;
        }
        rozw();
    }
    cout << wynik << endl;
    return 0;
}
