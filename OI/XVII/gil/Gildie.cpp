#include<stdio.h>
#include<vector>
using namespace std;

const int ROZMIAR = 210000;
int nWierz, nKraw, kraw1, kraw2;
vector<int> graf[ROZMIAR];
char wynik[ROZMIAR];
bool czyByl[ROZMIAR];

int dfs(int wierz, char znak) {
    czyByl[wierz] = true;
    wynik[wierz] = znak;
    int wynik = 1;
    for(int i = 0; i < graf[wierz].size(); i++) {
        if(czyByl[graf[wierz][i]] == false) {
            wynik += dfs(graf[wierz][i], znak == 'K' ? 'S' : 'K');
        }
    }
    return wynik;
}

int main() {
    scanf("%d%d", &nWierz, &nKraw);
    for(int i = 0; i < nKraw; i++) {
        scanf("%d%d", &kraw1, &kraw2);
        graf[kraw1].push_back(kraw2);
        graf[kraw2].push_back(kraw1);
    }
    for(int i = 1; i <= nWierz; i++) {
        if(czyByl[i] == false) {
            if(dfs(i,'K') == 1) {
                printf("NIE");
                return 0;
            }
        }
    }
    printf("TAK\n");
    for(int i = 1; i <= nWierz; i++) {
        printf("%c\n",wynik[i]);
    }
    return 0;
}
