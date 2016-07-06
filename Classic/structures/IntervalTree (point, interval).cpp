#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1 << 20;
int tree[MAX_SIZE * 2];
int qCount;
int nQuery;
bool isQuery;
int r1, r2;

void createTree() {
    for(int i = 0; i < MAX_SIZE; i++) {
        tree[i + MAX_SIZE] = tree[i];
        tree[i] = 0;
    }
    for(int i = MAX_SIZE - 1; i >= 1; i--) {
        tree[i] = max(tree[i*2], tree[i*2 + 1]);
    }
}

void powieksz(int num, int inc) {
    num += MAX_SIZE;
    tree[num] += inc;
    num /= 2;
    while(num > 0) {
        tree[num] = max(tree[num*2], tree[num*2 + 1]);
        num /= 2;
    }
}

int maxInterval(int fromInd, int toInd) {
    fromInd += MAX_SIZE;
    toInd += MAX_SIZE;
    int result = max(tree[fromInd], tree[toInd]);
    while(fromInd/2 < toInd/2) {
        if(fromInd % 2 == 0) result = max(result, tree[fromInd + 1]);
        if(toInd % 2 == 1) result = max(result, tree[toInd - 1]);
        fromInd /= 2;
        toInd /= 2;
    }
    return result;
}

int main() {
    scanf("%d", &qCount);
    for(int i = 0; i < qCount; i++) {
        scanf("%d", &tree[i]);
    }
    createTree();
    scanf("%d", &nQuery);
    for(int i = 0; i < nQuery; i++) {
        scanf("%d", &isQuery);
        if(isQuery == true) {
            scanf("%d%d", &r1, &r2);
            powieksz(r1, r2);
        }else {
            scanf("%d%d", &r1, &r2);
            printf("%d\n",maxInterval(r1, r2));
        }
    }
    return 0;
}
