#include<iostream>
using namespace std;

typedef long long int int_t;

int main() {
    int_t wysokosc, numer_pilki, ile_dodac = 1, wynik = 0;
    cin >> numer_pilki >> wysokosc;
    for(int i=1;i<wysokosc;i++) {
        ile_dodac *= 2;
    }
    while(ile_dodac != 0) {
        if(numer_pilki%2==0) {
            wynik += ile_dodac;
            numer_pilki /= 2;
        }else {
            numer_pilki /= 2;
            numer_pilki += 1;
        }
        ile_dodac /= 2;
    }
    cout << wynik;
    return 0;
}
