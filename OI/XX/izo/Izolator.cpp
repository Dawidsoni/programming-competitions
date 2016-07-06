#include<stdio.h>
#include<algorithm>
using namespace std;

int ile, wynik;
int tab[100100];

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d", &tab[i]);
        wynik += tab[i];
    }
    sort(tab, tab + ile);
    int pocz = 0, kon = ile - 1;
    while(pocz < kon) {
        wynik += tab[kon--] - tab[pocz++];
    }
    printf("%d",wynik);
    return 0;
}
