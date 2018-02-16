#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100010;

int nodeCount, queryCount;
int v1, v2;
int vDeep[MAX_SIZE];
int vType[MAX_SIZE];
bool isVisited[MAX_SIZE];
vector<int> edgeList[MAX_SIZE];
vector<int> tree[MAX_SIZE];
vector<int> deepVec[MAX_SIZE];
int currType = 1;

void createTree(int node) {
    isVisited[node] = true;
    for(int i = 0; i < (int)edgeList[node].size(); i++) {
        if(isVisited[edgeList[node][i]] == false) {
            tree[node].push_back(edgeList[node][i]);
            createTree(edgeList[node][i]);
        }
    }
}

int initDeep(int node) {
    int deep = 1;
    for(int i = 0; i < (int)tree[node].size(); i++) {
        deep = max(deep, initDeep(tree[node][i]) + 1);
    }
    vDeep[node] = deep;
    return deep;
}

void createDeepVec() {
    for(int i = 1; i <= nodeCount; i++) {
        deepVec[vDeep[i]].push_back(i);
    }
}

vector<int> getId(int node) {
    vector<int> id;
    for(int i = 0; i < (int)tree[node].size(); i++) {
        id.push_back(vType[tree[node][i]]);
    }
    sort(id.begin(), id.end());
    return id;
}

void assignType(vector<int> deepVec) {
    vector<pair<vector<int>, int> > idList;
    for(int i = 0; i < (int)deepVec.size(); i++) {
        idList.push_back(pair<vector<int>, int>(getId(deepVec[i]), deepVec[i]));     
    }
    sort(idList.begin(), idList.end());
    vType[idList[0].second] = currType;
    for(int i = 1; i < (int)deepVec.size(); i++) {
        if(idList[i].first != idList[i - 1].first) {
            currType++; 
        }
        vType[idList[i].second] = currType;
    }
    currType++;
}

void countResult() {
    int maxDeep = initDeep(1);
    createDeepVec();
    for(int i = 1; i <= maxDeep; i++) {
        assignType(deepVec[i]);    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nodeCount >> queryCount;
    for(int i = 0; i + 1 < nodeCount; i++) {
        cin >> v1 >> v2;
        edgeList[v1].push_back(v2);
        edgeList[v2].push_back(v1);
    }
    createTree(1);
    countResult();
    for(int i = 0; i < queryCount; i++) {
        cin >> v1 >> v2;
        if(vDeep[v1] == vDeep[v2] && vType[v1] == vType[v2]) {
            cout << "Tak\n";
        }else {
            cout << "Nie\n";
        }
    }
    return 0;
}
