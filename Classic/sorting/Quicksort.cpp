#include<stdio.h>
#include<iostream> 
#include<ctime>
#include<cstdlib>
using namespace std;

int randInt(int fromInd, int toInd) {
    return rand() % (toInd - fromInd + 1) + fromInd;
}

int partition(int * arr, int fromInd, int toInd) { 
    int lessInd = fromInd - 1;
    for(int i = fromInd; i <= toInd - 1; i++) {
        if(arr[i] < arr[toInd]) {
            lessInd++;
            swap(arr[lessInd], arr[i]);
        }
    }
    swap(arr[toInd], arr[lessInd + 1]);
    return lessInd + 1;
}

int randomPartition(int * arr, int fromInd, int toInd) {
    int i = randInt(fromInd, toInd - 1);
    swap(arr[i], arr[toInd]);
    return partition(arr, fromInd, toInd);
}

void quicksort(int * arr, int fromInd, int toInd) {
    if(fromInd < toInd) {
        int middle = randomPartition(arr, fromInd, toInd);
        quicksort(arr, fromInd, middle - 1);
        quicksort(arr, middle + 1, toInd);
    }
}

int arr[1000000];
int count;

int main() {
    srand((unsigned int)time((time_t *)(NULL)));
    scanf("%d", &count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, count - 1);
    for(int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
