#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;


int wynik[2000000];
set<int> tab[2000000];
bool czy_bylo[2000000];
int ile, wcz_1, wcz_2;

int najdluzsza_sciezka(int z_numeru) {
    if(tab[z_numeru].size() == 0) {
        czy_bylo[z_numeru] = true;
        return 1;
    }
    else if(wynik[z_numeru] == 0) {
        set<int>::iterator it = tab[z_numeru].end();
        it--;
        int max = 0;
        do {
            int wyn = najdluzsza_sciezka(*it) + 1;
            if(wyn > max) max = wyn;
            it--;
        } while (it != tab[z_numeru].begin());
        wynik[z_numeru] = max;
        czy_bylo[z_numeru] = true;
        return max;
    }else {
        czy_bylo[z_numeru] = true;
        return wynik[z_numeru] + 1;
    }
}

int main() {
    scanf("%d", &ile);
    for(int i=1;i<=ile;i++) {
        scanf("%d %d", &wcz_1, &wcz_2);
        for(int j=wcz_1; j <= wcz_2; j++) {
            if( i > j) {
                tab[i].insert(j);
            }
        }
    }
    while(true) {
        bool czy_koniec = true;
        for(int i = ile; i >= 1; i--) {
            if(czy_bylo[i] == false) {
                czy_koniec = false;
                najdluzsza_sciezka(i);
            }
        }
        if(czy_koniec) break;
    }
    int max = 0;
    for(int i=1; i <= ile ; i++) {
        if(wynik[i] > max) max = wynik[i];
    }
    printf("%d", max);
    return 0;
}
