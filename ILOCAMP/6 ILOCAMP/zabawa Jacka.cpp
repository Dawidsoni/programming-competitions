#include<stdio.h>
#include<set>
using namespace std;

int n_testow, n_plackow, waga, szalka;
multiset<int> lewa;
multiset<int> prawa;
typedef multiset<int>::iterator it_type;

int main() {
    scanf("%d", &n_testow);
    for(int i=0;i<n_testow;i++) {
        scanf("%d", &n_plackow);
        for(int j=0;j<n_plackow;j++) {
            int wieksze_lewe = 0, wieksze_prawe = 0;
            scanf("%d %d", &waga, &szalka);
            if(szalka == 1) lewa.insert(waga);
            else prawa.insert(waga);
            if(prawa.size() == 0) printf(">\n");
            else if(lewa.size() == 0 ) printf("<\n");
            else {
            it_type it_lewy = lewa.end();
            it_type it_prawy = prawa.end();
            it_lewy--;
            it_prawy--;
            while(true) {
                if(*it_lewy > *it_prawy) {
                    wieksze_lewe++;
                   // printf("a");
                }else if(*it_lewy < *it_prawy) {
                   // printf("b");
                    wieksze_prawe++;
                }
                if(it_lewy == lewa.begin() || it_prawy == prawa.begin()) {
                    if(it_lewy != lewa.begin() && wieksze_prawe > wieksze_lewe) wieksze_lewe = wieksze_prawe;
                    if(it_prawy != prawa.begin() && wieksze_lewe > wieksze_prawe) wieksze_lewe = wieksze_prawe;
                    break;
                }
                it_lewy--;
                it_prawy--;
            }
           // printf("to: %d %d", wieksze_lewe, wieksze_prawe);
            if(wieksze_lewe == wieksze_prawe) printf("?\n");
            else if(wieksze_lewe > wieksze_prawe) printf(">\n");
            else printf("<\n");
            }
        }
    }
    return 0;
}
