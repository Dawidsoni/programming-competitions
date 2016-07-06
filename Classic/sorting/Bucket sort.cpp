#include<stdio.h>
#include<list>
using namespace std;

double arr[100000];
double bArr[100000];
int count;
int arrNum;
list<double> bList[100000];

void bSort(int num) {
    int arrNum = 0;
    for(list<double>::iterator it = bList[num].begin(); it != bList[num].end(); it++) {
        bArr[arrNum++] = *it;
    }
    for(int i = 1; i < (int)bList[num].size(); i++) {
        double val = bArr[i];
        int j = i - 1;
        while(j >= 0 && bArr[j] > val) {
            bArr[j + 1] = bArr[j];
            j--;
        }
        bArr[j + 1] = val;
    }
    arrNum = 0;
    for(list<double>::iterator it = bList[num].begin(); it != bList[num].end(); it++) {
        *it = bArr[arrNum++];
    }
}

int main() {
    scanf("%d", &count);
    for(int i = 0;i < count; i++) {
        scanf("%lf", &arr[i]);
        int index = count * arr[i];
        bList[index].push_back(arr[i]);
    }
    for(int i = 0; i < count; i++) {
        bSort(i);
    }
    for(int i = 0; i < count; i++) { 
        for(list<double>::iterator it = bList[i].begin(); it != bList[i].end(); it++) {
            arr[arrNum] = *it;
            arrNum++;
        }
    }
    for(int i = 0; i < count; i++) {
        printf("%lf ", arr[i]);
    }
    return 0;
}
