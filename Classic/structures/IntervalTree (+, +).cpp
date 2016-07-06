#include<stdio.h>

const int TREE_SIZE = 1 << 20;
int tree[TREE_SIZE * 2];
int sumTree[TREE_SIZE * 2];
int count, nCount;
int fInd, tInd, o_i;
bool isIncrement;

void createTree() {
    for(int i = 0; i < TREE_SIZE; i++) {
        tree[i + TREE_SIZE] = sumTree[i + TREE_SIZE] = tree[i];
        tree[i] = 0;
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        sumTree[i] = sumTree[i*2] + sumTree[i*2 + 1];
    }
}

void increment(int fromInd, int toInd, int inc) {
    int elemCount = 1;
    fromInd += TREE_SIZE;
    toInd += TREE_SIZE;
    int fInd = fromInd / 2, tInd = toInd / 2;
    tree[fromInd] += inc;
    sumTree[fromInd] += inc;
    if(fromInd != toInd) {
        tree[toInd] += inc;
        sumTree[toInd] += inc;
    }
    while(fromInd / 2 < toInd / 2) {
        if(fromInd % 2 == 0) {
            tree[fromInd + 1] += inc;
            sumTree[fromInd + 1] += (inc*elemCount);
        }
        if(toInd % 2 == 1) {
            tree[toInd - 1] += inc;
            sumTree[toInd - 1] += (inc*elemCount);
        }
        fromInd /= 2;
        toInd /= 2;
        elemCount *= 2;
    }
    while(fInd > 0) {
        sumTree[fInd] = sumTree[fInd*2] + sumTree[fInd*2 + 1];
        sumTree[tInd] = sumTree[tInd*2] + sumTree[tInd*2 + 1];
        fInd /= 2;
        tInd /= 2;
    }
}

int intervalSum(int fromInd, int toInd) {
    int elemCount = 1, fromLeft = 1, fromRight = 1;
    int leftResult = 0, rightResult = 0;
    fromInd += TREE_SIZE;
    toInd += TREE_SIZE;
    while(fromInd / 2 < toInd / 2) {
        leftResult += (tree[fromInd]*fromLeft);
        rightResult += (tree[toInd]*fromRight);
        if(fromInd % 2 == 0) {
            fromLeft += elemCount;
            leftResult += sumTree[fromInd + 1];
        }
        if(toInd % 2 == 1) {
            fromRight += elemCount;
            rightResult += sumTree[toInd - 1];
        }
        fromInd /= 2;
        toInd /= 2;
        elemCount *= 2;
    }
    leftResult += (tree[fromInd]*fromLeft);
    rightResult += (tree[toInd]*fromRight);
    fromInd /= 2;
    while(fromInd > 0) {
        leftResult += (tree[fromInd] * (fromLeft + fromRight));
        fromInd /= 2;
    }
    return leftResult + rightResult;
}

int main() {
    scanf("%d", &count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &tree[i]);
    }
    createTree();
    scanf("%d", &nCount);
    for(int i = 0; i < nCount; i++) {
        scanf("%d", &isIncrement);
        if(isIncrement == true) {
            scanf("%d%d%d", &fInd, &tInd, &o_i);
            increment(fInd,tInd,o_i);
        }else {
            scanf("%d%d", &fInd, &tInd);
            printf("%d\n", intervalSum(fInd,tInd));
        }
    }
    return 0;
}
