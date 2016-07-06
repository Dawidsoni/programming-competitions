#include<stdio.h>

int ile, wcz_n, wcz_k;
int wynik[1000];

void wyznacz_zbiory(int max_zbioru, int ile_elem, int ktory_poziom, int od_ilu) {
    if(ktory_poziom<=ile_elem) {
        for(int i=od_ilu;i<=max_zbioru - (ile_elem - ktory_poziom);i++) {
            wynik[ktory_poziom - 1] = i;
            wyznacz_zbiory(max_zbioru, ile_elem, ktory_poziom + 1, i + 1);
        }
    }else {
        for(int i=0; i<ile_elem;i++) {
            printf("%d ", wynik[i]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d", &ile);
    for(int i=0;i<ile;i++) {
        scanf("%d %d", &wcz_n, &wcz_k);
        wyznacz_zbiory(wcz_n, wcz_k, 1, 1);
        printf("\n");
    }
    return 0;
}
