#include <iostream>
using namespace std;

const int MAX_SIZE = 1100000;
const int MOD_P = 1000000007;
typedef long long int LType;

int arrCount;
int arr[MAX_SIZE];
LType powerArr[MAX_SIZE];
LType result;

void initPowers() {
    powerArr[0] = 1;
    for(int i = 1; i <= arrCount; i++) {
        powerArr[i] = (powerArr[i - 1] * 2);
        if(powerArr[i] >= MOD_P) {
            powerArr[i] %= MOD_P;
        }
    }
}

LType getElemSum(int ind) {
    LType elemSum = 0;
    elemSum += powerArr[arrCount];
    elemSum += powerArr[arrCount - 1];
    elemSum -= powerArr[arrCount - ind - 1];
    if(elemSum < 0) {
        elemSum += MOD_P;
    }
    elemSum -= powerArr[ind];
    if(elemSum < 0) {
        elemSum += MOD_P;
    }
    elemSum *= arr[ind];
    if(elemSum >= MOD_P) {
        elemSum %= MOD_P;
    }
    return elemSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> arrCount;
    for(int i = 0; i < arrCount; i++) {
        cin >> arr[i];
    }
    initPowers();
    for(int i = 0; i < arrCount; i++) {
        result += getElemSum(i);
        if(result >= MOD_P) {
            result %= MOD_P;
        }
    }
    cout << result << "\n";
}
