#include<iostream>
#include<climits>
using namespace std;

class Range {
public:
    int from, to, val;
    Range(int from_, int to_, int val_) : from(from_), to(to_), val(val_) {}
};

int arr[1000000];
int count;

Range findInTheMiddle(int fromInd, int middleInd, int toInd) {
    int maxLeft = INT_MIN, maxRight = INT_MIN;
    int indexLeft, indexRight, sumLeft = 0, sumRight = 0;
    for(int i = middleInd; i >= fromInd; i--) {
        sumLeft += arr[i];
        if(sumLeft>maxLeft) {
            maxLeft = sumLeft;
            indexLeft = i;
        }
    }
    for(int i = middleInd + 1; i <= toInd; i++) {
        sumRight += arr[i];
        if(sumRight>maxRight) {
            maxRight = sumRight;
            indexRight = i;
        }
    }
    return Range(indexLeft, indexRight, maxLeft + maxRight);
}

Range maxSubarray(int fromInd, int toInd) {
    if(fromInd == toInd) {
        return Range(fromInd, toInd, arr[fromInd]);
    }else {
        int middleInd = (fromInd + toInd) / 2;
        Range startRange = maxSubarray(fromInd, middleInd);
        Range endRange = maxSubarray(middleInd + 1, toInd);
        Range middleRange = findInTheMiddle(fromInd,middleInd,toInd);
        if(startRange.val >= endRange.val && startRange.val >= middleRange.val) {
            return startRange;
        }else if(middleRange.val >= startRange.val && middleRange.val >= endRange.val) {
            return middleRange;
        }else {
            return endRange;
        }
    }
}

int main() {
    cin >> count;
    for(int i=0; i < count; i++) {
        cin >> arr[i];
    }
    Range range = maxSubarray(0, count - 1);
    cout << range.from << " " << range.to << " " << range.val;
    return 0;
}
