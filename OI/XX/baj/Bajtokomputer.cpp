#include<stdio.h>
#include<climits>
#include<algorithm>
using namespace std;

const int rozmiar = 1000100;
int ile;
int tab[rozmiar];
int n_koniec[rozmiar];
int suma_konca, do_kad;
int maks_plus;
int maks_minus, suma_minus;

int main() {
    maks_plus = INT_MAX;
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d", &tab[i]);
    }
    for(int i = ile - 1; i >= 0; i--) {
        suma_konca += 1 - tab[i];
        if(tab[i] == 1) n_koniec[i] = suma_konca;
    }
    //jechanie -1 obcinam do miejsca, gdzie ciag rosnie
    do_kad = ile - 1;
    while(tab[do_kad] >= tab[do_kad - 1]) do_kad--;
    do_kad++;
    for(int i = 0; tab[i] == 0; i++) {
        if(tab[i + 1] == -1) {
            printf("BRAK");
            return 0;
        }
    }
    for(int i = 0; i < do_kad; i++) {
        suma_minus += tab[i] + 1;
        if(tab[i] < tab[i - 1]) {
            maks_minus += suma_minus;
            suma_minus = 0;
        }else if(tab[i] == 1) {
            maks_plus = min(maks_plus, maks_minus  + n_koniec[i]);
        }
    }
    printf("%d",min(maks_minus,maks_plus));
    return 0;
}
