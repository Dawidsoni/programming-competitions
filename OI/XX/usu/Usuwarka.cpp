#include<iostream>
#include<vector>
using namespace std;

class czarny {
public:
    int numer;
    vector<int> bialy_po;
};

char wczytaj;
int wynik[1000000];// 4 MB
int biale_do_usuniecia, ile, ile_wynik = 0, ile_czar = 0;
czarny czar[1000000];

int main() {
    czar[ile_czar].numer = 0;
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> ile >> biale_do_usuniecia;
    for(int i=0;i<ile;i++) {
        cin >> wczytaj;
        if(wczytaj=='c') {
            ile_czar++;
            czar[ile_czar].numer = i + 1;
        }else if(wczytaj=='b') {
            czar[ile_czar].bialy_po.push_back(i + 1);
        }
        if(ile_czar!=0&&czar[ile_czar].bialy_po.size()+czar[ile_czar - 1].bialy_po.size()>=biale_do_usuniecia) {
        for(int ii=czar[ile_czar].bialy_po.size() - 1;ii>=0;ii--) {
            wynik[ile_wynik++] = czar[ile_czar].bialy_po[ii];
        }
        wynik[ile_wynik++] = czar[ile_czar].numer;
        for(int ii=czar[ile_czar-1].bialy_po.size() - 1,a = 0;ii>=0&&a<=biale_do_usuniecia - (czar[ile_czar].bialy_po.size() + 1);ii--,a++)
            wynik[ile_wynik++] = czar[ile_czar-1].bialy_po[ii];
            czar[ile_czar-1].bialy_po.resize(czar[ile_czar-1].bialy_po.size() - (biale_do_usuniecia - (czar[ile_czar].bialy_po.size())));
            czar[ile_czar].bialy_po.resize(0);
            ile_czar--;
        }
    }
   for(int i=ile_wynik-1;i>=0;i--) {
        cout << wynik[i] << " ";
        if((i)%(biale_do_usuniecia+1)==0) cout << endl;
    }
    return 0;
}
