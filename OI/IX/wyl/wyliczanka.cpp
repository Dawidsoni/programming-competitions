#include<iostream>
using namespace std;

typedef long long int LTYPE;
const int MAX_SIZE = 23;
int ile, tab[MAX_SIZE], wyn[MAX_SIZE], pocz, wynik = 1, maxWyn = 300000000, ileDodac = 1;
bool czyKoniec = false;

int nwd(int val1, int val2) {
    if(val2 > val1) swap(val1, val2);
    return (val1 % val2 ==  0) ? val2 : nwd(val2, val1 % val2);
}

int nww(int val1,int val2) {
    return (LTYPE)val1 * (LTYPE)val2 / nwd(val1, val2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
    }
    for(int i = ile, szuk = 1; i >= 1; i--, szuk++) {
        for(int ii = pocz, licz = 1;; ii++) {
            if(tab[ii % ile] == szuk) {
                wyn[i] = (licz % i);
                pocz = ii + 1;
                tab[ii % ile] = 0;
                break;
            }else if(tab[ii % ile] != 0) {
                licz++;
            }
        }
    }
    int i = ile;
    for(; wynik <= maxWyn; wynik += ileDodac) {
        czyKoniec = true;
        for(; i >= 1; i--) {
            if((wynik % i) != wyn[i]) {
                czyKoniec = false;
                break;
            }else {
                ileDodac = nww(ileDodac, i);
            }
        }
        if(czyKoniec) break;
    }
    if(czyKoniec) cout << wynik;
    else cout << "NIE";
    return 0;
}
