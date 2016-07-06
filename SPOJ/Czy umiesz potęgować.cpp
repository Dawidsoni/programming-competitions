#include<stdio.h>

struct ostatnie_cyfry {
    ostatnie_cyfry() {}
    ostatnie_cyfry(int numer) {
    int numer_skok = numer;
    for(int i=0;;i++) {
    tab[i] = numer_skok;
    numer_skok *= numer;
    numer_skok %= 10;
    if(numer_skok==numer) {
        ile = i+1;
        break;
    }
    }
    }
    int tab[4];
    int ile;
};


int main() {
    ostatnie_cyfry ostatnie[10];
    for(int i=0;i<10;i++)
        ostatnie[i] = ostatnie_cyfry(i);
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
    scanf("%d",&a);
    scanf("%d",&b);
    a = a%10;
    if(b!=0) {
    int ktore = (b%ostatnie[a].ile) - 1;
    if(ktore==-1) ktore = ostatnie[a].ile - 1;
    printf("%d\n",ostatnie[a].tab[ktore]);
    }else
        printf("1\n");

    }
    return 0;
}
