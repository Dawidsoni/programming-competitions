#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string merge(string a, string b, int ile_liter) {
    string wynik = "";
    for(int i=0;i<ile_liter;i++) {
        wynik += a[i];
        wynik += b[i];
    }
    return wynik;
}

int main() {
    int n;
    string a,b,lacznie[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        cin >> a;
        cin >> b;
        lacznie[i] = merge(a,b, a.size()<b.size() ? a.size() : b.size() );
    }
    for(int i=0;i<n;i++) {
        cout << lacznie[i] << endl;
    }
    return 0;
}
