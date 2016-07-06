#include<stdio.h>
using namespace std;

int ile, dzien1, dzien2, ktory_dzien;
int tab[10000], ile_tab;

int main() {
    scanf("%d", &ile);
    for(int i=0;i<ile;i++) {
        scanf("%d %d %d", &ktory_dzien, &dzien1, &dzien2);
        tab[1] = dzien1 % 10;
        tab[2] = dzien2 % 10;
        for(int i=3;;i++) {
            tab[i] = tab[i - 1] + tab[i - 2];
            tab[i] %= 10;
                if(tab[i]==tab[2] && tab[i - 1]==tab[1]) {
                    ile_tab = i - 2;
                    break;
                }
            }
            ktory_dzien %= ile_tab;
            if(ktory_dzien==0) ktory_dzien = ile_tab;
            printf("%d\n", tab[ktory_dzien]);
    }
    return 0;
}
