#include <iostream>
#include <stdlib.h>
using namespace std;

typedef long long int LType;

const int MAX_SIZE = 1000010;

LType countArr[MAX_SIZE];
LType result = 0;
int fromInd, toInd;

void initCountArr(int fromInd, int toInd) {
    for(int divSize = 1; divSize < MAX_SIZE; divSize++) {
	int startElem = max(2 * divSize, divSize * (fromInd / divSize));
	for(int arrElem = startElem; arrElem <= toInd; arrElem += divSize) {
	    countArr[arrElem] += divSize;
	}
    }
}

int main() {
    cin >> fromInd >> toInd;
    initCountArr(fromInd, toInd);
    for(int i = fromInd; i <= toInd; i++) {
	result += abs(i - countArr[i]);	
    }
    cout << result << "\n";
    return 0;
}
