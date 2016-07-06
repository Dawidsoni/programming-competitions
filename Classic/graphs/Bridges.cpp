#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> IPair;
const int MAX_SIZE = 1000000;
const int INF = 100000000;
vector<int> graph[MAX_SIZE];
bool isCounted[MAX_SIZE];
int preOrder[MAX_SIZE];
IPair result[MAX_SIZE];
int vCount, eCount, v1, v2, currPre = 1, qCount;

int dfsOrder(int vertex, int parent) {
    isCounted[vertex] = true;
    preOrder[vertex] = currPre++;
    int low = preOrder[vertex];
    for(int i = 0; i < (int)graph[vertex].size(); i++) {
        if(isCounted[graph[vertex][i]] == false) {
            int lowChild = dfsOrder(graph[vertex][i], vertex);
            if(lowChild > preOrder[vertex]) {
				result[qCount++] = IPair(vertex, graph[vertex][i]);
			}
            low = min(low, lowChild);
        }else if(parent != graph[vertex][i]) {
            low = min(low, preOrder[graph[vertex][i]]);
        }
    }
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
            dfsOrder(i, 1);
        }
    }
    printf("%d\n", qCount);
    for(int i = 0; i < (int)qCount; i++) {
        printf("%d %d\n", result[i].first, result[i].second);
    }
    return 0;
}
