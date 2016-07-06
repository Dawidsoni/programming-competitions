#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef unsigned int UType;
typedef unsigned long long int LType;
const int SIZE = 2000000;
const UType ST_P = 1000000033;

UType pot[SIZE];
UType tabHash[SIZE];
string str;
vector<int> suf;

void robPot() {
    pot[0] = 1;
    for(int i = 1; i <= str.size(); i++) {
        pot[i] = ((LType)pot[i - 1] * ST_P);
    }
}

void robHash() {
    tabHash[0] = str[0];
    for(int i = 1; i < str.size(); i++) {
        tabHash[i] = (tabHash[i - 1] + ((LType)pot[i] * str[i]));
    }
}

UType wezHash(int odkad, int dokad) {
    UType aktHash = tabHash[dokad] - (odkad == 0 ? 0 : tabHash[odkad - 1]);
    aktHash = ((LType)aktHash * pot[str.size() - odkad]);
    return aktHash;
}

bool czyMozna(int wynik) {
    int aktDal = wynik - 1;
    for(int i = 1; i < str.size(); i++) {
        if(wezHash(0, wynik - 1) == wezHash(i, i + wynik - 1)) {
            aktDal = i + wynik - 1;
        }
        if(i > aktDal) return false;
    }
    return true;
}

void robSuf() {
    for(int i = 0; i < str.size(); i++) {
        if(wezHash(0, i) == wezHash(str.size() - 1 - i, str.size() - 1)) {
            suf.push_back(i + 1);
        }
    }
}

int robWyn() {
    int aktMin = suf[0];
    for(int i = 0; i < suf.size(); i++) {
        if(suf[i] < aktMin) continue;
        if(czyMozna(suf[i])) return suf[i];
        aktMin = suf[i] * 2;
    }
}

int main() {
    cin >> str;
    robPot();
    robHash();
    robSuf();
    cout << robWyn();
    return 0;
}
