#include<iostream>
#include<stdio.h>
using namespace std;

int arr[100000];
int count;

inline int leftSon(int i) {
    return 2 * i;
}

inline int rightSon(int i) {
    return 2 * i + 1;
}

inline int parent(int i) {
    return i / 2;
}

void moveDown(int * arr, int count, int ind) {
    int left = leftSon(ind), right = rightSon(ind), max;
    if(left <= count && arr[left] > arr[ind]) max = left;
    else max = ind;
    if(right <= count && arr[right] > arr[max]) max = right;
    if(max != ind) {
        swap(arr[max], arr[ind]);
        moveDown(arr, count, max);
    }
}


void makeHeap(int * arr, int count) {
    for(int i = count / 2; i >= 1 ; i--) {
        moveDown(arr, count, i);
    }
}

void heapSort(int * arr, int count) {
    makeHeap(arr,count);
    for(int i = 1; i <= count; i++) {
        swap(arr[1], arr[count - i + 1]);
        moveDown(arr, count - i, 1);
    }
}

int main() {
    scanf("%d", &count);
    for(int i = 1; i <= count; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, count);
    for(int i = 1; i <= count; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
