#include<iostream>
using namespace std;

string nap;
int ile;
int suma, n_lit = 1;

int main() {
    cin >> ile >> nap;
    nap[ile] = 'Z';
    for(int i = 1; i <= ile; i++) {
        if(nap[i] == nap[i - 1]) {
            n_lit++;
        }else {
            suma += n_lit/2;
            n_lit = 1;
        }
    }
    cout << suma;
    return 0;
}
