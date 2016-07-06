#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isCounted[1000000];

int main() {
    vector<vector<int> > graph;
    graph.resize(100000);
    queue<int> vQueue;
    int n, a, b, startV;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >>  b;
        graph[a].push_back(b);
    }
    cin >> startV;
    vQueue.push(startV);
    isCounted[startV] = true;
    while(!vQueue.empty()) {
        int currV = vQueue.front();
        vQueue.pop();
        cout << currV << " ";
        for(int i = 0; i < (int)graph[currV].size(); i++) {
            if(isCounted[graph[currV][i]]==false) {
                vQueue.push(graph[currV][i]);
                isCounted[graph[currV][i]] = true;
            }
        }
    }
    return 0;
}
