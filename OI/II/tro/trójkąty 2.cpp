#include<stdio.h>
#include<algorithm>
using namespace std;

int tab[100], ile;

int main() {
    for(;;ile++) {
        scanf("%d",&tab[ile]);
        if(tab[ile] == 0) break;
        if(ile == 99) break;
    }
    sort(tab, tab + ile);
    for(int i = 2; i < ile; i++) {
        if(tab[i] < tab[i - 1] + tab[i - 2]) {
            printf("%d %d %d\n",tab[i],tab[i - 1], tab[i - 2]);
            return 0;
        }
    }
    printf("NIE\n");
    return 0;
}
