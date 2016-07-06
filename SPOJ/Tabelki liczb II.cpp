#include<stdio.h>

int ile, n_wierszy, n_kolumn;
int tab[1000][1000];
int wynik[1000][1000];
//  tab[wiersz][kolumna]

void wypisz() {
    for(int i=0;i<n_wierszy;i++) {
    for(int j=0;j<n_kolumn;j++) {
            printf("%d ", wynik[i][j]);
        }
        printf("\n");
    }
}

void rob_wynik() {
    for(int i=0; i < n_kolumn ; i++) {
        if( i % 2 == 0) { //w dó³
            for(int j = 0 ; j + 1 < n_wierszy; j++) {
                wynik[j + 1][i] = tab[j][i];
            }
            if(i + 1 != n_kolumn) {
                wynik[n_wierszy - 1][i + 1] = tab[n_wierszy - 1][i];
            }else {
                wynik[0][0] = tab[n_wierszy - 1][i];
            }
        }else { //w górê
            for(int j=1; j < n_wierszy; j++) {
                wynik[j - 1][i] = tab[j][i];
            }
            if(i + 1 != n_kolumn) {
                wynik[0][i + 1] = tab[0][i];
            }else {
                wynik[0][0] = tab[0][i];
            }
        }
    }
}

int main() {
    scanf("%d", & ile);
    for(int i=0; i< ile;i++) {
        scanf("%d %d", &n_wierszy, &n_kolumn);
        for(int j=0; j < n_wierszy; j++) {
            for(int jj = 0; jj<n_kolumn; jj++) {
                scanf("%d", &tab[j][jj]);
            }
        }
        rob_wynik();
        wypisz();
    }
    return 0;
}
