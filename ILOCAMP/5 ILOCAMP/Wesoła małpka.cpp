#include<stdio.h>

typedef long long int int_t;

int nwd(int_t a, int_t b) {
    while(a!=0&&b!=0) {
        if(a > b) {
            a %= b;
        }else {
            b %= a;
        }
    }
    if(a==0) return b;
    else return a;
}


int_t ile, n_klatek, dlugosc_skoku;

int main() {
    scanf("%lld",&ile);
    for(int i=0;i<ile;i++) {
        scanf("%lld%lld",&n_klatek,&dlugosc_skoku);
        printf("%lld\n",n_klatek/nwd(n_klatek,dlugosc_skoku));
    }
    return 0;
}
