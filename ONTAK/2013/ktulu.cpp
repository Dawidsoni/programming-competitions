#include<stdio.h>
#include<algorithm>
using namespace std;

const int ROZMIAR = 550000;
int ile;
int tab[ROZMIAR];
int dpTab[ROZMIAR];

int main() {
    scanf("%d", &ile);
    for(int i = 1; i <= ile; i++) {
        scanf("%d", &tab[i]);
    }
    sort(tab + 1, tab + ile + 1);
    for(int i = 1; i <= ile; i++){
        if(i - tab[i] < 0) {
            dpTab[i] = -1;
        }
        else if(dpTab[i - tab[i]] != -1 && tab[i - tab[i] + 1] + 1 >= tab[i]) {
            dpTab[i] = dpTab[i - tab[i]] + 1;
        }else {
            dpTab[i] = -1;
        }
    }
    /*for(int i = 1; i <= ile; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
    for(int i = 1; i <= ile; i++) {
        printf("%d ",dpTab[i]);
    }
    printf("\n");*/
    printf("%d",dpTab[ile]);
    return 0;
}
