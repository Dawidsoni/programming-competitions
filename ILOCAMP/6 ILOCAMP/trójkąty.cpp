#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

typedef long long int long_type;
typedef pair<int,int> para;
set<para> poszukiwane;
set<para> krawedze;
vector<int> do_posz[500100];
long_type brakujace[500100];
long_type wierz_asi;
long_type trojkaty_jacka;
long_type trojkaty_asi;
long_type ile_wierz, wierz1, wierz2, ile_kraw;
long_type n_znika;
int main() {
    scanf("%d %d", &ile_wierz, &ile_kraw);
    n_znika = ile_wierz - 2;
    for(int i = 3; i<=ile_wierz;i++) {
        trojkaty_jacka += (i - 1)*(i - 2) / 2;
    }
    for(int i=0;i<ile_kraw;i++) {
        scanf("%d %d", &wierz1, &wierz2);
        int ktory_min = min(wierz1, wierz2), ktory_max = max(wierz1, wierz2);
            do_posz[ktory_min].push_back(ktory_max);
            do_posz[ktory_max].push_back(ktory_min);
            for(int i=0;i + 1<do_posz[ktory_min].size();i++) {
                poszukiwane.insert(para(min(do_posz[ktory_min][i], ktory_max), max(do_posz[ktory_min][i], ktory_max)));
            }
            for(int i=0;i + 1<do_posz[ktory_max].size();i++) {
                poszukiwane.insert(para(min(do_posz[ktory_max][i], ktory_min), max(do_posz[ktory_max][i], ktory_min)));
            }
            krawedze.insert(para(ktory_min,ktory_max));
        trojkaty_jacka = trojkaty_jacka - (n_znika - brakujace[wierz1] -  brakujace[wierz2]);
        if(brakujace[wierz1]==0) wierz_asi++;
        if(brakujace[wierz2]==0) wierz_asi++;
        brakujace[wierz1]++;
        brakujace[wierz2]++;
    }
    for(set<para>::iterator it = krawedze.begin(); it != krawedze.end(); it++) {
        if(poszukiwane.find(*it) != poszukiwane.end()) trojkaty_asi++;
    }
  //  printf("%d ", poszukiwane.size());
   // printf("%d %d ", (*poszukiwane.begin()).first, (*poszukiwane.begin()).second);
    printf("%d", trojkaty_asi + trojkaty_jacka);
    return 0;
}
