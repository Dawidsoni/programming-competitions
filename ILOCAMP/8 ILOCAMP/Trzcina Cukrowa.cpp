#include <stdio.h>
 
const int ROZMIAR = 1010;
 
int ile, odX, doX, odY, doY, nPyt;
int tab[ROZMIAR][ROZMIAR];
int suma[ROZMIAR][ROZMIAR][10];
 
int nwd(int licz1, int licz2) {
	while(licz1 != 0 && licz2 != 0) {
		if(licz1 > licz2) licz1 %= licz2;
        else licz2 %= licz1;
    }
    return licz1 == 0 ? licz2 : licz1;
}
 
int main() {
    scanf("%d%d",&ile,&nPyt);
    for(int i = 1; i <= ile; i++) {
            for(int ii = 1; ii <= ile; ii++) {
				scanf("%d",&tab[i][ii]);
            }
    }
    for(int i = 1; i <= ile; i++) {
            for(int ii = 1; ii <= ile; ii++) {
                    suma[i][ii][0] = tab[i][ii];
            }
    }
    for(int dlug = 1, poteg = 1; dlug <= 9; dlug++, poteg *= 2) {
        for(int i = 1; i <= ile; i++) {
	        for(int j = 1; j <= ile; j++) {
			    if(i + poteg <= ile && j + poteg <= ile) {
				    int akt = nwd(suma[i][j][dlug - 1], suma[i + poteg][j][dlug - 1]);
                    akt = nwd(akt, suma[i][j + poteg][dlug - 1]);
                    akt = nwd(akt, suma[i + poteg][j + poteg][dlug - 1]);
                    suma[i][j][dlug] = akt;
               }
			}
		}
    }
	for(int i = 0; i < nPyt; i++) {
		scanf("%d%d%d%d", &odX, &odY, &doX, &doY);
        int dlugosc = doX - odX + 1;
        int maxPot = 1, ind = 0;
        while(maxPot * 2 <= dlugosc) {
                maxPot *= 2;
                ind++;
        }
        int wynik = nwd(suma[odX][odY][ind], suma[odX + (dlugosc - maxPot)][odY][ind]);
        wynik = nwd(wynik, suma[odX][odY + (dlugosc - maxPot)][ind]);
        wynik = nwd(wynik, suma[odX + (dlugosc - maxPot)][odY + (dlugosc - maxPot)][ind]);
		printf("%d\n", wynik);
    }      
	return 0;
}
