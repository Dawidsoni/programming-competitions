#include<stdio.h>

const int ROZMIAR = 1100000;
int ile, nSciezek, odkad, dokad;
int tab[ROZMIAR];

int main() {
    scanf("%d%d", &ile, &nSciezek);
    ile--;
    for(int i = 1; i <= ile; i++) {
        tab[i] = i + 1;
    }
    for(int i = 0; i < nSciezek; i++) {
        scanf("%d%d",&odkad, &dokad);
        if(tab[odkad] != -1 && tab[odkad] < dokad) {
            int wart = tab[odkad];
            tab[odkad] = dokad;
            while(odkad < dokad) {
                odkad = wart;
                if(odkad >= dokad || wart >= dokad) break;
                wart = tab[odkad];
                tab[odkad] = -1;
                ile--;
            }
        }
        printf("%d\n",ile);
    }
    return 0;
}
