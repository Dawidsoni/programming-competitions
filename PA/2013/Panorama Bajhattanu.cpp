#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long int lInt;
const lInt ROZ = 1100000;
lInt tab1[ROZ], tab2[ROZ];
lInt ile1, ile2, suma, wczyt;
lInt max1, max2;

int main() {
    scanf("%lld%lld",&ile1,&ile2);
    for(lInt i = 0; i < ile1; i++) {
        scanf("%lld",&wczyt);
        tab1[wczyt]++;
        max1 = max(max1,wczyt);
    }
    for(lInt i = 0; i < ile2; i++) {
        scanf("%lld",&wczyt);
        tab2[wczyt]++;
        max2 = max(max2,wczyt);
    }
    if(max1 != max2) {
        printf("NIE");
    }else {
        for(lInt i = 0;ile1 > 0 && ile2 > 0;i++) {
            suma += i * tab1[i] * ile2;
            ile1 -= tab1[i];
            suma += i * tab2[i] * ile1;
            ile2 -= tab2[i];
        }
        printf("%lld",suma);
    }
    return 0;
}
