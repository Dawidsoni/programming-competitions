#include<stdio.h>

int size[1000000];
int price[1000000];
int sCount;
int capacity;
int result[1000000];

int main() {
    scanf("%d %d", &capacity, &sCount);
    for(int i = 0; i < sCount; i++) {
        scanf("%d %d", &size[i], &price[i]);
    }
    for(int i = 1; i <= capacity; i++) {
        for(int j = 0; j < sCount; j++) {
            if(size[j] > i) continue;
            if(price[j] + result[i - size[j]] > result[i]) {
                result[i] = price[j] + result[i - size[j]];
            }
        }
    }
    for(int i = 1; i <= capacity; i++) {
        printf("%d ",result[i]);
    }
    return 0;
}
