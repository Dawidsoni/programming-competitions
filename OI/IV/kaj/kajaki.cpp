#include<stdio.h>
#include<algorithm>
using namespace std;

int rozKaj, ile, wynik;
int tab[50000];

int main() {
    scanf("%d%d",&rozKaj,&ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d",&tab[i]);
    }
    sort(tab,tab+ile);
    int min = 0, max = ile - 1;
    for(;min < max;max--,wynik++) {
        if(tab[max] + tab[min] <= rozKaj) min++;
    }
    if(max == min) wynik++;
    printf("%d",wynik);
    return 0;
}
