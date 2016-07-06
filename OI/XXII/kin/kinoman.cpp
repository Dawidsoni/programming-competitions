#include<iostream>
#include<queue>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 1100000;

LType ile, nWart, aktWyn, maxWyn;
LType tab[MAX_SIZE], wart[MAX_SIZE];
LType ileJest[MAX_SIZE];

void dlaPocz(LType pocz) {
    aktWyn = 0;
    for(int i = 1; i <= nWart; i++) {
        ileJest[i] = 0;
    }
    for(int i = pocz; i < ile; i++) {
        ileJest[tab[i]]++;
        if(ileJest[tab[i]] == 1) {
            aktWyn += wart[tab[i]];
        }else if(ileJest[tab[i]] == 2) {
            aktWyn -= wart[tab[i]];
        }
        maxWyn = max(maxWyn, aktWyn);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile >> nWart;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
    }
    for(int i = 1; i <= nWart; i++) {
        cin >> wart[i];
    }
    for(int i = 0; i < ile; i++) {
        dlaPocz(i);
    }
    cout << maxWyn << "\n";
    return 0;
}
