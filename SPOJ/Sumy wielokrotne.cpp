#include<stdio.h>


int main() {
    long long sumy[100000];
    int wczytaj = 1;
    int ile;
    long long suma = 0;
    for(int i=0;;i++) {
        sumy[i] = 0;
        wczytaj = 1;
        for(int ii=0;wczytaj!=0&&wczytaj!=EOF;ii++) {
            if(scanf("%lld",&wczytaj)==EOF) {
                ile = i+1;
                if(ii==0) ile--;
                goto start;
            }

            sumy[i] += wczytaj;
        }
    }
    start:
    for(int i=0;i<ile;i++) {
        printf("%lld\n",sumy[i]);
        suma += sumy[i];
    }
    printf("%lld",suma);
    return 0;
}
