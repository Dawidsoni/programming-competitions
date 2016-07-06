#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

struct ile_razy_imie {
    string imie;
    mutable int ile;
    ile_razy_imie() : ile(1) {}
    ile_razy_imie(string x) {imie = x;}
};


class typ_obj {
public:
bool operator()(const ile_razy_imie & lewy, const ile_razy_imie & prawy) {
    if(lewy.ile>prawy.ile) return true;
    if(lewy.ile==prawy.ile) {
        if(lewy.imie<prawy.imie) return true;
    }
    return false;
}
};


bool operator<(const ile_razy_imie & lewy, const ile_razy_imie & prawy) {
        if(lewy.imie>prawy.imie) return true;
    return false;
}

void na_duze(string & nazwa) {
    for(int i=0;i<nazwa.size();i++) {
        if(nazwa[i]>=97&&nazwa[i]<=122) nazwa[i] = nazwa[i] - 32;
    }
}


int main() {
    ile_razy_imie wczytaj;
    set<ile_razy_imie> ile_imie;
    set<ile_razy_imie,typ_obj> kopia;
    for(;;) {
        getline(cin,wczytaj.imie);
        if(cin.eof()) break;
        wczytaj.imie.erase(0,wczytaj.imie.rfind(' ')+1);
        na_duze(wczytaj.imie);
        wczytaj.ile = 1;
        set<ile_razy_imie>::iterator it = ile_imie.find(wczytaj);
        if(it==ile_imie.end()) {
            ile_imie.insert(wczytaj);
        }else {
            it->ile++;
        }
    }
    for(set<ile_razy_imie>::iterator it = ile_imie.begin();it!=ile_imie.end();it++) {
        kopia.insert(*it);
    }

    for(set<ile_razy_imie,typ_obj>::iterator it = kopia.begin();it!=kopia.end();it++) {
        cout << it->imie << " " << it->ile << endl;
    }
    return 0;
}
