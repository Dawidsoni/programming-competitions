#include<iostream>
#include<climits>
using namespace std;

int arr[100000];
int count;


void linkSets(int startInd, int middleInd, int endInd) {
    int length1 = middleInd - startInd + 1;
    int length2 = endInd - middleInd;
    int set1[length1], set2[length2];    
    int elem1 = 0, elem2 = 0;
    for(int i = 0; i < length1; i++) {
        set1[i] = arr[startInd + i];
    }
    for(int i = 0; i < length2; i++) {
        set2[i] = arr[middleInd + 1 + i];
    }
    set1[length1] = INT_MAX;
    set2[length2] = INT_MAX;
    for(int i = 0; i < length1 + length2; i++) {
        if(set1[elem1] < set2[elem2]) {
            arr[startInd + i] = set1[elem1];
            elem1++;
        }else {
            arr[startInd + i] = set2[elem2];
            elem2++;
        }
    }
}

void mergeSort(int fromInd, int toInd) {
    int middleInd = (fromInd + toInd)/2;
    if(toInd - fromInd > 0) {
        mergeSort(fromInd, middleInd);
        mergeSort(middleInd + 1, toInd);
        linkSets(fromInd, middleInd, toInd);
    }
}

int main() {
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    mergeSort(0, count - 1);
    for(int i=0; i < count; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
