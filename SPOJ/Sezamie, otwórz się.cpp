#include<iostream>
using namespace std;

string tekst;
string wzor;
int ile;
int tab_pref[100000];

bool kmp() {
    tab_pref[0] = 0;
    int poz = 0;
    for(int i = 1; i < wzor.size(); i++) {
        while(poz > 0 && wzor[i] != wzor[poz]) {
            poz = tab_pref[poz - 1];
        }
        if(wzor[i] == wzor[poz]) poz++;
        tab_pref[i] = poz;
    }
    poz = 0;
    for(int i = 0; i < tekst.size(); i++) {
        while(poz > 0 && tekst[i] != wzor[poz]) {
            poz = tab_pref[poz - 1];
        }
        if(tekst[i] == wzor[poz]) poz++;
        if(poz == wzor.size()) return true;
    }
    return false;
}


int main() {
    cin >> ile;
    for(int i=0;i < ile;i++) {
        cin >> tekst >> wzor;
        tekst.resize(tekst.size()*2);
        for(int i = tekst.size()/2; i < tekst.size(); i++) {
            tekst[i] = tekst[i - tekst.size()/2];
        }
        if(kmp()) {
            cout << "yes" << endl;
        }else {
            cout << "no" << endl;
        }
    }
    return 0;
}
