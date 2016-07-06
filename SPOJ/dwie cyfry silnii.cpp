#include<stdio.h>

int main() {
    int n, wczytaj;
    long wsk[100000];
    scanf("%d",&n);


    for(int i=0;i<n;i++) {
        scanf("%d",&wczytaj);
        wsk[i] = 1;
        for(int ii=2;ii<=wczytaj&&ii<=10;ii++) {
            wsk[i] *= ii;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d %d \n",((wsk[i]%100) - (wsk[i]%10))/10,wsk[i]%10);
    }
    return 0;
}
