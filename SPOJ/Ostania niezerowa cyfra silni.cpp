#include<stdio.h>
using namespace std;

long long int  ostatnia_cyfra[1001];
long long int ile, wczytaj;
const long long int o_ile = 10000000000000000;
int main() {
    ostatnia_cyfra[0] = 1;
    long long int ostatnia = 1;
    for(int i=1;i<1001;i++) {
        ostatnia_cyfra[i] = ostatnia * i;
        while(ostatnia_cyfra[i] % 10 == 0) {
            ostatnia_cyfra[i] /= 10;
        }
        ostatnia = ostatnia_cyfra[i] % o_ile;
        ostatnia_cyfra[i] %= 10;
    }
    scanf("%d", &ile);
    for(int i=0;i<ile;i++) {
        scanf("%d", &wczytaj);
        printf("%d\n",ostatnia_cyfra[wczytaj]);
    }
    return 0;
}
