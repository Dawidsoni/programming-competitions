#include<stdio.h>
#include<vector>
using namespace std;

typedef pair<int, int> para;
const int MAX_SIZE = 1000000;
vector<para> graph[MAX_SIZE];
bool isCounted[MAX_SIZE], isInResult[MAX_SIZE], isEdge[MAX_SIZE];
int group1[MAX_SIZE], group2[MAX_SIZE];
int vCount, eCount, gr1Count, gr2Count, v1, v2, vertex, result, numKraw;

bool dfs(int vertex, bool isFree) {
    isCounted[vertex] = true;
    for(int i = 0; i < (int)graph[vertex].size(); i++) {
        if(isCounted[graph[vertex][i].first] == false && isEdge[graph[vertex][i].second] == isFree) {
            if(isFree && isInResult[graph[vertex][i].first] == false) {
                isEdge[graph[vertex][i].second] = false;
                isInResult[graph[vertex][i].first] = true;
                return true;
            }
            bool result = dfs(graph[vertex][i].first,!isFree);
            if(result == true) {
                isEdge[graph[vertex][i].second] = isEdge[!graph[vertex][i].second];
                return result;
            }
        }
    }
    return false;
}

bool matched(int vertex) {
    for(int i = 1; i <= vCount; i++) isCounted[i] = false;
    isInResult[vertex] = dfs(vertex, true);
    return isInResult[vertex];
}

int main() {
    scanf("%d%d%d", &gr1Count, &gr2Count, &eCount);
    vCount = gr1Count + gr2Count;
    for(int i = 0; i < gr1Count; i++) {
        scanf("%d", &vertex);
        group1[i] = vertex;
    }
    for(int i = 0; i < gr2Count; i++) {
        scanf("%d", &vertex);
        group2[i] = vertex;
    }
    for(int i = 0; i < eCount; i++) {
        scanf("%d%d", &v1, &v2);
        graph[v1].push_back(para(v2, i));
        graph[v2].push_back(para(v1, i));
        isEdge[i] = true;
    }
    for(int i = 0; i < gr1Count; i++) {
        if(matched(group1[i])) result++;
    }
    printf("%d",result);
    return 0;
}
