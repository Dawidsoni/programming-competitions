#include<iostream>
#include<algorithm>
using namespace std;

const int ROZMIAR = 1000100;
const int TREE_SIZE = 1 << 20;

int ile, nPyt, odkad, dokad;
int dMaks[TREE_SIZE * 2];
int dSciez[TREE_SIZE * 2];

void ustawMaks(int odkad, int dokad, int war) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    int odK = odkad/2, doK = dokad/2;
    dMaks[odkad] = dSciez[odkad] = max(dMaks[odkad], war);
    dMaks[dokad] = dSciez[dokad] = max(dMaks[dokad], war);
    while(odkad/2 < dokad/2) {
        if(odkad % 2 == 0) {
            dMaks[odkad + 1] = max(dMaks[odkad + 1], war);
            dSciez[odkad + 1] = max(dSciez[odkad + 1], dMaks[odkad + 1]);
        }
        if(dokad % 2 == 1) {
            dMaks[dokad - 1] = max(dMaks[dokad - 1], war);
            dSciez[dokad - 1] = max(dSciez[dokad - 1], dMaks[dokad - 1]);
        }
        odkad /= 2;
        dokad /= 2;
    }
    while(odK > 0) {
        dSciez[odK] = max(dSciez[odK], max(dSciez[odK * 2], dSciez[odK * 2 + 1]));
        dSciez[doK] = max(dSciez[doK], max(dSciez[doK * 2], dSciez[doK * 2 + 1]));
        odK /= 2;
        doK /= 2;
    }
}

int zwrocMaks(int odkad, int dokad) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    int lMax = 0, pMax = 0, odK = odkad, doK = dokad;
    while(odkad/2 < dokad/2) {
        if(odkad % 2 == 0) lMax = max(lMax, dSciez[odkad + 1]);
        if(dokad % 2 == 1) pMax = max(pMax, dSciez[dokad - 1]);
        odkad /= 2;
        dokad /= 2;
    }
    while(odK > 0) {
        lMax = max(lMax, dMaks[odK]);
        pMax = max(pMax, dMaks[doK]);
        odK /= 2;
        doK /= 2;
    }
    return max(lMax, pMax);
}

int main() {
    cin >> ile >> nPyt;
    for(int i = 0; i < nPyt; i++) {
        cin >> dokad >> odkad;
        dokad += odkad;
        dokad--;
        ustawMaks(odkad, dokad, zwrocMaks(odkad, dokad) + 1);
    }
    cout << zwrocMaks(0, ile - 1);
    return 0;
}