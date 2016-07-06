#include<stdio.h>
#include<algorithm>
using namespace std;

const int TREE_SIZE = 1 << 20;
int tree[TREE_SIZE * 2];
int maxTree[TREE_SIZE * 2];
int sCount;
int nQuery;
bool isChange;
int fInd, tInd, inc;

void createTree() {
    for(int i = 0; i < TREE_SIZE; i++) {
        tree[i + TREE_SIZE] = maxTree[i + TREE_SIZE] = tree[i];
        tree[i] = 0;
    }
    for(int i = TREE_SIZE - 1; i >= 1; i--) {
        maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
    }
 }

void setMax(int fromInd, int toInd, int maxVal) {
    fromInd += TREE_SIZE;
    toInd += TREE_SIZE;
    int fInd = fromInd / 2, tInd = toInd / 2;
    tree[fromInd] = max(tree[fromInd], maxVal);
    tree[toInd] = max(tree[toInd], maxVal);
    maxTree[fromInd] = max(tree[fromInd], maxVal);
    maxTree[toInd] = max(tree[toInd], maxVal);
    while(fromInd / 2 < toInd / 2) {
        if(fromInd % 2 == 0) tree[fromInd + 1] = max(tree[fromInd + 1], maxVal);
        if(toInd % 2 == 1) tree[toInd - 1] = max(tree[toInd - 1], maxVal);
        maxTree[fromInd + 1] = max(tree[fromInd + 1], max(maxTree[fromInd * 2], maxTree[fromInd * 2 + 1]));
        maxTree[toInd - 1] = max(tree[toInd - 1], max(maxTree[toInd * 2], maxTree[toInd * 2 + 1]));
        fromInd /= 2;
        toInd /= 2;
    }
    while(fInd > 0) {
        maxTree[fInd] = max(tree[fInd], max(maxTree[fInd * 2], maxTree[fInd * 2 + 1]));
        maxTree[tInd] = max(tree[tInd], max(maxTree[tInd * 2], maxTree[tInd * 2 + 1]));
        fInd /= 2;
        tInd /= 2;
    }
}

int getMax(int fromInd, int toInd) {
    fromInd += TREE_SIZE;
    toInd += TREE_SIZE;
    int leftMax = tree[fromInd], rightMax = tree[toInd];
    while(fromInd/2 < toInd/2) {
        if(fromInd % 2 == 0) leftMax = max(leftMax, maxTree[fromInd + 1]);
        if(toInd % 2 == 1) rightMax = max(rightMax, maxTree[toInd - 1]);
        leftMax = max(leftMax,tree[fromInd]);
        rightMax = max(rightMax, tree[toInd]);
        fromInd /= 2;
        toInd /= 2;
    }
    while(fromInd > 0) {
        leftMax = max(leftMax, tree[fromInd]);
        rightMax = max(rightMax, tree[toInd]);
        fromInd /= 2;
        toInd /= 2;
    }
    return max(leftMax, rightMax);
}

int main() {
    scanf("%d", &sCount);
    for(int i = 0; i < sCount; i++) {
        scanf("%d", &tree[i]);
    }
    createTree();
    scanf("%d", &nQuery);
    for(int i = 0;i < nQuery; i++) {
        scanf("%d", &isChange);
        if(isChange == true) {
            scanf("%d%d%d", &fInd, &tInd, &inc);
            setMax(fInd, tInd, inc);
        }else {
            scanf("%d%d", &fInd, &tInd);
            printf("%d\n",getMax(fInd, tInd));
        }
    }
    return 0;
}
