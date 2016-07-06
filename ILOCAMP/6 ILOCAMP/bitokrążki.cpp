#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

multiset<int> tab;
multiset<int> tab2;
typedef multiset<int>::iterator it_type;
int lewy, prawy, ile;
int max_wynik, wynik;
int wczytaj;

int main() {
    scanf("%d %d %d", &ile, &lewy, &prawy);
    for(int i=0;i<ile;i++) {
        scanf("%d", &wczytaj);
        tab.insert(wczytaj);
        tab2.insert(wczytaj);
    }
    it_type it = tab.lower_bound(lewy);
    int poprz_wartosc = lewy;
    while(it != tab.begin()) {
        it--;
        if(*it + 1 != poprz_wartosc && *it != poprz_wartosc) {
            break;
        }
        if(*it != poprz_wartosc) {
            wynik++;
            if(it == tab.begin()) break;
            poprz_wartosc = *it;
            it_type kopia = it;
            it--;
            tab.erase(kopia);
            it++;
        }
    }
    it = tab.upper_bound(prawy);
    poprz_wartosc = prawy;
    while(it != tab.end()) {
        if(*it - 1 != poprz_wartosc && *it != poprz_wartosc) {
            break;
        }
        if(*it != poprz_wartosc) {
            wynik++;
            if(it == tab.end()) break;
            poprz_wartosc = *it;
            it_type kopia = it;
            it++;
            tab.erase(kopia);
        }
    }
    ///////////////////////////////////////////////////////////////////
    max_wynik = wynik;
    wynik = 0;
    it = tab2.upper_bound(prawy);
    poprz_wartosc = prawy;
    while(it != tab2.end()) {
        if(*it - 1 != poprz_wartosc && *it != poprz_wartosc) {
            break;
        }
        if(*it != poprz_wartosc) {
            wynik++;
            if(it == tab2.end()) break;
            poprz_wartosc = *it;
            it_type kopia = it;
            it++;
            tab2.erase(kopia);
        }
    }
    it = tab2.lower_bound(lewy);
    poprz_wartosc = lewy;
    while(it != tab2.begin()) {
        it--;
        if(*it + 1 != poprz_wartosc && *it != poprz_wartosc) {
            break;
        }
        if(*it != poprz_wartosc) {
            wynik++;
            if(it == tab2.begin()) break;
            poprz_wartosc = *it;
            it_type kopia = it;
            it--;
            tab2.erase(kopia);
            it++;
        }
    }
    if(wynik > max_wynik) max_wynik = wynik;
    printf("%d",max_wynik);
    return 0;
}
