#include<stdio.h>
#include<vector>
using namespace std;

const int MAX_SIZE = 1000000;
vector<int> graph[MAX_SIZE];
vector<int> revGraph[MAX_SIZE];
vector<int> component[MAX_SIZE];
int vCount, eCount, postIncr, componentCount, varCount ,cCount, v1, v2, resCount;
int postOrder[MAX_SIZE];
bool isCounted[MAX_SIZE];
int currComp[MAX_SIZE];
int result[MAX_SIZE];

void dfs(int vertex) {
    isCounted[vertex] = true;
    for(int i = 0; i < (int)graph[vertex].size(); i++) {
        if(isCounted[graph[vertex][i]] == false) dfs(graph[vertex][i]);
    }
    postOrder[postIncr++] = vertex;
}

void revDfs(int vertex) {
    isCounted[vertex] = true;
    component[componentCount].push_back(vertex);
    for(int i = 0; i < (int)revGraph[vertex].size(); i++) {
        if(isCounted[revGraph[vertex][i]] == false) revDfs(revGraph[vertex][i]);
    }
}

void countRevGraph() {
    for(int i = 1; i <= vCount; i++) {
        for(int ii = 0; ii < (int)graph[i].size(); ii++) {
            revGraph[graph[i][ii]].push_back(i);
        }
    }
}

void sss() {
    for(int i = 1; i <= vCount; i++) {
        if(isCounted[i] == false) {
            dfs(i);
        }
    }
    countRevGraph();
    for(int i = 1; i <= vCount; i++) isCounted[i] = false;
    for(int i = vCount - 1; i >= 0; i--) {
        if(isCounted[postOrder[i]] == false) {
            revDfs(postOrder[i]);
            componentCount++;
        }
    }
}

int convertV(int vertex) {
    if(vertex > 0) return vertex * 2;
    else return vertex * -2 + 1;
}

int negate(int vertex) {
    if(vertex % 2 == 0) vertex++;
    else vertex--;
    return vertex;
}

bool countResult() {
    for(int i = componentCount - 1; i >= 0; i--) {
        for(int ii = 0; ii < (int)component[i].size(); ii++) {
            if(result[component[i][ii]] == -1) {
                result[component[i][ii]] = 1;
                result[negate(component[i][ii])] = 0;
                resCount++;
                for(int iii = 0; iii < (int)graph[component[i][ii]].size(); iii++) {
                    if(result[graph[component[i][ii]][iii]] == 0) return false;
                }
            }
        }
    }
    return (resCount >= vCount / 2);
}

int main() {
    scanf("%d%d", &varCount, &cCount);
    vCount = varCount * 2 + 1;
    for(int i = 0; i < cCount; i++) {
        scanf("%d%d", &v1, &v2);
        v1 = convertV(v1);
        v2 = convertV(v2);
        graph[negate(v1)].push_back(v2);
        graph[negate(v2)].push_back(v1);
    }
    sss();
    for(int i = 2; i <= vCount; i++) result[i] = -1;
    if(countResult()) {
        for(int i = 2; i <= vCount; i += 2) {
            if(result[i] == 1) printf("%d ", i / 2);
            else printf("%d ", i / -2);
        }
    }else printf("NIE");
    return 0;
}
