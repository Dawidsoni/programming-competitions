#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<vector<int> > graph;
stack<int> vStack;
vector<int> result;
int startV, v1, v2, eCount, vCount;
int indeg[1000000], outdeg[1000000];
bool isCycle = true;

int main() {
    graph.resize(1000000);
    cin >> vCount >> eCount;
    for(int i=0; i < eCount; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        outdeg[v1]++;
        indeg[v2]++;
    }
    for(int i=0; i < vCount; i++) {
        if(indeg[i] != outdeg[i]) {
            isCycle = false;
            break;
        }
    }
    cin >> startV;
    vStack.push(startV);
    if(isCycle) {
        while(!vStack.empty()) {
            int num = vStack.top();
            if(!graph[num].empty()) {
                vStack.push(graph[num].back());
                graph[num].pop_back();
            }else {
                result.push_back(vStack.top());
                vStack.pop();
            }
        }
        for(int i=result.size()-1;i>=0;i--) {
            cout << result[i] << " ";
        }
    }else {
        cout << "Nie ma cyklu";
    }
    return 0;
}
