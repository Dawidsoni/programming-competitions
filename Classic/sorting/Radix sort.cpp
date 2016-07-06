#include<stdio.h>

int arr[100000];
int result[100000];
int digit[100000];
int nArray[100000];
int kArray[100000];
int nRow[10];
int count, nDigits;
int nDiv = 10;

void countRow() {
    for(int i = 0; i < 10; i++) {
        nRow[i] = 0;
    }
    for(int i = 0; i < count; i++) {
        nArray[i] = result[i];
        kArray[i] = arr[i];
        nRow[digit[i]]++;
    }
    for(int i = 1; i < 10; i++) {
        nRow[i] += nRow[i - 1];
    }
    for(int i = count - 1; i >= 0; i--) {
        result[nRow[digit[i]] - 1] = nArray[i];
        arr[nRow[digit[i]] - 1] = kArray[i];
        nRow[digit[i]]--;
    }
}

int main() {
    scanf("%d%d", &nDigits, &count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
        result[i] = arr[i];
    }
    for(int i = 0; i < nDigits; i++) {
        for(int j = 0; j < count; j++) {
            digit[j] = (arr[j] % nDiv)/(nDiv / 10);
            arr[j] -= (arr[j] % nDiv);
        }
        nDiv *= 10;
        countRow();
    }
    for(int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
