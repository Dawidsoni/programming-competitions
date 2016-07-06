#include<stdio.h>
#include<algorithm>
using namespace std;

const int ROZMIAR = 1100000;
int ile, nPyt, wcz, licz1, licz2, sum1, sum2;
char str[ROZMIAR];
int suma;
int tab[ROZMIAR];
int odKad[2 * ROZMIAR];
int doKad[2 * ROZMIAR];

void liczSumy(int suma, int a, int b) {
    odKad[suma] = a + 1;
    doKad[suma] = b + 1;
    while(a < b) {
        if(tab[a] == 1 && tab[b] == 1) {
            a++;
            b--;
        }else if(tab[a] == 2) {
            a++;
        }else {
            b--;
        }
        suma -= 2;
        odKad[suma] = a + 1;
        doKad[suma] = b + 1;
    }
}

int main() {
    scanf("%d%d",&ile, &nPyt);
    scanf("%s",str);
    for(int i = 0; i < ile; i++) {
        if(str[i] == 'T') tab[i] = 2;
        else tab[i] = 1;
        suma += tab[i];
    }
    liczSumy(suma,0, ile - 1);
    for(int i = 0; i < ile && tab[i] != 1; i++) {
        licz1++;
        sum1 += tab[i];
    }
    for(int i = ile - 1; i >= 0 && tab[i] != 1; i--) {
        licz2++;
        sum2 += tab[i];
    }
    if(licz1 <= licz2) {
        liczSumy(suma - sum1 - 1, licz1 + 1, ile - 1);
    }else {
        liczSumy(suma - sum2 - 1, 0, ile - licz2 - 2);
    }
    for(int i = 0; i < nPyt; i++) {
        scanf("%d", &wcz);
        if(odKad[wcz] == 0) printf("NIE\n");
        else printf("%d %d\n",odKad[wcz], doKad[wcz]);
    }
    return 0;
}
