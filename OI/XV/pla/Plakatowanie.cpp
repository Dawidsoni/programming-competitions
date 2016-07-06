#include<iostream>
#include<stack>

using namespace std;

stack<int> stos;
int ile, szer, wys, wynik;

void dodaj(int licz) {
    while(stos.top() > licz) {
        wynik++;
        stos.pop();
    }
    if(stos.top() != licz) stos.push(licz);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    stos.push(0);
    for(int i = 0; i < ile; i++) {
        cin >> szer >> wys;
        dodaj(wys);
    }
    dodaj(0);
    cout << wynik;
    return 0;
}
