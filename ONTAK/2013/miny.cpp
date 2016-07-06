#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long int LType;
const int ROZMIAR = 120000;
const int TREE_SIZE = 1 << 17;
int ileZest, ile;
LType tabSr[ROZMIAR], tabZas[ROZMIAR];
int drzewoMin[TREE_SIZE * 2];
int drzewoMax[TREE_SIZE * 2];

void inicMin() {
    for(int i = 0; i < ile; i++) {
        drzewoMin[i + TREE_SIZE] = drzewoMin[i];
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        drzewoMin[i] = min(drzewoMin[i*2], drzewoMin[i*2 + 1]);
    }
}

void inicMax() {
    for(int i = 0; i < ile; i++) {
        drzewoMax[i + TREE_SIZE] = drzewoMax[i];
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        drzewoMax[i] = max(drzewoMax[i*2], drzewoMax[i*2 + 1]);
    }
}

int zapytanie(int numer) {
    numer += TREE_SIZE;
    int odKad = drzewoMin[numer];
    int doKad = drzewoMax[numer];
    odKad += TREE_SIZE;
    doKad += TREE_SIZE;
    int minWyn = min(drzewoMin[odKad], drzewoMin[doKad]);
    int maxWyn = max(drzewoMax[odKad], drzewoMax[doKad]);
    while(odKad / 2 < doKad / 2) {
        if(odKad % 2 == 0) {
            minWyn = min(minWyn, drzewoMin[odKad + 1]);
            maxWyn = max(maxWyn, drzewoMax[odKad + 1]);
        }
        if(doKad % 2 == 1) {
            minWyn = min(minWyn, drzewoMin[doKad - 1]);
            maxWyn = max(maxWyn, drzewoMax[doKad - 1]);
        }
        odKad /= 2;
        doKad /= 2;
    }
    drzewoMin[numer] = minWyn;
    drzewoMax[numer] = maxWyn;
    numer /= 2;
    while(numer >= 1) {
        drzewoMin[numer] = min(drzewoMin[numer*2], drzewoMin[numer*2 + 1]);
        drzewoMax[numer] = max(drzewoMax[numer*2], drzewoMax[numer*2 + 1]);
        numer /= 2;
    }
    return maxWyn - minWyn;
}

void wypisz() {
    for(int i = 0; i < ile; i++) {
        LType * wsk1 = lower_bound(tabSr, tabSr + ile, tabSr[i] - tabZas[i]);
        LType * wsk2 = upper_bound(tabSr, tabSr + ile, tabSr[i] + tabZas[i]);
        drzewoMin[i] = wsk1 - tabSr;
        drzewoMax[i] = wsk2 - tabSr - 1;
    }
    inicMax();
    inicMin();
    for(int i = 0; i < ile; i++) {
        int suma = zapytanie(i);
        while(true) {
            int nowa = zapytanie(i);
            if(nowa != suma) suma = nowa;
            else break;
        }
        printf("%d ",suma + 1);
    }
    printf("\n");
}


int main() {
    scanf("%d",&ileZest);
    for(int i = 0; i < ileZest; i++) {
        scanf("%d", &ile);
        for(int ii = 0; ii < ile; ii++) {
            scanf("%lld%lld",&tabSr[ii], &tabZas[ii]);
        }
        wypisz();
    }
    return 0;
}
