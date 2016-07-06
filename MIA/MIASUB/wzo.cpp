#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_SIZE = 1100000;

typedef pair<int, int> IPair;

int nVertex;
int vertex1, vertex2;
vector<int> graph[MAX_SIZE];
bool isChecked[MAX_SIZE];
vector<int> cycleList;
int result[MAX_SIZE];
int cycleVertex;

bool dfs(int vertex, int parent) {
	isChecked[vertex] = true;
	for(int i = 0; i < (int)graph[vertex].size(); i++) {
		if(graph[vertex][i] == parent) {
			continue;
		}
		if(isChecked[graph[vertex][i]]) {
			cycleList.push_back(vertex);
			cycleVertex = graph[vertex][i];
			return true;
		}else {
			if(dfs(graph[vertex][i], vertex)) {
				cycleList.push_back(vertex);
				return (vertex != cycleVertex);
			}
		}
	}
	return false;
}

void bfs() {
	queue<IPair> vQueue;
	for(int i = 0; i < (int)cycleList.size(); i++) {
		vQueue.push(IPair(cycleList[i], 0));
		isChecked[cycleList[i]] = true;
	}
	while(vQueue.size() > 0) {
		int currentV = vQueue.front().first;
		int currentLength = vQueue.front().second;
		vQueue.pop();
		for(int i = 0; i < (int)graph[currentV].size(); i++) {
			if(isChecked[graph[currentV][i]] == false) {
				isChecked[graph[currentV][i]] = true;
				vQueue.push(IPair(graph[currentV][i], currentLength + 1));
				result[graph[currentV][i]] = currentLength + 1;
			}
		}
		
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nVertex;
	for(int i = 0; i < nVertex; i++) {
		cin >> vertex1 >> vertex2;
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}
	dfs(1, 0);
	for(int i = 1; i <= nVertex; i++) {
		isChecked[i] = false;
	}
	bfs();	
	for(int i = 1; i <= nVertex; i++) {
		cout << result[i] << " ";
	}
	return 0;
}
