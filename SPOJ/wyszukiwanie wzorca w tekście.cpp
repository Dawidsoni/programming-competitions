#include<iostream>
using namespace std;

int ile, wcz;
string wzor, tekst;
int tab_pref[1000100];

void kmp() {
    int od_kad = 0;
    for(int i = 1; i < wzor.size(); i++) {
        while(od_kad > 0 && wzor[od_kad] != wzor[i]) {
            od_kad = tab_pref[od_kad - 1];
        }
        if(wzor[od_kad] == wzor[i]) od_kad++;
        tab_pref[i] = od_kad;
    }
    od_kad = 0;
    for(int i = 0; i < tekst.size(); i++) {
        while(od_kad > 0 && tekst[i] != wzor[od_kad]) {
            od_kad = tab_pref[od_kad - 1];
        }
        if(wzor[od_kad] == tekst[i]) od_kad++;
        if(od_kad == wzor.size()) {
            cout << i - wzor.size() + 1 << endl;
        }
    }
}

int main() {
    cin >> ile;
    for(int i =0; i < ile;i++) {
        cin >> wcz >> wzor >> tekst;
        wzor.resize(wcz);
        kmp();
    }
    return 0;
}
