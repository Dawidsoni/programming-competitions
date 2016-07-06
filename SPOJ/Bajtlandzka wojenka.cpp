#include<stdio.h>
#include<set>
#include<bitset>
using namespace std;

bitset<100> bajtolomeusz, przeciwnik;
set<int> karty_bajt;
int wczytaj, ile_wygranych;

int main() {
    for(int i=0; i<26;i++) {
        scanf("%d", &wczytaj);
        bajtolomeusz.set(wczytaj,1);
        karty_bajt.insert(wczytaj);
    }
    przeciwnik = bajtolomeusz.flip();
    for(int i=1;i<=52;i++) {
        if(przeciwnik[i]==0) continue;
        set<int>::iterator it = karty_bajt.lower_bound(i);
        if(it != karty_bajt.end()) {
            ile_wygranych++;
            karty_bajt.erase(it);
        }else {
            karty_bajt.erase(karty_bajt.begin());
        }
    }
    printf("%d",ile_wygranych);
    return 0;
}
