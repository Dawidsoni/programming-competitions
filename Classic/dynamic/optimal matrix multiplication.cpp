#include<stdio.h>
#include<climits>
using namespace std;

int arr[1000];
int result[1000][1000];
int optDiv[1000][1000];
int count;

int main() {
    scanf("%d", &count);
    count++;
    for(int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    for(int length = 2; length < count; length++) {
        for(int i = 0; i + length < count; i++) {
            int j = i + length;
            result[i][j] = INT_MAX;
            for(int k = i; k + 1 < j; k++) {  
                int val = result[i][k + 1] + result[k + 1][j] + arr[i] * arr[k + 1] * arr[j];
                if(val < result[i][j]) {
                    result[i][j] = val;
                    optDiv[i][j] = k + 1;
                }
            }
        }
    }
    printf("%d", result[0][count - 1]);
    return 0;
}
