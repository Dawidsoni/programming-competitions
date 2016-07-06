#include<stdio.h>
#include<vector>
using namespace std;

bool isCounted[100000];
vector<int> graph[100000];
int result[100000];
int vCount, incr, eCount;
int v1, v2;

void dfs(int vertex) {
    isCounted[vertex] = true;
    for(int i = 0; i < (int)graph[vertex].size(); i++) {
        if(isCounted[graph[vertex][i]] == false)
            dfs(graph[vertex][i]);
    }
    result[incr++] = vertex;
}

int main() {
    scanf("%d%d", &vCount, &eCount);
    for(int i = 0; i < eCount; i++) {
        scanf("%d%d", &v1, &v2);
        graph[v1].push_back(v2);
    }
    for(int i = 0; i < vCount; i++) {
        if(isCounted[i] == false)
            dfs(i);
    }
    for(int i = incr - 1; i >= 0 ; i--) {
        printf("%d ",result[i]);
    }
    return 0;
}
