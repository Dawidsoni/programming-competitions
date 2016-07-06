#include<stdio.h>
#include<algorithm>
using namespace std;

int parcel[1000010];
int wysokosc_dnia[1000010];
int wynik[1000010];
int max_wysokosc;
int maxim, minim;
int ile_parceli, ile_dni;
int najwyzszy_w_dol, najwyzszy_w_gore;
bool czy_nie_mozna[1000010];
int main() {
    scanf("%d %d", &ile_parceli, &ile_dni);
    bool czy_ostatnie_nizsze = true;
    for(int i=0;i<ile_parceli;i++) {
        scanf("%d", &parcel[i]);
        if(parcel[i] > maxim) maxim = parcel[i];
        if(czy_nie_mozna[i] == false ) {
            wynik[parcel[i]]++;
            czy_nie_mozna[i] = true;
        }
        if(parcel[i] > parcel[i - 1]) czy_nie_mozna[i - 1] = false;
    }
    for(int i=0;i<ile_dni;i++) {
        scanf("%d", &wysokosc_dnia[i]);
        printf("%d ", wynik[wysokosc_dnia[i] + 1]);
    }
    return 0;
}
