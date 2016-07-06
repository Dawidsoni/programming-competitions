#include<iostream>
using namespace std;

const int ROZMIAR = 70000;
const int TREE_SIZE = 1 << 17;

int ile, nPyt, maxSum, odkad, dokad, oIle;
int dMaks[TREE_SIZE * 2];
int dSciez[TREE_SIZE * 2];

int zwrocMaks(int odkad, int dokad) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    int lMax = 0, pMax = 0;
    while(odkad/2 < dokad/2) {
        lMax += dMaks[odkad];
        pMax += dMaks[dokad];
        if(odkad % 2 == 0) lMax = max(lMax, dSciez[odkad + 1]);
        if(dokad % 2 == 1) pMax = max(pMax, dSciez[dokad - 1]);
        odkad /= 2;
        dokad /= 2;
    }
    while(odkad > 0) {
        lMax += dMaks[odkad];
        pMax += dMaks[dokad];
        odkad /= 2;
        dokad /= 2;
    }
    return max(lMax, pMax);
}

void powieksz(int odkad, int dokad, int war) {
    odkad += TREE_SIZE;
    dokad += TREE_SIZE;
    int odk = odkad/2, dok = dokad/2;
    dMaks[odkad] += war;
    if(odkad != dokad) dMaks[dokad] += war;
    dSciez[odkad] = dMaks[odkad];
    dSciez[dokad] = dMaks[dokad];
    while(odkad/2 < dokad/2) {
        if(odkad % 2 == 0) {
            dMaks[odkad + 1] += war;
            dSciez[odkad + 1] += war;
        }
        if(dokad % 2 == 1) {
            dMaks[dokad - 1] += war;
            dSciez[dokad - 1] += war;
        }
        odkad /= 2;
        dokad /= 2;
    }
    while(odk > 0) {
        dSciez[odk] = max(dSciez[odk * 2], dSciez[odk * 2 + 1]) + dMaks[odk];
        dSciez[dok] = max(dSciez[dok * 2], dSciez[dok * 2 + 1]) + dMaks[dok];
        odk /= 2;
        dok /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> ile >> maxSum >> nPyt;
    for(int i = 0; i < nPyt; i++) {
        cin >> odkad >> dokad >> oIle;
        dokad--;
        int maks = zwrocMaks(odkad, dokad);
        if(maks + oIle > maxSum) {
            cout << "N" << endl;
        }else {
            powieksz(odkad, dokad, oIle);
            cout << "T" << endl;
        }

    }
    return 0;
}
