#include<stdio.h>
#include<fstream>
using namespace std;

const int ROZ = 1000000;
const int N_PIER = 31650;

int liczPier[ROZ];
int wynTab[ROZ];
bool b[ROZ];

int ile, liczba, ileRazy;
int licznik, ileWyn, ilePier;

long long int nOper;

void sito() {
    int i,j = 0;
    for(i=2;i*i<=N_PIER;i++) {
        if(b[i]==1) continue;
        if(b[i]==0)
        for(j=2*i;j<=N_PIER;j+=i) b[j]=1;
    }
    for(i=2;i<=N_PIER;i++) {
        if(b[i]==0) {
            liczPier[ilePier++] = i;
        }
    }
}

int maxLicz() {
    int nPotrzeba = 2, nTeSame = 0, nPoprzed = 0, wynik = 0, ostDod = 0;
    bool ostWyn = false;
    wynTab[ileWyn] = -1;
    for(int i = 1; i <= ileWyn; i++) {
        if(wynTab[i] == wynTab[i - 1]) {
            nTeSame++;
        }else {
            if(nPoprzed > 0 && ostWyn == false) {
                nPoprzed--;
                ostWyn = true;
                wynik++;
            }else
                nPoprzed += nTeSame;
            nPotrzeba = 1;
            nTeSame = 1;
        }
        if(nTeSame == nPotrzeba && ileWyn != i) {
            ostWyn = true;
            ostDod = nTeSame;
            wynik++;
            nPotrzeba++;
            nTeSame = 0;
        }else {
            ostWyn = false;
        }
    }
    return wynik + 2;
}

bool odp() {
    licznik = ileWyn =  0;
    if(liczba == 1) {
           if(1 >= ileRazy) return true;
           return false;

    }
    while(liczba > 1) {
        if(liczba%liczPier[licznik] == 0) {
            liczba /= liczPier[licznik];
            wynTab[ileWyn++] = liczPier[licznik];
        }else {
            licznik++;
            if(licznik == ilePier) {
                wynTab[ileWyn++] = liczba;
                liczba /= liczba;
            }
        }
    }
    if(maxLicz() >= ileRazy) return true;
    return false;
}

int main() {
    sito();
    scanf("%d",&ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d%d",&liczba, &ileRazy);
        if(odp()) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}
