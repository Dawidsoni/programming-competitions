#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int result[10000000], startV, eCount, a, b, c, vCount;
bool isCounted[10000000];
typedef pair<int,int> IPair;
vector<vector<IPair> > graph;
priority_queue<IPair, vector<IPair>, greater<IPair> > minQueue;

int main() {
    graph.resize(10000000);
    cin >> vCount >> eCount;
    for(int i=0; i < eCount; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(IPair(c, b));
    }
    cin >> startV;
    for(int i=1; i <= vCount; i++) {
        result[i] = INT_MAX;
    }
    result[startV] = 0;
    minQueue.push(IPair(0, startV));
    while(!minQueue.empty()) {
        while(true) {
            if(minQueue.empty()) break;
            if(isCounted[minQueue.top().second] == false)
                break;
            else {
                minQueue.pop();
            }
        }
        if(minQueue.empty()) break;
        int num = minQueue.top().second;
        isCounted[num] = true;
        for(int i = 0; i < (int)graph[num].size(); i++) {
            if(result[graph[num][i].second] > result[num] + graph[num][i].first) {
                result[graph[num][i].second] = result[num] + graph[num][i].first;
                minQueue.push(IPair(result[graph[num][i].first], graph[num][i].second));
            }
        }
        minQueue.pop();
    }
    for(int i=1;i<vCount;i++)
        cout << result[i] << " ";
    return 0;
}
