#include<stdio.h>

const int rozmiar = 1000100;
int wsk_pocz;
int n_kolor, n_lan;
int lan[rozmiar];
int max_kolor[rozmiar];
int ile_kolor[rozmiar];
int tab_pom[rozmiar];
int wczytaj, wynik, n_dobrych;

int main() {
    scanf("%d%d", &n_lan, &n_kolor);
    for(int i = 0; i < n_kolor; i++) {
        scanf("%d", &tab_pom[i]);
    }
    for(int i = 0; i < n_kolor; i++) {
        scanf("%d", &wczytaj);
        max_kolor[wczytaj] = tab_pom[i];
    }
    for(int i = 0; i < n_lan; i++) {
        scanf("%d", &lan[i]);
    }
    for(int i = 0; i < n_lan; i++) {
        ile_kolor[lan[i]]++;
        if(ile_kolor[lan[i]] > max_kolor[lan[i]]) {
            while(true) {
                ile_kolor[lan[wsk_pocz]]--;
                if((max_kolor[lan[wsk_pocz]] != 0)&&(ile_kolor[lan[wsk_pocz]] + 1 == max_kolor[lan[wsk_pocz]] || ile_kolor[lan[wsk_pocz]] == max_kolor[lan[wsk_pocz]])) n_dobrych--;
                wsk_pocz++;
                if(lan[wsk_pocz - 1] == lan[i]) break;
            }
        }
        if(ile_kolor[lan[i]] == max_kolor[lan[i]] && max_kolor[lan[i]] != 0) n_dobrych++;
        if(n_dobrych == n_kolor) wynik++;
    }
    printf("%d",wynik);
    return 0;
}
