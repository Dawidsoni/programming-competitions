#include<stdio.h>

const int ROZMIAR = 3100;
bool tab[ROZMIAR][ROZMIAR];
bool czyWyrzuc[ROZMIAR];
int nWierz, nKraw, kraw1, kraw2;

int main() {
    scanf("%d%d", &nWierz, &nKraw);
    for(int i = 0; i < nKraw; i++) {
        scanf("%d%d", &kraw1, &kraw2);
        tab[kraw1][kraw2] = true;
        tab[kraw2][kraw1] = true;
    }
    for(int i = 1; i <= nWierz; i++) {
        if(czyWyrzuc[i]) continue;
        for(int ii = 1; ii <= nWierz; ii++) {
            if(i == ii || czyWyrzuc[ii]) continue;
            if(tab[i][ii] == false) {
                czyWyrzuc[i] = czyWyrzuc[ii] = true;
                break;
            }
        }
    }
    for(int i = 1, licznik = 1; i <= nWierz && licznik <= nWierz/3; i++) {
        if(czyWyrzuc[i] == false) {
            printf("%d ",i);
            licznik++;
        }
    }
    return 0;
}
