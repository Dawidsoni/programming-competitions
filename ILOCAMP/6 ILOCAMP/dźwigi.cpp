#include<stdio.h>
#include<algorithm>
using namespace std;

typedef pair<int,int> para;
int wcz, ile;
bool czy_mozna = true;


para wczytaj() {
    para naj;
    scanf("%d", &wcz);
    if(wcz == 0) {
        para wyn1 = wczytaj();
        para wyn2 = wczytaj();
        if(!(wyn1.first < wyn2.second || wyn2.first < wyn1.second)) {
            czy_mozna = false;
//printf("%d %d ", wyn1.first, wyn1.second);
        }
        return para(max(wyn1.first, wyn2.first), min(wyn1.second, wyn2.second));
    }else {
        return para(wcz,wcz);
    }
}

int main() {
    para p1 = wczytaj();
    para p2 = wczytaj();
    if(!(p1.first < p2.second || p2.first < p1.second)) {
        czy_mozna = false;
    }
  //  para wynik = para(max(p1.first, p2.first), min(p1.second, p2.second));
  //  printf("%d %d", wynik.first, wynik.second);
    if(czy_mozna) printf("TAK");
    else printf("NIE");
    return 0;
}
