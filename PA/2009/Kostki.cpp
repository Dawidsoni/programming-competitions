#include<stdio.h>

const int MAX_N = 600;
const int MAX_K = 3600;
float tab[MAX_N][MAX_K];

void liczWynik() {
    tab[0][0] = 100;
    for(int n = 1; n < MAX_N; n++) {
        for(int k = 1; k < MAX_K; k++) {
            for(int i = 1; i <= 6; i++) {
                tab[n][k] += tab[n - 1][k - i]/6.0;
            }
        }
    }
}

int nZest, nRzut, nWyn;

int main() {
    scanf("%d",&nZest);
    liczWynik();
    for(int i = 0; i < nZest; i++) {
        scanf("%d%d",&nRzut, &nWyn);
        if(nRzut >= MAX_N || nWyn >= MAX_K) {
            printf("0\n");
         }else {
            printf("%d\n",(int)tab[nRzut][nWyn]);
        }
    }
    return 0;
}
