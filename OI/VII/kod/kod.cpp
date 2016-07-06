#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 220;

int ile, ktoraPerm, akt, wynik[MAX_SIZE];
bool czyByl[MAX_SIZE];

int szukaj(int nWyn, int & ktoraPerm) {
    int aktIle = 0;
    for(int i = 0;;i++) {
        aktIle += (wynik[i] * wynik[nWyn - 1 - i]);
        if(aktIle >= ktoraPerm) {
            ktoraPerm = ktoraPerm - (aktIle - (wynik[i] * wynik[nWyn - 1 - i]));
            return i + 1;
        }
    }
}

string robWyn(int odkad, int dokad, int ktoraPerm) {
    string strWyn = "";
    int akt = szukaj(dokad - odkad + 1, ktoraPerm) + odkad - 1;
    //cout << "odkad = " << odkad << " dokad = " << dokad << " akt = " << akt << " ktoraPerm = " << ktoraPerm << " nast1 =  " << ( ktoraPerm / wynik[dokad - (akt + 1) + 1] + (ktoraPerm % wynik[dokad - (akt + 1) + 1] ? 1 : 0)) << " nast2 = " << wynik[dokad - (akt + 1) + 1] << " lit = " << (char)(akt + 'a' - 1) << endl;
    strWyn += (akt + 'a' - 1);
    if(odkad != dokad && akt > odkad) strWyn += robWyn(odkad, akt - 1, ktoraPerm / wynik[dokad - (akt + 1) + 1] + (ktoraPerm % wynik[dokad - (akt + 1) + 1] ? 1 : 0));
    if(odkad != dokad && akt < dokad) strWyn += robWyn(akt + 1, dokad, ktoraPerm % wynik[dokad - (akt + 1) + 1] == 0 ? wynik[dokad - (akt + 1) + 1] :  ktoraPerm % wynik[dokad - (akt + 1) + 1]);
    return strWyn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ktoraPerm >> ile;
    wynik[0] = wynik[1] = 1;
    for(int i = 2; i <= ile; i++) {
        for(int ii = 0; ii < i; ii++) {
            wynik[i] += (wynik[ii] * wynik[i - 1 - ii]);
        }
    }
    string wynik = "";
    wynik += robWyn(1, ile, ktoraPerm);
    cout << wynik;
    return 0;
}
