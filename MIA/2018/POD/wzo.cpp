#include <iostream>
#include <vector>
using namespace std;

typedef long long int LType;

const int MAX_DIGITS = 60;
const int MAX_SIZE = 1000010;

int n;
int modNum[MAX_DIGITS];
bool isPossible[MAX_SIZE];
int indexList[MAX_SIZE];
vector<int> digitList;

void initModNum() {
    modNum[0] = 1;
    modNum[1] = 10 % n;
    if(modNum[1] == 0) {
        modNum[1] = n;
    }
    for(int i = 2; i < MAX_DIGITS; i++) {
        modNum[i] = ((LType)modNum[i - 1] * modNum[1]) % n;
        if(modNum[i] == 0) {
            modNum[i] = n;
        }
    }
}

void updatePosNumSet(int num, int index) {
    vector<int> indVec;
    for(int i = 0; i < n; i++) {
        int ind = i + num;
        if(ind > n) {
            ind %= n;
        }
        if(isPossible[i] && isPossible[ind] == false) { 
            indVec.push_back(ind);
        }
    }
    for(int i = 0; i < (int)indVec.size(); i++) {
        isPossible[indVec[i]] = true;
        indexList[indVec[i]] = index;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    initModNum();
    isPossible[0] = true;
    for(int i = 0; i < MAX_DIGITS; i++) {
        updatePosNumSet(modNum[i], i);
    }
    int num = n;
    while(num != 0) {
        int index = indexList[num];
        digitList.push_back(index);
        num -= modNum[index];
        if(num < 0) {
            num += n;
        }
    }
    cout << "1";
    for(int i = 1; i < (int)digitList.size(); i++) {
        for(int j = 0; j < digitList[i - 1] - digitList[i] - 1; j++) {
            cout << "0";
        }
        cout << "1";
    }
    for(int i = digitList[digitList.size() - 1]; i > 0; i--) {
        cout << "0";
    }
    cout << "\n";
    return 0;
}
