#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;

const int rozmiar_drz = 1 << 21;


void buduj_drzewo(int tab[]) {
    for(int i = 0; i < rozmiar_drz/2; i++) {
        tab[i + rozmiar_drz/2] = tab[i];
        tab[i] = 0;
    }
    for(int od_kad = (rozmiar_drz/2) - 1; od_kad >= 1; od_kad--) {
        tab[od_kad] = max(tab[od_kad*2], tab[od_kad*2 + 1]);
    }
}

int maks(int tab[], int od_kad, int do_kad) {
    od_kad += rozmiar_drz/2;
    do_kad += rozmiar_drz/2;
    int wynik = max(tab[od_kad],tab[do_kad]);
    while(od_kad / 2 < do_kad / 2) {
        if(od_kad % 2 == 0) wynik = max(wynik,tab[od_kad + 1]);
        if(do_kad % 2 == 1) wynik = max(wynik,tab[do_kad - 1]);
        od_kad /= 2;
        do_kad /= 2;
    }
    return wynik;
}

int min_tab[rozmiar_drz/2];
int maks_tab[rozmiar_drz/2];
int min_drzewo[rozmiar_drz];
int ile;
int maks_war = INT_MIN;
int wynik = 0;
int maks_wynik = 0;
int od_kad = 0;

int main() {

    scanf("%d", &ile);
    for(int i = 0; i <ile;i++) {
        scanf("%d%d",&min_tab[i], &maks_tab[i]);
        min_drzewo[i] = min_tab[i];
    }
    maks_tab[ile] = INT_MIN;
    buduj_drzewo(min_drzewo);
    for(int i = 0; i < ile; i++) {
        wynik++;
        if(maks_war < min_tab[i]) maks_war = min_tab[i];
        if(maks_war > maks_tab[i + 1]) {
            if(wynik > maks_wynik) maks_wynik = wynik;
            while(true) {
                maks_war = maks(min_drzewo,od_kad,i);
                if(maks_war <= maks_tab[i + 1]) {
                    break;
                }
                wynik--;
                od_kad++;
                if(od_kad > i) {
                    wynik = 0;
                    break;
                }
            }

        }
    }
    printf("%d",maks_wynik);
    return 0;
}
