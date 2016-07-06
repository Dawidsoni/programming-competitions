#include<iostream> //bo string
#include<set>
using namespace std;

class kod_wyrazu {
public:
    kod_wyrazu() {}
    kod_wyrazu(string wyr, string ko) : wyraz(wyr), kod(ko) {}
    string wyraz;
    string kod;
    friend bool operator < (const kod_wyrazu & k1, const kod_wyrazu & k2) {
        if(k1.wyraz == "!" || k2.wyraz == "!") {
            if(k1.kod < k2.kod) return true;
            return false;
        }
        if(k1.kod < k2.kod) return true;
        if(k1.kod == k2.kod) {
            if(k1.wyraz < k2.wyraz) return true;
        }
        return false;
    }
};

multiset<kod_wyrazu> kody_wyr;
multiset<string> wynik;
int ile_wyr, ile_kod;
string wczytaj;


int main() {
    cin >> ile_wyr >> ile_kod;
    for(int i=0;i<ile_wyr;i++) {
        kod_wyrazu kod_w;
        cin >> kod_w.wyraz;
        kod_w.kod.resize(kod_w.wyraz.size());
        for(int i=0;i<kod_w.wyraz.size();i++) {
            char znak = kod_w.wyraz[i];
            if(znak=='a'||znak=='b'||znak=='c') kod_w.kod[i] = '2';
            if(znak=='d'||znak=='e'||znak=='f') kod_w.kod[i] = '3';
            if(znak=='g'||znak=='h'||znak=='i') kod_w.kod[i] = '4';
            if(znak=='j'||znak=='k'||znak=='l') kod_w.kod[i] = '5';
            if(znak=='m'||znak=='n'||znak=='o') kod_w.kod[i] = '6';
            if(znak=='p'||znak=='q'||znak=='r'||znak=='s') kod_w.kod[i] = '7';
            if(znak=='t'||znak=='u'||znak=='v') kod_w.kod[i] = '8';
            if(znak=='w'||znak=='x'||znak=='y'||znak=='z') kod_w.kod[i] = '9';
        }
        kody_wyr.insert(kod_w);
    }
    for(int i=0;i<ile_kod;i++) {
        cin >> wczytaj;
        kod_wyrazu kod_w;
        kod_w.kod = wczytaj;
        kod_w.wyraz = "!";
        multiset<kod_wyrazu>::iterator it = kody_wyr.find(kod_w);
        if(it != kody_wyr.end()) {
            wynik.erase(wynik.begin(), wynik.end());
            while(it != kody_wyr.end() && it->kod == wczytaj) {
                cout << it->wyraz << " ";
                it++;
            }
        }else {
            cout << "BRAK";
        }
        cout << endl;
    }
    return 0;
}
