#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

typedef pair<int, int> Para;
const int MAX_SIZE = 1100000;

int ile, nKraw, maksRoz, wczA, wczB, nWyn;
vector<Para> kraw;
vector<vector<int> > wynik;

bool czyMozna(vector<int> & wek) {
    wek.push_back(wek[0]);
    if(wek[wek.size() - 1] - wek[wek.size() - 2] > maksRoz || wek[wek.size() - 2] - wek[wek.size() - 1] > maksRoz) return false;
    for(int i = 0; i + 1 < wek.size(); i++) {
        if(find(&kraw[0], &kraw[nKraw], Para(wek[i], wek[i + 1])) != &kraw[nKraw]) return false;
    }
    return true;
}


int sprawdzListe() {
    int wyn = 0;
    for(int i = 0; i < wynik.size(); i++) {
        if(czyMozna(wynik[i])) wyn++;
    }
    return wyn;
}

void robListe(vector<int> & wek, set<int> & zbior) {
    if(wek.size() == ile) {
        wynik.push_back(wek);
        return;
    }
    int ostElem = wek[wek.size() - 1];
    for(int i = max(ostElem - maksRoz, 1); i <= min(ostElem + maksRoz, ile); i++) {
        if(zbior.find(i) == zbior.end()) {
            wek.push_back(i);
            zbior.insert(i);
            robListe(wek, zbior);
            zbior.erase(i);
            wek.pop_back();
        }
    }
}

void dodaj2() {
    vector<int> wek, wek2;
    int i = ile;
    for(; i >= 1; i -= 2) {
        wek.push_back(i);
    }
    if(i == 0) i = 1;
    else i = 2;
    for(; i <= ile; i += 2) {
        wek.push_back(i);
    }
    wynik.push_back(wek);
    wek2.push_back(ile);
    for(int i = wek.size() - 1; i >= 1; i--) {
        wek2.push_back(wek[i]);
    }
    wynik.push_back(wek2);
}

int main(){
    cin >> ile >> nKraw >> maksRoz;
    for(int i = 0; i < nKraw; i++) {
        cin >> wczA >> wczB;
        kraw.push_back(Para(wczA, wczB));
    }
    sort(&kraw[0], &kraw[nKraw]);
    if(maksRoz == 0 && ile > 1) {
        cout << "0";
    }else if(maksRoz == 1 && ile > 2) {
        cout << "0";
    }else if(ile == 1) {
        cout << "1";
    }else if(ile == 2) {
        vector<int> wek;
        wek.push_back(2);
        wek.push_back(1);
        wynik.push_back(wek);
        cout << sprawdzListe();
    }else if(maksRoz == 2) {
        dodaj2();
        cout << sprawdzListe();
    }else {
        vector<int> wek;
        wek.push_back(ile);
        set<int> zbior;
        zbior.insert(ile);
        robListe(wek, zbior);
        cout << sprawdzListe();
    }
    return 0;
}
