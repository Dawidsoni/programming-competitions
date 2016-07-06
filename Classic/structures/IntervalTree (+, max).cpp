#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1 << 20;
int tree[MAX_SIZE * 2];
int maxTree[MAX_SIZE * 2];
int sCount, nQuery;
bool isIncrement;
int fInd, tInd, o_i;

void createTree() {
    for(int i = 0; i < MAX_SIZE; i++) {
        tree[i + MAX_SIZE] = tree[i];
        maxTree[i + MAX_SIZE] = tree[i];
        tree[i] = 0;
    }
    for(int i = MAX_SIZE - 1; i >= 1; i--) {
        maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
    }
}

void increment(int fromInd, int toInd, int inc) {
    fromInd += MAX_SIZE;
    toInd += MAX_SIZE;
    int fInd = fromInd/2, tInd = toInd/2;
    tree[fromInd] += inc;
    if(fromInd != toInd) tree[toInd] += inc;
    maxTree[fromInd] = tree[fromInd];
    maxTree[toInd] = tree[toInd];
    while(fromInd / 2 < toInd / 2) {
        if(fromInd % 2 == 0) {
            tree[fromInd + 1] += inc;
            maxTree[fromInd + 1] += inc;
        }
        if(toInd % 2 == 1) {
            tree[toInd - 1] += inc;
            maxTree[toInd - 1] += inc;
        }
        toInd /= 2;
        fromInd /= 2;
    }
    while(fInd > 0) {
        maxTree[fInd] = max(maxTree[fInd * 2], maxTree[fInd * 2 + 1]) + tree[fInd];
        maxTree[tInd] = max(maxTree[tInd * 2], maxTree[tInd * 2 + 1]) + tree[tInd];
        fInd /= 2;
        tInd /= 2;
    }
}

int maxVal(int fromInd, int toInd) {
    fromInd += MAX_SIZE;
    toInd += MAX_SIZE;
    int maxLeft = 0, maxRight = 0;
    while(fromInd/2 < toInd/2) {
        maxLeft += tree[fromInd];
        if(fromInd % 2 == 0) maxLeft = max(maxLeft, maxTree[fromInd + 1]);
        maxRight += tree[toInd];
        if(toInd % 2 == 1) maxRight = max(maxRight, maxTree[toInd - 1]);
        fromInd /= 2;
        toInd /= 2;
    }
    while(fromInd > 0) {
        maxLeft += tree[fromInd];
        maxRight += tree[toInd];
        fromInd /= 2;
        toInd /= 2;
    }
    return max(maxLeft, maxRight);
}


int main() {
    scanf("%d", &sCount);
    for(int i = 0; i < sCount; i++) {
        scanf("%d", &tree[i]);
    }
    createTree();
    scanf("%d", &nQuery);
    for(int i = 0; i < nQuery; i++) {
        scanf("%d", &isIncrement);
        if(isIncrement == true) {
            scanf("%d%d%d", &fInd, &tInd, &o_i);
            increment(fInd, tInd, o_i);
            printf("incrementylem\n");
        }else {
            scanf("%d%d", &fInd, &tInd);
            printf("%d\n", maxVal(fInd, tInd));
        }
    }
    return 0;
}
