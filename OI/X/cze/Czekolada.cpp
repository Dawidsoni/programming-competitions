#include<stdio.h>
#include<algorithm>
using namespace std;

const int ROZMIAR = 1100;
int tab1[ROZMIAR];
int tab2[ROZMIAR];
int ile1, ile2, wynik;
int mnoz1 = 1, mnoz2 = 1;

int main() {
    scanf("%d%d", &ile1, &ile2);
    tab1[0] = tab2[0] = -1;
    for(int i = 1 ; i < ile1; i++) {
        scanf("%d", &tab1[i]);
    }
    for(int i = 1; i < ile2; i++) {
        scanf("%d", &tab2[i]);
    }
    sort(tab1,tab1 + ile1);
    sort(tab2,tab2 + ile2);
    while(ile1 > 1 || ile2 > 1) {
        if(tab1[ile1 - 1] > tab2[ile2 - 1]) {
            wynik += tab1[ile1 - 1] * mnoz1;
            mnoz2++;
            ile1--;
        }else {
            wynik += tab2[ile2 - 1] * mnoz2;
            mnoz1++;
            ile2--;
        }
    }
    printf("%d",wynik);
    return 0;
}
