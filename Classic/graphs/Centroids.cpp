#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX_SIZE = 1000000;
vector<int> graph[MAX_SIZE];
bool isCounted[MAX_SIZE];
int result[MAX_SIZE];
int preOrder[MAX_SIZE];
int vCount, eCount, v1, v2, currRes, currPre = 1;

int dfs(int vertex, int parent, bool isRoot) {
    isCounted[vertex] = true;
    preOrder[vertex] = currPre++;
    int low = preOrder[vertex];
    bool isCentroid = false;
    for(int i = 0; i < (int)graph[vertex].size(); i++) {
        if(isCounted[graph[vertex][i]] == false) {
            int lowChild = dfs(graph[vertex][i], vertex, false);
            if(isRoot && i == 1) {
                isCentroid = true;
            }
            else if(isRoot == false) {
                if(preOrder[vertex] <= lowChild) isCentroid = true;
            }
            low = min(low, lowChild);
        }else if(graph[vertex][i] != parent) {
            low = min(low, preOrder[graph[vertex][i]]);
        }
    }
    if(isCentroid) result[currRes++] = vertex;
    return low;
}

int main() {
    scanf("%d%d", &vCount, &eCount);
    for(int i = 0; i < eCount; i++) {
        scanf("%d%d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i <= vCount; i++) {
        if(isCounted[i] == false) {
            dfs(i, 0, true);
        }
    }
    printf("%d\n",currRes);
    for(int i = 0; i < currRes; i++) {
        printf("%d ",result[i]);
    }
    return 0;
}
