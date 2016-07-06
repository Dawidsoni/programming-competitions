#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long int LType;
const int ROZMIAR = 1100000;
LType ileGrz, ileCzas, wynik, maks, dwaPola;
LType tab[ROZMIAR];

int main() {
    scanf("%lld%lld",&ileGrz, &ileCzas);
    for(int i = 0; i < ileGrz; i++) {
        scanf("%lld",&tab[i]);
    }
    if(ileGrz == 1) {
        ileCzas += 2;
        maks = (ileCzas/2) * tab[0];
    }else {
        for(int i = 0; i + 1 < ileGrz && ileCzas > 0; i++, ileCzas--) {
            wynik += tab[i];
            if(ileCzas % 2 == 0) {
                dwaPola = (ileCzas/2) * (tab[i] + tab[i + 1]);
            }else {
                dwaPola = ((ileCzas/2) * (tab[i] + tab[i + 1])) + tab[i + 1];
            }
            maks = max(maks,wynik + dwaPola);
        }
    }
    printf("%lld",maks);
    return 0;
}
