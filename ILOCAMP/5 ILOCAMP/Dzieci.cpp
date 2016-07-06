#include<iostream>
using namespace std;

bool czy_juz_bylo[1000001];
int na_ktore_isc[1000001];
int ile, wynik = 0, od_kad = 1;

int main() {
    cin >> ile;
    for(int i=0;i<ile;i++) {
        cin >> na_ktore_isc[i];
    }
    int ktore_pole = 1;
    for(int i=0;i+1<ile;i++) {
        czy_juz_bylo[ktore_pole] = true;
        if(czy_juz_bylo[na_ktore_isc[ktore_pole]]) {
            for(int i=od_kad;i<=ile;i++) {
                if(czy_juz_bylo[i]==false) {
                    ktore_pole = i;
                    od_kad = i;
                    wynik++;
                    break;
                }
            }
        }else {
            ktore_pole = na_ktore_isc[ktore_pole];
        }
    }
    cout << wynik;
    return 0;
}
