#include<iostream>
#include<string>
using namespace std;


int pref[1000000];
string pattern, text;

void countPref(string text) {
    int ind = 0;
    for(int i = 1; i < (int)text.size(); i++) {
        while(ind > 0 && text[i] != text[ind]) {
            ind = pref[ind - 1];
        }
        if(text[i] == text[ind]) {
            ind++;
        }
        pref[i] = ind;
    }
}

int main() {
    cin >> text >> pattern;
    countPref(pattern);
    int ind = 0;
    for(int i = 0; i < (int)text.size(); i++) {
        while(ind > 0 && text[i] != pattern[ind]) {
            ind = pref[ind - 1];
        }
        if(text[i] == pattern[ind]) ind++;
        if(ind == (int)pattern.size()) {
            cout << "Jest na " << i - pattern.size() + 1 << " pozycji" << endl;
            ind = pref[ind - 1];
        }
    }

    return 0;
}
