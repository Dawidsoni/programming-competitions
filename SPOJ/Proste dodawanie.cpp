#include<stdio.h>

int main() {
    int n, ile, wczytaj, sumy[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&ile);
        sumy[i] = 0;
        for(int ii=0;ii<ile;ii++) {
            scanf("%d",&wczytaj);
            sumy[i] += wczytaj;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d\n",sumy[i]);
    }


    return 0;
}
