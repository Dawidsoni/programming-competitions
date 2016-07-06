#include<iostream>
#include<vector>
using namespace std;

bool isCounted[1000000];
vector<vector<int> > graph;

void dfs(int vertexNum) {
    isCounted[vertexNum] = true;
    cout << vertexNum << " ";
    for(int i = 0; i < (int)graph[vertexNum].size(); i++) {
        if(isCounted[graph[vertexNum][i]] == false) {
            dfs(graph[vertexNum][i]);
        }
    }
}

int main() {
    int n, a, b, startV;
    graph.resize(1000000);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    cin >> startV;
    dfs(startV);
    return 0;
}
