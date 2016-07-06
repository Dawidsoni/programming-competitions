#include<stdio.h>
#include<algorithm>
using namespace std;

int tab[600000];
int lewy[600000];
int prawy[600000];
int dyn_wynik[600000];
int n_dyn_wynik;
int ile;

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d", &tab[i]);
    }
    for(int i = 0; i <ile; i++) {
        int * wsk = lower_bound(dyn_wynik, dyn_wynik + n_dyn_wynik, tab[i]);
        *wsk = tab[i];
        if(wsk == &dyn_wynik[n_dyn_wynik]) n_dyn_wynik++;
        lewy[i] = n_dyn_wynik;
    }
    n_dyn_wynik = 0;
    for(int i = ile - 1; i >= 0; i--) {
        int * wsk = lower_bound(dyn_wynik, dyn_wynik + n_dyn_wynik, tab[i]);
        *wsk = tab[i];
        if(wsk == &dyn_wynik[n_dyn_wynik]) n_dyn_wynik++;
        prawy[i] = n_dyn_wynik;
    }
    int max = 0;
    for(int i=0; i < ile;i++) {
        if(lewy[i] + prawy[i] > max) max = lewy[i] + prawy[i];
    }
    printf("%d", ile - max + 1);
    return 0;
}
