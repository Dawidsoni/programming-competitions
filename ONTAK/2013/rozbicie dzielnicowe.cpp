#include<stdio.h>
#include<vector>
using namespace std;

const int ROZMIAR = 300000;
vector<int> drzewo[ROZMIAR];
int ile, ileDziel, kraw1, kraw2, wynik, aktDziel;
bool czyByl[ROZMIAR];

int dfs(int numer, int minDziel) {
    czyByl[numer] = true;
    int suma = 1;
    for(int i = 0; i < drzewo[numer].size(); i++) {
        if(czyByl[drzewo[numer][i]] == false) {
            suma += dfs(drzewo[numer][i], minDziel);
        }
    }
    if(suma >= minDziel) {
        suma = 0;
        aktDziel++;
    }
    return suma;
}

bool czyDaSie(int minDziel) {
    aktDziel = 0;
    for(int i = 1; i <= ile; i++) {
        czyByl[i] = false;
    }
    dfs(1, minDziel);
    if(aktDziel >= ileDziel)
        return true;
    return false;
}

int main() {
    scanf("%d%d", &ile, &ileDziel);
    for(int i = 0; i + 1 < ile; i++) {
        scanf("%d%d",&kraw1, &kraw2);
        drzewo[kraw1].push_back(kraw2);
        drzewo[kraw2].push_back(kraw1);
    }
    int odKad = 0;
    int doKad = wynik = ile;
    while(odKad < doKad) {
        int srednia = (odKad + doKad)/2;
        if(czyDaSie(srednia)) {
            odKad = srednia + 1;
            wynik = srednia;
        }else {
            doKad = srednia;
        }
    }
    printf("%d",wynik);
    return 0;
}
