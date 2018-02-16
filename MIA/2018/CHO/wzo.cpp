#include <iostream>
#include <bitset>
using namespace std;

int queryCount, recipeCount, ingrCount, dishCount, ownedIngrCount;
int ownedIngrList[20];
int ingrCost[20];
bool ingrAcc;
bitset<13> ingrArr[35];
bitset<13> cpArr[35];

bitset<13> createMask(int num) {
    int pos = 0;
    bitset<13> result;
    while(num > 0) {
        if(num % 2 == 1) {
            result.set(pos);
        }
        num /= 2;
        pos++;
    }
    return result;
}

void putOwned() {
    bitset<13> ownedMask;
    for(int i = 0; i < ownedIngrCount; i++) {
        ownedMask.set(ownedIngrList[i]);
    }
    ownedMask.flip();
    for(int i = 0; i < recipeCount; i++) {
        ingrArr[i] &= ownedMask;
    }
}

bool isSufficientDishes() {
    int total = 0;
    for(int i = 0; i < recipeCount; i++) {
        if(cpArr[i].count() == 0) {
            total++;
        }
    }
    return (total >= dishCount);
}

void makeCpArr() {
    for(int i = 0; i < recipeCount; i++) {
        cpArr[i] = ingrArr[i];
    }
}

void putMask(bitset<13> mask) {
    for(int i = 0; i < recipeCount; i++) {
        cpArr[i] &= mask;
    }
}

int getCost(bitset<13> mask) {
    mask.flip();
    int result = 0;
    for(int i = 0; i < ingrCount; i++) {
        if(mask[i]) {
            result += ingrCost[i];
        }
    }
    return result;
}

int countResult() {
    int result = 1000000000;
    putOwned();
    for(int i = 1; i < (1 << ingrCount); i++) {
        bitset<13> mask = createMask(i);
        makeCpArr();
        putMask(mask);
        if(isSufficientDishes()) {
            result = min(result, getCost(mask));
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> queryCount;
    for(int i = 0; i < queryCount; i++) {
        cin >> recipeCount >> ingrCount >> dishCount >> ownedIngrCount;
        for(int j = 0; j < ownedIngrCount; j++) {
            cin >> ownedIngrList[j];
        }
        for(int j = 0; j < ingrCount; j++) {
            cin >> ingrCost[j];
        }
        for(int j = 0; j < recipeCount; j++) {
            for(int k = 0; k < ingrCount; k++) {
                cin >> ingrAcc;
                if(ingrAcc) {
                    ingrArr[j].set(k);
                }
            }
        }
        cout << countResult() << "\n";
        for(int j = 0; j < recipeCount; j++) {
            ingrArr[j].reset();
        }
    }
    return 0;
}
