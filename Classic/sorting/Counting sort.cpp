#include<stdio.h>

int count, maxNum;
int arr[1000000];
int nRow[1000000];
int result[1000000];

int main() {
    scanf("%d%d", &maxNum, &count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
        nRow[arr[i]]++;
    }
    for(int i = 1; i <= maxNum; i++) {
        nRow[i] += nRow[i - 1];
    }
    for(int i = count - 1; i >= 0; i--) {
        result[nRow[arr[i]] - 1] = arr[i];
        nRow[arr[i]]--;
    }
    for(int i = 0; i < count; i++) {
        printf("%d ",result[i]);
    }
    return 0;
}
