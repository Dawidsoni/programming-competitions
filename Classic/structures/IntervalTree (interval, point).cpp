#include<stdio.h>

const int TREE_SIZE = 1 << 20;
int tree[TREE_SIZE * 2];
int count;
int nQuery;
int fInd, tInd, inc;

void createTree() {
    for(int i = 0; i < TREE_SIZE; i++) {
        tree[i + TREE_SIZE] = tree[i];
        tree[i] = 0;
    }
}

void increment(int fromInd, int toInd, int inc) {
    fromInd += TREE_SIZE;
    toInd += TREE_SIZE;
    tree[fromInd] += inc;
    if(fromInd != toInd) tree[toInd] += inc;
    while(fromInd/2 < toInd/2) {
        if(fromInd % 2 == 0) tree[fromInd + 1] += inc;
        if(toInd % 2 == 1) tree[toInd - 1] += inc;
        fromInd /= 2;
        toInd /= 2;
    }
}

int getVal(int num) {
    num += TREE_SIZE;
    int result = 0;
    while(num > 0) {
        result += tree[num];
        num /= 2;
    }
    return result;
}

int main() {
    scanf("%d", &count);
    for(int i = 0; i < count; i++) {
        scanf("%d",&tree[i]);
    }
    createTree();
    scanf("%d", &nQuery);
    for(int i = 0; i < nQuery; i++) {
        scanf("%d%d%d", &fInd, &tInd, &inc);
        increment(fInd, tInd, inc);
        for(int j = 0; j < count; j++) {
            printf("%d ", getVal(j));
        }
        printf("\n");
    }
    return 0;
}
